---
title: "LC 1011: Capacity To Ship Packages Within D Days"
module: "03 Binary Search"
concept: "Binary Search on Answer"
difficulty: "Medium"
complexity: "O(N log(sum_weight))"
space_complexity: "O(1)"
companies:
  - Amazon
  - Google
  - Meta
  - Microsoft
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - binary-search-on-answer
  - greedy
---

# 🟡 LC 1011: Capacity To Ship Packages Within D Days

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Binary Search on Answer]] (Greedy Sequential Bin-Packing)
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(N \log(\sum \text{weights} - \max(\text{weights})))$
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Amazon]], [[Google]], [[Meta]], [[Microsoft]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Find the minimum container/ship capacity to transport items in **strict sequential order** within $D$ days."
> - **Immediate Strategy**:
>   1. Search space is bounded by $[\max(\text{weights}), \sum \text{weights}]$.
>   2. Define feasibility predicate `isPossible(cap)`: greedily pack consecutive items into today's ship until exceeding `cap`, then increment day count.
>   3. As capacity increases, required days monotonically decreases $\implies$ Binary search for the first valid capacity.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Monotonic Greedy Bin-Packing Invariant
> Let $g(C)$ be the minimum number of days needed to ship packages with capacity $C$ while preserving given order.
> 1. **Monotonicity**:
>    $$\forall C_1 < C_2, \quad g(C_1) \ge g(C_2)$$
>    Hence, the predicate $P(C) = (g(C) \le D)$ generates a monotonic boolean array:
>    $$[\text{false}, \text{false}, \dots, \text{false}, \mathbf{true}, \text{true}, \dots, \text{true}]$$
> 2. **Optimal Substructure of Greedy Packing**:
>    Because packages must be loaded in the given order, maximizing the load on day $t$ strictly leaves fewer or equal packages for days $\ge t + 1$. A greedy accumulation never requires more days than any non-greedy partition.
> 3. **Search Space Bounds**:
>    - **Lower Bound ($low = \max(\text{weights})$)**: Packages cannot be split. If $C < \max(\text{weights})$, the heaviest package will never fit on any day, sinking the ship.
>    - **Upper Bound ($high = \sum \text{weights}$)**: Carrying every package in a single day ($D = 1$).

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **The `l = 1` vs `l = max_w` Trap (The Sinking Ship Bug)**:
>    If $l = 1$ and `isPossible` does not check `if (w > cap) return false;`, the `else` branch will blindly assign `current_load = w`, putting a $10\text{ kg}$ box onto a $1\text{ kg}$ ship and falsely reporting `true`! Either set $l = \max(\text{weights})$ or add the guard rail inside `isPossible`.
> 2. **Do NOT Sort the Weights**:
>    Packages must be shipped in the order given. Sorting alters the problem completely and yields wrong answers.
> 3. **Initial Day Count**:
>    Initialize `days_needed = 1` (not `0`), because packing the first package occupies Day 1.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite**: [[LC 875 Koko Eating Bananas]] — Independent ceiling sum on unsorted piles
- 🎯 **Current Anchor**: [[LC 1011 Capacity To Ship Packages Within D Days]] — Order-preserved greedy packing
- ➔ **Next Boss Variation**: [[LC 410 Split Array Largest Sum]] — Minimizing maximum subarray sum (identical mathematical isomorphic formulation!)

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 1011: Capacity To Ship Packages Within D Days
// Time Complexity: O(N log(sum_weight)) | Space Complexity: O(1)
// Technique: Binary Search on Answer / Greedy Feasibility (03 Binary Search)

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
private:
    bool isPossible(const vector<int>& weights, int days, int cap) {
        int days_needed = 1;
        int current_load = 0;

        for (int w : weights) {
            // Guard rail: single package exceeds capacity
            if (w > cap) return false;

            if (current_load + w <= cap) {
                current_load += w;
            } else {
                days_needed++;
                current_load = w; // Start next day with this package
            }
        }

        return days_needed <= days;
    }

public:
    int shipWithinDays(const vector<int>& weights, int days) {
        int max_w = 0;
        int sum_w = 0;
        for (int w : weights) {
            max_w = max(max_w, w);
            sum_w += w;
        }

        // Search space: [max(weights), sum(weights)]
        int l = max_w, r = sum_w;
        int ans = sum_w;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(weights, days, mid)) {
                ans = mid;      // Feasible capacity, try searching smaller
                r = mid - 1;
            } else {
                l = mid + 1;    // Capacity too small, increase
            }
        }

        return ans;
    }
};
```
