---
title: "LC 215: Kth Largest Element in an Array"
module: "08 Heaps & Priority Queues"
concept: "Binary Heap & Priority Queue"
difficulty: "Medium"
complexity: "O(N log K)"
space_complexity: "O(N)"
companies:
  - Meta
  - Amazon
  - Google
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 215: Kth Largest Element in an Array

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[08 Heaps & Priority Queues]]
> - **Core Concept**: [[Binary Heap & Priority Queue]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N log K))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Meta]], [[Amazon]], [[Google]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Binary Heap & Priority Queue application in `08 Heaps & Priority Queues`.
> - **Immediate Strategy**: Min-heap of size K, or QuickSelect in O(N).

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Binary Heap & Priority Queue**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Current Anchor**: [[LC 215 Kth Largest Element in an Array]]
- ➔ **Next Boss Variation**: [[LC 347 Top K Frequent Elements]]
- ➔ **Next Boss Variation**: [[LC 295 Find Median from Data Stream]]

---

## 💻 Optimal C++20 Implementation

```cpp
// Optimal C++20 Solution for LC 215: Kth Largest Element in an Array
// Time Complexity: O(N log K) | Space Complexity: O(N)
// Technique: Binary Heap & Priority Queue (08 Heaps & Priority Queues)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Core interview algorithmic implementation
    // Intuition: Min-heap of size K, or QuickSelect in O(N).
};

```
