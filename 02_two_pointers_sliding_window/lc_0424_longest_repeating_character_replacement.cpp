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
