---
title: "LC 21: Merge Two Sorted Lists"
module: "05 Linked Lists"
concept: "In-Place Linked List Reversal"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Apple
  - Microsoft
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 21: Merge Two Sorted Lists

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[05 Linked Lists]]
> - **Core Concept**: [[In-Place Linked List Reversal]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Apple]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: In-Place Linked List Reversal application in `05 Linked Lists`.
> - **Immediate Strategy**: Iterative dummy head merge comparing heads.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **In-Place Linked List Reversal**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 206 Reverse Linked List]]
- 🎯 **Current Anchor**: [[LC 21 Merge Two Sorted Lists]]
- ➔ **Next Boss Variation**: [[LC 23 Merge k Sorted Lists]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 21: Merge Two Sorted Lists
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: In-Place Linked List Reversal (05 Linked Lists)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Iterative dummy head merge comparing heads.
};

```
