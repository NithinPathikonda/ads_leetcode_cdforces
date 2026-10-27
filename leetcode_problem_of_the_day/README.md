# 📅 LeetCode Problem of the Day (POTD) Archive

A dedicated chronological log for daily LeetCode challenges, organized by year, month, and date with problem statements, optimal complexity targets, and C++20 solutions.

---

## 📊 POTD Summary Table

| Date | # | Problem | Difficulty | Category / Pattern | Time | Space | Solution |
| :---: | :---: | :--- | :---: | :--- | :---: | :---: | :--- |
| **2026-10-27** | 3963 | [Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/) | Easy | Constructive / Grid Path | $O(M \times N)$ | $O(1)$ | [2026_10_27_lc_3963.cpp](2026-10/2026_10_27_lc_3963_create_grid_with_exactly_one_path.cpp) |
| **2026-09-28** | 1614 | [Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/) | Easy | Stack / Depth Counter | $O(N)$ | $O(1)$ | [2026_09_28_lc_1614.cpp](2026-09/2026_09_28_lc_1614_maximum_nesting_depth_of_the_parentheses.cpp) |

---

## 🗓️ Archive by Month

### 📌 October 2026

#### 📅 2026-10-27: LC 3963 — Create Grid With Exactly One Path
* **Problem Link**: [LeetCode 3963: Create Grid With Exactly One Path](https://leetcode.com/problems/create-grid-with-exactly-one-path/?envType=daily-question&envId=2026-10-27)
* **Difficulty**: Easy
* **Topic**: Constructive Algorithms / Matrix Traversal / Grid
* **Solution File**: [`leetcode_problem_of_the_day/2026-10/2026_10_27_lc_3963_create_grid_with_exactly_one_path.cpp`](2026-10/2026_10_27_lc_3963_create_grid_with_exactly_one_path.cpp)
* **Core Takeaways**:
  * Carve an L-shaped path: traverse all the way across the first row `i == 0` then all the way down the last column `j == n - 1`.
  * Place obstacles `'#'` everywhere else to strictly prevent any alternative branching paths.
  * Time: $O(M \times N)$, Space: $O(1)$ auxiliary.

---

### 📌 September 2026

#### 📅 2026-09-28: LC 1614 — Maximum Nesting Depth of the Parentheses
* **Problem Link**: [LeetCode 1614: Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2026-09-28)
* **Difficulty**: Easy
* **Topic**: Stack / Simulation / String
* **Solution File**: [`leetcode_problem_of_the_day/2026-09/2026_09_28_lc_1614_maximum_nesting_depth_of_the_parentheses.cpp`](2026-09/2026_09_28_lc_1614_maximum_nesting_depth_of_the_parentheses.cpp)
* **Core Takeaways**:
  * The input string is guaranteed to be a Valid Parentheses String (VPS).
  * Characters other than `'('` and `')'` (digits and operators) do not affect parentheses nesting depth.
  * Every `'('` increases current nesting level by $+1$; every `')'` decreases it by $-1$.
  * Maintaining a simple integer counter yields optimal **$O(N)$ Time** and **$O(1)$ Auxiliary Space** without needing dynamic stack allocations.

---

## 📝 POTD Entry Template

When logging a new daily problem, follow this section format:

```markdown
#### 📅 YYYY-MM-DD: LC <ProblemNumber> — <Problem Title>
* **Problem Link**: [LeetCode Title](https://leetcode.com/problems/...)
* **Difficulty**: Easy / Medium / Hard
* **Topic**: <Pattern / Topic>
* **Solution File**: [`leetcode_problem_of_the_day/YYYY-MM/YYYY_MM_DD_lc_<number>_<slug>.cpp`](...)
* **Core Takeaways**:
  * <Key intuition and edge cases>
  * Time: O(...), Space: O(...)
```
