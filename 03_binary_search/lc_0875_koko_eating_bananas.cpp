/**
 * ============================================================================
 * Problem: LC 875 - Koko Eating Bananas
 * Difficulty: Medium
 * Pattern: Binary Search on Answer / Monotonic Predicate
 * Target MNCs: Google, Amazon, Meta, Bloomberg, Uber, Airbnb, Microsoft
 * 
 * Invariant & Mathematical Formulation:
 *   Let k be the eating speed (bananas per hour).
 *   For each pile p, the hours required to finish it is:
 *       ceil(p / k) = (p + k - 1) / k
 *   
 *   Total hours needed at speed k:
 *       f(k) = sum(ceil(piles[i] / k)) for all piles
 *   
 *   Monotonicity Property:
 *     As speed k increases, total hours f(k) is monotonically non-increasing.
 *     Condition: f(k) <= h
 *     Predicate: [false, false, ..., false, true, true, ..., true]
 *     We seek the MINIMUM k such that f(k) <= h (the first 'true').
 * 
 * Search Space:
 *   - Lower Bound: low = 1 (Koko eats at least 1 banana/hr)
 *   - Upper Bound: high = max(piles) (since h >= piles.size(), speed > max(piles)
 *     still takes 1 hr/pile = piles.size() <= h hours, so max(piles) is sufficient)
 * 
 * Complexity:
 *   - Time:  O(N * log(max(piles))) where N = piles.size()
 *   - Space: O(1) auxiliary space
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
private:
    /**
     * Helper predicate: checks if Koko can finish all bananas within h hours at speed k.
     * Uses 64-bit integer (long long) for total_hours to prevent integer overflow.
     */
    bool canFinish(const vector<int>& piles, int h, int k) {
        long long total_hours = 0;
        for (int pile : piles) {
            // Equivalent to ceil(pile / (double)k) avoiding floating-point inaccuracies
            total_hours += (pile + (long long)k - 1) / k;
            if (total_hours > h) {
                return false; // Early termination optimization
            }
        }
        return total_hours <= h;
    }

public:
    int minEatingSpeed(const vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                ans = mid;         // Feasible speed, try to find a smaller valid speed
                high = mid - 1;    // Search left half
            } else {
                low = mid + 1;     // Too slow, need higher speed -> search right half
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
    // piles = [3, 6, 7, 11], h = 8 -> expected 4
    vector<int> t1 = {3, 6, 7, 11};
    assert(solver.minEatingSpeed(t1, 8) == 4);

    // Test 2: Standard LeetCode Example 2
    // piles = [30, 11, 23, 4, 20], h = 5 -> expected 30 (h == piles.size())
    vector<int> t2 = {30, 11, 23, 4, 20};
    assert(solver.minEatingSpeed(t2, 5) == 30);

    // Test 3: Standard LeetCode Example 3
    // piles = [30, 11, 23, 4, 20], h = 6 -> expected 23
    vector<int> t3 = {30, 11, 23, 4, 20};
    assert(solver.minEatingSpeed(t3, 6) == 23);

    // Test 4: Single pile, exact division
    // piles = [10], h = 2 -> expected 5 (ceil(10/5) = 2)
    vector<int> t4 = {10};
    assert(solver.minEatingSpeed(t4, 2) == 5);

    // Test 5: Single pile, non-exact division
    // piles = [10], h = 3 -> expected 4 (ceil(10/4) = 3)
    vector<int> t5 = {10};
    assert(solver.minEatingSpeed(t5, 3) == 4);

    // Test 6: Huge hours available (h >= sum(piles)) -> minimum speed is 1
    vector<int> t6 = {3, 6, 7, 11};
    assert(solver.minEatingSpeed(t6, 100) == 1);

    // Test 7: All identical piles
    // piles = [8, 8, 8, 8], h = 8 -> expected 4 (each takes 2 hrs)
    vector<int> t7 = {8, 8, 8, 8};
    assert(solver.minEatingSpeed(t7, 8) == 4);

    // Test 8: Large pile sizes avoiding 32-bit overflow
    // piles = [1000000000], h = 2 -> expected 500000000
    vector<int> t8 = {1000000000};
    assert(solver.minEatingSpeed(t8, 2) == 500000000);

    // Test 9: Multiple large piles requiring 64-bit hour accumulation
    // piles = [10^9, 10^9], h = 10^9 -> expected 2
    vector<int> t9 = {1000000000, 1000000000};
    assert(solver.minEatingSpeed(t9, 1000000000) == 2);

    cout << "✅ All 9 test scenarios passed successfully for LC 875 (Koko Eating Bananas)!" << endl;
    return 0;
}

