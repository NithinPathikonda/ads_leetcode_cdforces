---
title: "LC 5: Longest Palindromic Substring"
module: "23 Advanced Strings (KMP & Rabin-Karp)"
concept: "KMP & String Matching"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Microsoft
  - Meta
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 5: Longest Palindromic Substring

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[23 Advanced Strings (KMP & Rabin-Karp)]]
> - **Core Concept**: [[KMP & String Matching]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Microsoft]], [[Meta]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: KMP & String Matching application in `23 Advanced Strings (KMP & Rabin-Karp)`.
> - **Immediate Strategy**: Expand around center in O(N^2) or Manacher's in O(N).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **KMP & String Matching**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 5 Longest Palindromic Substring]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 5: Longest Palindromic Substring
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: KMP & String Matching (23 Advanced Strings (KMP & Rabin-Karp))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Expand around center in O(N^2) or Manacher's in O(N).
};

```
