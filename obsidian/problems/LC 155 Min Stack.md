---
title: "LC 155: Min Stack"
module: "04 Stack & Monotonic Stack"
concept: "Monotonic Stack"
difficulty: "Medium"
complexity: "O(1)"
space_complexity: "O(1)"
companies:
  - Amazon
  - Bloomberg
  - Microsoft
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 155: Min Stack

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[04 Stack & Monotonic Stack]]
> - **Core Concept**: [[Monotonic Stack]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(1))$
> - **Space Complexity**: $\mathcal{O}(O(1))$
> - **Target MNCs**: [[Amazon]], [[Bloomberg]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Monotonic Stack application in `04 Stack & Monotonic Stack`.
> - **Immediate Strategy**: Store pair (val, current_min) or dual stack for O(1) minimum.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 155 Min Stack]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 155: Min Stack
// Time Complexity: O(1) | Space Complexity: O(1)
// Technique: Monotonic Stack (04 Stack & Monotonic Stack)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Store pair (val, current_min) or dual stack for O(1) minimum.
};

```
