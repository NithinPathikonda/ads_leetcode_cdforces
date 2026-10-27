#!/usr/bin/env python3
"""
Obsidian Knowledge Graph Generator & Synchronizer
Parses TRACKER.md and POTD archive to build a fully bi-directionally linked
Obsidian Vault with custom Graph View coloring, Pattern MOCs, Company Hubs,
and Problem Cards.
"""

import os
import re
import json
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
VAULT_DIR = BASE_DIR / "obsidian"
PATTERNS_DIR = VAULT_DIR / "patterns"
PROBLEMS_DIR = VAULT_DIR / "problems"
COMPANIES_DIR = VAULT_DIR / "companies"
DIFFICULTY_DIR = VAULT_DIR / "difficulty"
OBSIDIAN_CONF_DIR = VAULT_DIR / ".obsidian"

def sanitize_filename(name: str) -> str:
    cleaned = re.sub(r'[\\/*?:"<>|]', '', name)
    return cleaned.strip()

def setup_directories():
    for d in [VAULT_DIR, PATTERNS_DIR, PROBLEMS_DIR, COMPANIES_DIR, DIFFICULTY_DIR, OBSIDIAN_CONF_DIR]:
        d.mkdir(parents=True, exist_ok=True)

def generate_obsidian_config():
    # app.json
    app_json = {
        "useMarkdownLinks": False,
        "newFileLocation": "root",
        "attachmentFolderPath": "/",
        "livePreview": True
    }
    with open(OBSIDIAN_CONF_DIR / "app.json", "w", encoding="utf-8") as f:
        json.dump(app_json, f, indent=2)

    # graph.json with tailored color groups
    graph_json = {
        "collapse-filter": False,
        "search": "",
        "localJumps": 1,
        "localBacklinks": True,
        "localForelinks": True,
        "localInterlinks": True,
        "showTags": True,
        "showAttachments": False,
        "hideUnresolved": False,
        "collapse-color-groups": False,
        "colorGroups": [
            {"query": "path:patterns", "color": {"a": 1, "rgb": 1098689}},   # Emerald Green (#10b981)
            {"query": "path:problems", "color": {"a": 1, "rgb": 3923448}},   # Sky Blue (#3b82f6)
            {"query": "path:companies", "color": {"a": 1, "rgb": 12617212}}, # Purple (#c084fc)
            {"query": "path:difficulty", "color": {"a": 1, "rgb": 16097035}},# Amber (#f59e0b)
            {"query": "file:Index", "color": {"a": 1, "rgb": 15485081}}      # Pink (#ec4899)
        ],
        "collapse-display": False,
        "showArrow": True,
        "textFadeMultiplier": 0,
        "nodeSizeMultiplier": 1.25,
        "lineSizeMultiplier": 1.2,
        "collapse-forces": False,
        "centerStrength": 0.518,
        "repelStrength": 10,
        "linkStrength": 1,
        "linkDistance": 120
    }
    with open(OBSIDIAN_CONF_DIR / "graph.json", "w", encoding="utf-8") as f:
        json.dump(graph_json, f, indent=2)

def normalize_pattern(raw_pattern: str) -> list:
    patterns = []
    p = raw_pattern.strip()
    if "Two Pointers" in p:
        patterns.append("Two Pointers")
    if "Sliding Window" in p:
        patterns.append("Sliding Window")
    if "Prefix Sum" in p or "Running Min" in p or "Prefix & Suffix" in p:
        patterns.append("Prefix Sums")
    if "Kadane" in p:
        patterns.append("Kadane's Algorithm")
    if "Hash Map" in p or "Frequency" in p or "Hash Set" in p:
        patterns.append("Hash Maps & Frequency")
    if "Bucket Sort" in p:
        patterns.append("Bucket Sort")
    if "Dutch National Flag" in p:
        patterns.append("Dutch National Flag")
    if "Spiral Matrix" in p or "Matrix" in p:
        patterns.append("Matrix Traversal")
    if "Stack" in p or "Monotonic" in p:
        patterns.append("Monotonic Stack")
    if not patterns:
        patterns.append(p.split("/")[0].strip())
    return sorted(list(set(patterns)))

def normalize_companies(raw_companies: str) -> list:
    parts = [c.strip() for c in raw_companies.split(",") if c.strip()]
    cleaned = []
    for c in parts:
        if "Google" in c: cleaned.append("Google")
        elif "Meta" in c: cleaned.append("Meta")
        elif "Amazon" in c: cleaned.append("Amazon")
        elif "Microsoft" in c: cleaned.append("Microsoft")
        elif "Apple" in c: cleaned.append("Apple")
        elif "Bloomberg" in c: cleaned.append("Bloomberg")
        elif "ByteDance" in c: cleaned.append("ByteDance")
        elif c: cleaned.append(c)
    return sorted(list(set(cleaned)))

