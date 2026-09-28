/**
 * Problem: LC 1614 - Maximum Nesting Depth of the Parentheses
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 * Date: 2026-09-28 (LeetCode Problem of the Day)
 * Topic: Stack / Simulation
 * Difficulty: Easy
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given a valid parentheses string (VPS) represented as string s, return the
 * nesting depth of s.
 *
 * A string is a valid parentheses string if it is empty, or can be written as
 * AB (A concatenated with B), or (A) where A is a VPS.
 * The nesting depth is the maximum number of nested parentheses.
 *
 * Constraints:
 * 1 <= s.length <= 100
 * s consists of digits 0-9 and characters '+', '-', '*', '/', '(', and ')'.
 * It is guaranteed that parentheses expression s is a VPS.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N) — Single pass over string s of length N.
 * - Space Complexity:
 *     - Using Stack: O(N) in worst case (e.g. "((((...))))").
 *     - Counter-only (Optimal): O(1) auxiliary space (integer counter only).
 *
 * Pattern / Trigger:
 * - Valid Parentheses depth tracking -> Increment on '(', update max, decrement on ')'.
 *
 * Critical Edge Cases:
 * - String with no parentheses (e.g., "1"): depth is 0.
 * - Single nested pair: "(1+(2*3)+((8)/4))+1": depth is 3.
 * - Flat consecutive pairs "()()": depth is 1.
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    // Approach 1: Stack Simulation + Counter (User Solution)
    int maxDepth(string s) {
        stack<char> st;
        int maxi = 0, counter = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(s[i]);
                counter += 1;
                maxi = max(maxi, counter);
            } else if (s[i] == ')') {
                st.pop();
                counter -= 1;
            }
        }
        return maxi;
    }

    // Approach 2: O(1) Space Counter (Optimal Follow-Up)
    int maxDepthOptimal(const string& s) {
        int max_depth = 0;
        int current_depth = 0;
        for (char c : s) {
            if (c == '(') {
                current_depth++;
                max_depth = max(max_depth, current_depth);
            } else if (c == ')') {
                current_depth--;
            }
        }
        return max_depth;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard nested expression
    string s1 = "(1+(2*3)+((8)/4))+1";
    int res1 = sol.maxDepth(s1);
    cout << "Test 1: " << res1 << " (Expected: 3) -> "
         << (res1 == 3 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Sequential non-nested groups
    string s2 = "(1)+((2))+(((3)))";
    int res2 = sol.maxDepth(s2);
    cout << "Test 2: " << res2 << " (Expected: 3) -> "
         << (res2 == 3 ? "PASSED" : "FAILED") << "\n";

    // Test 3: No parentheses
    string s3 = "1+2*3";
    int res3 = sol.maxDepth(s3);
    cout << "Test 3: " << res3 << " (Expected: 0) -> "
         << (res3 == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Flat parentheses
    string s4 = "()()()";
    int res4 = sol.maxDepth(s4);
    cout << "Test 4: " << res4 << " (Expected: 1) -> "
         << (res4 == 1 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
