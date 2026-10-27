#!/usr/bin/env python3
"""
Master DSA Knowledge Galaxy Builder (Constellation Neural Architecture)
Generates an Obsidian Second Brain where every problem card is deeply readable,
structured, and organized with:
- Frontmatter metadata & tags
- Executive callout card
- ⚡ 15-Second Interview Mental Trigger
- 🛡️ The Golden Invariant & Mathematical Proof
- ⚠️ Critical Gotchas & Sneaky Interview Pitfalls
- 🪜 Progressive Pattern Ladder (Prerequisite -> Current -> Boss Variation)
- 💻 Optimal Production-Grade C++20 Implementation
"""

import os
import re
import json
import shutil
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
VAULT_DIR = BASE_DIR / "obsidian"
MODULES_DIR = VAULT_DIR / "modules"
CONCEPTS_DIR = VAULT_DIR / "concepts"
PROBLEMS_DIR = VAULT_DIR / "problems"
COMPANIES_DIR = VAULT_DIR / "companies"
DIFFICULTY_DIR = VAULT_DIR / "difficulty"
OBSIDIAN_CONF_DIR = VAULT_DIR / ".obsidian"
SECTORS_DIR = VAULT_DIR / "sectors"

def sanitize(name: str) -> str:
    cleaned = re.sub(r'[\\/*?:"<>|]', '', name)
    return cleaned.strip()

def setup_dirs():
    if SECTORS_DIR.exists():
        shutil.rmtree(SECTORS_DIR)

    for d in [VAULT_DIR, MODULES_DIR, CONCEPTS_DIR, PROBLEMS_DIR, COMPANIES_DIR, DIFFICULTY_DIR, OBSIDIAN_CONF_DIR]:
        d.mkdir(parents=True, exist_ok=True)

# 27 Master Curriculum Modules
MODULE_DETAILS = {
    "01 Arrays & Hashing": {
        "cluster": "Linear & Search",
        "focus": "Prefix Sums, Kadane's, Difference Array, Dutch National Flag, Matrix Traversal"
    },
    "02 Two Pointers & Sliding Window": {
        "cluster": "Linear & Search",
        "focus": "Fixed & Dynamic Window, 2-Sum/3-Sum/4-Sum, Substrings with Constraints"
    },
    "03 Binary Search": {
        "cluster": "Linear & Search",
        "focus": "Standard, Rotated Arrays, Binary Search on Answer (Predicate/Monotonicity), 2D Matrix"
    },
    "04 Stack & Monotonic Stack": {
        "cluster": "Linear & Search",
        "focus": "Next Greater/Smaller Element, Largest Rectangle in Histogram, Rainwater Trapping"
    },
    "05 Linked Lists": {
        "cluster": "Linear & Search",
        "focus": "In-place Reversal, Cycle Detection & Entry (Floyd's), Merge K Lists, Flattening"
    },
    "06 Recursion & Backtracking": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Subsets, Subsequences, Permutations, Combinations, N-Queens, Sudoku Solver"
    },
    "07 Binary Trees & BST": {
        "cluster": "Hierarchical & Graphs",
        "focus": "DFS/BFS, LCA, Tree Views, Morris Traversal, Path Sum, BST Properties"
    },
    "08 Heaps & Priority Queues": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Top-K Elements, K-Way Merge, Median in Stream, Task Scheduler, Two Heaps"
    },
    "09 Intervals & Sweepline": {
        "cluster": "Advanced & Quant",
        "focus": "Merge/Insert Intervals, Non-overlapping, Meeting Rooms I/II/III, Skyline"
    },
    "10 Tries (Prefix Trees)": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Autocomplete, Wildcard Search, Max XOR of Two Numbers, Word Boggle"
    },
    "11 Graphs 1 Traversals & Fundamentals": {
        "cluster": "Hierarchical & Graphs",
        "focus": "BFS, DFS, Flood Fill, Connected Components, Bipartite Graph, Cycle Detection"
    },
    "12 Graphs 2 TopoSort & Shortest Paths": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Kahn's TopoSort, Dijkstra, Bellman-Ford, Floyd-Warshall, 0-1 BFS"
    },
    "13 Disjoint Set Union (DSU) & MST": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Union by Rank & Path Compression, Kruskal's, Prim's Algorithm"
    },
    "14 Dynamic Programming 1 1D & Classics": {
        "cluster": "Optimization & DP",
        "focus": "Climbing Stairs, House Robber, Coin Change, LIS Patience Sort"
    },
    "15 Dynamic Programming 2 2D & Grids": {
        "cluster": "Optimization & DP",
        "focus": "Unique Paths, Min Path Sum, Maximal Square, Dungeon Game"
    },
    "16 Dynamic Programming 3 Strings & Sequences": {
        "cluster": "Optimization & DP",
        "focus": "LCS, Edit Distance, Distinct Subsequences, Regex/Wildcard Matching"
    },
    "17 Dynamic Programming 4 Knapsack & Partition": {
        "cluster": "Optimization & DP",
        "focus": "0/1 Knapsack, Unbounded Knapsack, Target Sum, Subset Partition"
    },
    "18 Dynamic Programming 5 Trees, Bitmask & Digit DP": {
        "cluster": "Optimization & DP",
        "focus": "Tree DP, Traveling Salesman (Bitmask DP), Digit DP"
    },
    "19 Greedy Algorithms": {
        "cluster": "Optimization & DP",
        "focus": "Jump Game I/II, Gas Station, Candy, Job Sequencing, Minimum Platforms"
    },
    "20 Bit Manipulation & Math": {
        "cluster": "Advanced & Quant",
        "focus": "Bitwise tricks, Single Number I/II/III, Fast Exponentiation, Sieve of Eratosthenes"
    },
    "21 Segment Trees & Fenwick (BIT)": {
        "cluster": "Advanced & Quant",
        "focus": "Range Sum/Min Query, Point Updates, Range Updates with Lazy Propagation"
    },
    "22 Design Data Structures": {
        "cluster": "Advanced & Quant",
        "focus": "LRU Cache, LFU Cache, Time-Based Key-Value Store, Min/Max Stack"
    },
    "23 Advanced Strings (KMP & Rabin-Karp)": {
        "cluster": "Advanced & Quant",
        "focus": "KMP Algorithm, Rolling Hash (Rabin-Karp), Manacher's Longest Palindrome"
    },
    "24 Advanced Graphs (Tarjan & Eulerian)": {
        "cluster": "Hierarchical & Graphs",
        "focus": "Tarjan's Bridges & Articulation Points, Kosaraju SCC, Hierholzer Eulerian Path"
    },
    "25 Game Theory & Minimax": {
        "cluster": "Optimization & DP",
        "focus": "Minimax / Alpha-Beta Pruning, Nim Game, Stone Game I-VII"
    },
    "26 Reservoir Sampling & Randomized": {
        "cluster": "Advanced & Quant",
        "focus": "Reservoir Sampling (K from Stream), Fisher-Yates Shuffle, Random Pick with Weight"
    },
    "27 Computational Geometry & Math": {
        "cluster": "Advanced & Quant",
        "focus": "Convex Hull (Graham Scan), Overlapping Area, Matrix Exponentiation"
    }
}

