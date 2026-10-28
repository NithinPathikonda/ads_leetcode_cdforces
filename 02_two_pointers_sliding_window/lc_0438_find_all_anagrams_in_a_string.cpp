/**
 * ============================================================================
 * Problem: LC 438 - Find All Anagrams in a String
 * Difficulty: Medium
 * Pattern: Fixed-Size Sliding Window / Frequency Vector Match
 * Target MNCs: Meta, Amazon, Microsoft, Google, Apple
 * 
 * Complexity:
 *   - Time:  O(N * 26) = O(N) where N = s.length()
 *   - Space: O(1) auxiliary space (two 26-int frequency vectors)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) {
            return {};
        }

        vector<int> s1(26, 0), p1(26, 0);
        vector<int> ans;

        // Initialize counts for the first window of length m
        for (int i = 0; i < m; i++) {
            s1[s[i] - 'a']++;
            p1[p[i] - 'a']++;
        }

        int l = 0, r = m - 1;
        while (r < n) {
            if (s1 == p1) {
                ans.push_back(l);
            }
            // Shrink window from the left
            s1[s[l++] - 'a']--;

            // Advance right pointer and expand window
            r++;
            if (r < n) {
                s1[s[r] - 'a']++;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;

    // Test Case 1: Standard example
    {
        string s = "cbaebabacd";
        string p = "abc";
        vector<int> expected = {0, 6};
        assert(solver.findAnagrams(s, p) == expected);
        cout << "✅ Test Case 1 Passed: [cbaebabacd, abc] -> [0, 6]" << endl;
    }

    // Test Case 2: Overlapping anagrams
    {
        string s = "abab";
        string p = "ab";
        vector<int> expected = {0, 1, 2};
        assert(solver.findAnagrams(s, p) == expected);
        cout << "✅ Test Case 2 Passed: [abab, ab] -> [0, 1, 2]" << endl;
    }

    // Test Case 3: s is shorter than p
    {
        string s = "a";
        string p = "ab";
        vector<int> expected = {};
        assert(solver.findAnagrams(s, p) == expected);
        cout << "✅ Test Case 3 Passed: [a, ab] -> []" << endl;
    }

    // Test Case 4: Identical strings
    {
        string s = "anagram";
        string p = "anagram";
        vector<int> expected = {0};
        assert(solver.findAnagrams(s, p) == expected);
        cout << "✅ Test Case 4 Passed: [anagram, anagram] -> [0]" << endl;
    }

    cout << "\n🎉 ALL TEST CASES PASSED FOR LC 438!" << endl;
    return 0;
}
