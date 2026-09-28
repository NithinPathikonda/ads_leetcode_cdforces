/**
 * Problem 002: Best Time to Buy and Sell Stock
 * Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Topic: 01_arrays_hashing
 * Companies: Google, Meta, Amazon, Microsoft, Apple
 * Difficulty: Easy / Core Foundation
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * You are given an array 'prices' where prices[i] is the price of a given
 * stock on the ith day. You want to maximize profit by choosing a single
 * day to buy one stock and choosing a different day in the future to sell.
 *
 * Return maximum profit. If you cannot achieve any profit, return 0.
 *
 * Constraints:
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 * -------------------------------------------------------------
 *
 * Target Complexity:
 * - Time: O(N)
 * - Space: O(1)
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(const vector<int> &prices) {
    // TODO: Write your optimal O(N) Time, O(1) Space solution here
    int mini = prices[0], profit = 0;
    for (int i = 0; i < prices.size(); i++) {
      profit = max(profit, prices[i] - mini);
      mini = min(mini, prices[i]);
    }
    return profit;
  }
};

int main() {
  Solution sol;

  // Test 1: Standard profitable case
  vector<int> prices1 = {7, 1, 5, 3, 6, 4};
  int res1 = sol.maxProfit(prices1);
  cout << "Test 1: " << res1 << " (Expected: 5) -> "
       << (res1 == 5 ? "PASSED" : "FAILED") << "\n";

  // Test 2: Monotonically decreasing (no profit possible)
  vector<int> prices2 = {7, 6, 4, 3, 1};
  int res2 = sol.maxProfit(prices2);
  cout << "Test 2: " << res2 << " (Expected: 0) -> "
       << (res2 == 0 ? "PASSED" : "FAILED") << "\n";

  // Test 3: Single element
  vector<int> prices3 = {5};
  int res3 = sol.maxProfit(prices3);
  cout << "Test 3: " << res3 << " (Expected: 0) -> "
       << (res3 == 0 ? "PASSED" : "FAILED") << "\n";

  return 0;
}
