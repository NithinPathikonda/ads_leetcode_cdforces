# 🚀 Advanced Data Structures & Algorithms — MNC Master Prep

<div align="center">

![C++20](https://img.shields.io/badge/Language-C%2B%2B20-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Target](https://img.shields.io/badge/Target-Tier--1%20MNCs%20%7C%20FAANG-FF9900?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Active%20Preparation-success?style=for-the-badge)
![License](https://img.shields.io/badge/License-MIT-blue?style=for-the-badge)

**A rigorous, zero-gap algorithmic problem-solving repository structured by patterns, optimal complexities, and MNC interview archetypes.**

[Explore Roadmap](#-27-topic-master-curriculum) • [Progress Tracker](TRACKER.md) • [90-Day Sprint & Revision](REVISION_AND_TIMELINE.md) • [Contests & Upsolving](contests/CONTEST_LOG.md) • [Skills Audit](SKILLS_AUDIT.md) • [Memory Maps](MEMORY_MAPS.md) • [Error Log](learnings_and_error_logs/ERROR_LOG.md) • [C++ Setup](#-local-c-compilation)

</div>

---

## 📌 Mission & Overview

This repository is dedicated to mastering **competitive programming and technical interview patterns** for top-tier tech companies (**Google, Meta, Microsoft, Amazon, Apple, Uber, Netflix, Atlassian, DE Shaw, Bloomberg, Tower Research**).

Every problem includes:
- 💡 **Intuition & Mental Model** (Brute Force $\to$ Optimal Pattern)
- ⚡ **Clean, Modular C++ Implementation**
- 📊 **Strict Big-$O$ Time & Space Complexity Proofs**
- 🛡️ **Critical Edge Cases & Pitfalls**

---

## 🗺️ 27-Topic Master Curriculum

| # | Topic / Module | Key Focus Archetypes | Folder |
|---|---|---|---|
| **01** | **Arrays & Hashing** | Prefix Sums, Kadane's, Difference Array, Matrix Traversal | [`01_arrays_hashing/`](01_arrays_hashing/) |
| **02** | **Two Pointers & Sliding Window** | Fixed & Dynamic Windows, 2/3/4-Sum, Constrained Substrings | [`02_two_pointers_sliding_window/`](02_two_pointers_sliding_window/) |
| **03** | **Binary Search** | Rotated Arrays, Binary Search on Answer / Predicates, 2D Matrices | [`03_binary_search/`](03_binary_search/) |
| **04** | **Stack & Monotonic Stack** | Next Greater/Smaller, Rainwater Trapping, Largest Rectangle | [`04_stack_monotonic_stack/`](04_stack_monotonic_stack/) |
| **05** | **Linked Lists** | Floyd's Cycle, In-Place Reversal, Merge K Lists, LRU/LFU Internals | [`05_linked_lists/`](05_linked_lists/) |
| **06** | **Recursion & Backtracking** | Subsets, Permutations, N-Queens, Sudoku, Word Search | [`06_recursion_backtracking/`](06_recursion_backtracking/) |
| **07** | **Binary Trees & BST** | DFS/BFS, LCA, Tree Views, Morris Traversal, Path Sum, BST | [`07_binary_trees_and_bst/`](07_binary_trees_and_bst/) |
| **08** | **Heaps & Priority Queues** | Top-K Elements, K-Way Merge, Running Median, Task Scheduler | [`08_heaps_priority_queues/`](08_heaps_priority_queues/) |
| **09** | **Intervals & Sweepline** | Merge/Insert, Meeting Rooms I/II/III, Skyline Problem | [`09_intervals_sweepline/`](09_intervals_sweepline/) |
| **10** | **Tries (Prefix Trees)** | Autocomplete, Wildcard Search, Max XOR Pair | [`10_tries/`](10_tries/) |
| **11** | **Graphs 1: Traversals** | BFS/DFS, Flood Fill, Bipartite Matching, Cycle Detection | [`11_graphs_traversals/`](11_graphs_traversals/) |
| **12** | **Graphs 2: Shortest Paths** | Kahn's TopoSort, Dijkstra, Bellman-Ford, Floyd-Warshall, 0-1 BFS | [`12_graphs_toposort_shortest_paths/`](12_graphs_toposort_shortest_paths/) |
| **13** | **Disjoint Set Union & MST** | Union-Find (Rank + Path Compression), Kruskal's, Prim's | [`13_dsu_and_mst/`](13_dsu_and_mst/) |
| **14** | **DP 1: 1D & Classics** | Climbing Stairs, House Robber, Coin Change, LIS ($O(N \log N)$) | [`14_dp_1d_classics/`](14_dp_1d_classics/) |
| **15** | **DP 2: 2D & Grids** | Unique Paths, Min Path Sum, Maximal Square, Dungeon Game | [`15_dp_2d_grids/`](15_dp_2d_grids/) |
| **16** | **DP 3: Strings & Sequences** | LCS, Edit Distance, Distinct Subsequences, Wildcard/Regex | [`16_dp_strings_subsequences/`](16_dp_strings_subsequences/) |
| **17** | **DP 4: Knapsack & Partition** | 0/1 Knapsack, Unbounded, Target Sum, Subset Partition | [`17_dp_knapsack_partition/`](17_dp_knapsack_partition/) |
| **18** | **DP 5: Trees, Bitmask, Digit** | Tree DP (Diameter/Max Path), TSP Bitmask DP, Digit DP | [`18_dp_trees_bitmask_digit/`](18_dp_trees_bitmask_digit/) |
| **19** | **Greedy Algorithms** | Jump Game I/II, Gas Station, Candy, Job Sequencing | [`19_greedy_algorithms/`](19_greedy_algorithms/) |
| **20** | **Bit Manipulation & Math** | Bitwise Tricks, Single Number I/II/III, Sieve, Fast Power | [`20_bit_manipulation_math/`](20_bit_manipulation_math/) |
| **21** | **Segment Trees & Fenwick** | Range Queries, Point Updates, Lazy Propagation | [`21_segment_trees_fenwick/`](21_segment_trees_fenwick/) |
| **22** | **Design Data Structures** | LRU Cache, LFU Cache, Time-Based Key-Value Store, Min-Stack | [`22_design_data_structures/`](22_design_data_structures/) |
| **23** | **Advanced Strings** | KMP Algorithm, Rabin-Karp (Rolling Hash), Manacher's $O(N)$ | [`23_advanced_string_matching_kmp_rabin_karp/`](23_advanced_string_matching_kmp_rabin_karp/) |
| **24** | **Advanced Graphs** | Tarjan's (Bridges/Articulation Points), Kosaraju SCC, Hierholzer | [`24_advanced_graphs_tarjan_eulerian/`](24_advanced_graphs_tarjan_eulerian/) |
| **25** | **Game Theory & Minimax** | Minimax + Memoization, Nim Game, Stone Game Series | [`25_game_theory_minimax/`](25_game_theory_minimax/) |
| **26** | **Reservoir & Randomized** | Reservoir Sampling ($K$ from Stream), Fisher-Yates, Random Pick | [`26_reservoir_sampling_randomized/`](26_reservoir_sampling_randomized/) |
| **27** | **Geometry & Math** | Convex Hull (Graham Scan), Overlapping Polygons, Matrix Exp | [`27_computational_geometry_math/`](27_computational_geometry_math/) |

---

## 🏛️ 5-Step MNC Interview Framework

```
  1. Clarify Constraints  ──►  2. State Brute Force  ──►  3. Optimal Pattern & Big-O
                                                                   │
  5. Dry Run & Test Cases  ◄──  4. Clean Production Code   ◄───────┘
```

1. **Clarify Constraints**: $N \le 10^5 \implies O(N)$ or $O(N \log N)$; $N \le 20 \implies O(2^N)$ backtracking. Check negatives, duplicates, empty inputs.
2. **State Brute Force**: Establish the naive baseline ($O(N^2)$, $O(2^N)$) to prove why optimization is required.
3. **Propose Optimal Strategy**: Justify data structures (e.g. *“Using a Monotonic Stack avoids the nested loop by maintaining candidate boundaries in $O(N)$”*).
4. **Clean Implementation**: Meaningful variable names, modular helper functions, no unnecessary allocations.
5. **Dry Run & Edge Cases**: Walk through custom inputs, off-by-one boundary checks, and overflow prevention before finalizing.

---

## 💻 Local C++ Compilation

Compile any solution using modern C++20 flags:

```bash
# Compile with strict warnings and optimizations
g++ -std=c++20 -O2 -Wall -Wextra -Wshadow solution.cpp -o solution

# Execute
./solution
```

---

<div align="center">

*Continuous preparation beats sporadic intensity. Track your daily solved problems in [TRACKER.md](TRACKER.md).*

</div>