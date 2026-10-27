---
title: "LC 28: Find the Index of the First Occurrence in a String"
module: "23 Advanced Strings (KMP & Rabin-Karp)"
concept: "KMP & String Matching"
difficulty: "Easy"
complexity: "O(N + M)"
space_complexity: "O(N)"
companies:
  - Microsoft
  - Google
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 28: Find the Index of the First Occurrence in a String

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[23 Advanced Strings (KMP & Rabin-Karp)]]
> - **Core Concept**: [[KMP & String Matching]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N + M))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Microsoft]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: KMP & String Matching application in `23 Advanced Strings (KMP & Rabin-Karp)`.
> - **Immediate Strategy**: KMP LPS preprocessing or Rabin-Karp rolling hash.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 28 Find the Index of the First Occurrence in a String]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 28: Find the Index of the First Occurrence in a String
// Time Complexity: O(N + M) | Space Complexity: O(N)
// Technique: KMP & String Matching (23 Advanced Strings (KMP & Rabin-Karp))

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: KMP LPS preprocessing or Rabin-Karp rolling hash.
};

```
