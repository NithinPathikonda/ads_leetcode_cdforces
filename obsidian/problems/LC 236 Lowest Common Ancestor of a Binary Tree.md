---
title: "LC 236: Lowest Common Ancestor of a Binary Tree"
module: "07 Binary Trees & BST"
concept: "Lowest Common Ancestor (LCA)"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 236: Lowest Common Ancestor of a Binary Tree

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[07 Binary Trees & BST]]
> - **Core Concept**: [[Lowest Common Ancestor (LCA)]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Lowest Common Ancestor (LCA) application in `07 Binary Trees & BST`.
> - **Immediate Strategy**: Postorder DFS split point detection.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Lowest Common Ancestor (LCA)**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 236 Lowest Common Ancestor of a Binary Tree]]
- ➔ **Next Boss Variation**: [[LC 98 Validate Binary Search Tree]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 236: Lowest Common Ancestor of a Binary Tree
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Lowest Common Ancestor (LCA) (07 Binary Trees & BST)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Postorder DFS split point detection.
};

```
