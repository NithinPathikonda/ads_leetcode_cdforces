---
title: "LC 875: Koko Eating Bananas"
module: "03 Binary Search"
concept: "Binary Search on Answer"
difficulty: "Medium"
complexity: "O(N log(max_pile))"
space_complexity: "O(1)"
companies:
  - Google
  - Amazon
  - Meta
  - Bloomberg
  - Uber
  - Airbnb
  - Microsoft
type: "problem-card"
tags:
  - problem
  - medium
  - binary-search
  - binary-search-on-answer
  - optimization
---

# 🟡 LC 875: Koko Eating Bananas

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Binary Search on Answer]] (Monotonic Predicate Range Search)
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(N \log(\max(\text{piles})))$ — $N$ piles evaluated per binary search probe
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space
> - **Target MNCs**: [[Google]], [[Amazon]], [[Meta]], [[Bloomberg]], [[Uber]], [[Airbnb]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Find the minimum (or maximum) integer rate/capacity $k$ to finish a workload within time limit $h$."
> - **Immediate Strategy**: Define candidate speed range $[1, \max(\text{piles})]$. The hours required $f(k)$ decreases monotonically as $k$ increases. Binary search for the first $k$ where $f(k) \le h$.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Monotonic Predicate Invariant
> Let $f(k) = \sum_{i=0}^{N-1} \left\lceil \frac{\text{piles}[i]}{k} \right\rceil$ be the total hours required to consume all piles at speed $k$.
> 1. **Monotonicity**:
>    $$\forall k_1 < k_2, \quad \left\lceil \frac{p}{k_1} \right\rceil \ge \left\lceil \frac{p}{k_2} \right\rceil \implies f(k_1) \ge f(k_2)$$
>    Since $f(k)$ is monotonically non-increasing, the predicate $P(k) = (f(k) \le h)$ is monotonic:
>    $$[\text{false}, \text{false}, \dots, \text{false}, \mathbf{true}, \text{true}, \dots, \text{true}]$$
> 2. **Correctness of Search Boundaries**:
>    - $k_{\min} = 1$: Minimum positive eating speed.
>    - $k_{\max} = \max(\text{piles})$: Since $h \ge N$ and Koko spends at least $1$ hour per pile, eating faster than $\max(\text{piles})$ still takes exactly $N$ hours. Hence $k^* \le \max(\text{piles})$.
> 3. **Half-Elimination**:
>    - If $P(mid) = \text{true}$, then $\forall k \ge mid, P(k) = \text{true}$. Record $mid$ as candidate answer and search left (`high = mid - 1`).
>    - If $P(mid) = \text{false}$, then $\forall k \le mid, P(k) = \text{false}$. Prune left half and search right (`low = mid + 1`).

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **32-Bit Integer Overflow in Total Hours**:
>    If $k = 1$ and there are $10^4$ piles of size $10^9$, total hours can reach $10^{13} > 2^{31} - 1$. Accumulator **must** be `long long`.
> 2. **Integer Ceil Division Precision**:
>    Do NOT use `ceil((double)pile / k)` due to floating-point truncation issues on large integers. Use integer arithmetic: `(pile + (long long)k - 1) / k` or `(pile / k) + (pile % k != 0)`.
> 3. **Lower Bound Setting**:
>    Never set `low = 0` as that causes division by zero. Always start with `low = 1`.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 875 Koko Eating Bananas]] — Foundation of Binary Search on Answer
- ➔ **Next Step**: [[LC 1011 Capacity To Ship Packages Within D Days]] — Monotonic capacity check with sequential bin-packing
- ➔ **Next Boss Variation**: [[LC 410 Split Array Largest Sum]] — Minimizing maximum subarray sum using greedy feasibility

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 875: Koko Eating Bananas
// Time Complexity: O(N log(max_pile)) | Space Complexity: O(1)
// Technique: Binary Search on Answer (03 Binary Search)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long total_hours = 0;
        for (int pile : piles) {
            // Equivalent to ceil(pile / k) without floating point imprecision
            total_hours += (pile + (long long)k - 1) / k;
            if (total_hours > h) {
                return false; // Early exit optimization
            }
        }
        return total_hours <= h;
    }

public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                ans = mid;
                high = mid - 1; // Try to find a smaller feasible speed
            } else {
                low = mid + 1;  // Too slow, search higher speeds
            }
        }

        return ans;
    }
};
```
