/**
 * ============================================================================
 * Problem: LC 240 - Search a 2D Matrix II
 * Difficulty: Medium
 * Pattern: Binary Search Tree on Grid / Top-Right Staircase Search
 * Target MNCs: Amazon, Google, Microsoft, Meta, Apple
 * 
 * Invariant:
 *   Every row is sorted left-to-right; every column is sorted top-to-bottom.
 *   Starting at the Top-Right corner (row = 0, col = n - 1):
 *     - Moving Left (col--) strictly decreases values.
 *     - Moving Down (row++) strictly increases values.
 *   At each cell (row, col):
 *     - If matrix[row][col] == target: found -> return true.
 *     - If matrix[row][col] > target: all elements below in this column are
 *       even larger -> trim column (col--).
 *     - If matrix[row][col] < target: all elements to the left in this row are
 *       even smaller -> trim row (row++).
 * 
 * Complexity:
 *   - Time:  O(M + N) — each step trims 1 row or 1 column
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
    // Time: O(M + N) | Space: O(1)
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();

        // Start at the Top-Right Corner
        int row = 0, col = n - 1;

        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            }
            if (matrix[row][col] > target) {
                col--; // Shave off rightmost column
            } else {
                row++; // Shave off topmost row
            }
        }

        return false;
    }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
    Solution solver;

    // Standard 5x5 young tableau matrix
    vector<vector<int>> m1 = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    // Test 1: Element present in interior
    assert(solver.searchMatrix(m1, 5) == true);

    // Test 2: Element not present
    assert(solver.searchMatrix(m1, 20) == false);

    // Test 3: Top-Right corner itself
    assert(solver.searchMatrix(m1, 15) == true);

    // Test 4: Top-Left corner (smallest)
    assert(solver.searchMatrix(m1, 1) == true);

    // Test 5: Bottom-Right corner (largest)
    assert(solver.searchMatrix(m1, 30) == true);

    // Test 6: Bottom-Left corner
    assert(solver.searchMatrix(m1, 18) == true);

    // Test 7: Smaller than minimum
    assert(solver.searchMatrix(m1, 0) == false);

    // Test 8: Larger than maximum
    assert(solver.searchMatrix(m1, 100) == false);

    // Test 9: 1x1 matrix (hit)
    vector<vector<int>> m2 = {{-5}};
    assert(solver.searchMatrix(m2, -5) == true);

    // Test 10: 1x1 matrix (miss)
    assert(solver.searchMatrix(m2, -4) == false);

    // Test 11: 1xN single row
    vector<vector<int>> m3 = {{1, 4, 7, 11, 15}};
    assert(solver.searchMatrix(m3, 11) == true);
    assert(solver.searchMatrix(m3, 10) == false);

    // Test 12: Mx1 single column
    vector<vector<int>> m4 = {{1}, {2}, {3}, {10}, {18}};
    assert(solver.searchMatrix(m4, 10) == true);
    assert(solver.searchMatrix(m4, 9) == false);

    cout << "✅ All 12 test scenarios passed successfully for LC 240!" << endl;
    return 0;
}
