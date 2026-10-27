---
title: "LC 743: Network Delay Time"
module: "12 Graphs 2 TopoSort & Shortest Paths"
concept: "Dijkstra's Algorithm"
difficulty: "Medium"
complexity: "O((V + E) log V)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 743: Network Delay Time

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[12 Graphs 2 TopoSort & Shortest Paths]]
> - **Core Concept**: [[Dijkstra's Algorithm]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O((V + E) log V))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Dijkstra's Algorithm application in `12 Graphs 2 TopoSort & Shortest Paths`.
> - **Immediate Strategy**: Dijkstra's with min-heap priority queue from source K; return max dist.

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
- 🎯 **Current Anchor**: [[LC 743 Network Delay Time]]
- ➔ **Next Boss Variation**: [[LC 787 Cheapest Flights Within K Stops]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 743: Network Delay Time
// Time Complexity: O((V + E) log V) | Space Complexity: O(K)
// Technique: Dijkstra's Algorithm (12 Graphs 2 TopoSort & Shortest Paths)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Dijkstra's with min-heap priority queue from source K; return max dist.
};

```
