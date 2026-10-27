---
title: "Longest Common Subsequence (LCS)"
type: "concept-hub"
module: "16 Dynamic Programming 3: Strings & Sequences"
tags:
  - concept
  - algorithm
---

# 🟢 Algorithmic Concept: Longest Common Subsequence (LCS)

- **Parent Syllabus Module**: [[16 Dynamic Programming 3 Strings & Sequences]]
- **Backlink to Galaxy Root**: [[Index|🏠 Master Knowledge Galaxy Root]]

> **Intuition & Mental Model**:  
> 2D string matrix: if s1[i] == s2[j] -> 1 + dp[i-1][j-1]; else max(dp[i-1][j], dp[i][j-1]).

---

## 🎯 Target MNC Problems Utilizing This Concept
- [[LC 1143 Longest Common Subsequence]] — Medium | [[Amazon]], [[Google]], [[Meta]], [[Microsoft]] | [[O(M * N)]]
