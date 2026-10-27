---
title: "LC 141: Linked List Cycle"
module: "05 Linked Lists"
concept: "Floyd's Cycle Detection"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Microsoft
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 141: Linked List Cycle

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[05 Linked Lists]]
> - **Core Concept**: [[Floyd's Cycle Detection]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Floyd's Cycle Detection application in `05 Linked Lists`.
> - **Immediate Strategy**: Floyd's Tortoise and Hare fast and slow pointers.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Floyd's Cycle Detection**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 141 Linked List Cycle]]
- ➔ **Next Boss Variation**: [[LC 142 Linked List Cycle II]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 141: Linked List Cycle
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Floyd's Cycle Detection (05 Linked Lists)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Floyd's Tortoise and Hare fast and slow pointers.
};

```
