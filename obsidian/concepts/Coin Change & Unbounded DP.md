---
title: "Coin Change & Unbounded DP"
type: "concept-hub"
module: "14 Dynamic Programming 1: 1D & Classics"
tags:
  - concept
  - algorithm
---

# 🟢 Algorithmic Concept: Coin Change & Unbounded DP

- **Parent Syllabus Module**: [[14 Dynamic Programming 1 1D & Classics]]
- **Backlink to Galaxy Root**: [[Index|🏠 Master Knowledge Galaxy Root]]

> **Intuition & Mental Model**:  
> Iterates denominations updating dp[i] = min(dp[i], dp[i - coin] + 1).

---

## 🎯 Target MNC Problems Utilizing This Concept
- [[LC 322 Coin Change]] — Medium | [[Amazon]], [[Google]], [[Meta]], [[Microsoft]], [[Bloomberg]] | [[O(amount * coins)]]
