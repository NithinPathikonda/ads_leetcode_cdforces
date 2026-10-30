/**
 * ============================================================================
 * Problem: LC 704 - Binary Search
 * Difficulty: Easy
 * Pattern: Classic Binary Search on Sorted Array
 * Target MNCs: Apple, Google, Microsoft, Meta, Amazon
 * 
 * Invariant:
 *   The search space is maintained within the closed interval [l, r].
 *   At each step:
 *     - If nums[mid] == target: element found -> return mid.
 *     - If nums[mid] < target: target must be in right half (mid + 1 .. r) -> l = mid + 1.
 *     - If nums[mid] > target: target must be in left half (l .. mid - 1) -> r = mid - 1.
 *   Loop invariant holds while l <= r. If l > r, target does not exist -> return -1.
 * 
 * Complexity:
 *   - Time:  O(log N) — search space is halved every iteration
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
            // Safe midpoint to prevent 32-bit signed integer overflow
            int mid = (r - l) / 2 + l;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                l = mid + 1; // Discard left half including mid
            } else {
                r = mid - 1; // Discard right half including mid
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

    // Test 1: Standard hit in odd-length array
    vector<int> t1 = {-1, 0, 3, 5, 9, 12};
    assert(solver.search(t1, 9) == 4);

    // Test 2: Standard miss in odd-length array
    assert(solver.search(t1, 2) == -1);

    // Test 3: Single element array (hit)
    vector<int> t2 = {5};
    assert(solver.search(t2, 5) == 0);

    // Test 4: Single element array (miss)
    assert(solver.search(t2, -5) == -1);

    // Test 5: Target is the first element (left boundary)
    assert(solver.search(t1, -1) == 0);

    // Test 6: Target is the last element (right boundary)
    assert(solver.search(t1, 12) == 5);

    // Test 7: Target smaller than all elements
    assert(solver.search(t1, -100) == -1);

    // Test 8: Target larger than all elements
    assert(solver.search(t1, 100) == -1);

    // Test 9: Two element array (hit first)
    vector<int> t3 = {2, 5};
    assert(solver.search(t3, 2) == 0);

    // Test 10: Two element array (hit second)
    assert(solver.search(t3, 5) == 1);

    // Test 11: Two element array (miss)
    assert(solver.search(t3, 3) == -1);

    cout << "✅ All 11 test scenarios passed successfully for LC 704 (Binary Search)!" << endl;
    return 0;
}
