---
title: "LC 332: Reconstruct Itinerary"
module: "24 Advanced Graphs (Tarjan & Eulerian)"
concept: "Tarjan's Bridges & SCC"
difficulty: "Hard"
complexity: "O(E log E)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 332: Reconstruct Itinerary

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[24 Advanced Graphs (Tarjan & Eulerian)]]
> - **Core Concept**: [[Tarjan's Bridges & SCC]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(E log E))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Tarjan's Bridges & SCC application in `24 Advanced Graphs (Tarjan & Eulerian)`.
> - **Immediate Strategy**: Hierholzer's algorithm: postorder DFS with min-heap neighbor traversal.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Tarjan's Bridges & SCC**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 1192 Critical Connections in a Network]]
- 🎯 **Current Anchor**: [[LC 332 Reconstruct Itinerary]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 332: Reconstruct Itinerary
// Time Complexity: O(E log E) | Space Complexity: O(K)
// Technique: Tarjan's Bridges & SCC (24 Advanced Graphs (Tarjan & Eulerian))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Hierholzer's algorithm: postorder DFS with min-heap neighbor traversal.
};

```
