/**
 * Problem 021: Subarray Product Less Than K
 * Link: https://leetcode.com/problems/subarray-product-less-than-k/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Amazon, Bloomberg, Meta, Google
 * Difficulty: Medium / Core Dynamic Window Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array of positive integers nums and an integer k, return the number
 * of contiguous subarrays where the product of all the elements in the
 * subarray is strictly less than k.
 *
 * Constraints:
 * 1 <= nums.length <= 3 * 10^4
 * 1 <= nums[i] <= 1000
 * 0 <= k <= 10^6
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *     Each pointer (r and l) traverses the array from 0 to N - 1 at most once.
 *     The inner while loop executes at most N times in total across the entire
 *     algorithm.
 * - Space Complexity: O(1)
 *     Uses only scalar variables for product and count tracking.
 *
 * -------------------------------------------------------------
 * Pattern / Invariant:
 * - Dynamic Sliding Window with Subarray Counting:
 *     - If k <= 1, no subarray of positive integers can have product < k -> return 0.
 *     - Expand `r` multiplying: `product *= nums[r]`.
 *     - Shrink `l` dividing: `while (product >= k) product /= nums[l++]`.
 *     - Count all valid subarrays terminating at index `r`:
 *       `count += (r - l + 1)`.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal Dynamic Sliding Window Solution
    // Time: O(N), Space: O(1)
    int numSubarrayProductLessThanK(const vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int product = 1, count = 0;
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            product *= nums[r];
            while (product >= k) {
                product /= nums[l];
                l++;
            }
            // Count all valid subarrays ending at index r
            count += (r - l + 1);
        }
        return count;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {10, 5, 2, 6};
    int k1 = 100;
    int res1 = sol.numSubarrayProductLessThanK(nums1, k1);
    cout << "Test 1 [{10, 5, 2, 6}, k=100] -> Got: " << res1
         << " (Expected: 8) -> " << (res1 == 8 ? "PASSED" : "FAILED") << "\n";

    // Test 2: k = 0 (Edge case)
    vector<int> nums2 = {1, 2, 3};
    int k2 = 0;
    int res2 = sol.numSubarrayProductLessThanK(nums2, k2);
    cout << "Test 2 [{1, 2, 3}, k=0] -> Got: " << res2
         << " (Expected: 0) -> " << (res2 == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 3: k = 1 (Edge case with positive numbers)
    vector<int> nums3 = {1, 1, 1};
    int k3 = 1;
    int res3 = sol.numSubarrayProductLessThanK(nums3, k3);
    cout << "Test 3 [{1, 1, 1}, k=1] -> Got: " << res3
         << " (Expected: 0) -> " << (res3 == 0 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Another case
    vector<int> nums4 = {1, 2, 3, 4};
    int k4 = 10;
    int res4 = sol.numSubarrayProductLessThanK(nums4, k4);
    cout << "Test 4 [{1, 2, 3, 4}, k=10] -> Got: " << res4
         << " (Expected: 7) -> " << (res4 == 7 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
