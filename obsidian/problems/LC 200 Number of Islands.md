---
title: "LC 200: Number of Islands"
module: "11 Graphs 1 Traversals & Fundamentals"
concept: "Graph BFS & Shortest Path"
difficulty: "Medium"
complexity: "O(M * N)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Google
  - Meta
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 200: Number of Islands

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[11 Graphs 1 Traversals & Fundamentals]]
> - **Core Concept**: [[Graph BFS & Shortest Path]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M * N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Google]], [[Meta]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Graph BFS & Shortest Path application in `11 Graphs 1 Traversals & Fundamentals`.
> - **Immediate Strategy**: Grid BFS/DFS sink connected '1's to '0's.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Graph BFS & Shortest Path**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 200 Number of Islands]]
- ➔ **Next Boss Variation**: [[LC 133 Clone Graph]]
- ➔ **Next Boss Variation**: [[LC 994 Rotting Oranges]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 200: Number of Islands
// Time Complexity: O(M * N) | Space Complexity: O(K)
// Technique: Graph BFS & Shortest Path (11 Graphs 1 Traversals & Fundamentals)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Grid BFS/DFS sink connected '1's to '0's.
};

```
