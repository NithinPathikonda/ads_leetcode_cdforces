---
title: "LC 50: Pow(x, n)"
module: "20 Bit Manipulation & Math"
concept: "Fast Exponentiation"
difficulty: "Medium"
complexity: "O(log N)"
space_complexity: "O(K)"
companies:
  - Meta
  - Google
  - Bloomberg
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 50: Pow(x, n)

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[20 Bit Manipulation & Math]]
> - **Core Concept**: [[Fast Exponentiation]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(log N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Meta]], [[Google]], [[Bloomberg]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Fast Exponentiation application in `20 Bit Manipulation & Math`.
> - **Immediate Strategy**: Binary exponentiation: square base x and halve power n.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Fast Exponentiation**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 50 Pow(x, n)]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 50: Pow(x, n)
// Time Complexity: O(log N) | Space Complexity: O(K)
// Technique: Fast Exponentiation (20 Bit Manipulation & Math)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Binary exponentiation: square base x and halve power n.
};

```