def parse_tracker():
    tracker_path = BASE_DIR / "TRACKER.md"
    if not tracker_path.exists():
        return []

    content = tracker_path.read_text(encoding="utf-8")
    table_lines = [l for l in content.splitlines() if l.strip().startswith("|") and not l.strip().startswith("| #") and not l.strip().startswith("|:")]

    problems = []
    for line in table_lines:
        parts = [p.strip() for p in line.split("|")]
        # format: | # | Problem Name | Topic / Pattern | Difficulty | Companies | Status | Solution Link | Key Takeaways & Edge Cases |
        if len(parts) >= 9:
            num = parts[1]
            raw_name = parts[2]
            raw_pattern = parts[3]
            raw_diff = parts[4]
            raw_comp = parts[5]
            raw_status = parts[6]
            raw_sol = parts[7]
            takeaways = parts[8]

            if not ("✅" in raw_status or "Solved" in raw_status):
                continue

            # extract title and link
            name_match = re.search(r'\[(.*?)\]\((.*?)\)', raw_name)
            title = name_match.group(1) if name_match else raw_name
            url = name_match.group(2) if name_match else ""

            # extract sol link
            sol_match = re.search(r'\[(.*?)\]\((.*?)\)', raw_sol)
            sol_rel_path = sol_match.group(2) if sol_match else ""

            diff = "Easy" if "Easy" in raw_diff else ("Hard" if "Hard" in raw_diff else "Medium")

            problems.append({
                "num": num,
                "title": title,
                "url": url,
                "raw_pattern": raw_pattern,
                "patterns": normalize_pattern(raw_pattern),
                "difficulty": diff,
                "companies": normalize_companies(raw_comp),
                "solution_path": sol_rel_path,
                "takeaways": takeaways,
                "source": "Core 27-Module Curriculum"
            })
    return problems

def parse_potd():
    potd_readme = BASE_DIR / "leetcode_problem_of_the_day" / "README.md"
    if not potd_readme.exists():
        return []

    potds = [
        {
            "num": "POTD-01",
            "title": "LC 1614: Maximum Nesting Depth of the Parentheses",
            "url": "https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/",
            "raw_pattern": "Stack / Depth Counter",
            "patterns": ["Stack & Simulation"],
            "difficulty": "Easy",
            "companies": ["Google", "Amazon"],
            "solution_path": "leetcode_problem_of_the_day/2026-09/2026_09_28_lc_1614_maximum_nesting_depth_of_the_parentheses.cpp",
            "takeaways": "Valid parentheses depth tracking. Single pass with counter O(N) time O(1) space.",
            "source": "LeetCode Problem of the Day"
        },
        {
            "num": "POTD-02",
            "title": "LC 3963: Create Grid With Exactly One Path",
            "url": "https://leetcode.com/problems/create-grid-with-exactly-one-path/",
            "raw_pattern": "Constructive / Grid Path",
            "patterns": ["Constructive Algorithms", "Matrix Traversal"],
            "difficulty": "Easy",
            "companies": ["Google", "Meta"],
            "solution_path": "leetcode_problem_of_the_day/2026-10/2026_10_27_lc_3963_create_grid_with_exactly_one_path.cpp",
            "takeaways": "Construct L-shaped path: traverse first row (i=0) and last column (j=n-1). Block all other cells with '#' to prevent branching.",
            "source": "LeetCode Problem of the Day"
        }
    ]
    return potds

