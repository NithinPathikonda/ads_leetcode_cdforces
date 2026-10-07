/**
 * Problem 012: Two Sum II - Input Array Is Sorted
 * Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * Topic: 02_two_pointers_sliding_window
 * Companies: Amazon, Google, Apple, Meta, Microsoft, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given a 1-indexed array of integers numbers that is already sorted in
 * non-decreasing order, find two numbers such that they add up to a specific
 * target number.
 *
 * Return the indices of the two numbers, index1 and index2, added by one as an
 * integer array [index1, index2] of length 2.
 *
 * The tests are generated such that there is exactly one solution.
 * You may not use the same element twice.
 * Your solution must use only constant extra space.
 *
 * Constraints:
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers is sorted in non-decreasing order.
 * -1000 <= target <= 1000
 * The tests are generated such that there is exactly one solution.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(N)
 *     In each step, either the left pointer increments or the right pointer
 *     decrements. The loop runs at most N times.
 * - Space Complexity: O(1)
 *     Uses only two integer pointers, perfectly satisfying the O(1) extra space constraint.
 *
 * -------------------------------------------------------------
 * 🌟 Why Two Pointers Works (Invariant Proof vs Hash Map):
 * -------------------------------------------------------------
 * - If sum > target:
 *     Because the array is sorted, numbers[r] added to ANY element to the right
 *     of l would be even larger. Hence, numbers[r] can never pair with any valid
 *     element to form target. Safely decrement r--.
 * - If sum < target:
 *     Similarly, numbers[l] added to ANY element to the left of r would be even
 *     smaller. Hence, numbers[l] can never form target with any element. Safely increment l++.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal Two-Pointer Solution
    // Time: O(N), Space: O(1)
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int l = 0;
        int r = static_cast<int>(numbers.size()) - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];

            if (sum == target) {
                // Problem requires 1-based indexing
                return {l + 1, r + 1};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }

        return {};
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> expected1 = {1, 2};
    cout << "Test 1 [2, 7, 11, 15], target 9 -> "
         << (sol.twoSum(nums1, target1) == expected1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: Target with duplicates
    vector<int> nums2 = {2, 3, 4};
    int target2 = 6;
    vector<int> expected2 = {1, 3};
    cout << "Test 2 [2, 3, 4], target 6 -> "
         << (sol.twoSum(nums2, target2) == expected2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Negative numbers
    vector<int> nums3 = {-1, 0};
    int target3 = -1;
    vector<int> expected3 = {1, 2};
    cout << "Test 3 [-1, 0], target -1 -> "
         << (sol.twoSum(nums3, target3) == expected3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Both negative numbers
    vector<int> nums4 = {-5, -3, -1, 1, 4};
    int target4 = -6;
    vector<int> expected4 = {1, 3};
    cout << "Test 4 [-5, -3, -1, 1, 4], target -6 -> "
         << (sol.twoSum(nums4, target4) == expected4 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
