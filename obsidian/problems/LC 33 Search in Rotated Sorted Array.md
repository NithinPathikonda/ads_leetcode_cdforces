---
title: "LC 33: Search in Rotated Sorted Array"
module: "03 Binary Search"
concept: "Rotated Array Binary Search"
difficulty: "Medium"
complexity: "O(log N)"
space_complexity: "O(1)"
companies:
  - Meta
  - Google
  - Amazon
  - Microsoft
  - Apple
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - array
---

# 🟡 LC 33: Search in Rotated Sorted Array

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Rotated Array Binary Search]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(\log N)$ — logarithmic search space halving
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Meta]], [[Google]], [[Amazon]], [[Microsoft]], [[Apple]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Sorted array rotated at unknown pivot", searching for target in $\mathcal{O}(\log N)$ time.
> - **Immediate Strategy**: **At least one half is always sorted!**
>   1. Compute `mid = l + (r - l) / 2`.
>   2. Check if right half is sorted (`nums[mid] <= nums[r]`):
>      - If target lies in `(nums[mid], nums[r]]`, search right (`l = mid + 1`).
>      - Otherwise, search left (`r = mid - 1`).
>   3. Else, the left half must be sorted:
>      - If target lies in `[nums[l], nums[mid])`, search left (`r = mid - 1`).
>      - Otherwise, search right (`l = mid + 1`).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Half-Sorted Invariant
> Let array $A[l \dots r]$ be formed by rotating a strictly increasing array.
> For any choice of $mid \in [l, r]$:
> $$\text{Either } A[l \dots mid] \text{ is strictly sorted, OR } A[mid \dots r] \text{ is strictly sorted (or both)}.$$
> **Proof by Contradiction**: The original array has at most **one** rotation inflection point (where $A[k] > A[k+1]$). A single inflection point cannot exist simultaneously in both the open interval $(l, mid)$ and $(mid, r)$. Therefore, at least one sub-interval contains zero inflection points, making it strictly monotonic. Checking boundary conditions against the sorted half decides with 100% certainty whether $target$ lies in that half or the other.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Handling Single Elements (`<=` vs `<`)**:
>    Always use `nums[mid] <= nums[r]` (or `nums[l] <= nums[mid]`). When $l == mid$, using strict `<` incorrectly branches into the wrong half for 2-element arrays (e.g., `[3, 1]` searching for `1` or `3`).
> 2. **Target Boundary Inclusivity**:
>    - For the right sorted half: `nums[mid] < target && target <= nums[r]` (strictly greater than `nums[mid]` because `nums[mid] == target` is already checked; inclusive of `nums[r]`).
>    - For the left sorted half: `nums[l] <= target && target < nums[mid]` (inclusive of `nums[l]`; strictly less than `nums[mid]`).
> 3. **The Duplicates Follow-Up (LC 81)**:
>    If duplicates were allowed (`nums[l] == nums[mid] == nums[r]`), we cannot determine which half is sorted. In that case, worst-case time degrades to $\mathcal{O}(N)$ by incrementing $l++$ and decrementing $r--$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite**: [[LC 704 Binary Search]] — Standard monotonic binary search
- 🎯 **Current Anchor**: [[LC 33 Search in Rotated Sorted Array]] — Pivot handling with distinct values ($\mathcal{O}(\log N)$)
- ➔ **Sister Variation**: [[LC 81 Search in Rotated Sorted Array II]] — Handling duplicate elements ($\mathcal{O}(N)$ worst-case)
- ➔ **Next Step**: [[LC 153 Find Minimum in Rotated Sorted Array]] — Binary search for the inflection pivot itself
- ➔ **Final Boss**: [[LC 4 Median of Two Sorted Arrays]] — Dual binary search across two partitions (Hard)

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 33: Search in Rotated Sorted Array
// Time Complexity: O(log N) | Space Complexity: O(1)
// Technique: Rotated Array Binary Search (03 Binary Search)

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    int search(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Case 1: Right half is strictly sorted
            if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target lies in sorted right half
                } else {
                    r = mid - 1; // Target must be in left half
                }
            }
            // Case 2: Left half is strictly sorted
            else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target lies in sorted left half
                } else {
                    l = mid + 1; // Target must be in right half
                }
            }
        }

        return -1; // Target not found
    }
};
```
