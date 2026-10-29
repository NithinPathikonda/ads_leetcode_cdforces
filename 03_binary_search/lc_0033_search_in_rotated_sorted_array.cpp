/**
 * ============================================================================
 * Problem: LC 33 - Search in Rotated Sorted Array
 * Difficulty: Medium
 * Pattern: Binary Search / Rotated Array Boundary Decoupling
 * Target MNCs: Meta, Google, Amazon, Microsoft, Apple, Bloomberg
 * 
 * Invariant:
 *   In any rotated sorted array split at mid, at least ONE half ([l..mid] or 
 *   [mid..r]) is GUARANTEED to be strictly sorted.
 *   1. Check if the right half is sorted (nums[mid] <= nums[r]).
 *      - If target lies within (nums[mid], nums[r]], search right (l = mid + 1).
 *      - Otherwise, search left (r = mid - 1).
 *   2. Else, the left half must be sorted (nums[l] <= nums[mid]).
 *      - If target lies within [nums[l], nums[mid]), search left (r = mid - 1).
 *      - Otherwise, search right (l = mid + 1).
 * 
 * Complexity:
 *   - Time:  O(log N) — halving search space at each iteration
 *   - Space: O(1) auxiliary space
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
public:
    // User's Verified Optimal Solution
    // Time: O(log N) | Space: O(1)
    int search(const vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Case 1: Right half is strictly sorted
            if (nums[mid] <= nums[r]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1; // Target lies in sorted right half
                } else {
                    r = mid - 1; // Target must be in left half
                }
            }
            // Case 2: Left half is strictly sorted
            else {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1; // Target lies in sorted left half
                } else {
                    l = mid + 1; // Target must be in right half
                }
            }
        }

        return -1; // Target not found
    }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
    Solution solver;

    // Test 1: Standard rotated array (target present in right half)
    assert(solver.search({4, 5, 6, 7, 0, 1, 2}, 0) == 4);

    // Test 2: Standard rotated array (target not present)
    assert(solver.search({4, 5, 6, 7, 0, 1, 2}, 3) == -1);

    // Test 3: Standard rotated array (target present in left half)
    assert(solver.search({4, 5, 6, 7, 0, 1, 2}, 5) == 1);

    // Test 4: Single element array (match)
    assert(solver.search({1}, 1) == 0);

    // Test 5: Single element array (no match)
    assert(solver.search({1}, 0) == -1);

    // Test 6: Two elements rotated (search first)
    assert(solver.search({3, 1}, 3) == 0);

    // Test 7: Two elements rotated (search second)
    assert(solver.search({3, 1}, 1) == 1);

    // Test 8: Unrotated strictly sorted array
    assert(solver.search({1, 2, 3, 4, 5, 6, 7}, 4) == 3);

    // Test 9: Pivot at the very end
    assert(solver.search({2, 3, 4, 5, 6, 7, 1}, 1) == 6);

    cout << "✅ All 9 test cases passed successfully for LC 33!" << endl;
    return 0;
}
