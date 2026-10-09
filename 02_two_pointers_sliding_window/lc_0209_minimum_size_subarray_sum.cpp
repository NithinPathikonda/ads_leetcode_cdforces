/**
 * Problem 018: Minimum Size Subarray Sum
 * Link: https://leetcode.com/problems/minimum-size-subarray-sum/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Google, Meta, Amazon, Microsoft, Bloomberg
 * Difficulty: Medium / Core Dynamic Window Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array of positive integers nums and a positive integer target,
 * return the minimal length of a subarray whose sum is greater than or equal
 * to target. If there is no such subarray, return 0 instead.
 *
 * Constraints:
 * 1 <= target <= 10^9
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^4
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *     The right pointer traverses the array from 0 to N - 1. The left pointer
 *     moves strictly forward, advancing at most N times in total across the
 *     entire algorithm. Hence, each element is visited at most twice.
 * - Space Complexity: O(1)
 *     Uses only a few scalar tracking variables.
 *
 * -------------------------------------------------------------
 * Pattern / Invariant:
 * - Dynamic Sliding Window with Positive Monotonicity:
 *     Since all numbers are positive, expanding `r` strictly INCREASES `sum`,
 *     and shrinking `l` strictly DECREASES `sum`.
 *     1. Expand `r` to accumulate `sum`.
 *     2. Whenever `sum >= target`, record candidate minimal length and shrink
 *        `l` to find the tightest valid window.
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal Dynamic Sliding Window Solution
    // Time: O(N), Space: O(1)
    int minSubArrayLen(int target, const vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        long long sum = 0;
        int mini = INT_MAX;
        bool flag = true;

        while (r < n) {
            sum += nums[r];
            while (sum >= target) {
                flag = false;
                mini = min(mini, r - l + 1);
                sum -= nums[l++];
            }
            r++;
        }

        return flag ? 0 : mini;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {2, 3, 1, 2, 4, 3};
    int target1 = 7;
    int res1 = sol.minSubArrayLen(target1, nums1);
    cout << "Test 1 [target=7, {2,3,1,2,4,3}] -> Got: " << res1
         << " (Expected: 2) -> " << (res1 == 2 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Minimal length is 1
    vector<int> nums2 = {1, 4, 4};
    int target2 = 4;
    int res2 = sol.minSubArrayLen(target2, nums2);
    cout << "Test 2 [target=4, {1,4,4}] -> Got: " << res2
         << " (Expected: 1) -> " << (res2 == 1 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Target unattainable
    vector<int> nums3 = {1, 1, 1, 1, 1, 1, 1, 1};
    int target3 = 11;
    int res3 = sol.minSubArrayLen(target3, nums3);
    cout << "Test 3 [target=11, all 1s] -> Got: " << res3
         << " (Expected: 0) -> " << (res3 == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Single element equal to target
    vector<int> nums4 = {5};
    int target4 = 5;
    int res4 = sol.minSubArrayLen(target4, nums4);
    cout << "Test 4 [target=5, {5}] -> Got: " << res4
         << " (Expected: 1) -> " << (res4 == 1 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
