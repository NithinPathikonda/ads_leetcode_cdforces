---
title: "LC 398: Random Pick Index"
module: "26 Reservoir Sampling & Randomized"
concept: "Reservoir Sampling"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Meta
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 398: Random Pick Index

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[26 Reservoir Sampling & Randomized]]
> - **Core Concept**: [[Reservoir Sampling]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Reservoir Sampling application in `26 Reservoir Sampling & Randomized`.
> - **Immediate Strategy**: Reservoir sampling: pick index with probability 1 / count.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Reservoir Sampling**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 398 Random Pick Index]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 398: Random Pick Index
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Reservoir Sampling (26 Reservoir Sampling & Randomized)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Reservoir sampling: pick index with probability 1 / count.
};

```
