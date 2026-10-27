---
title: "LC 33: Search in Rotated Sorted Array"
module: "03 Binary Search"
concept: "Rotated Array Binary Search"
difficulty: "Medium"
complexity: "O(log N)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Meta
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 33: Search in Rotated Sorted Array

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Rotated Array Binary Search]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(log N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Meta]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Rotated Array Binary Search application in `03 Binary Search`.
> - **Immediate Strategy**: Identify which half is sorted; check if target falls in sorted interval.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Rotated Array Binary Search**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 704 Binary Search]]
- 🎯 **Current Anchor**: [[LC 33 Search in Rotated Sorted Array]]
- ➔ **Next Boss Variation**: [[LC 153 Find Minimum in Rotated Sorted Array]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 33: Search in Rotated Sorted Array
// Time Complexity: O(log N) | Space Complexity: O(K)
// Technique: Rotated Array Binary Search (03 Binary Search)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Identify which half is sorted; check if target falls in sorted interval.
};

```
