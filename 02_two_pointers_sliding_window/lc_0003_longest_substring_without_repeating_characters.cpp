/**
 * Problem 015: Longest Substring Without Repeating Characters
 * Link:
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Amazon, Meta, Microsoft, Google, Apple, Bloomberg, Uber
 * Difficulty: Medium / FAANG Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given a string s, find the length of the longest substring without repeating
 * characters.
 *
 * Constraints:
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Sliding Window with Map Erase - User's Solution):
 *     - Time Complexity: O(2N) = O(N)
 *       Each character is visited at most twice (once by r, once by l).
 *     - Space Complexity: O(min(N, Sigma)) where Sigma is the alphabet size.
 *
 * - Approach 2 (Direct-Jump Sliding Window with 128-Array - Optimal FAANG
 * 1-Pass):
 *     - Time Complexity: O(N)
 *       The right pointer advances strictly once. When a duplicate is found,
 *       the left pointer jumps directly past the previous occurrence in O(1):
 *       l = max(l, last_seen[s[r]] + 1).
 *     - Space Complexity: O(1) auxiliary space (fixed 128-element array for
 * ASCII).
 *
 * Pattern / Trigger:
 * - "Longest substring without duplicates" -> Dynamic Sliding Window [l, r]
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // Approach 1: Sliding Window with Map Erase (User's Solution)
  // Time: O(2N) = O(N), Space: O(min(N, Sigma))
  int lengthOfLongestSubstring(string s) {
    int l = 0, r = 0, n = s.size(), maxi = 0;
    unordered_map<char, int> mpp;

    while (r < n) {
      if (mpp.find(s[r]) == mpp.end()) {
        maxi = max(maxi, r - l + 1);
        mpp[s[r]]++;
        r++;
      } else {
        mpp.erase(s[l++]);
      }
    }

    return maxi;
  }

  // Approach 2: Direct-Jump Sliding Window with Fixed ASCII Array (Optimal
  // 1-Pass) Time: O(N), Space: O(1)
  int lengthOfLongestSubstringOptimal(const string &s) {
    int n = s.size();
    int max_len = 0;
    // Stores last seen index of each ASCII character (initialized to -1)
    vector<int> last_seen(128, -1);

    int l = 0;
    for (int r = 0; r < n; ++r) {
      unsigned char c = s[r];

      // If character was seen inside the current window [l, r], jump l past it
      if (last_seen[c] >= l) {
        l = last_seen[c] + 1;
      }

      last_seen[c] = r;
      max_len = max(max_len, r - l + 1);
    }

    return max_len;
  }
};

int main() {
  Solution sol;

  // Test 1: Standard case with repeating characters
  string s1 = "abcabcbb";
  int exp1 = 3;
  cout << "Test 1 \"abcabcbb\" -> User: " << sol.lengthOfLongestSubstring(s1)
       << " | Optimal: " << sol.lengthOfLongestSubstringOptimal(s1) << " -> "
       << (sol.lengthOfLongestSubstring(s1) == exp1 &&
                   sol.lengthOfLongestSubstringOptimal(s1) == exp1
               ? "PASSED"
               : "FAILED")
       << "\n";

  // Test 2: All identical characters
  string s2 = "bbbbb";
  int exp2 = 1;
  cout << "Test 2 \"bbbbb\" -> User: " << sol.lengthOfLongestSubstring(s2)
       << " | Optimal: " << sol.lengthOfLongestSubstringOptimal(s2) << " -> "
       << (sol.lengthOfLongestSubstring(s2) == exp2 &&
                   sol.lengthOfLongestSubstringOptimal(s2) == exp2
               ? "PASSED"
               : "FAILED")
       << "\n";

  // Test 3: Repeating in middle
  string s3 = "pwwkew";
  int exp3 = 3;
  cout << "Test 3 \"pwwkew\" -> User: " << sol.lengthOfLongestSubstring(s3)
       << " | Optimal: " << sol.lengthOfLongestSubstringOptimal(s3) << " -> "
       << (sol.lengthOfLongestSubstring(s3) == exp3 &&
                   sol.lengthOfLongestSubstringOptimal(s3) == exp3
               ? "PASSED"
               : "FAILED")
       << "\n";

  // Test 4: Empty string
  string s4 = "";
  int exp4 = 0;
  cout << "Test 4 \"\" -> User: " << sol.lengthOfLongestSubstring(s4)
       << " | Optimal: " << sol.lengthOfLongestSubstringOptimal(s4) << " -> "
       << (sol.lengthOfLongestSubstring(s4) == exp4 &&
                   sol.lengthOfLongestSubstringOptimal(s4) == exp4
               ? "PASSED"
               : "FAILED")
       << "\n";

  // Test 5: String with spaces and symbols
  string s5 = "a b!a b!";
  int exp5 = 4; // " b!a" or "b!a "
  cout << "Test 5 \"a b!a b!\" -> User: " << sol.lengthOfLongestSubstring(s5)
       << " | Optimal: " << sol.lengthOfLongestSubstringOptimal(s5) << " -> "
       << (sol.lengthOfLongestSubstring(s5) == exp5 &&
                   sol.lengthOfLongestSubstringOptimal(s5) == exp5
               ? "PASSED"
               : "FAILED")
       << "\n";

  return 0;
}
