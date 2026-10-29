---
title: "LC 74: Search a 2D Matrix"
module: "03 Binary Search"
concept: "2D Matrix Binary Search"
difficulty: "Medium"
complexity: "O(log(M * N))"
space_complexity: "O(1)"
companies:
  - Microsoft
  - Amazon
  - Meta
  - Apple
  - Google
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - matrix
  - array
---

# 🟡 LC 74: Search a 2D Matrix

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[2D Matrix Binary Search]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(\log(M \cdot N))$ — binary search across $M \cdot N$ cells
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Microsoft]], [[Amazon]], [[Meta]], [[Apple]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Each row sorted, first element of row > last element of previous row."
> - **Immediate Strategy**: Virtual 1D-to-2D Coordinate Flattening.
>   - Range: `l = 0`, `r = m * n - 1`
>   - Convert 1D index `mid` to 2D indices using **column count `cols`**:
>     $$\text{row} = \lfloor \text{mid} / \text{cols} \rfloor, \quad \text{col} = \text{mid} \pmod{\text{cols}}$$
>   - Value: `matrix[row][col]`. Standard binary search!

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ 1D Isomorphism Invariant
> Let grid $M$ have dimensions $m \times n$.
> - Because $M[i][n-1] < M[i+1][0]$ for all $i \in [0, m-2]$ and $M[i][j] \le M[i][j+1]$ for all $j \in [0, n-2]$, the sequence:
>   $$A[k] = M[\lfloor k / n \rfloor][k \bmod n], \quad \forall k \in [0, m \cdot n - 1]$$
>   is **strictly non-decreasing** across its entire domain.
> - The mapping $k \mapsto (\lfloor k / n \rfloor, k \bmod n)$ is a bijective isomorphism from $[0, m \cdot n - 1]$ to $[0, m-1] \times [0, n-1]$.
> - Therefore, binary search on $k \in [0, m \cdot n - 1]$ evaluates the exact monotonic space in $\mathcal{O}(\log(m \cdot n))$ steps with zero memory copying.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **The Row vs. Column Divisor Trap**:
>    Always divide and modulo by the **number of columns** (`m` or `cols`), NOT the number of rows (`n` or `rows`):
>    ```cpp
>    // ❌ BUG: Dividing by number of rows causes out-of-bounds row index!
>    int temp = matrix[mid / rows][mid % rows];
>    
>    // ✅ FIX: Each row contains 'cols' elements
>    int temp = matrix[mid / cols][mid % cols];
>    ```
> 2. **Integer Overflow on $M \cdot N$**:
>    If $M$ and $N$ are large (e.g. $10^5 \times 10^5$), $M \cdot N$ exceeds standard 32-bit signed integer limits ($2 \cdot 10^9$). Use `long long` for $l, r, mid$. (In LeetCode 74, $m, n \le 100$, so `int` is safe).
> 3. **Empty Matrix Guards**:
>    Always guard with `if (matrix.empty() || matrix[0].empty()) return false;`.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite**: [[LC 704 Binary Search]] — Standard 1D monotonic search
- 🎯 **Current Anchor**: [[LC 74 Search a 2D Matrix]] — Strictly ordered grid isomorphic to 1D
- ➔ **Next Boss Variation**: [[LC 240 Search a 2D Matrix II]] — Rows and cols sorted independently (cannot flatten into 1D; requires Top-Right Staircase Search in $\mathcal{O}(M + N)$)

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 74: Search a 2D Matrix
// Time Complexity: O(log(M * N)) | Space Complexity: O(1)
// Technique: Virtual 1D Coordinate Flattening Binary Search

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0, r = rows * cols - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = matrix[mid / cols][mid % cols]; // Divisor is 'cols'

            if (val == target) {
                return true;
            } else if (val < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return false;
    }
};
```
