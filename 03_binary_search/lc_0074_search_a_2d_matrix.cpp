/**
 * ============================================================================
 * Problem: LC 74 - Search a 2D Matrix
 * Difficulty: Medium
 * Pattern: Binary Search / 2D Matrix Coordinate Flattening
 * Target MNCs: Microsoft, Amazon, Meta, Apple, Google
 * 
 * Invariant:
 *   Because the matrix satisfies:
 *     1. Each row is sorted in non-decreasing order.
 *     2. The first integer of each row > last integer of the previous row.
 *   The entire M x N matrix forms a strictly monotonic 1D array of length M * N.
 * 
 * Coordinate Transformation:
 *   Given 1D index `mid` in [0, M * N - 1]:
 *     row = mid / cols
 *     col = mid % cols
 *     val = matrix[row][col]
 * 
 * Complexity:
 *   - Time:  O(log(M * N))
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
    // Time: O(log(M * N)) | Space: O(1)
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int n = matrix.size();       // Number of rows
        int m = matrix[0].size();    // Number of columns

        int l = 0, r = n * m - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int temp = matrix[mid / m][mid % m]; // Divide & modulo by column count 'm'

            if (temp == target) {
                return true;
            } else if (temp < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
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

    // Test 1: Standard 3x4 matrix (target exists in first row)
    vector<vector<int>> m1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    assert(solver.searchMatrix(m1, 3) == true);

    // Test 2: Standard 3x4 matrix (target does not exist)
    assert(solver.searchMatrix(m1, 13) == false);

    // Test 3: Search for first element
    assert(solver.searchMatrix(m1, 1) == true);

    // Test 4: Search for last element
    assert(solver.searchMatrix(m1, 60) == true);

    // Test 5: Target smaller than smallest element
    assert(solver.searchMatrix(m1, 0) == false);

    // Test 6: Target larger than largest element
    assert(solver.searchMatrix(m1, 100) == false);

    // Test 7: 1x1 matrix (hit)
    vector<vector<int>> m2 = {{5}};
    assert(solver.searchMatrix(m2, 5) == true);

    // Test 8: 1x1 matrix (miss)
    assert(solver.searchMatrix(m2, 6) == false);

    // Test 9: 1xN matrix (single row)
    vector<vector<int>> m3 = {{1, 3, 5, 7, 9}};
    assert(solver.searchMatrix(m3, 7) == true);
    assert(solver.searchMatrix(m3, 4) == false);

    // Test 10: Mx1 matrix (single column)
    vector<vector<int>> m4 = {{1}, {3}, {5}, {7}, {9}};
    assert(solver.searchMatrix(m4, 5) == true);
    assert(solver.searchMatrix(m4, 8) == false);

    cout << "✅ All 10 test scenarios passed successfully for LC 74!" << endl;
    return 0;
}
