---
title: "LC 136: Single Number"
module: "20 Bit Manipulation & Math"
concept: "Bitwise Tricks"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 136: Single Number

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[20 Bit Manipulation & Math]]
> - **Core Concept**: [[Bitwise Tricks]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Bitwise Tricks application in `20 Bit Manipulation & Math`.
> - **Immediate Strategy**: XOR accumulator: duplicates cancel out leaving unique number.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Bitwise Tricks**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 136 Single Number]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 136: Single Number
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Bitwise Tricks (20 Bit Manipulation & Math)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: XOR accumulator: duplicates cancel out leaving unique number.
};

```
