/**
 * Problem 008: Subarray Sum Equals K
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * Topic: 01_arrays_hashing
 * Companies: Meta (Top #1 Tagged), Google, Amazon, Microsoft, Apple, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array of integers nums and an integer k, return the total number
 * of subarrays whose sum equals to k.
 *
 * A subarray is a contiguous non-empty sequence of elements within an array.
 *
 * Constraints:
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Brute Force Cumulative Sum):
 *     - Time Complexity: O(N^2)
 *       Two nested loops computing subarray sum for all pairs (i, j).
 *     - Space Complexity: O(1) auxiliary space.
 *     - Caveat: Too slow for large inputs (N = 2 * 10^4 -> 4 * 10^8 operations -> TLE).
 *
 * - Approach 2 (Prefix Sum + Hash Map Frequency Counting - User's Optimal Solution):
 *     - Time Complexity: O(N) average
 *       Single pass through the array. Map lookups and inserts take O(1) on average.
 *     - Space Complexity: O(N)
 *       unordered_map stores up to N distinct prefix sums.
 *
 * Pattern / Trigger:
 * - "Count contiguous subarrays with given sum k (with possible negative numbers)"
 *   -> Running Prefix Sum + Hash Map:
 *      Sum(i...j) = prefix[j] - prefix[i - 1] = k  ==>  prefix[i - 1] = prefix[j] - k.
 *
 * The Crucial Base Case Pitfall (Candidate Killer):
 * - `mpp[0] = 1`:
 *   A prefix sum of 0 has appeared 1 time (before examining any array elements).
 *   Without this base case, any valid subarray starting at index 0 (where prefix_sum == k)
 *   would fail to find its complement (prefix_sum - k = 0) and would be missed!
 *
 * Critical Edge Cases:
 * - Subarray starts at index 0: nums = [3], k = 3 -> 1.
 * - Negative numbers & zero sum: nums = [1, -1, 0], k = 0 -> 3 ([1, -1], [0], [1, -1, 0]).
 * - All zeros: nums = [0, 0, 0], k = 0 -> 6 subarrays.
 * - No valid subarray: nums = [1, 2, 3], k = 7 -> 0.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Brute Force Baseline (Interview discussion baseline)
    // Time: O(N^2), Space: O(1)
    int subarraySumBruteForce(const vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int current_sum = 0;
            for (int j = i; j < n; ++j) {
                current_sum += nums[j];
                if (current_sum == k) {
                    count++;
                }
            }
        }

        return count;
    }

    // Approach 2: Prefix Sum + Hash Map Frequency Counting (User's Optimal Solution)
    // Time: O(N), Space: O(N)
    int subarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        // Base case: prefix sum of 0 occurs 1 time before processing any elements
        mpp[0] = 1;

        int prefix_s = 0;
        int count = 0;

        for (size_t i = 0; i < nums.size(); ++i) {
            prefix_s += nums[i];

            // If (prefix_s - k) exists in the map, add its frequency to count
            auto it = mpp.find(prefix_s - k);
            if (it != mpp.end()) {
                count += it->second;
            }

            // Record / increment the frequency of current prefix_s
            mpp[prefix_s]++;
        }

        return count;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard positive array
    vector<int> nums1 = {1, 1, 1};
    int k1 = 2;
    cout << "Test 1 [1, 1, 1], k = 2 -> Expected: 2 | Got: "
         << sol.subarraySum(nums1, k1)
         << " -> " << (sol.subarraySum(nums1, k1) == 2 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Standard mixed array
    vector<int> nums2 = {1, 2, 3};
    int k2 = 3;
    cout << "Test 2 [1, 2, 3], k = 3 -> Expected: 2 | Got: "
         << sol.subarraySum(nums2, k2)
         << " -> " << (sol.subarraySum(nums2, k2) == 2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Array with negatives and k = 0
    vector<int> nums3 = {1, -1, 0};
    int k3 = 0;
    cout << "Test 3 [1, -1, 0], k = 0 -> Expected: 3 | Got: "
         << sol.subarraySum(nums3, k3)
         << " -> " << (sol.subarraySum(nums3, k3) == 3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: All zeros with k = 0
    vector<int> nums4 = {0, 0, 0};
    int k4 = 0;
    cout << "Test 4 [0, 0, 0], k = 0 -> Expected: 6 | Got: "
         << sol.subarraySum(nums4, k4)
         << " -> " << (sol.subarraySum(nums4, k4) == 6 ? "PASSED" : "FAILED") << "\n";

    // Test 5: Single element matching k
    vector<int> nums5 = {5};
    int k5 = 5;
    cout << "Test 5 [5], k = 5 -> Expected: 1 | Got: "
         << sol.subarraySum(nums5, k5)
         << " -> " << (sol.subarraySum(nums5, k5) == 1 ? "PASSED" : "FAILED") << "\n";

    // Test 6: No subarray matching k
    vector<int> nums6 = {1, 2, 3};
    int k6 = 7;
    cout << "Test 6 [1, 2, 3], k = 7 -> Expected: 0 | Got: "
         << sol.subarraySum(nums6, k6)
         << " -> " << (sol.subarraySum(nums6, k6) == 0 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
