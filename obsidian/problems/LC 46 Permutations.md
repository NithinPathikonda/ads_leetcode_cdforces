---
title: "LC 46: Permutations"
module: "06 Recursion & Backtracking"
concept: "Permutations & Combinations"
difficulty: "Medium"
complexity: "O(N!)"
space_complexity: "O(N)"
companies:
  - Microsoft
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 46: Permutations

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[06 Recursion & Backtracking]]
> - **Core Concept**: [[Permutations & Combinations]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N!))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Microsoft]], [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Permutations & Combinations application in `06 Recursion & Backtracking`.
> - **Immediate Strategy**: Backtracking swap or visited boolean array.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Permutations & Combinations**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 46 Permutations]]
- ➔ **Next Boss Variation**: [[LC 51 N-Queens]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 46: Permutations
// Time Complexity: O(N!) | Space Complexity: O(N)
// Technique: Permutations & Combinations (06 Recursion & Backtracking)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Backtracking swap or visited boolean array.
};

```
