# 🛑 Error Log & Bug Post-Mortem 

> **Rule**: Every failed test case, Time Limit Exceeded (TLE), Memory Limit Exceeded (MLE), or missed edge case gets logged here. Reviewing this weekly prevents repeating past mistakes.

---

## 📋 The 4 Error Categories

1. **Pattern Blindness (PB)**: Didn't recognize the right pattern/data structure.
2. **Edge-Case Blindspot (EB)**: Missed duplicates, negatives, empty/single element, integer overflow (`INT_MAX`, `1e18`).
3. **Off-by-One / Implementation Bug (IB)**: Pointer update order, `<` vs `<=`, array indexing, iterator invalidation.
4. **Time / Space Complexity (TC)**: Inefficient algorithm (e.g. $O(N^2)$ on $N=10^5$), excessive memory allocation.

---

## 📝 Error Log Table

| Date | Problem | Error Category | What Went Wrong? | What Was The Fix / Root Cause? |
| :--- | :--- | :---: | :--- | :--- |
| *YYYY-MM-DD* | *Two Sum* | *EB* | *Used element twice on `[3, 3]`, target 6* | *Checked complement before inserting current element into hash map.* |

---

## 🔍 Pre-Submission Checklist (Before Hitting Submit!)
- [ ] **Scale of $N$ checked**: Will my Big-$O$ run in $< 10^8$ operations (~1 second)?
- [ ] **Integer Overflow**: Can any sum/product exceed $2 \times 10^9$? Use `long long` where needed.
- [ ] **Empty & Single Element**: Does the code work on $N = 0$, $N = 1$, or $N = 2$?
- [ ] **Duplicates & Negatives**: Does the logic hold if all elements are identical or negative?
- [ ] **Pointer Boundaries**: Are while loops guaranteed to terminate (`left < right` vs `left <= right`)?
