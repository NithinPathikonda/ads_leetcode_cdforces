---
title: "LC 1143: Longest Common Subsequence"
module: "16 Dynamic Programming 3 Strings & Sequences"
concept: "Longest Common Subsequence"
difficulty: "Medium"
complexity: "O(M * N)"
space_complexity: "O(K)"
companies:
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 1143: Longest Common Subsequence

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[16 Dynamic Programming 3 Strings & Sequences]]
> - **Core Concept**: [[Longest Common Subsequence]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(M * N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Longest Common Subsequence application in `16 Dynamic Programming 3 Strings & Sequences`.
> - **Immediate Strategy**: Match: 1 + dp[i-1][j-1]; Mismatch: max(dp[i-1][j], dp[i][j-1]).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Longest Common Subsequence**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 1143 Longest Common Subsequence]]
- ➔ **Next Boss Variation**: [[LC 72 Edit Distance]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 1143: Longest Common Subsequence
// Time Complexity: O(M * N) | Space Complexity: O(K)
// Technique: Longest Common Subsequence (16 Dynamic Programming 3 Strings & Sequences)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Match: 1 + dp[i-1][j-1]; Mismatch: max(dp[i-1][j], dp[i][j-1]).
};

```
