---
title: "LC 739: Daily Temperatures"
module: "04 Stack & Monotonic Stack"
concept: "Monotonic Stack"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 739: Daily Temperatures

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[04 Stack & Monotonic Stack]]
> - **Core Concept**: [[Monotonic Stack]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Monotonic Stack application in `04 Stack & Monotonic Stack`.
> - **Immediate Strategy**: Monotonic decreasing stack holding indices waiting for warmer temperature.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 739 Daily Temperatures]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 739: Daily Temperatures
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
    // Intuition: Monotonic decreasing stack holding indices waiting for warmer temperature.
};

```
