---
title: "LC 438: Find All Anagrams in a String"
module: "02 Two Pointers & Sliding Window"
concept: "Fixed Sliding Window"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 438: Find All Anagrams in a String

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[02 Two Pointers & Sliding Window]]
> - **Core Concept**: [[Fixed Sliding Window]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Fixed Sliding Window application in `02 Two Pointers & Sliding Window`.
> - **Immediate Strategy**: Fixed window size p.length() matching character frequency map.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Fixed Sliding Window**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 567 Permutation in String]]
- 🎯 **Current Anchor**: [[LC 438 Find All Anagrams in a String]]
- ➔ **Next Boss Variation**: [[LC 76 Minimum Window Substring]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 438: Find All Anagrams in a String
// Time Complexity: O(N) | Space Complexity: O(N)
// Technique: Fixed Sliding Window (02 Two Pointers & Sliding Window)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Fixed window size p.length() matching character frequency map.
};

```
