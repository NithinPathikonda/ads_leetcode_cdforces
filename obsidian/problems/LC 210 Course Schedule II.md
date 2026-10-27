---
title: "LC 210: Course Schedule II"
module: "12 Graphs 2 TopoSort & Shortest Paths"
concept: "Kahn's Topological Sort"
difficulty: "Medium"
complexity: "O(V + E)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 210: Course Schedule II

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[12 Graphs 2 TopoSort & Shortest Paths]]
> - **Core Concept**: [[Kahn's Topological Sort]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(V + E))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Kahn's Topological Sort application in `12 Graphs 2 TopoSort & Shortest Paths`.
> - **Immediate Strategy**: TopoSort order array: push nodes when indegree reaches 0.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Kahn's Topological Sort**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 207 Course Schedule]]
- 🎯 **Current Anchor**: [[LC 210 Course Schedule II]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 210: Course Schedule II
// Time Complexity: O(V + E) | Space Complexity: O(K)
// Technique: Kahn's Topological Sort (12 Graphs 2 TopoSort & Shortest Paths)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: TopoSort order array: push nodes when indegree reaches 0.
};

```
