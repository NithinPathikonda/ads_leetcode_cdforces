/**
 * Problem 011: Spiral Matrix
 * Link: https://leetcode.com/problems/spiral-matrix/
 * Topic: 01_arrays_hashing
 * Companies: Microsoft, Apple, Amazon, Google, Meta, Cisco, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an m x n matrix, return all elements of the matrix in spiral order.
 *
 * Constraints:
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 10
 * -100 <= matrix[i][j] <= 100
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(M * N)
 *     Every element in the matrix is visited exactly once.
 * - Space Complexity: O(1) auxiliary space (excluding the output array).
 *
 * -------------------------------------------------------------
 * 🌟 THE GOLDEN RULE (Crucial Revision Note & Candidate Killer):
 * -------------------------------------------------------------
 * Why do we need `if (top <= bottom)` before going Left, and
 * `if (left <= right)` before going Up?
 *
 * Trace a Single-Row Matrix: matrix = [[1, 2, 3, 4]]
 * 1. Step 1 (Go Right across top): reads 1, 2, 3, 4 -> top becomes 1 (top > bottom!).
 * 2. Step 2 (Go Down across right): 1 <= 0 is false -> skipped, right becomes 2.
 * 3. Step 3 (Go Left across bottom):
 *    - WITHOUT `if (top <= bottom)`: It would read row 0 backwards (3, 2, 1),
 *      duplicating elements we ALREADY read in Step 1!
 *    - WITH `if (top <= bottom)`: Correctly skips this step.
 *
 * Trace a Single-Column Matrix: matrix = [[1], [2], [3]]
 * 1. Step 1 reads 1, top becomes 1.
 * 2. Step 2 reads 2, 3 down right column, right becomes -1 (left > right!).
 * 3. Step 4 (Go Up across left):
 *    - WITHOUT `if (left <= right)`: It would read column 0 upwards, duplicating elements!
 *    - WITH `if (left <= right)`: Correctly skips this step.
 *
 * In short:
 * - Before going Left: "Is there still a valid bottom row left that hasn't been crossed by top?" -> (top <= bottom)
 * - Before going Up: "Is there still a valid left column left that hasn't been crossed by right?" -> (left <= right)
 * -------------------------------------------------------------
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // User's Optimal 4-Boundary Layer Traversal Solution
    // Time: O(M * N), Space: O(1) auxiliary
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = col - 1;
        int top = 0, bottom = row - 1;
        vector<int> ans;
        ans.reserve(row * col);

        while (top <= bottom && left <= right) {
            // 1. Move Right: across the current 'top' row
            for (int i = left; i <= right; ++i) {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // 2. Move Down: along the current 'right' column
            for (int i = top; i <= bottom; ++i) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. Move Left: across the current 'bottom' row
            // GOLDEN RULE: Check if 'top' hasn't already crossed 'bottom' (prevents single-row duplicates)
            if (top <= bottom) {
                for (int i = right; i >= left; --i) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // 4. Move Up: along the current 'left' column
            // GOLDEN RULE: Check if 'left' hasn't already crossed 'right' (prevents single-column duplicates)
            if (left <= right) {
                for (int i = bottom; i >= top; --i) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // Test 1: 3x3 Square Matrix
    vector<vector<int>> m1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> expected1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    cout << "Test 1 (3x3): "
         << (sol.spiralOrder(m1) == expected1 ? "PASSED" : "FAILED") << "\n";

    // Test 2: 3x4 Rectangular Matrix
    vector<vector<int>> m2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> expected2 = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    cout << "Test 2 (3x4): "
         << (sol.spiralOrder(m2) == expected2 ? "PASSED" : "FAILED") << "\n";

    // Test 3: Single-Row Matrix (Validates top <= bottom Golden Rule!)
    vector<vector<int>> m3 = {
        {1, 2, 3, 4}
    };
    vector<int> expected3 = {1, 2, 3, 4};
    cout << "Test 3 (1x4 Single Row): "
         << (sol.spiralOrder(m3) == expected3 ? "PASSED" : "FAILED") << "\n";

    // Test 4: Single-Column Matrix (Validates left <= right Golden Rule!)
    vector<vector<int>> m4 = {
        {1},
        {2},
        {3}
    };
    vector<int> expected4 = {1, 2, 3};
    cout << "Test 4 (3x1 Single Col): "
         << (sol.spiralOrder(m4) == expected4 ? "PASSED" : "FAILED") << "\n";

    // Test 5: Single Element Matrix
    vector<vector<int>> m5 = {{42}};
    vector<int> expected5 = {42};
    cout << "Test 5 (1x1 Single Cell): "
         << (sol.spiralOrder(m5) == expected5 ? "PASSED" : "FAILED") << "\n";

    return 0;
}
