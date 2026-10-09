/**
 * Problem 020: Max Consecutive Ones III
 * Link: https://leetcode.com/problems/max-consecutive-ones-iii/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Meta (Top 10 High Frequency), Google, Amazon, Microsoft, ByteDance
 * Difficulty: Medium / Core Dynamic Window Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1s in the array if you can flip at most k 0s.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *     The right pointer traverses the array from 0 to N - 1. The left pointer
 *     moves strictly forward, advancing at most N times in total across the
 *     entire algorithm. Hence, each element is visited at most twice.
 * - Space Complexity: O(1)
 *     Uses only a few scalar variables for tracking counts and indices.
 *
 * -------------------------------------------------------------
 * Pattern / Invariant:
 * - Dynamic Sliding Window with Budget Invariant:
 *     "Flip at most k 0s" is equivalent to "Find longest window containing
 *     at most k zeros".
 *     1. Expand `r`: if nums[r] == 0, zero_count++.
 *     2. When zero_count > k: shrink `l` until zero_count <= k.
 *     3. Update max_len = max(max_len, r - l + 1).
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Optimal Dynamic Sliding Window Solution
    // Time: O(N), Space: O(1)
    int longestOnes(const vector<int>& nums, int k) {
        int l = 0, zero_count = 0, max_len = 0;
        int n = nums.size();

        for (int r = 0; r < n; ++r) {
            if (nums[r] == 0) {
                zero_count++;
            }

            // Shrink from left if zeros exceed allowed budget k
            while (zero_count > k) {
                if (nums[l] == 0) {
                    zero_count--;
                }
                l++;
            }

            max_len = max(max_len, r - l + 1);
        }

        return max_len;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case with k = 2
    vector<int> nums1 = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k1 = 2;
    int res1 = sol.longestOnes(nums1, k1);
    cout << "Test 1 [nums1, k=2] -> Got: " << res1
         << " (Expected: 6) -> " << (res1 == 6 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Standard case with k = 3
    vector<int> nums2 = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k2 = 3;
    int res2 = sol.longestOnes(nums2, k2);
    cout << "Test 2 [nums2, k=3] -> Got: " << res2
         << " (Expected: 10) -> " << (res2 == 10 ? "PASSED" : "FAILED") << "\n";

    // Test 3: k = 0 (no flips allowed)
    vector<int> nums3 = {1, 1, 0, 1, 1, 1, 0, 1};
    int k3 = 0;
    int res3 = sol.longestOnes(nums3, k3);
    cout << "Test 3 [nums3, k=0] -> Got: " << res3
         << " (Expected: 3) -> " << (res3 == 3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: All zeros, k = 2
    vector<int> nums4 = {0, 0, 0, 0};
    int k4 = 2;
    int res4 = sol.longestOnes(nums4, k4);
    cout << "Test 4 [all 0s, k=2] -> Got: " << res4
         << " (Expected: 2) -> " << (res4 == 2 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
