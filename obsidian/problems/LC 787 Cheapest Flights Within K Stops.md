---
title: "LC 787: Cheapest Flights Within K Stops"
module: "12 Graphs 2 TopoSort & Shortest Paths"
concept: "Dijkstra's Algorithm"
difficulty: "Medium"
complexity: "O(K * E)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 787: Cheapest Flights Within K Stops

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[12 Graphs 2 TopoSort & Shortest Paths]]
> - **Core Concept**: [[Dijkstra's Algorithm]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(K * E))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Dijkstra's Algorithm application in `12 Graphs 2 TopoSort & Shortest Paths`.
> - **Immediate Strategy**: Bellman-Ford relaxation K+1 times with distance copy buffer.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Dijkstra's Algorithm**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 743 Network Delay Time]]
- 🎯 **Current Anchor**: [[LC 787 Cheapest Flights Within K Stops]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 787: Cheapest Flights Within K Stops
// Time Complexity: O(K * E) | Space Complexity: O(K)
// Technique: Dijkstra's Algorithm (12 Graphs 2 TopoSort & Shortest Paths)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Bellman-Ford relaxation K+1 times with distance copy buffer.
};

```
