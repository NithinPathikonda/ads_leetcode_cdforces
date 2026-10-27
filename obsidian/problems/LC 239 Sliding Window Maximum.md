---
title: "LC 239: Sliding Window Maximum"
module: "02 Two Pointers & Sliding Window"
concept: "Monotonic Stack"
difficulty: "Hard"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 239: Sliding Window Maximum

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[02 Two Pointers & Sliding Window]]
> - **Core Concept**: [[Monotonic Stack]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Monotonic Stack application in `02 Two Pointers & Sliding Window`.
> - **Immediate Strategy**: Monotonic decreasing deque holding indices in window of size K.

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
- 🎯 **Current Anchor**: [[LC 239 Sliding Window Maximum]]
- ➔ **Next Boss Variation**: [[LC 42 Trapping Rain Water]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 239: Sliding Window Maximum
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Monotonic Stack (02 Two Pointers & Sliding Window)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Monotonic decreasing deque holding indices in window of size K.
};

```
