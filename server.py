"""
AlgoDeck Backend - FastAPI Server
Powers the local flashcard deck, compiles and runs C++ code, and syncs progress.
"""

import os
import subprocess
from pathlib import Path
from fastapi import FastAPI, HTTPException
from fastapi.staticfiles import StaticFiles
from fastapi.middleware.cors import CORSMiddleware
from pydantic import BaseModel

BASE_DIR = Path(__file__).resolve().parent

app = FastAPI(title="AlgoDeck API", version="1.0.0")

# Enable CORS for local development
app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

class RunCodeRequest(BaseModel):
    filepath: str

@app.get("/api/health")
def health():
    return {"status": "ok", "app": "AlgoDeck API"}

@app.post("/api/run-code")
def run_cpp_code(req: RunCodeRequest):
    """
    Compiles and executes a C++ file locally using clang++ -std=c++20.
    Returns stdout, stderr, and exit code.
    """
    clean_path = req.filepath.strip().lstrip("/")
    target_file = BASE_DIR / clean_path

    if not target_file.exists():
        raise HTTPException(status_code=404, detail=f"File not found: {clean_path}")

    binary_path = BASE_DIR / "temp_runner"

    # Step 1: Compile with C++20
    compile_cmd = [
        "clang++",
        "-std=c++20",
        "-O2",
        str(target_file),
        "-o",
        str(binary_path)
    ]

    try:
        comp_res = subprocess.run(compile_cmd, capture_output=True, text=True, timeout=10)
        if comp_res.returncode != 0:
            return {
                "success": False,
                "stage": "compilation",
                "output": comp_res.stderr or comp_res.stdout
            }
    except subprocess.TimeoutExpired:
        return {"success": False, "stage": "compilation", "output": "Compilation timed out (>10s)"}

    # Step 2: Execute Binary
    try:
        exec_res = subprocess.run([str(binary_path)], capture_output=True, text=True, timeout=5)
        return {
            "success": exec_res.returncode == 0,
            "stage": "execution",
            "output": exec_res.stdout + (("\nSTDERR:\n" + exec_res.stderr) if exec_res.stderr else "")
        }
    except subprocess.TimeoutExpired:
        return {"success": False, "stage": "execution", "output": "Execution timed out (>5s) - possible infinite loop!"}
    finally:
        if binary_path.exists():
            binary_path.unlink()

@app.get("/api/file-content")
def get_file_content(path: str):
    """Returns the raw contents of a given source code file."""
    clean_path = path.strip().lstrip("/")
    target_file = BASE_DIR / clean_path
    if not target_file.exists():
        raise HTTPException(status_code=404, detail="File not found")
    return {"content": target_file.read_text()}

# Mount UI static files at root
ui_dir = BASE_DIR / "ui"
if ui_dir.exists():
    app.mount("/", StaticFiles(directory=str(ui_dir), html=True), name="static")

if __name__ == "__main__":
    import uvicorn
    uvicorn.run("server:app", host="127.0.0.1", port=8000, reload=True)
