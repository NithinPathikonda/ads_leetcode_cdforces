/**
 * Problem: LC 3963 - Create Grid With Exactly One Path
 * Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
 * Date: 2026-10-27 (LeetCode Problem of the Day)
 * Topic: Constructive Algorithms / Matrix Traversal / Grid
 * Difficulty: Easy
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given two integers m and n, representing the number of rows and columns of a
 * grid, construct and return an m x n grid consisting of '.' (empty cell) and
 * '#' (obstacle) such that there is EXACTLY ONE valid path from the top-left
 * cell (0, 0) to the bottom-right cell (m - 1, n - 1).
 *
 * Valid moves are restricted to moving Down (i + 1, j) or Right (i, j + 1).
 *
 * Constraints:
 * 1 <= m, n <= 100
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Time Complexity: O(m * n)
 *     We iterate across all m x n cells exactly once to populate the grid strings.
 * - Space Complexity: O(1) auxiliary (O(m * n) output space)
 *     No additional data structures beyond the returned grid.
 *
 * Pattern / Trigger:
 * - Constructive Unique Path:
 *     In any grid where moves are only Right and Down, to guarantee exactly one
 *     path, we must eliminate any branching. The simplest canonical single path
 *     is an L-shaped path:
 *     1. Traverse all the way across the first row (0, 0) -> (0, n - 1).
 *     2. Traverse all the way down the last column (0, n - 1) -> (m - 1, n - 1).
 *     3. Fill all other cells with obstacles ('#').
 *     Since (0, 0) only has one open neighbor (0, 1), and each cell along the
 *     boundary only has one open forward neighbor, branching is strictly 0.
 *
 * Critical Edge Cases:
 * - m = 1, n = 1: Single cell (0, 0), which is '.' (path length 1).
 * - m = 1, n > 1: Single row, all '.', exactly 1 path (moving only Right).
 * - m > 1, n = 1: Single column, all '.', exactly 1 path (moving only Down).
 * -------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: User's Direct Cell-by-Cell Construction
    // Time: O(m * n), Space: O(1) auxiliary
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        for (int i = 0; i < m; i++) {
            string temp = "";
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == n - 1) {
                    temp += ".";
                } else {
                    temp += "#";
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }

    // Approach 2: Pre-allocated String Construction (Slightly more cache-friendly)
    // Time: O(m * n), Space: O(1) auxiliary
    vector<string> createGridOptimal(int m, int n) {
        vector<string> grid(m, string(n, '#'));
        for (int j = 0; j < n; ++j) {
            grid[0][j] = '.';
        }
        for (int i = 0; i < m; ++i) {
            grid[i][n - 1] = '.';
        }
        return grid;
    }
};

// Helper function to count paths from (0, 0) to (m - 1, n - 1) using DP
long long countPaths(const vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    if (grid[0][0] == '#' || grid[m - 1][n - 1] == '#') return 0;

    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    dp[0][0] = 1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '#') continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    Solution sol;

    // Test 1: Standard 3x3 Grid
    {
        int m = 3, n = 3;
        auto grid = sol.createGrid(m, n);
        long long paths = countPaths(grid);
        cout << "Test 1 (3x3): " << paths << " path(s) (Expected: 1) -> "
             << (paths == 1 ? "PASSED" : "FAILED") << "\n";
        cout << "Generated Grid:\n";
        for (const auto& row : grid) {
            cout << "  " << row << "\n";
        }
    }

    // Test 2: Single Row (1x5)
    {
        int m = 1, n = 5;
        auto grid = sol.createGrid(m, n);
        long long paths = countPaths(grid);
        cout << "\nTest 2 (1x5): " << paths << " path(s) (Expected: 1) -> "
             << (paths == 1 ? "PASSED" : "FAILED") << "\n";
    }

    // Test 3: Single Column (5x1)
    {
        int m = 5, n = 1;
        auto grid = sol.createGrid(m, n);
        long long paths = countPaths(grid);
        cout << "\nTest 3 (5x1): " << paths << " path(s) (Expected: 1) -> "
             << (paths == 1 ? "PASSED" : "FAILED") << "\n";
    }

    // Test 4: Single Cell (1x1)
    {
        int m = 1, n = 1;
        auto grid = sol.createGrid(m, n);
        long long paths = countPaths(grid);
        cout << "\nTest 4 (1x1): " << paths << " path(s) (Expected: 1) -> "
             << (paths == 1 ? "PASSED" : "FAILED") << "\n";
    }

    // Test 5: Asymmetric Grid (4x7)
    {
        int m = 4, n = 7;
        auto grid = sol.createGrid(m, n);
        long long paths = countPaths(grid);
        cout << "\nTest 5 (4x7): " << paths << " path(s) (Expected: 1) -> "
             << (paths == 1 ? "PASSED" : "FAILED") << "\n";
    }

    return 0;
}
