/**
 * Problem 010: Sort Colors
 * Link: https://leetcode.com/problems/sort-colors/
 * Topic: 01_arrays_hashing
 * Companies: Microsoft, Amazon, Meta, Google, Apple, Adobe
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array nums with n objects colored red, white, or blue, sort them
 * in-place so that objects of the same color are adjacent, with the colors
 * in the order 0 (red), 1 (white), and 2 (blue).
 *
 * You must solve this problem without using the library's sort function.
 *
 * Constraints:
 * n == nums.length
 * 1 <= n <= 300
 * nums[i] is either 0, 1, or 2.
 *
 * Follow-up:
 * Could you come up with a one-pass algorithm using only constant extra space?
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Counting Sort Baseline):
 *     - Time Complexity: O(N) in 2 passes (Pass 1: count 0,1,2; Pass 2: overwrite nums).
 *     - Space Complexity: O(1) auxiliary space (array of size 3).
 *
 * - Approach 2 (Dutch National Flag Algorithm - User's Optimal One-Pass Solution):
 *     - Time Complexity: O(N) in 1 single pass.
 *     - Space Complexity: O(1) in-place.
 *
 * The Core Invariant (Dijkstra's Dutch National Flag):
 * [0 ... l - 1]     : All 0s
 * [l ... c - 1]     : All 1s
 * [c ... r]         : Unprocessed / unknown elements
 * [r + 1 ... n - 1] : All 2s
 *
 * The Critical Interview Trap:
 * Why do we NOT increment `c` when swapping `nums[c]` with `nums[r]`?
 * - Because the element swapped in from index `r` is completely unknown / unprocessed!
 *   It could be 0, 1, or 2. We MUST inspect `nums[c]` again on the next iteration.
 * - In contrast, when swapping with `l`, the incoming element is guaranteed to be 1,
 *   so advancing `c++` is safe.
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Counting Sort (Two-Pass Baseline)
    // Time: O(N), Space: O(1)
    void sortColorsCountingSort(vector<int>& nums) {
        int counts[3] = {0, 0, 0};
        for (int x : nums) {
            counts[x]++;
        }

        int idx = 0;
        for (int color = 0; color < 3; ++color) {
            while (counts[color]-- > 0) {
                nums[idx++] = color;
            }
        }
    }

    // Approach 2: Dutch National Flag Algorithm (User's Optimal One-Pass Solution)
    // Time: O(N), Space: O(1) in-place
    void sortColors(vector<int>& nums) {
        int l = 0;
        int c = 0;
        int r = static_cast<int>(nums.size()) - 1;

        while (c <= r) {
            if (nums[c] == 2) {
                // Swap with r, but do NOT increment c because nums[r] was uninspected!
                swap(nums[r], nums[c]);
                r--;
            } else if (nums[c] == 0) {
                // Swap with l, safe to advance c because incoming element is known to be 1
                swap(nums[c], nums[l]);
                l++;
                c++;
            } else {
                // Element is 1, already in correct middle zone
                c++;
            }
        }
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> expected1 = {0, 0, 1, 1, 2, 2};
    sol.sortColors(nums1);
    cout << "Test 1 [2, 0, 2, 1, 1, 0] -> "
         << (nums1 == expected1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Two elements
    vector<int> nums2 = {2, 0, 1};
    vector<int> expected2 = {0, 1, 2};
    sol.sortColors(nums2);
    cout << "Test 2 [2, 0, 1] -> "
         << (nums2 == expected2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Already sorted
    vector<int> nums3 = {0, 1, 2};
    vector<int> expected3 = {0, 1, 2};
    sol.sortColors(nums3);
    cout << "Test 3 [0, 1, 2] -> "
         << (nums3 == expected3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: All identical elements
    vector<int> nums4 = {2, 2, 2};
    vector<int> expected4 = {2, 2, 2};
    sol.sortColors(nums4);
    cout << "Test 4 [2, 2, 2] -> "
         << (nums4 == expected4 ? "PASSED" : "FAILED") << "\n";

    // Test 5: Reverse sorted
    vector<int> nums5 = {2, 2, 1, 1, 0, 0};
    vector<int> expected5 = {0, 0, 1, 1, 2, 2};
    sol.sortColors(nums5);
    cout << "Test 5 [2, 2, 1, 1, 0, 0] -> "
         << (nums5 == expected5 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
