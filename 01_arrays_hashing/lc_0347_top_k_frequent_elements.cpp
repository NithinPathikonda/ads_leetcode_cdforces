/**
 * Problem 005: Top K Frequent Elements
 * Link: https://leetcode.com/problems/top-k-frequent-elements/
 * Topic: 01_arrays_hashing
 * Companies: Meta, Amazon, Google, Microsoft, Apple, Bloomberg
 * Difficulty: Medium / Core Interview Archetype
 *
 * -------------------------------------------------------------
 * Problem Statement:
 * Given an integer array nums and an integer k, return the k most frequent elements.
 * You may return the answer in any order.
 *
 * Constraints:
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 * -------------------------------------------------------------
 *
 * Complexity Analysis:
 * - Approach 1 (Frequency Map + Sorting - User's Solution):
 *     - Time Complexity: O(N + D log D)
 *       where N is nums.size() and D is the number of distinct elements (D <= N).
 *       Counting frequencies: O(N). Sorting distinct elements: O(D log D).
 *     - Space Complexity: O(D)
 *       Hash map and vector store D distinct elements and counts.
 *
 * - Approach 2 (Min-Heap of size K):
 *     - Time Complexity: O(N + D log K)
 *       Pushing into a min-heap capped at size K takes O(log K).
 *     - Space Complexity: O(D + K)
 *
 * - Approach 3 (Bucket Sort by Frequency - Optimal):
 *     - Time Complexity: O(N)
 *       Max possible frequency of any element is N.
 *       Create buckets[freq] where 1 <= freq <= N.
 *       Iterate backwards from bucket N down to 1 until k elements are collected.
 *     - Space Complexity: O(N)
 *
 * Pattern / Trigger:
 * - "Top K frequent" -> Frequency map + Bucket Sort (for strict O(N)) OR Min-Heap of size K.
 *
 * Critical Edge Cases:
 * - All elements identical (e.g., nums = [1,1,1], k = 1) -> [1].
 * - All elements distinct (e.g., nums = [1,2,3], k = 2) -> any 2 elements.
 * - Negative numbers (e.g., nums = [-1, -1, 2], k = 1) -> [-1].
 * - Single element array (e.g., nums = [5], k = 1) -> [5].
 * -------------------------------------------------------------
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    // Approach 1: Frequency Map + Sort Vector (User Solution)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        vector<pair<int, int>> sorter;
        sorter.reserve(mpp.size());
        for (const auto& it : mpp) {
            sorter.push_back({it.first, it.second});
        }

        // Sort descending by frequency
        sort(sorter.begin(), sorter.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        vector<int> ans;
        ans.reserve(k);
        for (int i = 0; i < k; ++i) {
            ans.push_back(sorter[i].first);
        }
        return ans;
    }

    // Approach 2: Bucket Sort by Frequency (Optimal O(N) Time)
    vector<int> topKFrequentBucketSort(const vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        // Buckets index represents frequency; max possible frequency is nums.size()
        int n = static_cast<int>(nums.size());
        vector<vector<int>> buckets(n + 1);
        for (const auto& [val, freq] : mpp) {
            buckets[freq].push_back(val);
        }

        vector<int> ans;
        ans.reserve(k);
        // Traverse buckets from highest frequency down to lowest
        for (int freq = n; freq >= 1 && static_cast<int>(ans.size()) < k; --freq) {
            for (int val : buckets[freq]) {
                ans.push_back(val);
                if (static_cast<int>(ans.size()) == k) break;
            }
        }
        return ans;
    }

    // Approach 3: Min-Heap of Size K (O(N log K) Time, O(D + K) Space)
    vector<int> topKFrequentMinHeap(const vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        // Min-heap storing pair<frequency, value>
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<P>> min_heap;

        for (const auto& [val, freq] : mpp) {
            min_heap.push({freq, val});
            if (static_cast<int>(min_heap.size()) > k) {
                min_heap.pop();
            }
        }

        vector<int> ans;
        ans.reserve(k);
        while (!min_heap.empty()) {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};

// Helper to check if two vectors have the same set of elements
bool matchSet(vector<int> a, vector<int> b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    Solution sol;

    // Test 1: Standard case
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    int k1 = 2;
    auto res1 = sol.topKFrequent(nums1, k1);
    cout << "Test 1: [";
    for (size_t i = 0; i < res1.size(); ++i) cout << res1[i] << (i + 1 < res1.size() ? ", " : "");
    cout << "] (Expected: [1, 2]) -> "
         << (matchSet(res1, {1, 2}) ? "PASSED" : "FAILED") << "\n";

    // Test 2: Single element
    vector<int> nums2 = {1};
    int k2 = 1;
    auto res2 = sol.topKFrequent(nums2, k2);
    cout << "Test 2: [";
    for (size_t i = 0; i < res2.size(); ++i) cout << res2[i] << (i + 1 < res2.size() ? ", " : "");
    cout << "] (Expected: [1]) -> "
         << (matchSet(res2, {1}) ? "PASSED" : "FAILED") << "\n";

    // Test 3: Negative numbers
    vector<int> nums3 = {-1, -1, -2, -2, -2, 5};
    int k3 = 2;
    auto res3 = sol.topKFrequent(nums3, k3);
    cout << "Test 3: [";
    for (size_t i = 0; i < res3.size(); ++i) cout << res3[i] << (i + 1 < res3.size() ? ", " : "");
    cout << "] (Expected: [-2, -1]) -> "
         << (matchSet(res3, {-2, -1}) ? "PASSED" : "FAILED") << "\n";

    // Test 4: Verify O(N) Bucket Sort matches expected output
    auto res_bucket = sol.topKFrequentBucketSort(nums1, k1);
    cout << "Test 4 (Bucket Sort O(N)): "
         << (matchSet(res_bucket, {1, 2}) ? "PASSED" : "FAILED") << "\n";

    return 0;
}
