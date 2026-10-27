---
title: "LC 56: Merge Intervals"
module: "09 Intervals & Sweepline"
concept: "Interval Merging & Sweepline"
difficulty: "Medium"
complexity: "O(N log N)"
space_complexity: "O(N)"
companies:
  - Google
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 56: Merge Intervals

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[09 Intervals & Sweepline]]
> - **Core Concept**: [[Interval Merging & Sweepline]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N log N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Interval Merging & Sweepline application in `09 Intervals & Sweepline`.
> - **Immediate Strategy**: Sort by start time. Merge if start <= prev.end.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Interval Merging & Sweepline**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 56 Merge Intervals]]
- ➔ **Next Boss Variation**: [[LC 57 Insert Interval]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 56: Merge Intervals
// Time Complexity: O(N log N) | Space Complexity: O(N)
// Technique: Interval Merging & Sweepline (09 Intervals & Sweepline)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Sort by start time. Merge if start <= prev.end.
};

```
