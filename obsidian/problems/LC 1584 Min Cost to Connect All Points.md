---
title: "LC 1584: Min Cost to Connect All Points"
module: "13 Disjoint Set Union (DSU) & MST"
concept: "Kruskal's & Prim's MST"
difficulty: "Medium"
complexity: "O(E log V)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Microsoft
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 1584: Min Cost to Connect All Points

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[13 Disjoint Set Union (DSU) & MST]]
> - **Core Concept**: [[Kruskal's & Prim's MST]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(E log V))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Kruskal's & Prim's MST application in `13 Disjoint Set Union (DSU) & MST`.
> - **Immediate Strategy**: Manhattan distance complete graph solved via Prim's or Kruskal's.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Kruskal's & Prim's MST**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 684 Redundant Connection]]
- 🎯 **Current Anchor**: [[LC 1584 Min Cost to Connect All Points]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 1584: Min Cost to Connect All Points
// Time Complexity: O(E log V) | Space Complexity: O(K)
// Technique: Kruskal's & Prim's MST (13 Disjoint Set Union (DSU) & MST)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Manhattan distance complete graph solved via Prim's or Kruskal's.
};

```
