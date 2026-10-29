---
title: "LC 153: Find Minimum in Rotated Sorted Array"
module: "03 Binary Search"
concept: "Rotated Array Binary Search"
difficulty: "Medium"
complexity: "O(log N)"
space_complexity: "O(1)"
companies:
  - Meta
  - Amazon
  - Microsoft
  - Google
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - array
---

# 🟡 LC 153: Find Minimum in Rotated Sorted Array

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Rotated Array Binary Search]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(\log N)$ — binary search space halving
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Meta]], [[Amazon]], [[Microsoft]], [[Google]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Find the minimum element in a rotated sorted array with unique elements" in $\mathcal{O}(\log N)$ time.
> - **Immediate Strategy**: Compare `nums[mid]` against `nums[r]`:
>   - If `nums[mid] > nums[r]`: The pivot/inflection drop is strictly to the right $\implies$ `l = mid + 1`.
>   - If `nums[mid] <= nums[r]`: `mid` itself could be the minimum, or the minimum is to the left $\implies$ `r = mid`.
>   - Terminate when `l == r`; return `nums[l]`.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Inflection Invariant
> Let the minimum element be located at index $k$.
> - For any subarray $[l, r]$, if $nums[mid] > nums[r]$, then the rotation inflection MUST occur in $(mid, r]$. Hence, $k \in (mid, r]$, proving $l = mid + 1$ is safe and discards zero candidate solutions.
> - Conversely, if $nums[mid] \le nums[r]$, the right subarray $[mid \dots r]$ is sorted, so the minimum cannot lie in $(mid, r]$. Hence, $k \in [l, mid]$, proving $r = mid$ preserves the minimum.
> - Because $r - l$ strictly decreases at each step, the search converges to $l = r = k$ in $\mathcal{O}(\log N)$ iterations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Do NOT Compare `nums[mid]` with `nums[l]`**:
>    Comparing with `nums[l]` fails on unrotated arrays (e.g. `[1, 2, 3]`), because `nums[mid] > nums[l]` happens both when rotated right AND when already sorted! Always compare against `nums[r]`.
> 2. **Never Do `r = mid - 1` on the Right-Sorted Branch**:
>    If `nums[mid]` is the actual minimum (e.g. `[3, 1, 2]`), `r = mid - 1` would exclude the minimum element entirely. You must use `r = mid`.
> 3. **The Duplicates Trap (LC 154)**:
>    If elements can be duplicates, `nums[mid] == nums[r]` could happen without knowing which side is sorted. You must fallback to `r--`, giving $\mathcal{O}(N)$ worst-case.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite**: [[LC 33 Search in Rotated Sorted Array]] — Search for target with rotation
- 🎯 **Current Anchor**: [[LC 153 Find Minimum in Rotated Sorted Array]] — Find inflection point in distinct array ($\mathcal{O}(\log N)$)
- ➔ **Sister Variation**: [[LC 154 Find Minimum in Rotated Sorted Array II]] — Handling duplicates ($\mathcal{O}(N)$ worst-case)
- ➔ **Next Step**: [[LC 74 Search a 2D Matrix]] — 2D coordinate flattening binary search

---

## 💻 Optimal C++20 Implementations

### Approach 1: User's Half-Elimination Search
```cpp
// Time Complexity: O(log N) | Space Complexity: O(1)
class SolutionUser {
public:
    int findMin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = -1, mini = INT_MAX;
        while (l <= r) {
            mid = l + (r - l) / 2;
            mini = min(mini, nums[mid]);

            if (nums[l] <= nums[mid]) {
                mini = min(mini, nums[l]);
                l = mid + 1;
            } else if (nums[mid] <= nums[r]) {
                mini = min(mini, nums[mid]);
                r = mid - 1;
            }
        }
        return mini;
    }
};
```

---

### Approach 2: Canonical Inflection Check (Interview Standard)
```cpp
// Time Complexity: O(log N) | Space Complexity: O(1)
class SolutionCanonical {
public:
    int findMin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1; // Minimum must be in (mid, r]
            } else {
                r = mid;     // Minimum could be mid or in [l, mid]
            }
        }

        return nums[l];
    }
};
```
