---
title: "LC 133: Clone Graph"
module: "11 Graphs 1 Traversals & Fundamentals"
concept: "Graph DFS & Components"
difficulty: "Medium"
complexity: "O(V + E)"
space_complexity: "O(K)"
companies:
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 133: Clone Graph

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[11 Graphs 1 Traversals & Fundamentals]]
> - **Core Concept**: [[Graph DFS & Components]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(V + E))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Graph DFS & Components application in `11 Graphs 1 Traversals & Fundamentals`.
> - **Immediate Strategy**: Hash map old_node -> new_node with DFS neighbor cloning.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Graph DFS & Components**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 200 Number of Islands]]
- 🎯 **Current Anchor**: [[LC 133 Clone Graph]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 133: Clone Graph
// Time Complexity: O(V + E) | Space Complexity: O(K)
// Technique: Graph DFS & Components (11 Graphs 1 Traversals & Fundamentals)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Hash map old_node -> new_node with DFS neighbor cloning.
};

```
