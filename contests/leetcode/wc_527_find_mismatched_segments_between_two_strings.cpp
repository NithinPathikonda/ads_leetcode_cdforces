/**
 * ============================================================================
 * Contest: LeetCode Weekly Contest 527
 * Problem: Find Mismatched Segments Between Two Strings
 * URL: https://leetcode.com/contest/weekly-contest-527/problems/find-mismatched-segments-between-two-strings/
 * Difficulty: Medium / Easy-Medium
 * Pattern: String Traversal / Two Pointers (Contiguous Segment Grouping)
 * 
 * Approaches Included:
 *   1. SolutionLive: User's Live Contest Submission (XOR match detection + string buffer accumulation)
 *   2. SolutionOptimized: Production Two-Pointer Sliding Window (Index tracking + single-allocation slicing)
 * 
 * Complexity:
 *   - Time:  O(N) — single pass through strings of length N
 *   - Space: O(N) — for returning the resultant mismatched segment substrings
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

// ============================================================================
// Approach 1: User's Live Contest Submission
// Uses bitwise XOR (s1[i] ^ s2[i]) to detect character mismatch and accumulates
// into string buffers t1, t2 with trailing flush.
// Time: O(N) | Space: O(N)
// ============================================================================
class SolutionLive {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans; 
        vector<string> temp;
        string t1 = "", t2 = "";
        int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (s1[i] ^ s2[i]) {
                t1 += s1[i];
                t2 += s2[i];
            } else if ((s1[i] ^ s2[i]) == 0 && i != 0) {
                temp = {};
                if (t1.size()) {
                    temp.push_back(t1); 
                    temp.push_back(t2);
                    t1 = ""; t2 = "";
                    ans.push_back(temp);
                }
            }
        }
        if (t1.size()) {
            temp = {};
            temp.push_back(t1); 
            temp.push_back(t2);
            t1 = ""; t2 = "";
            ans.push_back(temp);
        }
        return ans;
    }
};

// ============================================================================
// Approach 2: Optimal Two-Pointer Sliding Window
// Tracks the start index of any mismatched block. Slices substrings only once
// upon segment termination, eliminating incremental buffer reallocations.
// Time: O(N) | Space: O(N)
// ============================================================================
class SolutionOptimized {
public:
    vector<vector<string>> findMismatchedSegments(const string& s1, const string& s2) {
        vector<vector<string>> ans;
        int n = s1.size();
        int start = -1;

        // Iterate up to n to automatically flush trailing segment without redundant post-loop code
        for (int i = 0; i <= n; i++) {
            bool is_mismatch = (i < n && s1[i] != s2[i]);

            if (is_mismatch) {
                if (start == -1) start = i; // Mark start of contiguous mismatch
            } else if (start != -1) {
                // Segment ended at i - 1; slice substring pair directly
                ans.push_back({s1.substr(start, i - start), s2.substr(start, i - start)});
                start = -1; // Reset marker
            }
        }

        return ans;
    }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
    SolutionLive liveSolver;
    SolutionOptimized optSolver;

    // Helper lambda to run both solvers against expected output
    auto testBoth = [&](const string& s1, const string& s2, const vector<vector<string>>& expected) {
        assert(liveSolver.findMismatchedSegments(s1, s2) == expected);
        assert(optSolver.findMismatchedSegments(s1, s2) == expected);
    };

    // Test 1: Disjoint mismatched segments in the interior
    // "abcde", "abxye" -> mismatch "cd" vs "xy"
    testBoth("abcde", "abxye", {{"cd", "xy"}});

    // Test 2: Multiple separate mismatched segments
    // "aXbYcZ", "aAbBcC" -> mismatches: "X" vs "A", "Y" vs "B", "Z" vs "C"
    testBoth("aXbYcZ", "aAbBcC", {{"X", "A"}, {"Y", "B"}, {"Z", "C"}});

    // Test 3: Mismatch at index 0
    // "xyzabc", "123abc" -> mismatch "xyz" vs "123"
    testBoth("xyzabc", "123abc", {{"xyz", "123"}});

    // Test 4: Mismatch at the trailing end (tests post-loop flush)
    // "abcxyz", "abc123" -> mismatch "xyz" vs "123"
    testBoth("abcxyz", "abc123", {{"xyz", "123"}});

    // Test 5: Entire string is completely mismatched
    // "aaaa", "bbbb" -> mismatch "aaaa" vs "bbbb"
    testBoth("aaaa", "bbbb", {{"aaaa", "bbbb"}});

    // Test 6: Exactly identical strings (no mismatches)
    testBoth("leetcode", "leetcode", {});

    // Test 7: Alternating mismatch characters
    testBoth("abab", "baba", {{"abab", "baba"}});

    // Test 8: Single character string (match)
    testBoth("a", "a", {});

    // Test 9: Single character string (mismatch)
    testBoth("a", "b", {{"a", "b"}});

    cout << "✅ All 9 test scenarios passed for both SolutionLive and SolutionOptimized!" << endl;
    return 0;
}
