---
title: "LC 322: Coin Change"
module: "14 Dynamic Programming 1 1D & Classics"
concept: "1D Linear DP"
difficulty: "Medium"
complexity: "O(amount * coins)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Google
  - Meta
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 322: Coin Change

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[14 Dynamic Programming 1 1D & Classics]]
> - **Core Concept**: [[1D Linear DP]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(amount * coins))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Google]], [[Meta]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: 1D Linear DP application in `14 Dynamic Programming 1 1D & Classics`.
> - **Immediate Strategy**: Unbounded knapsack: dp[i] = min(dp[i], 1 + dp[i - c]).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **1D Linear DP**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 198 House Robber]]
- 🎯 **Current Anchor**: [[LC 322 Coin Change]]
- ➔ **Next Boss Variation**: [[LC 300 Longest Increasing Subsequence]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 322: Coin Change
// Time Complexity: O(amount * coins) | Space Complexity: O(K)
// Technique: 1D Linear DP (14 Dynamic Programming 1 1D & Classics)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Unbounded knapsack: dp[i] = min(dp[i], 1 + dp[i - c]).
};

```
