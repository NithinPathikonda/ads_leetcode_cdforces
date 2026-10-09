/**
 * Problem 019: Trapping Rain Water
 * Link: https://leetcode.com/problems/trapping-rain-water/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Google, Meta, Amazon, Apple, Microsoft, Bloomberg, Goldman Sachs
 * Difficulty: Hard / FAANG Crown Jewel Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 * Constraints:
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Prefix Max & Suffix Max Arrays):
 *     - Time Complexity: O(N) (3 linear passes)
 *     - Space Complexity: O(N) (Two auxiliary arrays of size N)
 *     - Intuition: Water at i = min(prefix_max[i], suffix_max[i]) - height[i]
 *
 * - Approach 2 (Two Pointers with Running Extremes - User's Optimal Solution):
 *     - Time Complexity: O(N) (Single pass, pointers converge)
 *     - Space Complexity: O(1) auxiliary space
 *     - Intuition: Since water is bottlenecked by the shorter wall, if
 *       left_max <= right_max, left is guaranteed to be the bottleneck.
 *       Process left and advance l++; else process right and advance r--.
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Prefix Max and Suffix Max Arrays
    // Time: O(N), Space: O(N)
    int trapPrefixSuffix(const vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> prefix_max(n, 0), suffix_max(n, 0);

        prefix_max[0] = height[0];
        for (int i = 1; i < n; ++i) {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }

        suffix_max[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }

        int total_water = 0;
        for (int i = 0; i < n; ++i) {
            total_water += min(prefix_max[i], suffix_max[i]) - height[i];
        }

        return total_water;
    }

    // Approach 2: Optimal Two Pointers with Running Extremes
    // Time: O(N), Space: O(1)
    int trap(const vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int l = 0, r = n - 1;
        int left_max = 0, right_max = 0;
        int total_water = 0;

        while (l < r) {
            left_max = max(left_max, height[l]);
            right_max = max(right_max, height[r]);

            if (left_max <= right_max) {
                total_water += left_max - height[l];
                l++;
            } else {
                total_water += right_max - height[r];
                r--;
            }
        }

        return total_water;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard LeetCode elevation map
    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int res1 = sol.trap(h1);
    cout << "Test 1 [0,1,0,2,1,0,1,3,2,1,2,1] -> Got: " << res1
         << " (Expected: 6) -> " << (res1 == 6 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Steeper valley
    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    int res2 = sol.trap(h2);
    cout << "Test 2 [4,2,0,3,2,5] -> Got: " << res2
         << " (Expected: 9) -> " << (res2 == 9 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Flat / No water can be trapped
    vector<int> h3 = {3, 3, 3};
    int res3 = sol.trap(h3);
    cout << "Test 3 [3,3,3] -> Got: " << res3
         << " (Expected: 0) -> " << (res3 == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Monotonically decreasing then increasing (V-shape)
    vector<int> h4 = {3, 0, 2};
    int res4 = sol.trap(h4);
    cout << "Test 4 [3,0,2] -> Got: " << res4
         << " (Expected: 2) -> " << (res4 == 2 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
