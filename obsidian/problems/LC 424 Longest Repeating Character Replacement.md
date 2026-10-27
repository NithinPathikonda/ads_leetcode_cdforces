---
title: "LC 424: Longest Repeating Character Replacement"
module: "02 Two Pointers & Sliding Window"
concept: "Dynamic Sliding Window"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 424: Longest Repeating Character Replacement

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[02 Two Pointers & Sliding Window]]
> - **Core Concept**: [[Dynamic Sliding Window]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Dynamic Sliding Window application in `02 Two Pointers & Sliding Window`.
> - **Immediate Strategy**: Window len - max_freq <= k invariant.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **Dynamic Sliding Window**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{31}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite Pattern**: [[LC 3 Longest Substring Without Repeating Characters]]
- 🎯 **Current Anchor**: [[LC 424 Longest Repeating Character Replacement]]
- ➔ **Next Boss Variation**: [[LC 1004 Max Consecutive Ones III]]

---

## 💻 Optimal C++20 Implementation

```cpp
/**
 * Problem 016: Longest Repeating Character Replacement
 * Link: https://leetcode.com/problems/longest-repeating-character-replacement/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Amazon, Meta, Google, Microsoft, Apple, Uber
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 * Constraints:
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *     Both r and l pointers traverse the string at most once.
 * - Space Complexity: O(1)
 *     Uses a fixed-size frequency array of 26 integers.
 *
 * -------------------------------------------------------------
 * Pattern / Invariant:
 * - Dynamic Sliding Window with Frequency Invariant:
 *     (window_len - max_freq) <= k
 * - Why max_freq does not need to decrement on left shrink:
 *     A smaller max_freq can only produce a window smaller than our historical
 *     best. Only a new peak max_freq can expand our maximum window.
 * -------------------------------------------------------------
 15Ot26'1
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal Dynamic Sliding Window Solution
    // Time: O(N), Space: O(1)
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int l = 0, max_freq = 0, max_len = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r] - 'A']++;
            max_freq = max(max_freq, count[s[r] - 'A']);

            while ((r - l + 1) - max_freq > k) {
                count[s[l] - 'A']--;
                l++;
            }
            max_len = max(max_len, r - l + 1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case with k = 2
    string s1 = "ABAB";
    int k1 = 2;
    int res1 = sol.characterReplacement(s1, k1);
    cout << "Test 1 [\"ABAB\", k=2] -> Got: " << res1 << " (Expected: 4) -> "
         << (res1 == 4 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Standard case with k = 1
    string s2 = "AABABBA";
    int k2 = 1;
    int res2 = sol.characterReplacement(s2, k2);
    cout << "Test 2 [\"AABABBA\", k=1] -> Got: " << res2 << " (Expected: 4) -> "
         << (res2 == 4 ? "PASSED" : "FAILED") << "\n";

    // Test 3: k = 0 (no replacement allowed)
    string s3 = "ABBB";
    int k3 = 0;
    int res3 = sol.characterReplacement(s3, k3);
    cout << "Test 3 [\"ABBB\", k=0] -> Got: " << res3 << " (Expected: 3) -> "
         << (res3 == 3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: All same characters
    string s4 = "AAAA";
    int k4 = 2;
    int res4 = sol.characterReplacement(s4, k4);
    cout << "Test 4 [\"AAAA\", k=2] -> Got: " << res4 << " (Expected: 4) -> "
         << (res4 == 4 ? "PASSED" : "FAILED") << "\n";

    return 0;
}

```
