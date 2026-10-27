---
title: "LC 62: Unique Paths"
module: "15 Dynamic Programming 2 2D & Grids"
concept: "2D Grid DP"
difficulty: "Medium"
complexity: "O(M * N)"
type: "problem-card"
tags:
  - problem
  - medium
---

# LC 62: Unique Paths

- **Module**: [[15 Dynamic Programming 2 2D & Grids]]
- **Core Concept**: [[2D Grid DP]]
- **Difficulty**: [[Medium]]
- **Time Complexity**: `O(M * N)`
- **Target Companies**: [[Amazon]], [[Google]]

---

## 💡 Optimal Intuition & Trigger
> dp[i][j] = dp[i-1][j] + dp[i][j-1] with 1D row buffer.

---

### 🪜 Pattern Ladder & Progressive Variations
- ➔ Next Pattern Step: [[LC 64 Minimum Path Sum]]

