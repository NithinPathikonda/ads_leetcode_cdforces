/**
 * ============================================================================
 * Problem: LC 20 - Valid Parentheses
 * Difficulty: Easy / Foundation
 * Pattern: Delimiter Matching / LIFO Stack Invariant
 * Target MNCs: Google, Meta, Amazon, Microsoft, Apple, Bloomberg
 *
 * Invariant:
 *   A string of brackets is valid if and only if:
 *     1. Open brackets must be closed by the same type of brackets.
 *     2. Open brackets must be closed in the correct order (LIFO).
 *     3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Mechanism:
 *   - Use std::stack<char> to track opening brackets.
 *   - Early exit: If string length is odd (s.size() % 2 != 0), it is mathematically
 *     impossible to be balanced -> return false.
 *   - For each opening bracket ('(', '{', '['), push it onto the stack.
 *   - For each closing bracket (')', '}', ']'):
 *       - If stack is empty -> invalid (closing bracket without opener) -> return false.
 *       - Check if top of stack matches the counterpart opener. If match -> pop.
 *       - If mismatch -> invalid -> return false.
 *   - At end of traversal, stack must be completely empty (return stack.empty()).
 *
 * Complexity:
 *   - Time:  O(N) — single pass through the string of length N
 *   - Space: O(N) auxiliary space — stack holds at most N/2 opening brackets
 * ============================================================================
 */

#include <cassert>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  // User's Verified Optimal Solution
  // Time: O(N) | Space: O(N)
  bool isValid(string s) {
    stack<char> stack;
    if (s.size() % 2 != 0)
      return false;

    for (size_t i = 0; i < s.size(); i++) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        stack.push(s[i]);
      } else {
        if (stack.empty())
          return false;
        char temp = stack.top();
        if (s[i] == ')' && temp == '(') {
          stack.pop();
        } else if (s[i] == ']' && temp == '[') {
          stack.pop();
        } else if (s[i] == '}' && temp == '{') {
          stack.pop();
        } else {
          return false;
        }
      }
    }

    return stack.empty();
  }
};

// ============================================================================
// Comprehensive Unit Test Suite
// ============================================================================
int main() {
  Solution solver;

  // Test 1: Single matching pair
  assert(solver.isValid("()") == true);

  // Test 2: Sequential multiple bracket types
  assert(solver.isValid("()[]{}") == true);

  // Test 3: Simple mismatch
  assert(solver.isValid("(]") == false);

  // Test 4: Nested valid structure
  assert(solver.isValid("([])") == true);

  // Test 5: Complex deeply nested valid structure
  assert(solver.isValid("{[()()]{[]}}") == true);

  // Test 6: Incorrect nesting / crossing brackets
  assert(solver.isValid("([)]") == false);

  // Test 7: Single character (odd length)
  assert(solver.isValid("(") == false);
  assert(solver.isValid("]") == false);

  // Test 8: Odd length unbalanced
  assert(solver.isValid("(){") == false);

  // Test 9: Starts with closing bracket
  assert(solver.isValid("]()[") == false);

  // Test 10: Only opening brackets
  assert(solver.isValid("(((((") == false);

  // Test 11: Only closing brackets
  assert(solver.isValid("))))))") == false);

  // Test 12: Empty string
  assert(solver.isValid("") == true);

  cout << "✅ All 12 test scenarios passed successfully for LC 20 (Valid Parentheses)!"
       << endl;
  return 0;
}
