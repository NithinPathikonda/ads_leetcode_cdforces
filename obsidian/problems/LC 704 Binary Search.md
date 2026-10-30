---
title: "LC 704: Binary Search"
module: "03 Binary Search"
concept: "Binary Search on Array"
difficulty: "Easy"
complexity: "O(log N)"
space_complexity: "O(1)"
companies:
  - Apple
  - Google
  - Microsoft
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - easy
  - binary-search
  - fundamentals
---

# 🟢 LC 704: Binary Search

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Binary Search on Array]] (Halving Sorted Search Space)
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(\log N)$ — divides candidate range by 2 each comparison
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Apple]], [[Google]], [[Microsoft]], [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Given an array of integers `nums` which is sorted in ascending order, and an integer `target`."
> - **Immediate Strategy**: Maintain closed interval $[l, r]$. Compute mid safely via `(r - l) / 2 + l`. Branch into 3 possibilities: hit (`nums[mid] == target`), search right (`l = mid + 1`), or search left (`r = mid - 1`).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Search Space Invariant
> Let candidate target index $i \in [l, r]$.
> 1. **Hypothesis**: At every step $k$, if $target \in nums$, then $target \in nums[l \dots r]$.
> 2. **Base Case**: At $k = 0$, $l = 0, r = N - 1$, so $nums[l \dots r]$ contains the entire array.
> 3. **Inductive Step**:
>    - If $nums[mid] = target$: found, return $mid$.
>    - If $nums[mid] < target$: because $nums$ is non-decreasing, $\forall i \le mid, nums[i] \le nums[mid] < target$. Target cannot exist in $[l \dots mid]$. Setting $l \leftarrow mid + 1$ preserves the invariant.
>    - If $nums[mid] > target$: because $nums$ is non-decreasing, $\forall i \ge mid, nums[i] \ge nums[mid] > target$. Target cannot exist in $[mid \dots r]$. Setting $r \leftarrow mid - 1$ preserves the invariant.
> 4. **Termination**: $l \le r$ strictly shrinks by at least 1 element each step. If $l > r$, interval is empty $\implies target \notin nums$, return $-1$.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **32-Bit Midpoint Overflow**:
>    Never write `mid = (l + r) / 2`. If $l + r > 2^{31} - 1$, it overflows to a negative number. Always use `mid = l + (r - l) / 2` or `(r - l) / 2 + l`.
> 2. **Loop Boundary Condition**:
>    Use `while (l <= r)`, NOT `while (l < r)`. If you use `<`, a 1-element remaining search space ($l == r$) will terminate before checking that element!
> 3. **Strict Progress**:
>    Ensure `l = mid + 1` and `r = mid - 1`. Doing `l = mid` or `r = mid` with `while (l <= r)` causes an infinite loop when $r - l = 1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 704 Binary Search]] — Clean textbook baseline
- ➔ **Next Step**: [[LC 33 Search in Rotated Sorted Array]] — Half-sorted elimination on pivoted array
- ➔ **Next Variation**: [[LC 34 Find First and Last Position of Element in Sorted Array]] — Duplicate boundary expansion

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 704: Binary Search
// Time Complexity: O(log N) | Space Complexity: O(1)
// Technique: Classic Binary Search on Sorted Array (03 Binary Search)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            // Safe midpoint to prevent 32-bit signed integer overflow
            int mid = (r - l) / 2 + l;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1; // Discard left half
            } else {
                r = mid - 1; // Discard right half
            }
        }

        return -1; // Target absent
    }
};
```
