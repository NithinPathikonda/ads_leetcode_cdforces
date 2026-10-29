---
title: "LC 240: Search a 2D Matrix II"
module: "03 Binary Search"
concept: "2D Matrix Binary Search"
difficulty: "Medium"
complexity: "O(M + N)"
space_complexity: "O(1)"
companies:
  - Amazon
  - Google
  - Microsoft
  - Meta
  - Apple
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - matrix
  - divide-and-conquer
---

# 🟡 LC 240: Search a 2D Matrix II

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[2D Matrix Binary Search]] (Staircase Elimination / Grid BST)
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(M + N)$ — eliminates 1 row or 1 column per comparison
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Amazon]], [[Google]], [[Microsoft]], [[Meta]], [[Apple]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Rows sorted left-to-right AND columns sorted top-to-bottom, but NO cross-row ordering" (unlike LC 74).
> - **Immediate Strategy**: Start at the **Top-Right Corner** `(row = 0, col = n - 1)` (or Bottom-Left):
>   - If `matrix[row][col] == target`: return `true`.
>   - If `matrix[row][col] > target`: column values below are strictly larger $\implies$ prune column (`col--`).
>   - If `matrix[row][col] < target`: row values to the left are strictly smaller $\implies$ prune row (`row++`).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Bounding Box Trimming Invariant
> At any step $k$, let candidate search space be the rectangle bounded by rows $[row, m - 1]$ and columns $[0, col]$.
> - **Case 1 (`M[row][col] > target`)**:
>   Because column $col$ is sorted in non-decreasing order:
>   $$\forall i \ge row, \quad M[i][col] \ge M[row][col] > target.$$
>   Therefore, no element in column $col$ can equal $target$. Pruning the column via $col \leftarrow col - 1$ discards **zero** valid candidate solutions.
> - **Case 2 (`M[row][col] < target`)**:
>   Because row $row$ is sorted in non-decreasing order:
>   $$\forall j \le col, \quad M[row][j] \le M[row][col] < target.$$
>   Therefore, no element in row $row$ can equal $target$. Pruning the row via $row \leftarrow row + 1$ discards **zero** valid candidate solutions.
> - **Termination**: Total steps bounded by $m$ row increments + $n$ column decrements $\le M + N \implies \mathcal{O}(M + N)$.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Why 1D Binary Search Fails (The LC 74 vs LC 240 Trap)**:
>    In LC 74, `matrix[i+1][0] > matrix[i][n-1]`. In LC 240, this is false (e.g. Row 0 ends at 15, Row 1 starts at 2). Flattening to 1D creates non-monotonic drops $\implies$ 1D binary search is invalid!
> 2. **Why Top-Left `(0, 0)` Fails**:
>    Moving right from `(0, 0)` increases values, and moving down also increases values. If `matrix[0][0] < target`, you cannot eliminate either path without searching both! Only Top-Right and Bottom-Left have opposite monotonicity.
> 3. **Empty Matrix Guard**:
>    Always check `if (matrix.empty() || matrix[0].empty()) return false;`.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Predecessor**: [[LC 74 Search a 2D Matrix]] — Strictly ordered grid isomorphic to 1D ($\mathcal{O}(\log(M \cdot N))$)
- 🎯 **Current Anchor**: [[LC 240 Search a 2D Matrix II]] — Independent row/col sorted grid ($\mathcal{O}(M + N)$)
- ➔ **Next Boss Variation**: [[LC 378 Kth Smallest Element in a Sorted Matrix]] — Binary search on range using staircase count

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 240: Search a 2D Matrix II
// Time Complexity: O(M + N) | Space Complexity: O(1)
// Technique: Top-Right Staircase Search (03 Binary Search)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        // Start at Top-Right corner
        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                col--; // Prune rightmost remaining column
            } else {
                row++; // Prune topmost remaining row
            }
        }

        return false;
    }
};
```
