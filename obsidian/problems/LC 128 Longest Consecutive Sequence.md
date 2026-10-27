---
title: "LC 128: Longest Consecutive Sequence"
module: "01 Arrays & Hashing"
concept: "Hash Maps & Sets"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Meta
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 128: Longest Consecutive Sequence

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[01 Arrays & Hashing]]
> - **Core Concept**: [[Hash Maps & Sets]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Meta]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Hash Maps & Sets application in `01 Arrays & Hashing`.
> - **Immediate Strategy**: Hash set lookup; only count streaks starting where (x-1) is not in set.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Hash Maps & Sets**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- 🎯 **Foundational Anchor Pattern**: [[LC 128 Longest Consecutive Sequence]]

---

## 💻 Optimal C++20 Implementation

```cpp
/**
 * Problem 007: Longest Consecutive Sequence
 * Link: https://leetcode.com/problems/longest-consecutive-sequence/
 * Topic: 01_arrays_hashing
 * Companies: Google, Meta, Amazon, Microsoft, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 * Constraints:
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Sorting Baseline):
 *     - Time Complexity: O(N log N)
 *       Sort array, then iterate once tracking consecutive streaks while ignoring duplicates.
 *     - Space Complexity: O(1) or O(N) depending on sort implementation.
 *     - Caveat: Does not satisfy the strict O(N) requirement.
 *
 * - Approach 2 (Hash Set Sequence Leader Discovery - User's Optimal Solution):
 *     - Time Complexity: O(N)
 *       Inserting all N elements into an unordered_set takes O(N) average time.
 *       For each number `x`, we check if `x - 1` exists in the set (O(1)).
 *       - If `x - 1` exists, `x` is NOT the start of a sequence -> skip immediately.
 *       - If `x - 1` does not exist, `x` is a sequence leader -> expand forward `x + 1, x + 2...`
 *       Each number is visited at most twice (once in outer iteration, once in inner expansion),
 *       giving an amortized O(N) running time.
 *     - Space Complexity: O(N)
 *       unordered_set stores up to N unique integers.
 *
 * Pattern / Trigger:
 * - "Longest consecutive sequence in O(N) without sorting" -> Hash Set + Sequence Starter Guard (`set.find(x - 1) == set.end()`).
 *
 * Critical Edge Cases:
 * - Empty array (`nums = []`) -> return 0.
 * - Single element (`nums = [10]`) -> return 1.
 * - Array with all duplicates (`nums = [1, 1, 1, 1]`) -> return 1.
 * - Negative numbers & zero (`nums = [-2, -1, 0, 1]`) -> return 4.
 * - Non-consecutive large gaps (`nums = [100, 4, 200, 1, 3, 2]`) -> return 4.
 * -------------------------------------------------------------
 Revision: 13Ot26'1
 */

#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Sorting Baseline (Interview discussion baseline)
    // Time: O(N log N), Space: O(1) auxiliary
    int longestConsecutiveSorting(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int max_streak = 1;
        int current_streak = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            // Ignore duplicate elements
            if (nums[i] == nums[i - 1]) continue;

            if (nums[i] == nums[i - 1] + 1) {
                current_streak++;
            } else {
                max_streak = max(max_streak, current_streak);
                current_streak = 1;
            }
        }

        return max(max_streak, current_streak);
    }

    // Approach 2: Hash Set Sequence Leader Discovery (Optimal O(N) Solution)
    // Time: O(N), Space: O(N)
    int longestConsecutive(const vector<int>& nums) {
        int max_length = 0;
        unordered_set<int> my_set(nums.begin(), nums.end());

        for (int it : my_set) {
            // Check if 'it' is the start of a consecutive sequence
            // If (it - 1) does NOT exist, 'it' is the leader of the sequence
            if (my_set.find(it - 1) == my_set.end()) {
                int length = 0;
                while (my_set.find(it + length) != my_set.end()) {
                    length++;
                }
                max_length = max(max_length, length);
            }
        }

        return max_length;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    cout << "Test 1 [100, 4, 200, 1, 3, 2] -> Expected: 4 | Got: "
         << sol.longestConsecutive(nums1)
         << " -> " << (sol.longestConsecutive(nums1) == 4 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Consecutive with duplicates
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << "Test 2 [0, 3, 7, 2, 5, 8, 4, 6, 0, 1] -> Expected: 9 | Got: "
         << sol.longestConsecutive(nums2)
         << " -> " << (sol.longestConsecutive(nums2) == 9 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Empty array edge case
    vector<int> nums3 = {};
    cout << "Test 3 [] -> Expected: 0 | Got: "
         << sol.longestConsecutive(nums3)
         << " -> " << (sol.longestConsecutive(nums3) == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Single element edge case
    vector<int> nums4 = {42};
    cout << "Test 4 [42] -> Expected: 1 | Got: "
         << sol.longestConsecutive(nums4)
         << " -> " << (sol.longestConsecutive(nums4) == 1 ? "PASSED" : "FAILED") << "\n";

    // Test 5: Negative numbers
    vector<int> nums5 = {-5, -4, -3, 10, 12};
    cout << "Test 5 [-5, -4, -3, 10, 12] -> Expected: 3 | Got: "
         << sol.longestConsecutive(nums5)
         << " -> " << (sol.longestConsecutive(nums5) == 3 ? "PASSED" : "FAILED") << "\n";

    return 0;
}

```