def generate_vault():
    setup_directories()
    generate_obsidian_config()

    problems = parse_tracker() + parse_potd()

    # Collections for indexing
    pattern_to_problems = {}
    company_to_problems = {}
    difficulty_to_problems = {}

    for prob in problems:
        for pat in prob["patterns"]:
            pattern_to_problems.setdefault(pat, []).append(prob)
        for comp in prob["companies"]:
            company_to_problems.setdefault(comp, []).append(prob)
        difficulty_to_problems.setdefault(prob["difficulty"], []).append(prob)

    # 1. Generate Problem Notes
    for prob in problems:
        safe_title = sanitize_filename(prob["title"])
        prob_file = PROBLEMS_DIR / f"{safe_title}.md"

        pattern_links = ", ".join([f"[[{pat}]]" for pat in prob["patterns"]])
        company_links = ", ".join([f"[[{comp}]]" for comp in prob["companies"]])
        diff_link = f"[[{prob['difficulty']}]]"

        # Code snippet if available
        code_section = ""
        if prob["solution_path"]:
            code_file = BASE_DIR / prob["solution_path"]
            if code_file.exists():
                code_text = code_file.read_text(encoding="utf-8")
                code_section = f"""
## 💻 C++ Implementation

```cpp
{code_text}
```
"""
            else:
                code_section = f"\n*Relative solution path: `{prob['solution_path']}`*\n"

        content = f"""---
title: "{prob['title']}"
number: "{prob['num']}"
difficulty: "{prob['difficulty']}"
source: "{prob['source']}"
url: "{prob['url']}"
status: "Solved"
tags:
  - problem
  - {prob['difficulty'].lower()}
---

# {prob['title']}

- **Curriculum Index**: #{prob['num']} ({prob['source']})
- **Difficulty**: {diff_link}
- **Patterns / Archetypes**: {pattern_links}
- **Target Companies**: {company_links}
- **Problem Link**: [{prob['title']}]({prob['url']})
- **Backlink to Vault Hub**: [[Index|🏠 Master Knowledge Graph]]

---

## 💡 Intuition & Core Takeaways
> {prob['takeaways']}

---

## 🔗 Related Knowledge Nodes
- Patterns: {pattern_links}
- Companies: {company_links}
- Difficulty Level: {diff_link}

{code_section}
"""
        prob_file.write_text(content, encoding="utf-8")

    # 2. Generate Pattern Hub Notes
    pattern_descriptions = {
        "Two Pointers": "Two pointers moving toward each other (opposite direction) or in tandem to eliminate search space in sorted arrays or bounded subarrays.",
        "Sliding Window": "Maintains a continuous contiguous subsegment [L, R] subject to an invariant constraint. Fixed-size slides in O(1) per step; dynamic expands R and shrinks L.",
        "Prefix Sums": "Precomputes cumulative running sums or products allowing O(1) range sum queries and O(N) subarray sum matching with hash maps.",
        "Kadane's Algorithm": "Greedy running sum dynamic programming to find maximum subarray sum in strictly O(N) time and O(1) space.",
        "Hash Maps & Frequency": "O(1) average lookup and complement pairing (Two Sum archetype) and frequency tracking.",
        "Bucket Sort": "O(N) linear-time frequency grouping bypassing O(N log N) comparison sorting.",
        "Dutch National Flag": "3-way in-place partitioning with 3 pointers (low, mid, high) dividing an array into three distinct partitions in a single pass.",
        "Matrix Traversal": "Boundary-based layer peeling and multi-dimensional coordinate simulation.",
        "Monotonic Stack": "Maintains elements in strictly increasing or decreasing order to resolve Next Greater / Next Smaller elements and area boundaries in O(N).",
        "Constructive Algorithms": "Synthesizes mathematical configurations or grids satisfying explicit path constraints without brute-force search.",
        "Stack & Simulation": "LIFO order tracking to match nested structures, parentheses depth, and operation reversals."
    }

    for pat, prob_list in pattern_to_problems.items():
        safe_pat = sanitize_filename(pat)
        pat_file = PATTERNS_DIR / f"{safe_pat}.md"
        desc = pattern_descriptions.get(pat, "Core algorithmic pattern.")

        prob_links = "\n".join([f"- [[{sanitize_filename(p['title'])}]] ({p['difficulty']} — #{p['num']})" for p in prob_list])

        content = f"""---
title: "{pat}"
type: "pattern-hub"
tags:
  - pattern
  - hub
---

# 🟢 Pattern: {pat}

> **Mental Model**: {desc}

---

## 🎯 Solved Problems Using This Pattern ({len(prob_list)})
{prob_links}

---

## 🗺️ Navigation
- [[Index|🏠 Master Knowledge Graph Hub]]
"""
        pat_file.write_text(content, encoding="utf-8")

    # 3. Generate Company Notes
    for comp, prob_list in company_to_problems.items():
        safe_comp = sanitize_filename(comp)
        comp_file = COMPANIES_DIR / f"{safe_comp}.md"

        prob_links = "\n".join([f"- [[{sanitize_filename(p['title'])}]] — {p['difficulty']} ({', '.join(p['patterns'])})" for p in prob_list])

        content = f"""---
title: "{comp}"
type: "company-hub"
tags:
  - company
  - {comp.lower()}
---

# 🟣 Company Hub: {comp}

> Curated MNC problem bank asked in technical rounds at **{comp}**.

---

## 📋 Tagged Solved Problems ({len(prob_list)})
{prob_links}

---

## 🗺️ Navigation
- [[Index|🏠 Master Knowledge Graph Hub]]
"""
        comp_file.write_text(content, encoding="utf-8")

    # 4. Generate Difficulty Notes
    for diff, prob_list in difficulty_to_problems.items():
        safe_diff = sanitize_filename(diff)
        diff_file = DIFFICULTY_DIR / f"{safe_diff}.md"

        prob_links = "\n".join([f"- [[{sanitize_filename(p['title'])}]] — {', '.join(p['patterns'])}" for p in prob_list])

        content = f"""---
title: "{diff}"
type: "difficulty-tier"
tags:
  - difficulty
  - {diff.lower()}
---

# 🟡 Difficulty Tier: {diff}

Total Solved in this tier: **{len(prob_list)}**

---

## Problems
{prob_links}

---

## 🗺️ Navigation
- [[Index|🏠 Master Knowledge Graph Hub]]
"""
        diff_file.write_text(content, encoding="utf-8")

    # 5. Master Index (MOC)
    all_patterns_links = "\n".join([f"- [[{sanitize_filename(pat)}]] ({len(pl)} problems)" for pat, pl in sorted(pattern_to_problems.items())])
    all_companies_links = "\n".join([f"- [[{sanitize_filename(comp)}]] ({len(pl)} problems)" for comp, pl in sorted(company_to_problems.items())])
    all_diff_links = "\n".join([f"- [[{sanitize_filename(diff)}]] ({len(pl)} problems)" for diff, pl in sorted(difficulty_to_problems.items())])

    index_content = f"""---
title: "Nithin's DSA Master Knowledge Graph"
type: "moc"
tags:
  - moc
  - root
---

# 🚀 Nithin's Algorithmic Knowledge Graph

Welcome to your **Obsidian DSA Second Brain**! This vault connects algorithmic patterns, Tier-1 MNC interview archetypes, and solved problems into an interactive bi-directional graph network.

---

## 📊 Vault Statistics at a Glance
- **Total Solved Problems Linked**: `{len(problems)}`
- **Core Pattern Hubs**: `{len(pattern_to_problems)}`
- **Target Company Hubs**: `{len(company_to_problems)}`
- **Difficulty Tiers**: `{len(difficulty_to_problems)}`

---

## 🟢 1. Core Algorithmic Pattern Hubs
{all_patterns_links}

---

## 🟣 2. Target MNC Company Hubs
{all_companies_links}

---

## 🟡 3. Difficulty Tiers
{all_diff_links}

---

## ⚡ How to Open Graph View in Obsidian
1. In Obsidian, open this folder: `/Users/nithinpathikonda/Documents/dsa/obsidian` (or open `/Users/nithinpathikonda/Documents/dsa` as vault).
2. Press **`Cmd + G`** (or click the **Graph View** icon on the left sidebar).
3. Notice the preconfigured colors:
   - 🟢 **Emerald Green**: Pattern Hubs (`path:patterns`)
   - 🔵 **Sky Blue**: Solved Problems (`path:problems`)
   - 🟣 **Purple**: Companies (`path:companies`)
   - 🟡 **Amber**: Difficulties (`path:difficulty`)
   - 🌸 **Pink**: Master Index (`file:Index`)

---

*To re-synchronize after solving new problems, run:*  
`python3 obsidian/sync_graph.py`
"""
    (VAULT_DIR / "Index.md").write_text(index_content, encoding="utf-8")

    # README for the vault
    readme_content = f"""# 🧠 Obsidian Knowledge Graph Vault

This folder is a standalone **Obsidian Vault** pre-configured for your DSA preparation.

## 🚀 Quick Start
1. Open the **Obsidian** app on your Mac.
2. Click **"Open folder as vault"**.
3. Choose `/Users/nithinpathikonda/Documents/dsa/obsidian`.
4. Press **`Cmd + G`** to open the full interactive **Knowledge Graph**!

## 🔄 Keeping in Sync
Whenever you solve new problems in `TRACKER.md` or POTD, simply run:
```bash
python3 obsidian/sync_graph.py
```
This will automatically generate new problem cards, update pattern hubs, and maintain your knowledge graph!
"""
    (VAULT_DIR / "README.md").write_text(readme_content, encoding="utf-8")

    print(f"✅ Generated Obsidian Vault successfully:")
    print(f"   - {len(problems)} Problem cards")
    print(f"   - {len(pattern_to_problems)} Pattern hubs")
    print(f"   - {len(company_to_problems)} Company hubs")
    print(f"   - Graph configuration saved to {OBSIDIAN_CONF_DIR / 'graph.json'}")

if __name__ == "__main__":
    generate_vault()
