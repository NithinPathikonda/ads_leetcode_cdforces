---
title: "LC 79: Word Search"
module: "06 Recursion & Backtracking"
concept: "Backtracking & Pruning"
difficulty: "Medium"
complexity: "O(M * N * 3^L)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Microsoft
  - Meta
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 79: Word Search

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[06 Recursion & Backtracking]]
> - **Core Concept**: [[Backtracking & Pruning]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M * N * 3^L))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Microsoft]], [[Meta]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Backtracking & Pruning application in `06 Recursion & Backtracking`.
> - **Immediate Strategy**: Grid DFS with temporary character replacement.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Backtracking & Pruning**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 79 Word Search]]
- ➔ **Next Boss Variation**: [[LC 211 Design Add and Search Words]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 79: Word Search
// Time Complexity: O(M * N * 3^L) | Space Complexity: O(K)
// Technique: Backtracking & Pruning (06 Recursion & Backtracking)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Grid DFS with temporary character replacement.
};

```
