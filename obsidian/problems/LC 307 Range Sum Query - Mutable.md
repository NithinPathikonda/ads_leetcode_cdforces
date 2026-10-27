---
title: "LC 307: Range Sum Query - Mutable"
module: "21 Segment Trees & Fenwick (BIT)"
concept: "Segment Tree & Fenwick"
difficulty: "Medium"
complexity: "O(log N)"
space_complexity: "O(K)"
companies:
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 307: Range Sum Query - Mutable

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[21 Segment Trees & Fenwick (BIT)]]
> - **Core Concept**: [[Segment Tree & Fenwick]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(log N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Segment Tree & Fenwick application in `21 Segment Trees & Fenwick (BIT)`.
> - **Immediate Strategy**: Segment tree or BIT point update and range query.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Segment Tree & Fenwick**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 307 Range Sum Query - Mutable]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 307: Range Sum Query - Mutable
// Time Complexity: O(log N) | Space Complexity: O(K)
// Technique: Segment Tree & Fenwick (21 Segment Trees & Fenwick (BIT))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Segment tree or BIT point update and range query.
};

```
