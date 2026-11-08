# 🏆 LeetCode Weekly Contest 527 Dashboard

- **Date**: 2026-11-08
- **Platform**: [LeetCode Contest](https://leetcode.com/contest/weekly-contest-527/)
- **Live Score**: 4 / 21 pts (Q1 Solved Live)

---

## 📊 Problem Breakdown & Upsolving Queue

| # | Problem | Difficulty | Points | Live Status | Upsolve Status | Solution File |
|---|---|:---:|:---:|:---:|:---:|---|
| **Q1** | [Find Mismatched Segments Between Two Strings](https://leetcode.com/contest/weekly-contest-527/problems/find-mismatched-segments-between-two-strings/) | Medium | 4 | ✅ Solved Live | ✅ Complete | [q1_find_mismatched_segments_between_two_strings.cpp](q1_find_mismatched_segments_between_two_strings.cpp) |
| **Q2** | [Count Valid Suffix Sorts I](https://leetcode.com/contest/weekly-contest-527/problems/count-valid-suffix-sorts-i/) | Medium | 5 | ⏱️ TLE | ⏳ Queued | [q2_count_valid_suffix_sorts_i.cpp](q2_count_valid_suffix_sorts_i.cpp) |
| **Q3** | [Minimum Cost to Make Red Nodes Connected](https://leetcode.com/contest/weekly-contest-527/problems/minimum-cost-to-make-red-nodes-connected/) | Medium | 5 | ⏳ Not Attempted | ⏳ Queued | [q3_minimum_cost_to_make_red_nodes_connected.cpp](q3_minimum_cost_to_make_red_nodes_connected.cpp) |
| **Q4** | [Count Valid Suffix Sorts II](https://leetcode.com/contest/weekly-contest-527/problems/count-valid-suffix-sorts-ii/) | Hard | 7 | ⏳ Not Attempted | ⏳ Queued | [q4_count_valid_suffix_sorts_ii.cpp](q4_count_valid_suffix_sorts_ii.cpp) |

---

## 💡 Contest Takeaways
1. **Q1 (Find Mismatched Segments)**: Solved using XOR character matching and buffer accumulation. Optimized to two-pointer sliding window without string reallocations.
2. **Q2 (Count Valid Suffix Sorts I)**: Full array simulation with repeated $O(N \log N)$ sorting caused TLE. Invariant observation: valid $l$ lies in $s \le l \le p$, requiring only a single suffix verification.
3. **Q3 & Q4**: Queued for targeted upsolving sessions.
