---
title: "LC 90: Subsets II"
module: "06 Recursion & Backtracking"
concept: "Backtracking & Pruning"
difficulty: "Medium"
complexity: "O(2^N)"
space_complexity: "O(K)"
companies:
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 90: Subsets II

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[06 Recursion & Backtracking]]
> - **Core Concept**: [[Backtracking & Pruning]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(2^N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Backtracking & Pruning application in `06 Recursion & Backtracking`.
> - **Immediate Strategy**: Sort first; skip duplicates when nums[i] == nums[i-1] at same depth.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Backtracking & Pruning**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 78 Subsets]]
- 🎯 **Current Anchor**: [[LC 90 Subsets II]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 90: Subsets II
// Time Complexity: O(2^N) | Space Complexity: O(K)
// Technique: Backtracking & Pruning (06 Recursion & Backtracking)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Sort first; skip duplicates when nums[i] == nums[i-1] at same depth.
};

```