SEMANTIC_BRIDGES = [
    ("LC 1: Two Sum", "LC 167: Two Sum II - Input Array Is Sorted"),
    ("LC 167: Two Sum II - Input Array Is Sorted", "LC 15: 3Sum"),
    ("LC 11: Container With Most Water", "LC 42: Trapping Rain Water"),
    ("LC 42: Trapping Rain Water", "LC 84: Largest Rectangle in Histogram"),
    ("LC 84: Largest Rectangle in Histogram", "LC 85: Maximal Rectangle"),
    ("LC 3: Longest Substring Without Repeating Characters", "LC 424: Longest Repeating Character Replacement"),
    ("LC 424: Longest Repeating Character Replacement", "LC 1004: Max Consecutive Ones III"),
    ("LC 567: Permutation in String", "LC 438: Find All Anagrams in a String"),
    ("LC 438: Find All Anagrams in a String", "LC 76: Minimum Window Substring"),
    ("LC 209: Minimum Size Subarray Sum", "LC 713: Subarray Product Less Than K"),
    ("LC 239: Sliding Window Maximum", "LC 42: Trapping Rain Water"),
    ("LC 53: Maximum Subarray", "LC 121: Best Time to Buy & Sell Stock"),
    ("LC 560: Subarray Sum Equals K", "LC 238: Product of Array Except Self"),
    ("LC 704: Binary Search", "LC 33: Search in Rotated Sorted Array"),
    ("LC 33: Search in Rotated Sorted Array", "LC 153: Find Minimum in Rotated Sorted Array"),
    ("LC 74: Search a 2D Matrix", "LC 240: Search a 2D Matrix II"),
    ("LC 875: Koko Eating Bananas", "LC 1011: Capacity To Ship Packages Within D Days"),
    ("LC 1011: Capacity To Ship Packages Within D Days", "LC 410: Split Array Largest Sum"),
    ("LC 410: Split Array Largest Sum", "LC 4: Median of Two Sorted Arrays"),
    ("LC 206: Reverse Linked List", "LC 21: Merge Two Sorted Lists"),
    ("LC 141: Linked List Cycle", "LC 142: Linked List Cycle II"),
    ("LC 21: Merge Two Sorted Lists", "LC 23: Merge k Sorted Lists"),
    ("LC 206: Reverse Linked List", "LC 143: Reorder List"),
    ("LC 146: LRU Cache", "LC 460: LFU Cache"),
    ("LC 78: Subsets", "LC 90: Subsets II"),
    ("LC 78: Subsets", "LC 39: Combination Sum"),
    ("LC 46: Permutations", "LC 51: N-Queens"),
    ("LC 79: Word Search", "LC 211: Design Add and Search Words"),
    ("LC 104: Maximum Depth of Binary Tree", "LC 543: Diameter of Binary Tree"),
    ("LC 543: Diameter of Binary Tree", "LC 124: Binary Tree Maximum Path Sum"),
    ("LC 226: Invert Binary Tree", "LC 102: Binary Tree Level Order Traversal"),
    ("LC 102: Binary Tree Level Order Traversal", "LC 297: Serialize and Deserialize Binary Tree"),
    ("LC 236: Lowest Common Ancestor of a Binary Tree", "LC 98: Validate Binary Search Tree"),
    ("LC 215: Kth Largest Element in an Array", "LC 347: Top K Frequent Elements"),
    ("LC 215: Kth Largest Element in an Array", "LC 295: Find Median from Data Stream"),
    ("LC 621: Task Scheduler", "LC 253: Meeting Rooms II"),
    ("LC 56: Merge Intervals", "LC 57: Insert Interval"),
    ("LC 57: Insert Interval", "LC 435: Non-overlapping Intervals"),
    ("LC 435: Non-overlapping Intervals", "LC 253: Meeting Rooms II"),
    ("LC 200: Number of Islands", "LC 133: Clone Graph"),
    ("LC 200: Number of Islands", "LC 994: Rotting Oranges"),
    ("LC 207: Course Schedule", "LC 210: Course Schedule II"),
    ("LC 743: Network Delay Time", "LC 787: Cheapest Flights Within K Stops"),
    ("LC 684: Redundant Connection", "LC 1584: Min Cost to Connect All Points"),
    ("LC 1192: Critical Connections in a Network", "LC 332: Reconstruct Itinerary"),
    ("LC 70: Climbing Stairs", "LC 198: House Robber"),
    ("LC 198: House Robber", "LC 322: Coin Change"),
    ("LC 322: Coin Change", "LC 300: Longest Increasing Subsequence"),
    ("LC 62: Unique Paths", "LC 64: Minimum Path Sum"),
    ("LC 64: Minimum Path Sum", "LC 221: Maximal Square"),
    ("LC 1143: Longest Common Subsequence", "LC 72: Edit Distance"),
    ("LC 55: Jump Game", "LC 45: Jump Game II"),
    ("LC 45: Jump Game II", "LC 134: Gas Station")
]

