---
title: "LC 214: Shortest Palindrome"
module: "23 Advanced Strings (KMP & Rabin-Karp)"
concept: "KMP & String Matching"
difficulty: "Hard"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 214: Shortest Palindrome

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[23 Advanced Strings (KMP & Rabin-Karp)]]
> - **Core Concept**: [[KMP & String Matching]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: KMP & String Matching application in `23 Advanced Strings (KMP & Rabin-Karp)`.
> - **Immediate Strategy**: KMP LPS of s + '#' + rev(s) gives longest palindromic prefix.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 214 Shortest Palindrome]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 214: Shortest Palindrome
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
    // Intuition: KMP LPS of s + '#' + rev(s) gives longest palindromic prefix.
};

```
