/**
 * Problem 001: Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 * Topic: 01_arrays_hashing
 * Companies: Google, Meta, Amazon, Microsoft, Apple, Uber
 * Difficulty: Easy / Foundation
 * 
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an array of integers 'nums' and an integer 'target', return 
 * indices of the two numbers such that they add up to 'target'.
 * 
 * - Each input has exactly one solution.
 * - You cannot use the same element twice.
 * - Return the answer in any order.
 * 
 * Constraints:
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * -------------------------------------------------------------
 * 
 * Target Complexity:
 * - Time: O(N)
 * - Space: O(N)
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // TODO: Write your optimal solution here
        
        return {};
    }
};

int main() {
    Solution sol;

    // Test 1
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Test 1: ";
    if (res1.size() == 2) cout << "[" << res1[0] << ", " << res1[1] << "] (Expected: [0, 1])\n";
    else cout << "Not implemented\n";

    // Test 2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Test 2: ";
    if (res2.size() == 2) cout << "[" << res2[0] << ", " << res2[1] << "] (Expected: [1, 2])\n";
    else cout << "Not implemented\n";

    // Test 3 (Duplicate elements)
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "Test 3: ";
    if (res3.size() == 2) cout << "[" << res3[0] << ", " << res3[1] << "] (Expected: [0, 1])\n";
    else cout << "Not implemented\n";

    return 0;
}
