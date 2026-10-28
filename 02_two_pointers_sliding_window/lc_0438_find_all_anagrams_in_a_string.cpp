/**
 * ============================================================================
 * Problem: LC 438 - Find All Anagrams in a String
 * Difficulty: Medium
 * Pattern: Fixed-Size Sliding Window / Frequency Vector Match
 * Target MNCs: Meta, Amazon, Microsoft, Google, Apple
 * 
 * Approaches Included:
 *   1. Explicit Two Pointers (User's verified l & r sliding window)
 *   2. Canonical 1-Loop Sliding Window (Interview standard: i & i - m)
 *   3. Ultra-Optimal O(1) Vector Overhead (Matches scalar counter 0..26)
 * 
 * Complexity:
 *   - Time:  O(N) where N = s.length()
 *   - Space: O(1) auxiliary space (26-int fixed arrays)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// ============================================================================
// Approach 1: Explicit Two Pointers (l & r) - User's Verified Solution
// Time: O(26 * N) = O(N) | Space: O(1)
// ============================================================================
class SolutionTwoPointers {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s1(26, 0), p1(26, 0);
        vector<int> ans;

        for (int i = 0; i < m; i++) {
            s1[s[i] - 'a']++;
            p1[p[i] - 'a']++;
        }

        int l = 0, r = m - 1;
        while (r < n) {
            if (s1 == p1) {
                ans.push_back(l);
            }
            // 1. Evict left character
            s1[s[l++] - 'a']--;

            // 2. Expand right boundary
            r++;
            if (r < n) {
                s1[s[r] - 'a']++;
            }
        }
        return ans;
    }
};

// ============================================================================
// Approach 2: Canonical 1-Loop Sliding Window (Interview Favorite)
// Eliminates separate l & r variables: i is incoming, i - m is outgoing.
// Time: O(26 * N) = O(N) | Space: O(1)
// ============================================================================
class SolutionCanonical {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s_count(26, 0), p_count(26, 0);
        vector<int> ans;

        // Seed initial window of size m
        for (int i = 0; i < m; ++i) {
            s_count[s[i] - 'a']++;
            p_count[p[i] - 'a']++;
        }

        if (s_count == p_count) {
            ans.push_back(0);
        }

        // Slide the window 1 position per iteration
        for (int i = m; i < n; ++i) {
            s_count[s[i] - 'a']++;       // Incoming char on right
            s_count[s[i - m] - 'a']--;   // Outgoing char on left

            if (s_count == p_count) {
                ans.push_back(i - m + 1); // Start index of matching window
            }
        }

        return ans;
    }
};

// ============================================================================
// Approach 3: Ultra-Optimal O(1) Match Counter (Zero 26-vector comparisons)
// Tracks scalar `matches` (0 to 26). When matches == 26, window is an anagram.
// Time: Strictly O(N) scalar arithmetic | Space: O(1)
// ============================================================================
class SolutionMatchesCounter {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s_count(26, 0), p_count(26, 0);
        vector<int> ans;

        for (int i = 0; i < m; ++i) {
            s_count[s[i] - 'a']++;
            p_count[p[i] - 'a']++;
        }

        int matches = 0;
        for (int c = 0; c < 26; ++c) {
            if (s_count[c] == p_count[c]) matches++;
        }

        if (matches == 26) {
            ans.push_back(0);
        }

        for (int i = m; i < n; ++i) {
            int in_char = s[i] - 'a';
            int out_char = s[i - m] - 'a';

            if (in_char == out_char) {
                // Char entering is same as char leaving; match state unchanged
                if (matches == 26) ans.push_back(i - m + 1);
                continue;
            }

            // 1. Process incoming character
            s_count[in_char]++;
            if (s_count[in_char] == p_count[in_char]) {
                matches++;
            } else if (s_count[in_char] == p_count[in_char] + 1) {
                matches--;
            }

            // 2. Process outgoing character
            s_count[out_char]--;
            if (s_count[out_char] == p_count[out_char]) {
                matches++;
            } else if (s_count[out_char] == p_count[out_char] - 1) {
                matches--;
            }

            if (matches == 26) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};

// ============================================================================
// Verification Test Suite
// ============================================================================
int main() {
    SolutionTwoPointers s1;
    SolutionCanonical s2;
    SolutionMatchesCounter s3;

    auto run_all_tests = [&](const string& name, auto& solver) {
        cout << "Testing " << name << "..." << endl;

        // Test 1: Standard example
        assert((solver.findAnagrams("cbaebabacd", "abc") == vector<int>{0, 6}));

        // Test 2: Overlapping matches
        assert((solver.findAnagrams("abab", "ab") == vector<int>{0, 1, 2}));

        // Test 3: s shorter than p
        assert((solver.findAnagrams("a", "ab") == vector<int>{}));

        // Test 4: Complete identical strings
        assert((solver.findAnagrams("anagram", "anagram") == vector<int>{0}));

        // Test 5: No matching anagrams
        assert((solver.findAnagrams("hello", "world") == vector<int>{}));

        cout << "  ✅ Passed all 5 test scenarios!" << endl;
    };

    run_all_tests("Approach 1 (Two Pointers)", s1);
    run_all_tests("Approach 2 (Canonical 1-Loop)", s2);
    run_all_tests("Approach 3 (Matches Counter)", s3);

    cout << "\n🎉 ALL 3 ALGORITHMIC APPROACHES VERIFIED CORRECT!" << endl;
    return 0;
}
