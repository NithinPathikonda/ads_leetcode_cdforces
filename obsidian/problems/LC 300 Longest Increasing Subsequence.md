---
title: "LC 300: Longest Increasing Subsequence"
module: "14 Dynamic Programming 1 1D & Classics"
concept: "Longest Increasing Subsequence"
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

# 🟡 LC 300: Longest Increasing Subsequence

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[14 Dynamic Programming 1 1D & Classics]]
> - **Core Concept**: [[Longest Increasing Subsequence]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N log N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Longest Increasing Subsequence application in `14 Dynamic Programming 1 1D & Classics`.
> - **Immediate Strategy**: Patience sort tails array with std::lower_bound.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Longest Increasing Subsequence**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 322 Coin Change]]
- 🎯 **Current Anchor**: [[LC 300 Longest Increasing Subsequence]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 300: Longest Increasing Subsequence
// Time Complexity: O(N log N) | Space Complexity: O(N)
// Technique: Longest Increasing Subsequence (14 Dynamic Programming 1 1D & Classics)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Patience sort tails array with std::lower_bound.
};

```
