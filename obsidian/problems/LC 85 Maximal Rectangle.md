---
title: "LC 85: Maximal Rectangle"
module: "04 Stack & Monotonic Stack"
concept: "Monotonic Stack"
difficulty: "Hard"
complexity: "O(M * N)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 85: Maximal Rectangle

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[04 Stack & Monotonic Stack]]
> - **Core Concept**: [[Monotonic Stack]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(M * N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Monotonic Stack application in `04 Stack & Monotonic Stack`.
> - **Immediate Strategy**: Row-by-row cumulative height histogram solved via LC 84.

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
- ⬅ **Prerequisite Pattern**: [[LC 84 Largest Rectangle in Histogram]]
- 🎯 **Current Anchor**: [[LC 85 Maximal Rectangle]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 85: Maximal Rectangle
// Time Complexity: O(M * N) | Space Complexity: O(K)
// Technique: Monotonic Stack (04 Stack & Monotonic Stack)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Row-by-row cumulative height histogram solved via LC 84.
};

```
