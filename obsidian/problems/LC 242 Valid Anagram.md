---
title: "LC 242: Valid Anagram"
module: "01 Arrays & Hashing"
concept: "Hash Maps & Sets"
difficulty: "Easy"
complexity: "O(N)"
space_complexity: "O(N)"
companies:
  - Google
  - Amazon
  - Microsoft
type: "problem-card"
tags:
  - problem
  - easy
---

# 🟢 LC 242: Valid Anagram

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[01 Arrays & Hashing]]
> - **Core Concept**: [[Hash Maps & Sets]]
> - **Difficulty**: Easy 🟢
> - **Time Complexity**: $\mathcal{O}(O(N))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Google]], [[Amazon]], [[Microsoft]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Hash Maps & Sets application in `01 Arrays & Hashing`.
> - **Immediate Strategy**: 26-int frequency count comparison in single pass.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 242 Valid Anagram]]

---

## 💻 Optimal C++20 Implementation

```cpp
/**
 * Problem 003: Valid Anagram
 * Link: https://leetcode.com/problems/valid-anagram/
 * Topic: 01_arrays_hashing
 * Companies: Google, Meta, Amazon, Microsoft, Bloomberg, Apple
 * Difficulty: Easy / Core Foundation
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given two strings s and t, return true if t is an anagram of s, and false otherwise.
 * An Anagram is a word or phrase formed by rearranging the letters of a different
 * word or phrase, typically using all the original letters exactly once.
 *
 * Constraints:
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * -------------------------------------------------------------
 *
 * Complexity:
 * - Time Complexity: O(N) — Single pass over strings of length N
 * - Space Complexity: O(1) — 26-element integer frequency array
 *
 * Pattern / Trigger:
 * - Permutation / frequency equivalence -> Single fixed-size frequency array
 *   increment for s, decrement for t, verify all zero.
 *
 * Critical Edge Cases:
 * - Different lengths: Immediate false (s.size() != t.size()).
 * - Duplicate characters in different frequencies: Caught when checking alpha_count != 0.
 * -------------------------------------------------------------
 Revision: 13Ot26'1
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        if (s.size() != t.size()) return false;

        int alpha_count[26] = {0};
        for (size_t i = 0; i < s.size(); ++i) {
            alpha_count[s[i] - 'a']++;
            alpha_count[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (alpha_count[i] != 0) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard valid anagram
    string s1 = "anagram", t1 = "nagaram";
    bool res1 = sol.isAnagram(s1, t1);
    cout << "Test 1: " << (res1 ? "true" : "false") << " (Expected: true) -> "
         << (res1 == true ? "PASSED" : "FAILED") << "\n";

    // Test 2: Invalid anagram (different characters)
    string s2 = "rat", t2 = "car";
    bool res2 = sol.isAnagram(s2, t2);
    cout << "Test 2: " << (res2 ? "true" : "false") << " (Expected: false) -> "
         << (res2 == false ? "PASSED" : "FAILED") << "\n";

    // Test 3: Different lengths
    string s3 = "a", t3 = "ab";
    bool res3 = sol.isAnagram(s3, t3);
    cout << "Test 3: " << (res3 ? "true" : "false") << " (Expected: false) -> "
         << (res3 == false ? "PASSED" : "FAILED") << "\n";

    // Test 4: Same characters, mismatched counts
    string s4 = "aacc", t4 = "ccac";
    bool res4 = sol.isAnagram(s4, t4);
    cout << "Test 4: " << (res4 ? "true" : "false") << " (Expected: false) -> "
         << (res4 == false ? "PASSED" : "FAILED") << "\n";

    return 0;
}

```
