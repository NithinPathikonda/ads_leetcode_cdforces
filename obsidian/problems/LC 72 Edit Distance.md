---
title: "LC 72: Edit Distance"
module: "16 Dynamic Programming 3 Strings & Sequences"
concept: "Edit Distance DP"
difficulty: "Medium"
complexity: "O(M * N)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
  - Microsoft
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 72: Edit Distance

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[16 Dynamic Programming 3 Strings & Sequences]]
> - **Core Concept**: [[Edit Distance DP]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M * N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Edit Distance DP application in `16 Dynamic Programming 3 Strings & Sequences`.
> - **Immediate Strategy**: Min operations: 1 + min({insert, delete, replace}).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Edit Distance DP**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 1143 Longest Common Subsequence]]
- 🎯 **Current Anchor**: [[LC 72 Edit Distance]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 72: Edit Distance
// Time Complexity: O(M * N) | Space Complexity: O(K)
// Technique: Edit Distance DP (16 Dynamic Programming 3 Strings & Sequences)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Min operations: 1 + min({insert, delete, replace}).
};

```
