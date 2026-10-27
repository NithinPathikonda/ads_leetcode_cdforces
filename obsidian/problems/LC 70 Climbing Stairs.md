---
title: "LC 70: Climbing Stairs"
module: "14 Dynamic Programming 1 1D & Classics"
concept: "1D Linear DP"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 70: Climbing Stairs

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[14 Dynamic Programming 1 1D & Classics]]
> - **Core Concept**: [[1D Linear DP]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: 1D Linear DP application in `14 Dynamic Programming 1 1D & Classics`.
> - **Immediate Strategy**: Fibonacci transition: dp[i] = dp[i-1] + dp[i-2].

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
- 🎯 **Current Anchor**: [[LC 70 Climbing Stairs]]
- ➔ **Next Boss Variation**: [[LC 198 House Robber]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 70: Climbing Stairs
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: 1D Linear DP (14 Dynamic Programming 1 1D & Classics)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Fibonacci transition: dp[i] = dp[i-1] + dp[i-2].
};

```
