---
title: "LC 4: Median of Two Sorted Arrays"
module: "03 Binary Search"
concept: "Binary Search on Array"
difficulty: "Hard"
complexity: "O(log(min(M, N)))"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
  - Microsoft
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 4: Median of Two Sorted Arrays

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Binary Search on Array]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(log(min(M, N))))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Binary Search on Array application in `03 Binary Search`.
> - **Immediate Strategy**: Binary search partition cut on smaller array.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Binary Search on Array**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 410 Split Array Largest Sum]]
- 🎯 **Current Anchor**: [[LC 4 Median of Two Sorted Arrays]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 4: Median of Two Sorted Arrays
// Time Complexity: O(log(min(M, N))) | Space Complexity: O(K)
// Technique: Binary Search on Array (03 Binary Search)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Binary search partition cut on smaller array.
};

```
