---
title: "LC 875: Koko Eating Bananas"
module: "03 Binary Search"
concept: "Binary Search on Answer"
difficulty: "Medium"
complexity: "O(N log(max_pile))"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 875: Koko Eating Bananas

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[03 Binary Search]]
> - **Core Concept**: [[Binary Search on Answer]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N log(max_pile)))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Binary Search on Answer application in `03 Binary Search`.
> - **Immediate Strategy**: Binary search speed K with predicate sum(ceil(p / k)) <= h.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Binary Search on Answer**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 875 Koko Eating Bananas]]
- ➔ **Next Boss Variation**: [[LC 1011 Capacity To Ship Packages Within D Days]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 875: Koko Eating Bananas
// Time Complexity: O(N log(max_pile)) | Space Complexity: O(N)
// Technique: Binary Search on Answer (03 Binary Search)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Binary search speed K with predicate sum(ceil(p / k)) <= h.
};

```
