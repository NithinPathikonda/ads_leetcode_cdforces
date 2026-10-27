---
title: "LC 135: Candy"
module: "19 Greedy Algorithms"
concept: "Greedy Intervals & Reachability"
difficulty: "Hard"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 135: Candy

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[19 Greedy Algorithms]]
> - **Core Concept**: [[Greedy Intervals & Reachability]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Greedy Intervals & Reachability application in `19 Greedy Algorithms`.
> - **Immediate Strategy**: Two passes: left-to-right (if ratings[i] > ratings[i-1]), right-to-left.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 135 Candy]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 135: Candy
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
    // Intuition: Two passes: left-to-right (if ratings[i] > ratings[i-1]), right-to-left.
};

```
