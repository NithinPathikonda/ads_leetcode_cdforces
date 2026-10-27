---
title: "LC 64: Minimum Path Sum"
module: "15 Dynamic Programming 2 2D & Grids"
concept: "2D Grid DP"
difficulty: "Medium"
complexity: "O(M * N)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 64: Minimum Path Sum

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[15 Dynamic Programming 2 2D & Grids]]
> - **Core Concept**: [[2D Grid DP]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M * N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: 2D Grid DP application in `15 Dynamic Programming 2 2D & Grids`.
> - **Immediate Strategy**: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **2D Grid DP**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 62 Unique Paths]]
- 🎯 **Current Anchor**: [[LC 64 Minimum Path Sum]]
- ➔ **Next Boss Variation**: [[LC 221 Maximal Square]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 64: Minimum Path Sum
// Time Complexity: O(M * N) | Space Complexity: O(K)
// Technique: 2D Grid DP (15 Dynamic Programming 2 2D & Grids)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).
};

```
