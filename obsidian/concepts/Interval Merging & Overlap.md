---
title: "Interval Merging & Overlap"
type: "concept-hub"
module: "09 Intervals & Sweepline"
tags:
  - concept
  - algorithm
---

# 🟢 Algorithmic Concept: Interval Merging & Overlap

- **Parent Syllabus Module**: [[09 Intervals & Sweepline]]
- **Backlink to Galaxy Root**: [[Index|🏠 Master Knowledge Galaxy Root]]

> **Intuition & Mental Model**:  
> Sort intervals by start time. Merge if curr.start <= prev.end; otherwise push new interval.

---

## 🎯 Target MNC Problems Utilizing This Concept
- [[LC 56 Merge Intervals]] — Medium | [[Meta]], [[Google]], [[Amazon]], [[Microsoft]], [[Apple]] | [[O(N log N)]]
- [[LC 57 Insert Interval]] — Medium | [[Google]], [[Meta]], [[Amazon]] | [[O(N)]]
- [[LC 435 Non-overlapping Intervals]] — Medium | [[Meta]], [[Google]], [[Amazon]] | [[O(N log N)]]
