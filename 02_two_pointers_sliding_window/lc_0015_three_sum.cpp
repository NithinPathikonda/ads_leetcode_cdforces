/**
 * Problem 013: 3Sum
 * Link: https://leetcode.com/problems/3sum/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Meta, Amazon, Apple, Google, Microsoft, Bloomberg
 * Difficulty: Medium / FAANG Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 * such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Constraints:
 * 3 <= nums.length <= 3000
 * -10^5 <= nums[i] <= 10^5
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N^2)
 *     Sorting takes O(N log N).
 *     Outer loop runs N times; inner two-pointer search runs in O(N).
 *     Total: O(N log N + N^2) = O(N^2).
 * - Space Complexity: O(1) auxiliary space (excluding the output array,
 *     ignoring O(log N) or O(N) sort stack depending on language).
 *
 * -------------------------------------------------------------
 * 🌟 The 3 Deduplication Golden Rules:
 * -------------------------------------------------------------
 * 1. Why sort first?
 *    - Reduces triplet deduplication from slow set allocations to simple adjacent skips.
 *    - Turns the search for remaining 2 elements into Two Sum II (O(1) space).
 *
 * 2. Why check (i > 0 && nums[i] == nums[i - 1]) in outer loop?
 *    - Process the FIRST occurrence of a value as the leader.
 *    - Skip subsequent identical values because all valid triplets starting with that
 *      value were already exhausted.
 *
 * 3. Why re-guard with `j < k` in inner duplicate while loops?
 *    - `while (j < k && nums[j] == nums[j - 1]) j++;`
 *    - Without `j < k`, an array of identical values (e.g., [0,0,0,0]) would cause
 *      `j` to cross `k` and march out-of-bounds, triggering a segmentation fault!
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal Sorting + Two-Pointer Solution
    // Time: O(N^2), Space: O(1) auxiliary
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        // Step 1: Sort the array (Crucial foundation for Two Pointers & Deduplication)
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element nums[i]
        for (int i = 0; i < n; ++i) {
            // Optimization: Since array is sorted, if smallest number > 0, sum can never be 0
            if (nums[i] > 0) break;

            // Rule 1: Skip duplicate leader values
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    // Match found!
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // Rule 2 & 3: Skip duplicate second and third values with j < k guard
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case with duplicates
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = sol.threeSum(nums1);
    cout << "Test 1 [-1, 0, 1, 2, -1, -4] -> Found " << res1.size() << " triplets (Expected: 2) -> "
         << (res1.size() == 2 ? "PASSED" : "FAILED") << "\n";

    // Test 2: All zeros (Validates j < k boundary guard!)
    vector<int> nums2 = {0, 0, 0, 0, 0};
    auto res2 = sol.threeSum(nums2);
    cout << "Test 2 [0, 0, 0, 0, 0] -> Found " << res2.size() << " triplet (Expected: 1) -> "
         << (res2.size() == 1 ? "PASSED" : "FAILED") << "\n";

    // Test 3: No valid triplets
    vector<int> nums3 = {0, 1, 1};
    auto res3 = sol.threeSum(nums3);
    cout << "Test 3 [0, 1, 1] -> Found " << res3.size() << " triplets (Expected: 0) -> "
         << (res3.empty() ? "PASSED" : "FAILED") << "\n";

    // Test 4: Array with identical positive/negative pairs
    vector<int> nums4 = {-2, 0, 1, 1, 2};
    auto res4 = sol.threeSum(nums4);
    cout << "Test 4 [-2, 0, 1, 1, 2] -> Found " << res4.size() << " triplets (Expected: 2) -> "
         << (res4.size() == 2 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
