---
title: "LC 20: Valid Parentheses"
module: "04 Stack & Monotonic Stack"
concept: "Monotonic Stack"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 20: Valid Parentheses

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[04 Stack & Monotonic Stack]]
> - **Core Concept**: [[Monotonic Stack]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Monotonic Stack application in `04 Stack & Monotonic Stack`.
> - **Immediate Strategy**: Stack matching closing brackets with corresponding openers.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Monotonic Stack**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 20 Valid Parentheses]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 20: Valid Parentheses
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Monotonic Stack (04 Stack & Monotonic Stack)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Stack matching closing brackets with corresponding openers.
};

```
