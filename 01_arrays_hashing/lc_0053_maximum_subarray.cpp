/**
 * Problem 009: Maximum Subarray
 * Link: https://leetcode.com/problems/maximum-subarray/
 * Topic: 01_arrays_hashing
 * Companies: Amazon, Microsoft, Apple, Google, Meta, Bloomberg, Cisco
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an integer array nums, find the subarray with the largest sum,
 * and return its sum.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 * Follow-up:
 * If you have figured out the O(n) solution, try coding another solution
 * using the divide and conquer approach, which is more subtle.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Kadane's Algorithm - User's Optimal Solution):
 *     - Time Complexity: O(N)
 *       Single linear scan of the array.
 *     - Space Complexity: O(1)
 *       Only tracks running sum and global maximum.
 *
 * - Approach 2 (Kadane's with Subarray Reconstruction - FAANG Follow-up):
 *     - Time Complexity: O(N)
 *     - Space Complexity: O(1)
 *       Records start and end indices of the maximum sum subarray.
 *
 * - Approach 3 (Divide and Conquer - Classic Tree Reduction):
 *     - Time Complexity: O(N log N)
 *       T(N) = 2*T(N/2) + O(N) crossing sum.
 *     - Space Complexity: O(log N) recursion call stack.
 *
 * Pattern / Trigger:
 * - "Maximum sum contiguous subarray" -> Kadane's Algorithm:
 *   Add current element to running sum; update global max;
 *   if running sum becomes negative, reset sum = 0 (abandon past baggage).
 *
 * Critical Edge Cases:
 * - All negative numbers: nums = [-5, -1, -3] -> must return -1 (NOT 0).
 *   (Crucial: updating global max BEFORE resetting sum to 0 ensures this works!)
 * - Single element: nums = [-1] -> -1; nums = [5] -> 5.
 * - Array with all positive numbers: nums = [1, 2, 3] -> 6.
 * - Alternating signs: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4] -> 6.
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Kadane's Algorithm (User's Optimal Solution)
    // Time: O(N), Space: O(1)
    int maxSubArray(const vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            maxi = max(maxi, sum);

            // If running sum drops below 0, it contributes negatively to future subarrays -> reset
            if (sum < 0) {
                sum = 0;
            }
        }

        return maxi;
    }

    // Approach 2: Kadane's with Subarray Index Reconstruction (MNC Follow-up)
    // Returns: {max_sum, start_index, end_index}
    // Time: O(N), Space: O(1)
    tuple<int, int, int> maxSubArrayWithIndices(const vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int start = 0, ans_start = 0, ans_end = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (sum == 0) {
                start = i; // Potential new subarray start
            }

            sum += nums[i];

            if (sum > maxi) {
                maxi = sum;
                ans_start = start;
                ans_end = i;
            }

            if (sum < 0) {
                sum = 0;
            }
        }

        return {maxi, ans_start, ans_end};
    }

    // Approach 3: Divide and Conquer (Follow-up)
    // Time: O(N log N), Space: O(log N)
    int maxCrossingSum(const vector<int>& nums, int low, int mid, int high) {
        int left_sum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= low; --i) {
            sum += nums[i];
            left_sum = max(left_sum, sum);
        }

        int right_sum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= high; ++i) {
            sum += nums[i];
            right_sum = max(right_sum, sum);
        }

        return left_sum + right_sum;
    }

    int maxSubArrayDCHelper(const vector<int>& nums, int low, int high) {
        if (low == high) return nums[low];

        int mid = low + (high - low) / 2;

        int left_max = maxSubArrayDCHelper(nums, low, mid);
        int right_max = maxSubArrayDCHelper(nums, mid + 1, high);
        int cross_max = maxCrossingSum(nums, low, mid, high);

        return max({left_max, right_max, cross_max});
    }

    int maxSubArrayDivideAndConquer(const vector<int>& nums) {
        return maxSubArrayDCHelper(nums, 0, nums.size() - 1);
    }
};

int main() {
    Solution sol;

    // Test 1: Standard mixed array
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int expected1 = 6;
    cout << "Test 1 [-2, 1, -3, 4, -1, 2, 1, -5, 4] -> Expected: " << expected1
         << " | Got: " << sol.maxSubArray(nums1)
         << " -> " << (sol.maxSubArray(nums1) == expected1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: All negative numbers (Crucial edge case!)
    vector<int> nums2 = {-3, -2, -5, -1, -4};
    int expected2 = -1;
    cout << "Test 2 [-3, -2, -5, -1, -4] (All Negatives) -> Expected: " << expected2
         << " | Got: " << sol.maxSubArray(nums2)
         << " -> " << (sol.maxSubArray(nums2) == expected2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Single element
    vector<int> nums3 = {-10};
    int expected3 = -10;
    cout << "Test 3 [-10] -> Expected: " << expected3
         << " | Got: " << sol.maxSubArray(nums3)
         << " -> " << (sol.maxSubArray(nums3) == expected3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: All positive numbers
    vector<int> nums4 = {5, 4, 1, 7, 8};
    int expected4 = 25;
    cout << "Test 4 [5, 4, 1, 7, 8] -> Expected: " << expected4
         << " | Got: " << sol.maxSubArray(nums4)
         << " -> " << (sol.maxSubArray(nums4) == expected4 ? "PASSED" : "FAILED") << "\n";

    // Test 5: Subarray Index Reconstruction check
    auto [max_sum, start_idx, end_idx] = sol.maxSubArrayWithIndices(nums1);
    cout << "Test 5 Reconstruction: Subarray from index " << start_idx << " to " << end_idx
         << " gives sum " << max_sum
         << " -> " << (max_sum == 6 && start_idx == 3 && end_idx == 6 ? "PASSED" : "FAILED") << "\n";

    // Test 6: Verify Divide and Conquer matches Kadane's
    cout << "Test 6 Divide and Conquer: "
         << (sol.maxSubArrayDivideAndConquer(nums1) == expected1 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
