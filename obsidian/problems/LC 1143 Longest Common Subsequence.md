---
title: "LC 1143: Longest Common Subsequence"
module: "16 Dynamic Programming 3 Strings & Sequences"
concept: "Longest Common Subsequence"
difficulty: "Medium"
complexity: "O(M * N)"
type: "problem-card"
tags:
  - problem
  - medium
---

# LC 1143: Longest Common Subsequence

- **Module**: [[16 Dynamic Programming 3 Strings & Sequences]]
- **Core Concept**: [[Longest Common Subsequence]]
- **Difficulty**: [[Medium]]
- **Time Complexity**: `O(M * N)`
- **Target Companies**: [[Amazon]], [[Google]]

---

## 💡 Optimal Intuition & Trigger
> Match: 1 + dp[i-1][j-1]; Mismatch: max(dp[i-1][j], dp[i][j-1]).

---

### 🪜 Pattern Ladder & Progressive Variations
- ➔ Next Pattern Step: [[LC 72 Edit Distance]]

