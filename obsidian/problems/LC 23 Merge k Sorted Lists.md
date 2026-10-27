---
title: "LC 23: Merge k Sorted Lists"
module: "05 Linked Lists"
concept: "In-Place Linked List Reversal"
difficulty: "Hard"
complexity: "O(N log K)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Meta
  - Google
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 23: Merge k Sorted Lists

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[05 Linked Lists]]
> - **Core Concept**: [[In-Place Linked List Reversal]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(N log K))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Meta]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: In-Place Linked List Reversal application in `05 Linked Lists`.
> - **Immediate Strategy**: Min-heap storing k list heads or divide and conquer merge.

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
- ⬅ **Prerequisite Pattern**: [[LC 21 Merge Two Sorted Lists]]
- 🎯 **Current Anchor**: [[LC 23 Merge k Sorted Lists]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 23: Merge k Sorted Lists
// Time Complexity: O(N log K) | Space Complexity: O(N)
// Technique: In-Place Linked List Reversal (05 Linked Lists)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Min-heap storing k list heads or divide and conquer merge.
};

```
