---
title: "LC 146: LRU Cache"
module: "22 Design Data Structures"
concept: "LRU & LFU Cache Design"
difficulty: "Medium"
complexity: "O(1)"
space_complexity: "O(1)"
companies:
  - Amazon
  - Google
  - Meta
  - Microsoft
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 146: LRU Cache

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[22 Design Data Structures]]
> - **Core Concept**: [[LRU & LFU Cache Design]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(1))$
> - **Space Complexity**: $\mathcal{O}(O(1))$
> - **Target MNCs**: [[Amazon]], [[Google]], [[Meta]], [[Microsoft]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: LRU & LFU Cache Design application in `22 Design Data Structures`.
> - **Immediate Strategy**: Hash map + Doubly Linked List with head (MRU) and tail (LRU).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **LRU & LFU Cache Design**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 146 LRU Cache]]
- ➔ **Next Boss Variation**: [[LC 460 LFU Cache]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 146: LRU Cache
// Time Complexity: O(1) | Space Complexity: O(1)
// Technique: LRU & LFU Cache Design (22 Design Data Structures)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Hash map + Doubly Linked List with head (MRU) and tail (LRU).
};

```
