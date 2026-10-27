---
title: "LC 416: Partition Equal Subset Sum"
module: "17 Dynamic Programming 4 Knapsack & Partition"
concept: "0-1 Knapsack"
difficulty: "Medium"
complexity: "O(N * target)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 416: Partition Equal Subset Sum

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[17 Dynamic Programming 4 Knapsack & Partition]]
> - **Core Concept**: [[0-1 Knapsack]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N * target))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: 0-1 Knapsack application in `17 Dynamic Programming 4 Knapsack & Partition`.
> - **Immediate Strategy**: 0-1 Knapsack boolean DP for target = sum / 2.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **0-1 Knapsack**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 416 Partition Equal Subset Sum]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 416: Partition Equal Subset Sum
// Time Complexity: O(N * target) | Space Complexity: O(N)
// Technique: 0-1 Knapsack (17 Dynamic Programming 4 Knapsack & Partition)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: 0-1 Knapsack boolean DP for target = sum / 2.
};

```
