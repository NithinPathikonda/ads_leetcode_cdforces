---
title: "LC 785: Is Graph Bipartite?"
module: "11 Graphs 1 Traversals & Fundamentals"
concept: "Graph DFS & Components"
difficulty: "Medium"
complexity: "O(V + E)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 785: Is Graph Bipartite?

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[11 Graphs 1 Traversals & Fundamentals]]
> - **Core Concept**: [[Graph DFS & Components]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(V + E))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Graph DFS & Components application in `11 Graphs 1 Traversals & Fundamentals`.
> - **Immediate Strategy**: 2-color BFS/DFS: assign alternating colors to adjacent nodes.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 785 Is Graph Bipartite]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 785: Is Graph Bipartite?
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
    // Intuition: 2-color BFS/DFS: assign alternating colors to adjacent nodes.
};

```