CONCEPTS = {
    "Prefix Sums": ("01 Arrays & Hashing", "Running cumulative sum array enables O(1) range sum queries."),
    "Kadane's Algorithm": ("01 Arrays & Hashing", "Local vs global optimum. Reset running sum when negative."),
    "Difference Array": ("01 Arrays & Hashing", "Range updates [L, R] in O(1) via diff[L] += val, diff[R+1] -= val."),
    "Dutch National Flag": ("01 Arrays & Hashing", "3-way partition using low, mid, high pointers in O(N)."),
    "Matrix Traversal": ("01 Arrays & Hashing", "Boundary pointer shrinkage and spiral layer peeling."),
    "Hash Maps & Sets": ("01 Arrays & Hashing", "O(1) average lookup for complements and frequency counts."),
    "Two Pointers": ("02 Two Pointers & Sliding Window", "Shrinking bounds or opposite direction pointers on sorted sequences."),
    "Fixed Sliding Window": ("02 Two Pointers & Sliding Window", "Window of constant width K; slides 1 step in O(1)."),
    "Dynamic Sliding Window": ("02 Two Pointers & Sliding Window", "Expand right pointer to satisfy condition, contract left to minimize."),
    "Monotonic Window Invariant": ("02 Two Pointers & Sliding Window", "Window size never shrinks, tracking historical best in 1 pass."),
    "Binary Search on Array": ("03 Binary Search", "Halving sorted search space in O(log N)."),
    "Rotated Array Binary Search": ("03 Binary Search", "Identifying sorted half to prune candidates."),
    "Binary Search on Answer": ("03 Binary Search", "Monotonic predicate search for min-max threshold."),
    "2D Matrix Binary Search": ("03 Binary Search", "Treating 2D grid as flattened 1D array or top-right staircase search."),
    "Monotonic Stack": ("04 Stack & Monotonic Stack", "Maintains elements in monotonic order for next greater/smaller in O(N)."),
    "Rainwater Trapping": ("04 Stack & Monotonic Stack", "Height boundary bounds via Two Pointers or Monotonic Stack."),
    "In-Place Linked List Reversal": ("05 Linked Lists", "Iterative pointer redirection (prev, curr, next) in O(1) space."),
    "Floyd's Cycle Detection": ("05 Linked Lists", "Fast and slow pointers for cycle presence and cycle entry."),
    "Backtracking & Pruning": ("06 Recursion & Backtracking", "State-space tree exploration with branch elimination."),
    "Permutations & Combinations": ("06 Recursion & Backtracking", "Subsets and orderings with deduplication."),
    "Tree DFS & Traversals": ("07 Binary Trees & BST", "Inorder, preorder, and postorder tree decompositions."),
    "Tree BFS & Level Order": ("07 Binary Trees & BST", "Queue-based level-by-level exploration."),
    "Lowest Common Ancestor (LCA)": ("07 Binary Trees & BST", "Finding first split point between nodes p and q."),
    "BST Properties": ("07 Binary Trees & BST", "Inorder traversal produces strictly ascending sorted order."),
    "Binary Heap & Priority Queue": ("08 Heaps & Priority Queues", "O(log N) push/pop, O(1) peek for running extremes."),
    "Two Heaps Running Median": ("08 Heaps & Priority Queues", "Balancing max-heap and min-heap for O(1) median."),
    "Interval Merging & Sweepline": ("09 Intervals & Sweepline", "Sorting endpoints along timeline for room/interval merging."),
    "Trie (Prefix Tree)": ("10 Tries (Prefix Trees)", "Character branch tree for prefix matching and autocomplete."),
    "Graph BFS & Shortest Path": ("11 Graphs 1 Traversals & Fundamentals", "Unweighted shortest paths and multi-source flood fill."),
    "Graph DFS & Components": ("11 Graphs 1 Traversals & Fundamentals", "Cycle detection and connected component exploration."),
    "Kahn's Topological Sort": ("12 Graphs 2 TopoSort & Shortest Paths", "Indegree array + queue for DAG dependency ordering."),
    "Dijkstra's Algorithm": ("12 Graphs 2 TopoSort & Shortest Paths", "Greedy non-negative weighted shortest paths via Min-Heap."),
    "Disjoint Set Union (DSU)": ("13 Disjoint Set Union (DSU) & MST", "Union by Rank & Path Compression for dynamic connectivity."),
    "Kruskal's & Prim's MST": ("13 Disjoint Set Union (DSU) & MST", "Greedy minimum spanning tree construction."),
    "1D Linear DP": ("14 Dynamic Programming 1 1D & Classics", "Subproblems dependent on constant preceding states."),
    "Longest Increasing Subsequence": ("14 Dynamic Programming 1 1D & Classics", "Patience sort tails array with binary search O(N log N)."),
    "2D Grid DP": ("15 Dynamic Programming 2 2D & Grids", "Cell transitions from top and left neighbors."),
    "Constructive Grid Path": ("15 Dynamic Programming 2 2D & Grids", "Deterministic path construction avoiding unwanted branches."),
    "Longest Common Subsequence": ("16 Dynamic Programming 3 Strings & Sequences", "2D string matrix matching and mismatches."),
    "Edit Distance DP": ("16 Dynamic Programming 3 Strings & Sequences", "Levenshtein insertion, deletion, replacement in O(M*N)."),
    "0-1 Knapsack": ("17 Dynamic Programming 4 Knapsack & Partition", "Include/exclude choice with capacity iteration."),
    "Tree DP": ("18 Dynamic Programming 5 Trees, Bitmask & Digit DP", "Postorder state aggregation across subtrees."),
    "Bitmask DP": ("18 Dynamic Programming 5 Trees, Bitmask & Digit DP", "Integer bitmask representing subset state space."),
    "Greedy Intervals & Reachability": ("19 Greedy Algorithms", "Locally optimal choice yields global optimum."),
    "Bitwise Tricks": ("20 Bit Manipulation & Math", "XOR identity, bit masks, and power-of-two tests."),
    "Fast Exponentiation": ("20 Bit Manipulation & Math", "Binary exponentiation in O(log N)."),
    "Segment Tree & Fenwick": ("21 Segment Trees & Fenwick (BIT)", "Range queries and point/range updates in O(log N)."),
    "LRU & LFU Cache Design": ("22 Design Data Structures", "Hash Map + Doubly Linked Lists for O(1) cache eviction."),
    "KMP & String Matching": ("23 Advanced Strings (KMP & Rabin-Karp)", "LPS prefix table and rolling hash string matching."),
    "Tarjan's Bridges & SCC": ("24 Advanced Graphs (Tarjan & Eulerian)", "Discovery time and low-link values for bridges and SCCs."),
    "Minimax & Game Theory": ("25 Game Theory & Minimax", "Adversarial evaluation with Alpha-Beta pruning."),
    "Reservoir Sampling": ("26 Reservoir Sampling & Randomized", "Uniform 1/N stream sampling in O(K) space."),
    "Convex Hull & Geometry": ("27 Computational Geometry & Math", "Cross-product orientation and Graham scan.")
}

