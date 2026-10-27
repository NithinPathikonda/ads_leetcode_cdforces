---
title: "LC 221: Maximal Square"
module: "15 Dynamic Programming 2 2D & Grids"
concept: "2D Grid DP"
difficulty: "Medium"
complexity: "O(M * N)"
type: "problem-card"
tags:
  - problem
  - medium
---

# LC 221: Maximal Square

- **Module**: [[15 Dynamic Programming 2 2D & Grids]]
- **Core Concept**: [[2D Grid DP]]
- **Difficulty**: [[Medium]]
- **Time Complexity**: `O(M * N)`
- **Target Companies**: [[Google]], [[Amazon]]

---

## 💡 Optimal Intuition & Trigger
> dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}).

---

### 🪜 Pattern Ladder & Progressive Variations
- ⬅ Prerequisite Pattern: [[LC 64 Minimum Path Sum]]

