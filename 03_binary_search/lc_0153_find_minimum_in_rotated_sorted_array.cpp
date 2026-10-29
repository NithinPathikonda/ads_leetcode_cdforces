/**
 * ============================================================================
 * Problem: LC 153 - Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Pattern: Binary Search on Rotated Array / Inflection Point Detection
 * Target MNCs: Meta, Amazon, Microsoft, Google, Bloomberg
 * 
 * Approaches Included:
 *   1. User's Half-Elimination Search (Checks sorted half, records min, advances)
 *   2. Canonical Inflection Bound (Compares mid with right: nums[mid] > nums[r])
 * 
 * Complexity:
 *   - Time:  O(log N) — halving the search space each step
 *   - Space: O(1) auxiliary space
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// ============================================================================
// Approach 1: User's Half-Elimination Search
// At each mid, determine which half is sorted:
// - If left is sorted: nums[l] is the minimum of that half; record it and search right.
// - Else right is sorted: nums[mid] is candidate minimum; record it and search left.
// Time: O(log N) | Space: O(1)
// ============================================================================
class SolutionUser {
public:
    int findMin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid = -1, mini = INT_MAX;
        while (l <= r) {
            mid = l + (r - l) / 2;
            mini = min(mini, nums[mid]);

            if (nums[l] <= nums[mid]) {
                mini = min(mini, nums[l]);
                l = mid + 1;
            } else if (nums[mid] <= nums[r]) {
                mini = min(mini, nums[mid]);
                r = mid - 1;
            }
        }
        return mini;
    }
};

// ============================================================================
// Approach 2: Canonical Inflection Comparison (Interview Standard)
// Compares nums[mid] directly with nums[r]:
// - If nums[mid] > nums[r]: inflection point (drop) MUST be strictly to the right -> l = mid + 1.
// - If nums[mid] <= nums[r]: nums[mid] could be the min or min is to the left -> r = mid.
// Loop terminates when l == r, pointing exactly to the minimum element.
// Time: O(log N) | Space: O(1)
// ============================================================================
class SolutionCanonical {
public:
    int findMin(const vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r]) {
                l = mid + 1; // Minimum must be in (mid, r]
            } else {
                r = mid;     // Minimum could be at mid or in [l, mid]
            }
        }

        return nums[l];
    }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
    SolutionUser user_sol;
    SolutionCanonical canonical_sol;

    auto run_tests = [&](const string& name, auto& solver) {
        cout << "Testing " << name << "..." << endl;

        // Test 1: Standard rotation
        assert(solver.findMin({3, 4, 5, 1, 2}) == 1);

        // Test 2: Standard rotation with 0
        assert(solver.findMin({4, 5, 6, 7, 0, 1, 2}) == 0);

        // Test 3: Unrotated strictly sorted array
        assert(solver.findMin({11, 13, 15, 17}) == 11);

        // Test 4: Single element
        assert(solver.findMin({42}) == 42);

        // Test 5: Two elements rotated
        assert(solver.findMin({2, 1}) == 1);

        // Test 6: Two elements sorted
        assert(solver.findMin({1, 2}) == 1);

        // Test 7: Minimum at index 1
        assert(solver.findMin({5, 1, 2, 3, 4}) == 1);

        // Test 8: Large odd-sized rotation
        assert(solver.findMin({3, 1, 2}) == 1);

        cout << "  ✅ Passed all test scenarios!" << endl;
    };

    run_tests("Approach 1 (User's Half Elimination)", user_sol);
    run_tests("Approach 2 (Canonical Inflection Check)", canonical_sol);

    cout << "\n🎉 ALL IMPLEMENTATIONS VERIFIED CORRECT!" << endl;
    return 0;
}
