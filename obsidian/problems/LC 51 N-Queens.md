---
title: "LC 51: N-Queens"
module: "06 Recursion & Backtracking"
concept: "Backtracking & Pruning"
difficulty: "Hard"
complexity: "O(N!)"
space_complexity: "O(N)"
companies:
  - Meta
  - Microsoft
type: "problem-card"
tags:
  - problem
  - hard
  - backtracking
---

# 👑 LC 51: N-Queens

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[06 Recursion & Backtracking]]
> - **Core Concept**: [[Backtracking & Pruning]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(N!)$ — bounded by recursive branching factor $(N \cdot (N-1) \cdot \dots \cdot 1)$
> - **Space Complexity**: $\mathcal{O}(N)$ — recursion call stack depth plus three $O(N)$ lookup sets
> - **Target MNCs**: [[Meta]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Clue**: Placing $N$ non-attacking chess pieces on an $N \times N$ grid, or exploring configurations where row, column, and diagonal safety must be maintained simultaneously ($N \le 12$).
> - **Immediate Strategy**: **Row-by-Row Backtracking with $\mathcal{O}(1)$ Boolean / Bitmask Lookup Sets**.
> - Placing exactly one queen per row eliminates row conflicts automatically; check columns and diagonals in $O(1)$ time rather than scanning the board.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> At any recursive step `row`, queens have been safely placed in rows `0` through `row - 1`. For a trial position `(row, col)`:
> 1. **Column Safety**: `!cols[col]`
> 2. **Main Diagonal ($\backslash$) Safety**: All cells along a main diagonal share the invariant `row - col = constant`. Shift by `+N` to map cleanly to positive indices `[0, 2N - 1]`:
>    $$\text{diag1} = \text{row} - \text{col} + N$$
> 3. **Anti-Diagonal ($/$) Safety**: All cells along an anti-diagonal share the invariant `row + col = constant`:
>    $$\text{diag2} = \text{row} + \text{col}$$
> When choosing `(row, col)`, set all three trackers to `true`. When backtracking, set all three to `false`.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **The $O(N)$ Board Scan Trap**: Never iterate over the 2D matrix or scan diagonal lines to verify safety. That degrades complexity from $\mathcal{O}(N!)$ to $\mathcal{O}(N! \cdot N^2)$, which TLEs in interviews. Use three $O(1)$ boolean arrays.
> 2. **State Restoration (Backtrack)**: Ensure all three boolean sets (`cols`, `diag1`, `diag2`) and the current row's board state (`board[row][col] = '.'`) are restored on unwinding.
> 3. **$N = 2, 3$**: No valid queen placements exist for $N=2$ or $N=3$. Return an empty vector without crashes.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 46 Permutations]] — *State-space tree exploration with visited arrays*
- 🎯 **Current Anchor**: [[LC 51 N-Queens]] — *2D geometric diagonal constraint pruning*
- ➔ **Next Boss Level**: [[LC 37 Sudoku Solver]] — *Multi-constraint 9x9 grid exact cover backtracking*

---

## 💻 Optimal C++20 Implementation

```cpp
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        
        // O(1) Constraint verification arrays
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n, false); // Main diagonal (\): row - col + n
        vector<bool> diag2(2 * n, false); // Anti diagonal (/): row + col

        auto backtrack = [&](auto& self, int row) -> void {
            // Base Case: All n queens placed safely across all rows
            if (row == n) {
                solutions.push_back(board);
                return;
            }

            for (int col = 0; col < n; ++col) {
                int d1 = row - col + n;
                int d2 = row + col;

                // O(1) Safety Check: Skip attacked columns or diagonals
                if (cols[col] || diag1[d1] || diag2[d2]) {
                    continue;
                }

                // 1. Choose: Place queen and mark constraint trackers
                board[row][col] = 'Q';
                cols[col] = diag1[d1] = diag2[d2] = true;

                // 2. Explore: Recurse into next row
                self(self, row + 1);

                // 3. Unchoose (Backtrack): Revert board cell and trackers
                board[row][col] = '.';
                cols[col] = diag1[d1] = diag2[d2] = false;
            }
        };

        backtrack(backtrack, 0);
        return solutions;
    }
};
```
