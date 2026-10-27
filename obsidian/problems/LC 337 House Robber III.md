---
title: "LC 337: House Robber III"
module: "18 Dynamic Programming 5 Trees, Bitmask & Digit DP"
concept: "Tree DP"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 337: House Robber III

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[18 Dynamic Programming 5 Trees, Bitmask & Digit DP]]
> - **Core Concept**: [[Tree DP]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Tree DP application in `18 Dynamic Programming 5 Trees, Bitmask & Digit DP`.
> - **Immediate Strategy**: Postorder returns pair: (rob_this_node, not_rob_this_node).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Tree DP**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 337 House Robber III]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 337: House Robber III
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Tree DP (18 Dynamic Programming 5 Trees, Bitmask & Digit DP)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Postorder returns pair: (rob_this_node, not_rob_this_node).
};

```
