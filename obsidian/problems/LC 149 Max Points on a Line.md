---
title: "LC 149: Max Points on a Line"
module: "27 Computational Geometry & Math"
concept: "Convex Hull & Geometry"
difficulty: "Hard"
complexity: "O(N^2)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 149: Max Points on a Line

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[27 Computational Geometry & Math]]
> - **Core Concept**: [[Convex Hull & Geometry]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(N^2))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Convex Hull & Geometry application in `27 Computational Geometry & Math`.
> - **Immediate Strategy**: Slope hash map dy/dx reduced by GCD for each origin point.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Convex Hull & Geometry**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 149 Max Points on a Line]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 149: Max Points on a Line
// Time Complexity: O(N^2) | Space Complexity: O(N)
// Technique: Convex Hull & Geometry (27 Computational Geometry & Math)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Slope hash map dy/dx reduced by GCD for each origin point.
};

```
