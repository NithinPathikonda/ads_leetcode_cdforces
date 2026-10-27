---
title: "LC 49: Group Anagrams"
module: "01 Arrays & Hashing"
concept: "Hash Maps & Sets"
difficulty: "Medium"
complexity: "O(N * K)"
space_complexity: "O(N)"
companies:
  - Amazon
  - Meta
  - Apple
type: "problem-card"
tags:
  - problem
  - medium
---

# 🟡 LC 49: Group Anagrams

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[01 Arrays & Hashing]]
> - **Core Concept**: [[Hash Maps & Sets]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(O(N * K))$
> - **Space Complexity**: $\mathcal{O}(O(N))$
> - **Target MNCs**: [[Amazon]], [[Meta]], [[Apple]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: Hash Maps & Sets application in `01 Arrays & Hashing`.
> - **Immediate Strategy**: Sort string or 26-char count signature as canonical hash map key.

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
- 🎯 **Foundational Anchor Pattern**: [[LC 49 Group Anagrams]]

---

## 💻 Optimal C++20 Implementation

```cpp
/**
 * Problem 004: Group Anagrams
 * Link: https://leetcode.com/problems/group-anagrams/
 * Topic: 01_arrays_hashing
 * Companies: Amazon, Meta, Google, Microsoft, Apple, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array of strings strs, group the anagrams together. You can return
 * the answer in any order.
 *
 * Constraints:
 * 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Canonical Key via Sorting - User's Solution):
 *     - Time Complexity: O(N * K log K)
 *       where N is strs.size() and K is the maximum length of a string.
 *       Sorting each string of length K takes O(K log K).
 *     - Space Complexity: O(N * K)
 *       Hash map stores all strings distributed across groups.
 *
 * - Approach 2 (Character Count Signature Key):
 *     - Time Complexity: O(N * K)
 *       Building a 26-char frequency tuple takes O(K), avoiding O(K log K) sort.
 *     - Space Complexity: O(N * K)
 *
 * Pattern / Trigger:
 * - Equivalence grouping -> Hash map mapping canonical representation to vector of original elements.
 *
 * Critical Edge Cases:
 * - Empty string `strs = [""]` -> `[[""]]`
 * - Single element `strs = ["a"]` -> `[["a"]]`
 * - No anagrams exist (all unique) -> each word forms its own singleton group
 * - Multiple identical strings (e.g. `["tea", "tea"]`) -> correctly grouped together
 * -------------------------------------------------------------
 Revision: 13Ot26'1
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Sorted String as Canonical Key (User Solution)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (const auto& it : strs) {
            string sorted_key = it;
            sort(sorted_key.begin(), sorted_key.end());
            mpp[sorted_key].push_back(it);
        }

        vector<vector<string>> ans;
        ans.reserve(mpp.size());
        for (auto& it : mpp) {
            ans.push_back(std::move(it.second));
        }
        return ans;
    }

    // Approach 2: Character Count Signature (O(N * K) Alternative)
    vector<vector<string>> groupAnagramsCountKey(const vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (const auto& s : strs) {
            int count[26] = {0};
            for (char c : s) count[c - 'a']++;

            // Create unique delimiter-separated frequency signature
            string key = "";
            for (int i = 0; i < 26; ++i) {
                key += '#';
                key += to_string(count[i]);
            }
            mpp[key].push_back(s);
        }

        vector<vector<string>> ans;
        ans.reserve(mpp.size());
        for (auto& it : mpp) {
            ans.push_back(std::move(it.second));
        }
        return ans;
    }
};

// Helper function to print grouped anagrams
void printGroups(const vector<vector<string>>& groups) {
    cout << "[\n";
    for (const auto& group : groups) {
        cout << "  [";
        for (size_t i = 0; i < group.size(); ++i) {
            cout << "\"" << group[i] << "\"" << (i + 1 < group.size() ? ", " : "");
        }
        cout << "]\n";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Test 1: Standard multi-group case
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res1 = sol.groupAnagrams(strs1);
    cout << "Test 1 Output:\n";
    printGroups(res1);
    cout << "Test 1 Group Count: " << res1.size() << " (Expected: 3) -> "
         << (res1.size() == 3 ? "PASSED" : "FAILED") << "\n\n";

    // Test 2: Single empty string
    vector<string> strs2 = {""};
    auto res2 = sol.groupAnagrams(strs2);
    cout << "Test 2 Output:\n";
    printGroups(res2);
    cout << "Test 2 Group Count: " << res2.size() << " (Expected: 1) -> "
         << (res2.size() == 1 && res2[0].size() == 1 ? "PASSED" : "FAILED") << "\n\n";

    // Test 3: Single character
    vector<string> strs3 = {"a"};
    auto res3 = sol.groupAnagrams(strs3);
    cout << "Test 3 Output:\n";
    printGroups(res3);
    cout << "Test 3 Group Count: " << res3.size() << " (Expected: 1) -> "
         << (res3.size() == 1 && res3[0][0] == "a" ? "PASSED" : "FAILED") << "\n";

    return 0;
}

```
