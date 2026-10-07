/**
 * Problem 014: Container With Most Water
 * Link: https://leetcode.com/problems/container-with-most-water/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Google, Meta, Amazon, Apple, Microsoft, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * You are given an integer array height of length n. There are n vertical lines
 * drawn such that the two endpoints of the i-th line are (i, 0) and (i, height[i]).
 *
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 * Notice that you may not slant the container.
 *
 * Constraints:
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Brute Force Baseline):
 *     - Time Complexity: O(N^2)
 *       Check all pairs (i, j) and compute area.
 *     - Space Complexity: O(1)
 *
 * - Approach 2 (Greedy Two Pointers - User's Optimal Solution):
 *     - Time Complexity: O(N)
 *       Pointers start at opposite ends and move toward each other.
 *       Each element is visited at most once.
 *     - Space Complexity: O(1)
 *       Uses only constant extra variables.
 *
 * -------------------------------------------------------------
 * 🌟 The Greedy Proof (Why we always move the shorter line):
 * -------------------------------------------------------------
 * Area = min(height[i], height[j]) * (j - i).
 *
 * - The area is strictly bottlenecked by the SHORTER line.
 * - If we keep the shorter line and move the taller line inward:
 *     1. Width (j - i) ALWAYS decreases by 1.
 *     2. The height can NEVER exceed the shorter line.
 *     => Therefore, moving the taller line is GUARANTEED to produce a smaller or equal area!
 * - The ONLY chance of finding a strictly greater area is to discard the shorter
 *   line and move inward in search of a taller wall!
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Brute Force Baseline (Interview discussion)
    // Time: O(N^2), Space: O(1)
    int maxAreaBruteForce(const vector<int>& height) {
        int max_water = 0;
        int n = height.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int area = min(height[i], height[j]) * (j - i);
                max_water = max(max_water, area);
            }
        }
        return max_water;
    }

    // Approach 2: Greedy Two Pointers (User's Optimal Solution)
    // Time: O(N), Space: O(1)
    int maxArea(const vector<int>& height) {
        int i = 0;
        int j = static_cast<int>(height.size()) - 1;
        int max_water = 0;

        while (i < j) {
            int area = min(height[i], height[j]) * (j - i);
            max_water = max(max_water, area);

            // Move the bottleneck (shorter line) inward
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max_water;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int expected1 = 49;
    cout << "Test 1 [1, 8, 6, 2, 5, 4, 8, 3, 7] -> Expected: " << expected1
         << " | Got: " << sol.maxArea(h1)
         << " -> " << (sol.maxArea(h1) == expected1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Minimal array of size 2
    vector<int> h2 = {1, 1};
    int expected2 = 1;
    cout << "Test 2 [1, 1] -> Expected: " << expected2
         << " | Got: " << sol.maxArea(h2)
         << " -> " << (sol.maxArea(h2) == expected2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Strictly decreasing heights
    vector<int> h3 = {5, 4, 3, 2, 1};
    int expected3 = 6; // Pair (5, 2) at width 3 -> min(5,2)*3 = 6 or pair (4, 2) at width 2 = 4
    cout << "Test 3 [5, 4, 3, 2, 1] -> Expected: " << expected3
         << " | Got: " << sol.maxArea(h3)
         << " -> " << (sol.maxArea(h3) == expected3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Flat plateau with large peaks
    vector<int> h4 = {2, 3, 4, 5, 18, 17, 6};
    int expected4 = 17; // Pair (18, 17) at distance 1 gives 17
    cout << "Test 4 [2, 3, 4, 5, 18, 17, 6] -> Expected: " << expected4
         << " | Got: " << sol.maxArea(h4)
         << " -> " << (sol.maxArea(h4) == expected4 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
