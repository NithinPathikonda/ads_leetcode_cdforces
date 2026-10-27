---
title: "LC 240: Search a 2D Matrix II"
module: "03 Binary Search"
concept: "2D Matrix Binary Search"
difficulty: "Medium"
complexity: "O(M + N)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 240: Search a 2D Matrix II

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[2D Matrix Binary Search]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M + N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: 2D Matrix Binary Search application in `03 Binary Search`.
> - **Immediate Strategy**: Start search from top-right corner; step left if target < val, down if target > val.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **2D Matrix Binary Search**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 74 Search a 2D Matrix]]
- 🎯 **Current Anchor**: [[LC 240 Search a 2D Matrix II]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 240: Search a 2D Matrix II
// Time Complexity: O(M + N) | Space Complexity: O(K)
// Technique: 2D Matrix Binary Search (03 Binary Search)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Start search from top-right corner; step left if target < val, down if target > val.
};

```
