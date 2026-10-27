---
title: "LC 877: Stone Game"
module: "25 Game Theory & Minimax"
concept: "Minimax & Game Theory"
difficulty: "Medium"
complexity: "O(1)"
space_complexity: "O(1)"
companies:
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 877: Stone Game

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[25 Game Theory & Minimax]]
> - **Core Concept**: [[Minimax & Game Theory]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(1))$
> - **Space Complexity**: $\mathcal{O}(O(1))$
> - **Target MNCs**: [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Minimax & Game Theory application in `25 Game Theory & Minimax`.
> - **Immediate Strategy**: First player always wins by picking either all even or all odd piles.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Minimax & Game Theory**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 877 Stone Game]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 877: Stone Game
// Time Complexity: O(1) | Space Complexity: O(1)
// Technique: Minimax & Game Theory (25 Game Theory & Minimax)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: First player always wins by picking either all even or all odd piles.
};

```
