/**
 * ============================================================================
 * Problem: LC 904 - Fruit Into Baskets
 * Difficulty: Medium
 * Pattern: Dynamic Sliding Window (At Most K Distinct Elements, K = 2)
 * Target MNCs: Google, Amazon, Meta, Microsoft
 * 
 * Approaches Included:
 *   1. Classic Dynamic Window (Intuitive `while (mpp.size() > 2)`)
 *   2. Optimal Non-Shrinking Window (User's `if (mpp.size() > 2)` Ratchet)
 * 
 * Complexity:
 *   - Time:  O(N) where N = fruits.length()
 *   - Space: O(1) auxiliary space (hash map contains at most 3 entries)
 * ============================================================================
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

// ============================================================================
// Approach 1: Classic Dynamic Sliding Window (`while` loop)
// Standard interview approach: expand r, shrink l until window is valid (<= 2).
// Time: O(N) | Space: O(1) (at most 3 keys in hash map)
// ============================================================================
class SolutionClassic {
public:
    int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> count;
        int l = 0, max_fruits = 0;
        int n = fruits.size();

        for (int r = 0; r < n; ++r) {
            count[fruits[r]]++;

            // Shrink window from the left while we exceed 2 distinct fruit types
            while (count.size() > 2) {
                count[fruits[l]]--;
                if (count[fruits[l]] == 0) {
                    count.erase(fruits[l]);
                }
                l++;
            }

            max_fruits = max(max_fruits, r - l + 1);
        }

        return max_fruits;
    }
};

// ============================================================================
// Approach 2: Optimal Non-Shrinking Sliding Window (User's Ratchet `if`)
// The window size `r - l + 1` never decreases. Once it reaches a valid size W,
// it only slides forward without shrinking. If invalid, both r and l advance.
// Time: O(N) strictly 1-pass | Space: O(1)
// ============================================================================
class SolutionNonShrinking {
public:
    int totalFruit(const vector<int>& fruits) {
        unordered_map<int, int> mpp;
        int l = 0, r = 0;
        int n = fruits.size();
        int ans = 0;

        for (r = 0; r < n; ++r) {
            mpp[fruits[r]]++;

            // If invalid, shift left boundary by 1 to maintain maximum window size
            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};

// ============================================================================
// Verification Test Suite
// ============================================================================
int main() {
    SolutionClassic s1;
    SolutionNonShrinking s2;

    auto run_tests = [&](const string& name, auto& solver) {
        cout << "Testing " << name << "..." << endl;

        // Test 1: Standard alternating 2 fruits
        assert(solver.totalFruit({1, 2, 1}) == 3);

        // Test 2: Skip first tree for longer streak
        assert(solver.totalFruit({0, 1, 2, 2}) == 3);

        // Test 3: Multiple occurrences of 2 types
        assert(solver.totalFruit({1, 2, 3, 2, 2}) == 4);

        // Test 4: Single tree
        assert(solver.totalFruit({42}) == 1);

        // Test 5: All trees identical
        assert(solver.totalFruit({5, 5, 5, 5, 5}) == 5);

        // Test 6: Many transitions
        assert(solver.totalFruit({3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4}) == 5);

        cout << "  ✅ Passed all test scenarios!" << endl;
    };

    run_tests("Approach 1 (Classic While)", s1);
    run_tests("Approach 2 (User's Non-Shrinking If)", s2);

    cout << "\n🎉 ALL ALGORITHMIC IMPLEMENTATIONS VERIFIED CORRECT!" << endl;
    return 0;
}
