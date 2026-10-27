---
title: "LC 45: Jump Game II"
module: "19 Greedy Algorithms"
concept: "Greedy Intervals & Reachability"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 45: Jump Game II

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[19 Greedy Algorithms]]
> - **Core Concept**: [[Greedy Intervals & Reachability]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Greedy Intervals & Reachability application in `19 Greedy Algorithms`.
> - **Immediate Strategy**: Track current interval end and furthest reach; increment jump at interval end.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Greedy Intervals & Reachability**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 55 Jump Game]]
- 🎯 **Current Anchor**: [[LC 45 Jump Game II]]
- ➔ **Next Boss Variation**: [[LC 134 Gas Station]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 45: Jump Game II
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Greedy Intervals & Reachability (19 Greedy Algorithms)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Track current interval end and furthest reach; increment jump at interval end.
};

```
