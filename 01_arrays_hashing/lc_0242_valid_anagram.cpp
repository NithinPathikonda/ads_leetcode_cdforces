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
