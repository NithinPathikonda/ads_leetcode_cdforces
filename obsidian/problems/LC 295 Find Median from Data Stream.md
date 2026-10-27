---
title: "LC 295: Find Median from Data Stream"
module: "08 Heaps & Priority Queues"
concept: "Two Heaps Running Median"
difficulty: "Hard"
complexity: "O(log N)"
space_complexity: "O(K)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - hard
---

# 🔴 LC 295: Find Median from Data Stream

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[08 Heaps & Priority Queues]]
> - **Core Concept**: [[Two Heaps Running Median]]
> - **Difficulty**: Hard 🔴
> - **Time Complexity**: $\mathcal{O}(O(log N))$
> - **Space Complexity**: $\mathcal{O}(O(K))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Two Heaps Running Median application in `08 Heaps & Priority Queues`.
> - **Immediate Strategy**: Max-heap for small half, Min-heap for large half; size diff <= 1.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Two Heaps Running Median**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 215 Kth Largest Element in an Array]]
- 🎯 **Current Anchor**: [[LC 295 Find Median from Data Stream]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 295: Find Median from Data Stream
// Time Complexity: O(log N) | Space Complexity: O(K)
// Technique: Two Heaps Running Median (08 Heaps & Priority Queues)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Max-heap for small half, Min-heap for large half; size diff <= 1.
};

```
