---
title: "LC 104: Maximum Depth of Binary Tree"
module: "07 Binary Trees & BST"
concept: "Tree DFS & Traversals"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 104: Maximum Depth of Binary Tree

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[07 Binary Trees & BST]]
> - **Core Concept**: [[Tree DFS & Traversals]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Tree DFS & Traversals application in `07 Binary Trees & BST`.
> - **Immediate Strategy**: 1 + max(maxDepth(left), maxDepth(right)).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Tree DFS & Traversals**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 104 Maximum Depth of Binary Tree]]
- ➔ **Next Boss Variation**: [[LC 543 Diameter of Binary Tree]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 104: Maximum Depth of Binary Tree
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Tree DFS & Traversals (07 Binary Trees & BST)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: 1 + max(maxDepth(left), maxDepth(right)).
};

```
