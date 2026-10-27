---
title: "LC 198: House Robber"
module: "14 Dynamic Programming 1 1D & Classics"
concept: "1D Linear DP"
difficulty: "Medium"
complexity: "O(N)"
type: "problem-card"
tags:
  - problem
  - medium
---

# LC 198: House Robber

- **Module**: [[14 Dynamic Programming 1 1D & Classics]]
- **Core Concept**: [[1D Linear DP]]
- **Difficulty**: [[Medium]]
- **Time Complexity**: `O(N)`
- **Target Companies**: [[Amazon]], [[Google]], [[Microsoft]]

---

## 💡 Optimal Intuition & Trigger
> dp[i] = max(dp[i-1], nums[i] + dp[i-2]) with 2 rolling scalars.

---

### 🪜 Pattern Ladder & Progressive Variations
- ⬅ Prerequisite Pattern: [[LC 70 Climbing Stairs]]
- ➔ Next Pattern Step: [[LC 322 Coin Change]]

