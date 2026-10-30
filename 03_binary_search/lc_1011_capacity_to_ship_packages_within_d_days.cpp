/**
 * ============================================================================
 * Problem: LC 1011 - Capacity To Ship Packages Within D Days
 * Difficulty: Medium
 * Pattern: Binary Search on Answer / Greedy Feasibility Simulation
 * Target MNCs: Amazon, Google, Meta, Microsoft, Bloomberg
 * 
 * Invariant & Mathematical Formulation:
 *   Let C be the ship capacity.
 *   Packages must be shipped in the order given (no reordering or splitting).
 * 
 * Feasibility Predicate (canShip(weights, days, C)):
 *   Greedily accumulate package weights into the current day:
 *     - If w > C: package cannot fit on any ship -> return false (guard rail).
 *     - If current_load + w <= C: add w to today's load.
 *     - Else: send today's ship away, increment days_needed++, start new day with w.
 *   Return days_needed <= days.
 * 
 * Monotonicity:
 *   As capacity C increases, the required days is monotonically non-increasing.
 *   Predicate: [false, false, ..., false, true, true, ..., true]
 *   We seek the MINIMAL capacity C that yields true.
 * 
 * Search Boundaries:
 *   - Lower Bound (low): max(weights) — the ship MUST be able to carry the
 *     heaviest single package, as packages cannot be split.
 *   - Upper Bound (high): sum(weights) — shipping all packages in a single day.
 * 
 * Complexity:
 *   - Time:  O(N * log(sum(weights) - max(weights)))
 *   - Space: O(1) auxiliary space
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
private:
    /**
     * Helper predicate: checks if packages can be shipped within 'days' at capacity 'cap'.
     * Features the defensive guard rail (w > cap) to guarantee physical feasibility.
     */
    bool isPossible(const vector<int>& weights, int days, int cap) {
        int days_needed = 1;
        int current_load = 0;

        for (int w : weights) {
            // Guard rail: if a single package exceeds capacity, it can never ship
            if (w > cap) return false;

            if (current_load + w <= cap) {
                current_load += w;
            } else {
                days_needed++;
                current_load = w; // Start new day with this package
            }
        }

        return days_needed <= days;
    }

public:
    int shipWithinDays(const vector<int>& weights, int days) {
        int max_w = 0;
        int sum_w = 0;

        for (int w : weights) {
            max_w = max(max_w, w);
            sum_w += w;
        }

        // Search space: [max(weights), sum(weights)]
        int l = max_w, r = sum_w;
        int ans = sum_w;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (isPossible(weights, days, mid)) {
                ans = mid;         // Feasible capacity, try searching for smaller
                r = mid - 1;
            } else {
                l = mid + 1;       // Capacity too small, must increase
            }
        }

        return ans;
    }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
    Solution solver;

    // Test 1: Standard LeetCode Example 1
    // weights = [1,2,3,4,5,6,7,8,9,10], days = 5 -> expected 15
    vector<int> t1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assert(solver.shipWithinDays(t1, 5) == 15);

    // Test 2: Standard LeetCode Example 2
    // weights = [3,2,2,4,1,4], days = 3 -> expected 6
    vector<int> t2 = {3, 2, 2, 4, 1, 4};
    assert(solver.shipWithinDays(t2, 3) == 6);

    // Test 3: Standard LeetCode Example 3
    // weights = [1,2,3,1,1], days = 4 -> expected 3
    vector<int> t3 = {1, 2, 3, 1, 1};
    assert(solver.shipWithinDays(t3, 4) == 3);

    // Test 4: The Oversized Package Trap Case ([2, 10, 3], days = 3)
    // Capacity must be at least 10 to carry the 10kg package!
    vector<int> t4 = {2, 10, 3};
    assert(solver.shipWithinDays(t4, 3) == 10);

    // Test 5: Single element array, 1 day
    vector<int> t5 = {10};
    assert(solver.shipWithinDays(t5, 1) == 10);

    // Test 6: Single element array, excess days
    vector<int> t6 = {10};
    assert(solver.shipWithinDays(t6, 5) == 10);

    // Test 7: days == 1 (must ship everything in 1 trip -> sum of all weights)
    vector<int> t7 = {1, 2, 3, 4, 5};
    assert(solver.shipWithinDays(t7, 1) == 15);

    // Test 8: days == weights.size() (can ship 1 item per day -> max weight)
    vector<int> t8 = {1, 2, 3, 4, 5};
    assert(solver.shipWithinDays(t8, 5) == 5);

    // Test 9: All identical weights
    // weights = [5, 5, 5, 5], days = 2 -> expected 10 (2 items per day)
    vector<int> t9 = {5, 5, 5, 5};
    assert(solver.shipWithinDays(t9, 2) == 10);

    // Test 10: Large weights
    vector<int> t10 = {500, 500, 500, 500};
    assert(solver.shipWithinDays(t10, 4) == 500);

    cout << "✅ All 10 test scenarios passed successfully for LC 1011 (Capacity To Ship Packages Within D Days)!" << endl;
    return 0;
}

