---
title: "Maximal Square DP"
type: "concept-hub"
module: "15 Dynamic Programming 2: 2D & Grids"
tags:
  - concept
  - algorithm
---

# 🟢 Algorithmic Concept: Maximal Square DP

- **Parent Syllabus Module**: [[15 Dynamic Programming 2 2D & Grids]]
- **Backlink to Galaxy Root**: [[Index|🏠 Master Knowledge Galaxy Root]]

> **Intuition & Mental Model**:  
> dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) tracking largest valid square.

---

## 🎯 Target MNC Problems Utilizing This Concept
- [[LC 221 Maximal Square]] — Medium | [[Google]], [[Meta]], [[Amazon]], [[Apple]] | [[O(M * N)]]
