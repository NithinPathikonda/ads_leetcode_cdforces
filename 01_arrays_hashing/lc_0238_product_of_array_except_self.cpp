/**
 * Problem 006: Product of Array Except Self
 * Link: https://leetcode.com/problems/product-of-array-except-self/
 * Topic: 01_arrays_hashing
 * Companies: Meta, Amazon, Apple, Google, Microsoft, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an integer array nums, return an array answer such that answer[i]
 * is equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 * You must write an algorithm that runs in O(n) time and without using the division operation.
 *
 * Constraints:
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 *
 * Follow-up:
 * Can you solve the problem in O(1) extra memory complexity?
 * (The output array does not count as extra space for memory analysis.)
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Zero-Counting with Division - User's Baseline):
 *     - Time Complexity: O(N)
 *       Single pass to count zeros and product of non-zero elements, second pass to fill answer.
 *     - Space Complexity: O(1) auxiliary space (excluding result vector).
 *     - Caveat: Problem forbids division, but this demonstrates solid zero-edge-case mastery.
 *
 * - Approach 2 (Prefix and Suffix Product Arrays - User's No-Division Solution):
 *     - Time Complexity: O(N)
 *       Pass 1 builds prefix products (left of i), Pass 2 builds suffix products (right of i),
 *       Pass 3 multiplies them: ans[i] = prefix[i] * suffix[i].
 *     - Space Complexity: O(N) auxiliary space for prefix and suffix arrays.
 *
 * - Approach 3 (In-Place Prefix with Running Suffix Variable - Optimal O(1) Extra Space):
 *     - Time Complexity: O(N)
 *       Pass 1 fills output array directly with prefix products.
 *       Pass 2 traverses right-to-left, multiplying by a running scalar suffix product.
 *     - Space Complexity: O(1) auxiliary space.
 *
 * Pattern / Trigger:
 * - "Product of array except self without division" -> Prefix & Suffix accumulation.
 *
 * Critical Edge Cases:
 * - Exactly one zero: nums = [1, 2, 0, 4] -> all outputs 0 except index of zero.
 * - Multiple zeros: nums = [0, 2, 0, 4] -> all outputs must be 0.
 * - Negative numbers & alternating signs: nums = [-1, 1, -1, 1].
 * - Minimal array length (N = 2): nums = [2, 3] -> [3, 2].
 * -------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Zero-Counting with Division (Interview Baseline & Edge Case Analysis)
    // Time: O(N), Space: O(1) extra space
    vector<int> productExceptSelfDivision(const vector<int>& nums) {
        int n = nums.size();
        int zero_count = 0;
        int zero_index = -1;
        long long prod_without_zeros = 1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                zero_count++;
                zero_index = i;
            } else {
                prod_without_zeros *= nums[i];
            }
        }

        vector<int> ans(n, 0);

        // Case 1: More than one zero -> every product except self will multiply at least one zero
        if (zero_count > 1) {
            return ans;
        }

        // Case 2: Exactly one zero -> only the element at zero_index has a non-zero product
        if (zero_count == 1) {
            ans[zero_index] = static_cast<int>(prod_without_zeros);
            return ans;
        }

        // Case 3: No zeros -> safe to use division
        for (int i = 0; i < n; ++i) {
            ans[i] = static_cast<int>(prod_without_zeros / nums[i]);
        }

        return ans;
    }

    // Approach 2: Prefix and Suffix Product Arrays (No Division)
    // Time: O(N), Space: O(N) auxiliary space
    vector<int> productExceptSelfPrefixSuffix(const vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n, 1);
        vector<int> suffixProduct(n, 1);
        vector<int> ans(n);

        // prefixProduct[i] contains the product of all elements to the left of i
        for (int i = 1; i < n; ++i) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }

        // suffixProduct[i] contains the product of all elements to the right of i
        for (int i = n - 2; i >= 0; --i) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }

        // Combine left and right products
        for (int i = 0; i < n; ++i) {
            ans[i] = prefixProduct[i] * suffixProduct[i];
        }

        return ans;
    }

    // Approach 3: Optimal In-Place Prefix + Running Suffix (FAANG Gold Standard)
    // Time: O(N), Space: O(1) auxiliary space (output array doesn't count)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // Pass 1: Accumulate prefix products directly in ans
        // ans[i] stores product of elements strictly to the left of i
        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Pass 2: Accumulate suffix products using a single running variable
        int suffix = 1;
        for (int i = n - 1; i >= 0; --i) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> expected1 = {24, 12, 8, 6};
    auto res1_opt = sol.productExceptSelf(nums1);
    auto res1_pre_suf = sol.productExceptSelfPrefixSuffix(nums1);
    auto res1_div = sol.productExceptSelfDivision(nums1);
    cout << "Test 1 [1, 2, 3, 4]: "
         << (res1_opt == expected1 && res1_pre_suf == expected1 && res1_div == expected1 ? "PASSED" : "FAILED")
         << "\n";

    // Test 2: Contains one zero
    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> expected2 = {0, 0, 9, 0, 0};
    auto res2_opt = sol.productExceptSelf(nums2);
    auto res2_pre_suf = sol.productExceptSelfPrefixSuffix(nums2);
    auto res2_div = sol.productExceptSelfDivision(nums2);
    cout << "Test 2 [-1, 1, 0, -3, 3]: "
         << (res2_opt == expected2 && res2_pre_suf == expected2 && res2_div == expected2 ? "PASSED" : "FAILED")
         << "\n";

    // Test 3: Multiple zeros
    vector<int> nums3 = {0, 4, 0};
    vector<int> expected3 = {0, 0, 0};
    auto res3_opt = sol.productExceptSelf(nums3);
    auto res3_pre_suf = sol.productExceptSelfPrefixSuffix(nums3);
    auto res3_div = sol.productExceptSelfDivision(nums3);
    cout << "Test 3 [0, 4, 0]: "
         << (res3_opt == expected3 && res3_pre_suf == expected3 && res3_div == expected3 ? "PASSED" : "FAILED")
         << "\n";

    // Test 4: Array of size 2 with negative numbers
    vector<int> nums4 = {-2, 5};
    vector<int> expected4 = {5, -2};
    auto res4_opt = sol.productExceptSelf(nums4);
    cout << "Test 4 [-2, 5]: "
         << (res4_opt == expected4 ? "PASSED" : "FAILED")
         << "\n";

    return 0;
}
