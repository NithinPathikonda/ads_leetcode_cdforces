/**
 * Problem 017: Permutation in String
 * Link: https://leetcode.com/problems/permutation-in-string/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Meta, Microsoft, Amazon, Google, Apple, Uber
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring
 * of s2.
 *
 * Constraints:
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Vector Equality Comparison):
 *     - Time Complexity: O(26 * N) = O(N)
 *       Vector comparison count1 == count2 takes 26 operations per slide.
 *     - Space Complexity: O(1) auxiliary space (26-size vectors).
 *
 * - Approach 2 (Matches Invariant Counter - Optimal FAANG SDE-III):
 *     - Time Complexity: O(N) strictly
 *       Maintains an integer `matches` (0 to 26). When sliding the window, only
 *       2 characters change (incoming and outgoing). Each updates `matches` in
 *       O(1) arithmetic operations without scanning the 26 elements.
 *     - Space Complexity: O(1) auxiliary space.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Fixed-Size Sliding Window with Direct Vector Comparison
    // Time: O(26 * N), Space: O(1)
    bool checkInclusionVectorCompare(const string& s1, const string& s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        if (count1 == count2) return true;

        for (int i = n1; i < n2; ++i) {
            count2[s2[i] - 'a']++;
            count2[s2[i - n1] - 'a']--;

            if (count1 == count2) return true;
        }

        return false;
    }

    // Approach 2: Optimal Match-Count Tracking (Strictly O(N))
    // Time: O(N), Space: O(1)
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;

        vector<int> count1(26, 0), count2(26, 0);

        // 1. Initialize character counts for s1 and first window of s2
        for (int i = 0; i < n1; ++i) {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        // 2. Count initial matching characters (out of 26)
        int matches = 0;
        for (int i = 0; i < 26; ++i) {
            if (count1[i] == count2[i]) matches++;
        }

        // 3. Slide the fixed window in strictly O(1) per step
        for (int i = n1; i < n2; ++i) {
            if (matches == 26) return true;

            int in = s2[i] - 'a';
            int out = s2[i - n1] - 'a';

            // Incoming character processing
            if (count1[in] == count2[in]) matches--;
            count2[in]++;
            if (count1[in] == count2[in]) matches++;

            // Outgoing character processing
            if (count1[out] == count2[out]) matches--;
            count2[out]--;
            if (count1[out] == count2[out]) matches++;
        }

        return matches == 26;
    }
};

int main() {
    Solution sol;

    // Test 1: Permutation exists ("ba" in "eidbaooo")
    string s1_1 = "ab", s2_1 = "eidbaooo";
    bool res1 = sol.checkInclusion(s1_1, s2_1);
    cout << "Test 1 [\"ab\", \"eidbaooo\"] -> Got: " << (res1 ? "true" : "false")
         << " (Expected: true) -> " << (res1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Permutation does not exist
    string s1_2 = "ab", s2_2 = "eidboaoo";
    bool res2 = sol.checkInclusion(s1_2, s2_2);
    cout << "Test 2 [\"ab\", \"eidboaoo\"] -> Got: " << (res2 ? "true" : "false")
         << " (Expected: false) -> " << (!res2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: s1 is longer than s2 (Edge case)
    string s1_3 = "hello", s2_3 = "hi";
    bool res3 = sol.checkInclusion(s1_3, s2_3);
    cout << "Test 3 [\"hello\", \"hi\"] -> Got: " << (res3 ? "true" : "false")
         << " (Expected: false) -> " << (!res3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Single identical character
    string s1_4 = "a", s2_4 = "a";
    bool res4 = sol.checkInclusion(s1_4, s2_4);
    cout << "Test 4 [\"a\", \"a\"] -> Got: " << (res4 ? "true" : "false")
         << " (Expected: true) -> " << (res4 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
