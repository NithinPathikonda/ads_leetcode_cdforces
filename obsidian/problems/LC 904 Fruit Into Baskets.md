---
title: "LC 904: Fruit Into Baskets"
module: "02 Two Pointers & Sliding Window"
concept: "Dynamic Sliding Window"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(1)"
companies:
  - Google
  - Amazon
  - Meta
  - Microsoft
type: "problem-card"
tags:
  - problem
  - medium
  - sliding-window
  - hash-table
  - array
---

# 🟡 LC 904: Fruit Into Baskets

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[02 Two Pointers & Sliding Window]]
> - **Core Concept**: [[Dynamic Sliding Window]] (At Most $K$ Distinct Elements, $K=2$)
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(N)$ where $N = \text{fruits.length}$
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space (hash map contains at most 3 entries)
> - **Target MNCs**: [[Google]], [[Amazon]], [[Meta]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Find the longest contiguous subarray containing at most 2 distinct values."
> - **Immediate Strategy**: Dynamic sliding window with a frequency map `count`:
>   1. **Expand $r$**: Pick `fruits[r]`, incrementing `count[fruits[r]]++`.
>   2. **Shrink $l$**: If `count.size() > 2`, evict from the left (`count[fruits[l]]--`). If count hits 0, erase the key, then increment $l++$.
>   3. **Maximize**: `ans = max(ans, r - l + 1)`.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Window State Invariant
> Let $W = [l, r]$ represent the contiguous subarray currently under inspection.
> - **Validity Invariant**: $W$ is valid iff $|\text{distinct}(W)| \le 2$.
> - **Linearity Guarantee**: Pointer $r$ advances from $0$ to $N-1$ ($N$ steps). Pointer $l$ only advances forward and never exceeds $r$ (at most $N$ steps). Total hash map operations are at most $2N \implies \mathcal{O}(N)$ amortized time.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Forgetting to Erase Zero-Count Keys**:
>    In C++, `mpp[key] = 0` does **NOT** remove the key! `mpp.size()` will still count it as present. You **must** call `mpp.erase(key)` when the count drops to 0.
> 2. **Double Evaluation of `mpp[fruits[l]]`**:
>    Calling `mpp[fruits[l]]` after decrementing can re-insert the key with value 0 if not careful. Always check `if (mpp[fruits[l]] == 0)` and erase immediately.
> 3. **The Non-Shrinking Ratchet (`if` vs `while`)**:
>    Replacing `while (mpp.size() > 2)` with `if (mpp.size() > 2)` turns the window into a non-shrinking ratchet. The window never shrinks; it only slides forward or expands, preserving the maximum valid window size seen so far.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Simpler Anchor**: [[LC 3 Longest Substring Without Repeating Characters]] — At most 1 occurrence of each character
- 🎯 **Current Anchor**: [[LC 904 Fruit Into Baskets]] — Longest subarray with at most $K=2$ distinct elements
- ➔ **Direct Generalization**: [[LC 340 Longest Substring with At Most K Distinct Characters]] — Arbitrary $K$
- ➔ **Next Boss**: [[LC 76 Minimum Window Substring]] — Dynamic contraction variable window with required counts (Hard)

---

## 💻 Optimal C++20 Implementations

### Approach 1: Classic Dynamic Sliding Window (`while`)
```cpp
// Time Complexity: O(N) | Space Complexity: O(1)
class SolutionClassic {
public:
    int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> count;
        int l = 0, max_fruits = 0;
        int n = fruits.size();

        for (int r = 0; r < n; ++r) {
            count[fruits[r]]++;

            // Shrink window from the left while distinct fruit types > 2
            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }

            max_fruits = max(max_fruits, r - l + 1);
        }

        return max_fruits;
    }
};
```

---

### Approach 2: Optimal Non-Shrinking Window (`if` Ratchet) — Your Solution
```cpp
// Time Complexity: O(N) 1-pass | Space Complexity: O(1)
class SolutionNonShrinking {
public:
    int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int n = fruits.size();
        int ans = 0;

        for (r = 0; r < n; ++r) {
            mpp[fruits[r]]++;

            // If invalid, shift left boundary by 1 to maintain maximum size
            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
```
