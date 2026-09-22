/**
 * Problem 001: Two Sum
 * Link: https://leetcode.com/problems/two-sum/
 * Topic: 01_arrays_hashing
 * Companies: Google, Meta, Amazon, Microsoft, Apple, Uber
 * Difficulty: Easy / Foundation
 * 
 * -------------------------------------------------------------
 * Complexity:
 * - Time Complexity: O(N) — Single pass, O(1) average hash map lookup
 * - Space Complexity: O(N) — Hash map stores up to N elements
 * 
 * Pattern / Trigger:
 * - Unsorted array + find pair summing to target -> Hash Map complement lookup
 * 
 * Critical Edge Cases:
 * - Duplicates (e.g. [3, 3], target = 6): Handled by checking map BEFORE inserting current element.
 * - Same element cannot be used twice: Guaranteed because current index 'i' is not in map yet.
 * -------------------------------------------------------------
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> mpp; // value -> index
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            int comp = target - nums[i];
            auto it = mpp.find(comp);
            if (it != mpp.end()) {
                // Return immediately using iterator (avoids re-hashing)
                return {it->second, i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> res1 = sol.twoSum(nums1, target1);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [0, 1]) -> "
         << ((res1 == vector<int>{0, 1}) ? "PASSED" : "FAILED") << "\n";

    // Test 2: Unordered indices
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> res2 = sol.twoSum(nums2, target2);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [1, 2]) -> "
         << ((res2 == vector<int>{1, 2}) ? "PASSED" : "FAILED") << "\n";

    // Test 3: Duplicates
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> res3 = sol.twoSum(nums3, target3);
    cout << "Test 3: [" << res3[0] << ", " << res3[1] << "] (Expected: [0, 1]) -> "
         << ((res3 == vector<int>{0, 1}) ? "PASSED" : "FAILED") << "\n";

    return 0;
}