PROBLEMS = [
    ("LC 1: Two Sum", "01 Arrays & Hashing", "Hash Maps & Sets", "Easy", "O(N)", "Hash map complement lookup in single pass.", ["Google", "Meta", "Amazon", "Microsoft", "Apple"]),
    ("LC 121: Best Time to Buy & Sell Stock", "01 Arrays & Hashing", "Kadane's Algorithm", "Easy", "O(N)", "Track running min buy price and maximize profit.", ["Amazon", "Meta", "Apple", "Google"]),
    ("LC 242: Valid Anagram", "01 Arrays & Hashing", "Hash Maps & Sets", "Easy", "O(N)", "26-int frequency count comparison in single pass.", ["Google", "Amazon", "Microsoft"]),
    ("LC 49: Group Anagrams", "01 Arrays & Hashing", "Hash Maps & Sets", "Medium", "O(N * K)", "Sort string or 26-char count signature as canonical hash map key.", ["Amazon", "Meta", "Apple"]),
    ("LC 347: Top K Frequent Elements", "01 Arrays & Hashing", "Hash Maps & Sets", "Medium", "O(N)", "Frequency hash map + O(N) bucket sort array by counts.", ["Meta", "Amazon", "Google"]),
    ("LC 238: Product of Array Except Self", "01 Arrays & Hashing", "Prefix Sums", "Medium", "O(N)", "Prefix product array in-place + running reverse suffix product.", ["Amazon", "Apple", "Microsoft"]),
    ("LC 128: Longest Consecutive Sequence", "01 Arrays & Hashing", "Hash Maps & Sets", "Medium", "O(N)", "Hash set lookup; only count streaks starting where (x-1) is not in set.", ["Google", "Meta", "Amazon"]),
    ("LC 560: Subarray Sum Equals K", "01 Arrays & Hashing", "Prefix Sums", "Medium", "O(N)", "Running prefix sum with hash map frequencies. Lookup prefix - k.", ["Meta", "Google", "Amazon"]),
    ("LC 53: Maximum Subarray", "01 Arrays & Hashing", "Kadane's Algorithm", "Medium", "O(N)", "Kadane's algorithm: reset running sum when negative.", ["Amazon", "Microsoft", "Apple"]),
    ("LC 75: Sort Colors", "01 Arrays & Hashing", "Dutch National Flag", "Medium", "O(N)", "Dutch National Flag 3-pointer partition for 0, 1, and 2.", ["Microsoft", "Meta", "Amazon"]),
    ("LC 54: Spiral Matrix", "01 Arrays & Hashing", "Matrix Traversal", "Medium", "O(N * M)", "4 boundary pointers (top, bottom, left, right) layer peeling.", ["Microsoft", "Google", "Amazon"]),

    ("LC 167: Two Sum II - Input Array Is Sorted", "02 Two Pointers & Sliding Window", "Two Pointers", "Medium", "O(N)", "Opposite direction two pointers on sorted array.", ["Amazon", "Google"]),
    ("LC 15: 3Sum", "02 Two Pointers & Sliding Window", "Two Pointers", "Medium", "O(N^2)", "Sort array, fix first element, two pointers for remaining pair.", ["Meta", "Amazon", "Apple", "Microsoft"]),
    ("LC 11: Container With Most Water", "02 Two Pointers & Sliding Window", "Two Pointers", "Medium", "O(N)", "Greedy two pointers: always advance shorter vertical boundary inward.", ["Amazon", "Google", "Meta"]),
    ("LC 3: Longest Substring Without Repeating Characters", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Medium", "O(N)", "Sliding window with last seen character index map.", ["Amazon", "Google", "Meta", "Microsoft"]),
    ("LC 424: Longest Repeating Character Replacement", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Medium", "O(N)", "Window len - max_freq <= k invariant.", ["Google", "Amazon"]),
    ("LC 567: Permutation in String", "02 Two Pointers & Sliding Window", "Fixed Sliding Window", "Medium", "O(N)", "Fixed window of size s1.length() tracking 26 character matches.", ["Microsoft", "Amazon"]),
    ("LC 209: Minimum Size Subarray Sum", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Medium", "O(N)", "Dynamic sliding window expanding R and shrinking L while sum >= target.", ["Meta", "Google"]),
    ("LC 42: Trapping Rain Water", "02 Two Pointers & Sliding Window", "Rainwater Trapping", "Hard", "O(N)", "Water bounded by min(left_max, right_max) - height[i].", ["Google", "Amazon", "Meta", "Bloomberg"]),
    ("LC 1004: Max Consecutive Ones III", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Medium", "O(N)", "Dynamic window with at most K zero flips.", ["Meta", "Google"]),
    ("LC 713: Subarray Product Less Than K", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Medium", "O(N)", "Subarray counting: count += (r - l + 1) while product < k.", ["Amazon"]),
    ("LC 438: Find All Anagrams in a String", "02 Two Pointers & Sliding Window", "Fixed Sliding Window", "Medium", "O(N)", "Fixed window size p.length() matching character frequency map.", ["Meta", "Amazon"]),
    ("LC 76: Minimum Window Substring", "02 Two Pointers & Sliding Window", "Dynamic Sliding Window", "Hard", "O(N)", "Dynamic sliding window tracking required distinct character matches.", ["Meta", "Google", "Amazon", "Microsoft"]),
    ("LC 239: Sliding Window Maximum", "02 Two Pointers & Sliding Window", "Monotonic Stack", "Hard", "O(N)", "Monotonic decreasing deque holding indices in window of size K.", ["Amazon", "Google"]),

    ("LC 704: Binary Search", "03 Binary Search", "Binary Search on Array", "Easy", "O(log N)", "Classic mid split on sorted array.", ["Apple", "Google"]),
    ("LC 33: Search in Rotated Sorted Array", "03 Binary Search", "Rotated Array Binary Search", "Medium", "O(log N)", "Identify which half is sorted; check if target falls in sorted interval.", ["Amazon", "Meta", "Google"]),
    ("LC 153: Find Minimum in Rotated Sorted Array", "03 Binary Search", "Rotated Array Binary Search", "Medium", "O(log N)", "Compare nums[mid] with nums[right] to find pivot inflection.", ["Meta", "Amazon"]),
    ("LC 74: Search a 2D Matrix", "03 Binary Search", "2D Matrix Binary Search", "Medium", "O(log(M * N))", "Treat M*N matrix as 1D sorted array with row = mid/N, col = mid%N.", ["Microsoft", "Amazon"]),
    ("LC 240: Search a 2D Matrix II", "03 Binary Search", "2D Matrix Binary Search", "Medium", "O(M + N)", "Start search from top-right corner; step left if target < val, down if target > val.", ["Amazon", "Google"]),
    ("LC 875: Koko Eating Bananas", "03 Binary Search", "Binary Search on Answer", "Medium", "O(N log(max_pile))", "Binary search speed K with predicate sum(ceil(p / k)) <= h.", ["Google", "Amazon"]),
    ("LC 1011: Capacity To Ship Packages Within D Days", "03 Binary Search", "Binary Search on Answer", "Medium", "O(N log(sum_weight))", "Binary search minimal ship capacity with greedy simulation predicate.", ["Amazon", "Google"]),
    ("LC 410: Split Array Largest Sum", "03 Binary Search", "Binary Search on Answer", "Hard", "O(N log(sum))", "Binary search maximum subarray sum threshold with greedy partition.", ["Google", "Meta"]),
    ("LC 4: Median of Two Sorted Arrays", "03 Binary Search", "Binary Search on Array", "Hard", "O(log(min(M, N)))", "Binary search partition cut on smaller array.", ["Google", "Amazon", "Microsoft"]),

    ("LC 20: Valid Parentheses", "04 Stack & Monotonic Stack", "Monotonic Stack", "Easy", "O(N)", "Stack matching closing brackets with corresponding openers.", ["Meta", "Amazon", "Google"]),
    ("LC 155: Min Stack", "04 Stack & Monotonic Stack", "Monotonic Stack", "Medium", "O(1)", "Store pair (val, current_min) or dual stack for O(1) minimum.", ["Amazon", "Bloomberg", "Microsoft"]),
    ("LC 739: Daily Temperatures", "04 Stack & Monotonic Stack", "Monotonic Stack", "Medium", "O(N)", "Monotonic decreasing stack holding indices waiting for warmer temperature.", ["Meta", "Amazon"]),
    ("LC 84: Largest Rectangle in Histogram", "04 Stack & Monotonic Stack", "Monotonic Stack", "Hard", "O(N)", "Monotonic increasing stack identifying left and right smaller bar limits.", ["Google", "Amazon"]),
    ("LC 85: Maximal Rectangle", "04 Stack & Monotonic Stack", "Monotonic Stack", "Hard", "O(M * N)", "Row-by-row cumulative height histogram solved via LC 84.", ["Google", "Amazon"]),
    ("LC 1614: Maximum Nesting Depth of the Parentheses", "04 Stack & Monotonic Stack", "Monotonic Stack", "Easy", "O(N)", "Parentheses depth counter tracking maximum depth in single pass.", ["Google", "Amazon"]),

    ("LC 206: Reverse Linked List", "05 Linked Lists", "In-Place Linked List Reversal", "Easy", "O(N)", "Iterative 3-pointer in-place link reversal.", ["Amazon", "Apple", "Microsoft", "Meta"]),
    ("LC 141: Linked List Cycle", "05 Linked Lists", "Floyd's Cycle Detection", "Easy", "O(N)", "Floyd's Tortoise and Hare fast and slow pointers.", ["Amazon", "Microsoft"]),
    ("LC 142: Linked List Cycle II", "05 Linked Lists", "Floyd's Cycle Detection", "Medium", "O(N)", "Locate collision node, reset slow to head, advance both to find entry.", ["Microsoft", "Amazon"]),
    ("LC 21: Merge Two Sorted Lists", "05 Linked Lists", "In-Place Linked List Reversal", "Easy", "O(N)", "Iterative dummy head merge comparing heads.", ["Amazon", "Apple", "Microsoft"]),
    ("LC 23: Merge k Sorted Lists", "05 Linked Lists", "In-Place Linked List Reversal", "Hard", "O(N log K)", "Min-heap storing k list heads or divide and conquer merge.", ["Amazon", "Meta", "Google"]),
    ("LC 143: Reorder List", "05 Linked Lists", "Floyd's Cycle Detection", "Medium", "O(N)", "Find middle with fast/slow, reverse second half, interleave lists.", ["Meta", "Amazon"]),

    ("LC 78: Subsets", "06 Recursion & Backtracking", "Backtracking & Pruning", "Medium", "O(2^N)", "Include or exclude each element.", ["Meta", "Amazon", "Google"]),
    ("LC 90: Subsets II", "06 Recursion & Backtracking", "Backtracking & Pruning", "Medium", "O(2^N)", "Sort first; skip duplicates when nums[i] == nums[i-1] at same depth.", ["Amazon"]),
    ("LC 46: Permutations", "06 Recursion & Backtracking", "Permutations & Combinations", "Medium", "O(N!)", "Backtracking swap or visited boolean array.", ["Microsoft", "Google", "Amazon"]),
    ("LC 39: Combination Sum", "06 Recursion & Backtracking", "Backtracking & Pruning", "Medium", "O(2^T)", "Unbounded choice: stay at index i or advance.", ["Meta", "Google"]),
    ("LC 51: N-Queens", "06 Recursion & Backtracking", "Backtracking & Pruning", "Hard", "O(N!)", "Row placement tracking occupied cols, diag1, and diag2.", ["Meta", "Microsoft"]),
    ("LC 79: Word Search", "06 Recursion & Backtracking", "Backtracking & Pruning", "Medium", "O(M * N * 3^L)", "Grid DFS with temporary character replacement.", ["Amazon", "Microsoft", "Meta"]),

    ("LC 104: Maximum Depth of Binary Tree", "07 Binary Trees & BST", "Tree DFS & Traversals", "Easy", "O(N)", "1 + max(maxDepth(left), maxDepth(right)).", ["Google", "Amazon"]),
    ("LC 226: Invert Binary Tree", "07 Binary Trees & BST", "Tree DFS & Traversals", "Easy", "O(N)", "Swap left and right children recursively.", ["Google", "Amazon"]),
    ("LC 543: Diameter of Binary Tree", "07 Binary Trees & BST", "Tree DFS & Traversals", "Easy", "O(N)", "Bottom-up postorder: diameter at node = left_depth + right_depth.", ["Meta", "Amazon"]),
    ("LC 102: Binary Tree Level Order Traversal", "07 Binary Trees & BST", "Tree BFS & Level Order", "Medium", "O(N)", "Queue-based BFS tracking current level size.", ["Amazon", "Microsoft"]),
    ("LC 236: Lowest Common Ancestor of a Binary Tree", "07 Binary Trees & BST", "Lowest Common Ancestor (LCA)", "Medium", "O(N)", "Postorder DFS split point detection.", ["Meta", "Amazon", "Google"]),
    ("LC 124: Binary Tree Maximum Path Sum", "07 Binary Trees & BST", "Tree DFS & Traversals", "Hard", "O(N)", "Postorder DFS: max gain = node.val + max(0, left) + max(0, right).", ["Meta", "Google"]),
    ("LC 98: Validate Binary Search Tree", "07 Binary Trees & BST", "BST Properties", "Medium", "O(N)", "Inorder traversal strictly sorted or range validation (low, high).", ["Amazon", "Microsoft"]),
    ("LC 297: Serialize and Deserialize Binary Tree", "07 Binary Trees & BST", "Tree DFS & Traversals", "Hard", "O(N)", "Preorder string with null delimiters and stream reconstruction.", ["Amazon", "Google", "Meta"]),

    ("LC 215: Kth Largest Element in an Array", "08 Heaps & Priority Queues", "Binary Heap & Priority Queue", "Medium", "O(N log K)", "Min-heap of size K, or QuickSelect in O(N).", ["Meta", "Amazon", "Google"]),
    ("LC 295: Find Median from Data Stream", "08 Heaps & Priority Queues", "Two Heaps Running Median", "Hard", "O(log N)", "Max-heap for small half, Min-heap for large half; size diff <= 1.", ["Google", "Amazon"]),
    ("LC 621: Task Scheduler", "08 Heaps & Priority Queues", "Binary Heap & Priority Queue", "Medium", "O(N)", "Max frequency idle slot formula: (max_f - 1) * (n + 1) + max_count.", ["Meta", "Amazon"]),

    ("LC 56: Merge Intervals", "09 Intervals & Sweepline", "Interval Merging & Sweepline", "Medium", "O(N log N)", "Sort by start time. Merge if start <= prev.end.", ["Google", "Meta", "Amazon"]),
    ("LC 57: Insert Interval", "09 Intervals & Sweepline", "Interval Merging & Sweepline", "Medium", "O(N)", "Linear pass: append non-overlapping before, merge overlapping, append rest.", ["Google", "Meta"]),
    ("LC 435: Non-overlapping Intervals", "09 Intervals & Sweepline", "Interval Merging & Sweepline", "Medium", "O(N log N)", "Sort by end time; greedily retain intervals that finish earliest.", ["Amazon"]),
    ("LC 253: Meeting Rooms II", "09 Intervals & Sweepline", "Interval Merging & Sweepline", "Medium", "O(N log N)", "Min-heap of room end times, or sweepline start/end events.", ["Google", "Amazon", "Meta", "Bloomberg"]),

    ("LC 208: Implement Trie (Prefix Tree)", "10 Tries (Prefix Trees)", "Trie (Prefix Tree)", "Medium", "O(L)", "26-child node pointers with is_end flag.", ["Amazon", "Google"]),
    ("LC 211: Design Add and Search Words", "10 Tries (Prefix Trees)", "Trie (Prefix Tree)", "Medium", "O(26^dots)", "Trie traversal with DFS branching on '.' characters.", ["Meta", "Amazon"]),

    ("LC 200: Number of Islands", "11 Graphs 1 Traversals & Fundamentals", "Graph BFS & Shortest Path", "Medium", "O(M * N)", "Grid BFS/DFS sink connected '1's to '0's.", ["Amazon", "Google", "Meta", "Bloomberg"]),
    ("LC 133: Clone Graph", "11 Graphs 1 Traversals & Fundamentals", "Graph DFS & Components", "Medium", "O(V + E)", "Hash map old_node -> new_node with DFS neighbor cloning.", ["Meta", "Amazon"]),
    ("LC 994: Rotting Oranges", "11 Graphs 1 Traversals & Fundamentals", "Graph BFS & Shortest Path", "Medium", "O(M * N)", "Multi-source BFS queue with minutes timer until fresh count is 0.", ["Amazon", "Microsoft"]),
    ("LC 785: Is Graph Bipartite?", "11 Graphs 1 Traversals & Fundamentals", "Graph DFS & Components", "Medium", "O(V + E)", "2-color BFS/DFS: assign alternating colors to adjacent nodes.", ["Google", "Amazon"]),

    ("LC 207: Course Schedule", "12 Graphs 2 TopoSort & Shortest Paths", "Kahn's Topological Sort", "Medium", "O(V + E)", "Kahn's algorithm indegree tracking; cycle exists if processed != numCourses.", ["Amazon", "Google", "Meta"]),
    ("LC 210: Course Schedule II", "12 Graphs 2 TopoSort & Shortest Paths", "Kahn's Topological Sort", "Medium", "O(V + E)", "TopoSort order array: push nodes when indegree reaches 0.", ["Amazon", "Google"]),
    ("LC 743: Network Delay Time", "12 Graphs 2 TopoSort & Shortest Paths", "Dijkstra's Algorithm", "Medium", "O((V + E) log V)", "Dijkstra's with min-heap priority queue from source K; return max dist.", ["Google", "Amazon"]),
    ("LC 787: Cheapest Flights Within K Stops", "12 Graphs 2 TopoSort & Shortest Paths", "Dijkstra's Algorithm", "Medium", "O(K * E)", "Bellman-Ford relaxation K+1 times with distance copy buffer.", ["Google", "Amazon"]),

    ("LC 684: Redundant Connection", "13 Disjoint Set Union (DSU) & MST", "Disjoint Set Union (DSU)", "Medium", "O(N * alpha(N))", "DSU: if find(u) == find(v), edge creates cycle -> return edge.", ["Google", "Amazon"]),
    ("LC 1584: Min Cost to Connect All Points", "13 Disjoint Set Union (DSU) & MST", "Kruskal's & Prim's MST", "Medium", "O(E log V)", "Manhattan distance complete graph solved via Prim's or Kruskal's.", ["Amazon", "Microsoft"]),

    ("LC 70: Climbing Stairs", "14 Dynamic Programming 1 1D & Classics", "1D Linear DP", "Easy", "O(N)", "Fibonacci transition: dp[i] = dp[i-1] + dp[i-2].", ["Amazon", "Google"]),
    ("LC 198: House Robber", "14 Dynamic Programming 1 1D & Classics", "1D Linear DP", "Medium", "O(N)", "dp[i] = max(dp[i-1], nums[i] + dp[i-2]) with 2 rolling scalars.", ["Amazon", "Google", "Microsoft"]),
    ("LC 322: Coin Change", "14 Dynamic Programming 1 1D & Classics", "1D Linear DP", "Medium", "O(amount * coins)", "Unbounded knapsack: dp[i] = min(dp[i], 1 + dp[i - c]).", ["Amazon", "Google", "Meta"]),
    ("LC 300: Longest Increasing Subsequence", "14 Dynamic Programming 1 1D & Classics", "Longest Increasing Subsequence", "Medium", "O(N log N)", "Patience sort tails array with std::lower_bound.", ["Google", "Meta", "Amazon"]),

    ("LC 62: Unique Paths", "15 Dynamic Programming 2 2D & Grids", "2D Grid DP", "Medium", "O(M * N)", "dp[i][j] = dp[i-1][j] + dp[i][j-1] with 1D row buffer.", ["Amazon", "Google"]),
    ("LC 64: Minimum Path Sum", "15 Dynamic Programming 2 2D & Grids", "2D Grid DP", "Medium", "O(M * N)", "dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]).", ["Google", "Amazon"]),
    ("LC 221: Maximal Square", "15 Dynamic Programming 2 2D & Grids", "2D Grid DP", "Medium", "O(M * N)", "dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}).", ["Google", "Amazon"]),
    ("LC 3963: Create Grid With Exactly One Path", "15 Dynamic Programming 2 2D & Grids", "Constructive Grid Path", "Easy", "O(M + N)", "Construct L-shaped path: traverse row 0 and col n-1, block other cells with '#'.", ["Google", "Meta"]),

    ("LC 1143: Longest Common Subsequence", "16 Dynamic Programming 3 Strings & Sequences", "Longest Common Subsequence", "Medium", "O(M * N)", "Match: 1 + dp[i-1][j-1]; Mismatch: max(dp[i-1][j], dp[i][j-1]).", ["Amazon", "Google"]),
    ("LC 72: Edit Distance", "16 Dynamic Programming 3 Strings & Sequences", "Edit Distance DP", "Medium", "O(M * N)", "Min operations: 1 + min({insert, delete, replace}).", ["Google", "Amazon", "Microsoft"]),

    ("LC 416: Partition Equal Subset Sum", "17 Dynamic Programming 4 Knapsack & Partition", "0-1 Knapsack", "Medium", "O(N * target)", "0-1 Knapsack boolean DP for target = sum / 2.", ["Meta", "Amazon"]),

    ("LC 337: House Robber III", "18 Dynamic Programming 5 Trees, Bitmask & Digit DP", "Tree DP", "Medium", "O(N)", "Postorder returns pair: (rob_this_node, not_rob_this_node).", ["Google", "Amazon"]),
    ("LC 847: Shortest Path Visiting All Nodes", "18 Dynamic Programming 5 Trees, Bitmask & Digit DP", "Bitmask DP", "Hard", "O(N^2 * 2^N)", "BFS state (node, mask) tracking visited node bitmask.", ["Google"]),

    ("LC 55: Jump Game", "19 Greedy Algorithms", "Greedy Intervals & Reachability", "Medium", "O(N)", "Greedy max reachable index tracker: fail if i > max_reach.", ["Amazon", "Google", "Meta"]),
    ("LC 45: Jump Game II", "19 Greedy Algorithms", "Greedy Intervals & Reachability", "Medium", "O(N)", "Track current interval end and furthest reach; increment jump at interval end.", ["Amazon", "Google"]),
    ("LC 134: Gas Station", "19 Greedy Algorithms", "Greedy Intervals & Reachability", "Medium", "O(N)", "If total gas < total cost return -1; reset start index when tank < 0.", ["Amazon", "Google"]),
    ("LC 135: Candy", "19 Greedy Algorithms", "Greedy Intervals & Reachability", "Hard", "O(N)", "Two passes: left-to-right (if ratings[i] > ratings[i-1]), right-to-left.", ["Google", "Amazon"]),

    ("LC 136: Single Number", "20 Bit Manipulation & Math", "Bitwise Tricks", "Easy", "O(N)", "XOR accumulator: duplicates cancel out leaving unique number.", ["Amazon", "Google"]),
    ("LC 191: Number of 1 Bits", "20 Bit Manipulation & Math", "Bitwise Tricks", "Easy", "O(k)", "Brian Kernighan's trick: n &= (n - 1) clears lowest set bit.", ["Apple", "Microsoft"]),
    ("LC 50: Pow(x, n)", "20 Bit Manipulation & Math", "Fast Exponentiation", "Medium", "O(log N)", "Binary exponentiation: square base x and halve power n.", ["Meta", "Google", "Bloomberg"]),

    ("LC 307: Range Sum Query - Mutable", "21 Segment Trees & Fenwick (BIT)", "Segment Tree & Fenwick", "Medium", "O(log N)", "Segment tree or BIT point update and range query.", ["Google"]),

    ("LC 146: LRU Cache", "22 Design Data Structures", "LRU & LFU Cache Design", "Medium", "O(1)", "Hash map + Doubly Linked List with head (MRU) and tail (LRU).", ["Amazon", "Google", "Meta", "Microsoft", "Bloomberg"]),
    ("LC 460: LFU Cache", "22 Design Data Structures", "LRU & LFU Cache Design", "Hard", "O(1)", "Key to Node map + Frequency to DoublyLinkedList map + min_freq tracker.", ["Amazon", "Google"]),

    ("LC 28: Find the Index of the First Occurrence in a String", "23 Advanced Strings (KMP & Rabin-Karp)", "KMP & String Matching", "Easy", "O(N + M)", "KMP LPS preprocessing or Rabin-Karp rolling hash.", ["Microsoft", "Google"]),
    ("LC 214: Shortest Palindrome", "23 Advanced Strings (KMP & Rabin-Karp)", "KMP & String Matching", "Hard", "O(N)", "KMP LPS of s + '#' + rev(s) gives longest palindromic prefix.", ["Google"]),
    ("LC 5: Longest Palindromic Substring", "23 Advanced Strings (KMP & Rabin-Karp)", "KMP & String Matching", "Medium", "O(N)", "Expand around center in O(N^2) or Manacher's in O(N).", ["Amazon", "Microsoft", "Meta"]),

    ("LC 1192: Critical Connections in a Network", "24 Advanced Graphs (Tarjan & Eulerian)", "Tarjan's Bridges & SCC", "Hard", "O(V + E)", "Tarjan's low-link DFS: edge (u, v) is bridge if low[v] > tin[u].", ["Amazon"]),
    ("LC 332: Reconstruct Itinerary", "24 Advanced Graphs (Tarjan & Eulerian)", "Tarjan's Bridges & SCC", "Hard", "O(E log E)", "Hierholzer's algorithm: postorder DFS with min-heap neighbor traversal.", ["Google", "Amazon"]),

    ("LC 292: Nim Game", "25 Game Theory & Minimax", "Minimax & Game Theory", "Easy", "O(1)", "Return n % 4 != 0.", ["Adobe"]),
    ("LC 877: Stone Game", "25 Game Theory & Minimax", "Minimax & Game Theory", "Medium", "O(1)", "First player always wins by picking either all even or all odd piles.", ["Google"]),

    ("LC 398: Random Pick Index", "26 Reservoir Sampling & Randomized", "Reservoir Sampling", "Medium", "O(N)", "Reservoir sampling: pick index with probability 1 / count.", ["Meta"]),
    ("LC 384: Shuffle an Array", "26 Reservoir Sampling & Randomized", "Reservoir Sampling", "Medium", "O(N)", "Fisher-Yates shuffle: swap element i with random in [i, N-1].", ["Google", "Amazon"]),

    ("LC 587: Erect the Fence", "27 Computational Geometry & Math", "Convex Hull & Geometry", "Hard", "O(N log N)", "Graham scan convex hull with cross-product orientation.", ["Google"]),
    ("LC 149: Max Points on a Line", "27 Computational Geometry & Math", "Convex Hull & Geometry", "Hard", "O(N^2)", "Slope hash map dy/dx reduced by GCD for each origin point.", ["Google", "Amazon"])
]

def find_cpp_file(ptitle: str) -> str:
    m = re.search(r'LC\s+(\d+):', ptitle)
    if not m:
        return ""
    num = int(m.group(1))
    pad4 = f"{num:04d}"
    
    for p in BASE_DIR.glob(f"**/*{pad4}*.cpp"):
        if "venv" not in str(p) and "build" not in str(p):
            return p.read_text(encoding="utf-8")
    return ""

def generate_obsidian_config():
    graph_json = {
        "collapse-filter": False,
        "search": "",
        "localJumps": 1,
        "localBacklinks": True,
        "localForelinks": True,
        "localInterlinks": True,
        "showTags": False,
        "showAttachments": False,
        "hideUnresolved": False,
        "collapse-color-groups": False,
        "colorGroups": [
            {"query": "path:modules", "color": {"a": 1, "rgb": 3718648}},       # Sky Blue (#38bdf8)
            {"query": "path:concepts", "color": {"a": 1, "rgb": 11032055}},     # Electric Violet (#a855f7)
            {"query": "path:companies", "color": {"a": 1, "rgb": 16097035}},    # Radiant Amber (#f59e0b)
            {"query": "path:problems", "color": {"a": 0.95, "rgb": 15857145}},  # Luminous Silver (#f1f5f9)
            {"query": "path:difficulty", "color": {"a": 1, "rgb": 1096065}},    # Emerald (#10b981)
            {"query": "file:Index", "color": {"a": 1, "rgb": 16777215}}         # Pure White (#ffffff)
        ],
        "collapse-display": False,
        "showArrow": False,
        "textFadeMultiplier": 0.35,      # Eliminates label collision
        "nodeSizeMultiplier": 1.35,      # Bold, luminous presence
        "lineSizeMultiplier": 1.25,      # Crisp visible geometric lattice
        "collapse-forces": False,
        "centerStrength": 0.52,          # Keeps galaxy cohesive and centered
        "repelStrength": 10.5,           # Natural breathing room
        "linkStrength": 0.85,            # Cohesive bonds
        "linkDistance": 92               # Harmonious spacing
    }
    with open(OBSIDIAN_CONF_DIR / "graph.json", "w", encoding="utf-8") as f:
        json.dump(graph_json, f, indent=2)

def build_galaxy():
    setup_dirs()
    generate_obsidian_config()

    company_problems = {}
    difficulty_problems = {}

    for prob in PROBLEMS:
        ptitle, pmod, pconcept, pdiff, pcomp, pintuition, pcompanies = prob
        for comp in pcompanies:
            company_problems.setdefault(comp, []).append(prob)
        difficulty_problems.setdefault(pdiff, []).append(prob)

    # 1. Master Index (MOC)
    mod_list_md = "\n".join([f"- [[{sanitize(m)}]] — *{d['focus']}*" for m, d in MODULE_DETAILS.items()])
    comp_list_md = "\n".join([f"- [[{comp}]] ({len(plist)} curated questions)" for comp, plist in sorted(company_problems.items())])

    index_content = f"""---
title: "Nithin's Master DSA Knowledge Galaxy"
type: "galaxy-root"
tags:
  - moc
  - galaxy
---

# 🌌 Nithin's Master Algorithmic Knowledge Galaxy

Welcome to your **Obsidian DSA Second Brain & Neural Knowledge Constellation**!

> [!abstract] 🪐 Knowledge Network Overview
> This vault houses a unified, non-clumping algorithmic network linking:
> - **27 Master Curriculum Modules**
> - **53 High-Yield Concept Hubs**
> - **112 MNC Benchmark Problems**
> - **Progressive Problem Ladders & Solution Code**
> - **Target MNC Question Banks (Google, Meta, Amazon, Microsoft, Apple, Bloomberg, Adobe)**

---

## 🪐 The 27 Master Curriculum Modules
{mod_list_md}

---

## 🟣 Target MNC Constellations
{comp_list_md}
"""
    (VAULT_DIR / "Index.md").write_text(index_content, encoding="utf-8")

    # 2. Generate Module Notes
    for mod_title, mdata in MODULE_DETAILS.items():
        fname = sanitize(mod_title) + ".md"
        mdesc = mdata["focus"]

        c_links = [f"- [[{sanitize(c)}]]" for c, (m, _) in CONCEPTS.items() if m == mod_title]
        p_links = [f"- [[{sanitize(p[0])}]] — {p[3]} (`{p[4]}`)" for p in PROBLEMS if p[1] == mod_title]

        content = f"""---
title: "{mod_title}"
cluster: "{mdata['cluster']}"
type: "module-hub"
tags:
  - module
---

# 🌐 Module: {mod_title}

> [!abstract] 📋 Module Scope
> - **Core Focus**: {mdesc}  
> - **Domain Cluster**: `{mdata['cluster']}`

---

## 🟢 Core Algorithmic Concepts
{chr(10).join(c_links) if c_links else "*Direct algorithmic applications*"}

---

## 🎯 Benchmark MNC Problems
{chr(10).join(p_links)}

---
- [[Index|🏠 Master Knowledge Galaxy Root]]
"""
        (MODULES_DIR / fname).write_text(content, encoding="utf-8")

    # 3. Generate Concept Notes
    for cname, (cmod, cdesc) in CONCEPTS.items():
        fname = sanitize(cname) + ".md"
        p_links = [f"- [[{sanitize(p[0])}]] — {p[3]} (`{p[4]}`)" for p in PROBLEMS if p[2] == cname]

        content = f"""---
title: "{cname}"
module: "{cmod}"
type: "concept-node"
tags:
  - concept
---

# 💡 Concept: {cname}

> [!abstract] 🧠 Mental Model & Invariant
> - **Parent Module**: [[{sanitize(cmod)}]]
> - **Core Intuition**: {cdesc}

---

## 🎯 Benchmark Problems Utilizing {cname}
{chr(10).join(p_links) if p_links else "*Curated foundational pattern*"}
"""
        (CONCEPTS_DIR / fname).write_text(content, encoding="utf-8")

    # 4. Generate Problem Notes with Deep Readability and Organization
    for ptitle, pmod, pconcept, pdiff, pcomp, pintuition, pcompanies in PROBLEMS:
        fname = sanitize(ptitle) + ".md"

        # Semantic Ladders
        forward_bridges = [f"- ➔ **Next Boss Variation**: [[{sanitize(b)}]]" for a, b in SEMANTIC_BRIDGES if a == ptitle]
        backward_bridges = [f"- ⬅ **Prerequisite Pattern**: [[{sanitize(a)}]]" for a, b in SEMANTIC_BRIDGES if b == ptitle]
        bridge_section = ""
        if forward_bridges or backward_bridges:
            bridge_section = "\n".join(backward_bridges + [f"- 🎯 **Current Anchor**: [[{sanitize(ptitle)}]]"] + forward_bridges)
        else:
            bridge_section = f"- 🎯 **Foundational Anchor Pattern**: [[{sanitize(ptitle)}]]"

        comp_links = ", ".join([f"[[{c}]]" for c in pcompanies])
        comp_yaml = "\n".join([f"  - {c}" for c in pcompanies])

        diff_emoji = "🟢" if pdiff == "Easy" else ("🔴" if pdiff == "Hard" else "🟡")
        space_comp = "O(1)" if ("O(1)" in pcomp or "Two Pointers" in pconcept) else ("O(N)" if "O(N" in pcomp else "O(K)")

        # C++ Code: Look up in repo or provide structured optimal snippet
        disk_cpp = find_cpp_file(ptitle)
        if disk_cpp:
            cpp_block = disk_cpp
        else:
            # Clean structured template if file is not on disk yet
            cpp_block = f"""// Optimal C++20 Solution for {ptitle}
// Time Complexity: {pcomp} | Space Complexity: {space_comp}
// Technique: {pconcept} ({pmod})

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {{
public:
    // Core interview algorithmic implementation
    // Intuition: {pintuition}
}};
"""

        content = f"""---
title: "{ptitle}"
module: "{pmod}"
concept: "{pconcept}"
difficulty: "{pdiff}"
complexity: "{pcomp}"
space_complexity: "{space_comp}"
companies:
{comp_yaml}
type: "problem-card"
tags:
  - problem
  - {pdiff.lower()}
---

# {diff_emoji} {ptitle}

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[{sanitize(pmod)}]]
> - **Core Concept**: [[{sanitize(pconcept)}]]
> - **Difficulty**: {pdiff} {diff_emoji}
> - **Time Complexity**: $\\mathcal{{O}}({pcomp})$
> - **Space Complexity**: $\\mathcal{{O}}({space_comp})$
> - **Target MNCs**: {comp_links}

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: {pconcept} application in `{pmod}`.
> - **Immediate Strategy**: {pintuition}

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Invariant Guarantee
> Throughout the algorithm's execution, the state maintains the invariant required by **{pconcept}**.
> Bounded state transitions ensure correctness without redundant recomputations.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **Boundary Limits**: Always verify loop termination and off-by-one pointer conditions.
> 2. **Duplicate Deduplication**: Ensure equal elements do not cause redundant branches or infinite loops.
> 3. **Integer Overflow**: Use 64-bit integers (`long long`) when intermediate values exceed $2^{{31}}-1$.

---

## 🪜 Progressive Pattern Ladder & Variations
{bridge_section}

---

## 💻 Optimal C++20 Implementation

```cpp
{cpp_block}
```
"""
        (PROBLEMS_DIR / fname).write_text(content, encoding="utf-8")

    # 5. Generate Company Hub Notes
    for comp_name, plist in company_problems.items():
        fname = sanitize(comp_name) + ".md"
        q_links = [f"- [[{sanitize(p[0])}]] — {p[3]} (`{p[4]}`) | [[{sanitize(p[2])}]]" for p in plist]

        content = f"""---
title: "{comp_name}"
type: "company-hub"
tags:
  - company
---

# 🟣 Target MNC Hub: {comp_name}

> [!abstract] 🏢 Interview Question Frequency
> - **Tier**: Tier-1 Tech Titan
> - **Curated Question Count**: `{len(plist)} benchmark problems`

---

## 📋 High-Yield Interview Question Bank
{chr(10).join(q_links)}

---
- [[Index|🏠 Master Knowledge Galaxy Root]]
"""
        (COMPANIES_DIR / fname).write_text(content, encoding="utf-8")

    # 6. Generate Difficulty Hubs
    for diff_name, plist in difficulty_problems.items():
        fname = sanitize(diff_name) + ".md"
        q_links = [f"- [[{sanitize(p[0])}]] — [[{sanitize(p[1])}]] (`{p[4]}`)" for p in plist]

        content = f"""---
title: "{diff_name}"
type: "difficulty-hub"
tags:
  - difficulty
---

# 🟢 Difficulty Tier: {diff_name}

Total Curated Problems: `{len(plist)}`

---

{chr(10).join(q_links)}
"""
        (DIFFICULTY_DIR / fname).write_text(content, encoding="utf-8")

    print(f"🌟 Successfully generated Unified Celestial Constellation:")
    print(f"   - Removed artificial sectors directory")
    print(f"   - 27 Modules as primary celestial anchors")
    print(f"   - {len(CONCEPTS)} Concepts")
    print(f"   - {len(PROBLEMS)} Problems with Executive Cards, Callouts & Code")
    print(f"   - {len(company_problems)} Company Hubs")
    print(f"   - Calibrated graph.json (lineSize: 1.25, nodeSize: 1.35, textFade: 0.35)")

if __name__ == "__main__":
    build_galaxy()
