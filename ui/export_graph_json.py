#!/usr/bin/env python3
"""
Exports Master DSA Knowledge Galaxy with Clean, Balanced Constellation Topology
and Complete Brain Memory Metadata.
"""

import sys
import json
from pathlib import Path

BASE_DIR = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(BASE_DIR))

from obsidian.build_master_knowledge_galaxy import (
    MODULE_DETAILS, CONCEPTS, PROBLEMS, SEMANTIC_BRIDGES, sanitize
)

OUTPUT_FILE = BASE_DIR / "ui" / "graph_data.json"

# Concise, punchy display names for clean graph readability (eliminates label wrapping/clumping)
SHORT_MODULE_NAMES = {
    "01 Arrays & Hashing": "01 Arrays & Hash",
    "02 Two Pointers & Sliding Window": "02 Two Pointers",
    "03 Binary Search": "03 Binary Search",
    "04 Stack & Monotonic Stack": "04 Monotonic Stack",
    "05 Linked Lists": "05 Linked Lists",
    "06 Recursion & Backtracking": "06 Backtracking",
    "07 Binary Trees & BST": "07 Binary Trees",
    "08 Heaps & Priority Queues": "08 Heaps & PQ",
    "09 Intervals & Sweepline": "09 Intervals & Sweep",
    "10 Tries (Prefix Trees)": "10 Tries",
    "11 Graphs 1 Traversals & Fundamentals": "11 Graph Traversals",
    "12 Graphs 2 TopoSort & Shortest Paths": "12 TopoSort & Paths",
    "13 Disjoint Set Union (DSU) & MST": "13 DSU & MST",
    "14 Dynamic Programming 1 1D & Classics": "14 1D Linear DP",
    "15 Dynamic Programming 2 2D & Grids": "15 2D Grid DP",
    "16 Dynamic Programming 3 Strings & Sequences": "16 String DP",
    "17 Dynamic Programming 4 Knapsack & Partition": "17 Knapsack DP",
    "18 Dynamic Programming 5 Trees, Bitmask & Digit DP": "18 Tree & Bitmask DP",
    "19 Greedy Algorithms": "19 Greedy Algorithms",
    "20 Bit Manipulation & Math": "20 Bit Manipulation",
    "21 Segment Trees & Fenwick (BIT)": "21 Segment Trees",
    "22 Design Data Structures": "22 System Design",
    "23 Advanced Strings (KMP & Rabin-Karp)": "23 KMP & Rabin-Karp",
    "24 Advanced Graphs (Tarjan & Eulerian)": "24 Tarjan & Eulerian",
    "25 Game Theory & Minimax": "25 Game Theory",
    "26 Reservoir Sampling & Randomized": "26 Randomized & Stream",
    "27 Computational Geometry & Math": "27 Geometry & Math"
}

# Rich Brain Memory Metadata Dictionary
BRAIN_METADATA = {
    "LC 1: Two Sum": {
        "trigger": "Unsorted array + Pair Sum -> 1-pass Hash Map complement lookup in O(N).",
        "invariant": "At step i, all elements before i are in map. We check target - nums[i] BEFORE inserting.",
        "pitfall": "Do NOT insert before checking, or element might pair with itself.",
        "code_path": "01_arrays_hashing/lc_0001_two_sum.cpp"
    },
    "LC 121: Best Time to Buy & Sell Stock": {
        "trigger": "Single buy & sell in sequence -> Track running minimum price seen so far.",
        "invariant": "Max profit at day i = max(0, price[i] - min_price_seen_so_far).",
        "pitfall": "Prices strictly decreasing -> answer is 0, never negative.",
        "code_path": "01_arrays_hashing/lc_0121_best_time_to_buy_and_sell_stock.cpp"
    },
    "LC 242: Valid Anagram": {
        "trigger": "Permutation character match -> 26-int frequency signature in single pass.",
        "invariant": "Lengths must match; +1 for s and -1 for t leaves all counts at exactly 0.",
        "pitfall": "Check s.length() == t.length() first before allocating memory.",
        "code_path": "01_arrays_hashing/lc_0242_valid_anagram.cpp"
    },
    "LC 49: Group Anagrams": {
        "trigger": "Group equivalent anagram strings -> Canonical key hash map.",
        "invariant": "Two strings share identical key iff they have identical character counts.",
        "pitfall": "Sorting string key takes O(K log K); 26-char count tuple takes O(K).",
        "code_path": "01_arrays_hashing/lc_0049_group_anagrams.cpp"
    },
    "LC 347: Top K Frequent Elements": {
        "trigger": "Top K elements with bounded frequency -> Bucket Sort by count.",
        "invariant": "Max possible frequency is N. Bucket array of size N+1 gives O(N) linear time.",
        "pitfall": "Heap approach is O(N log K); Bucket Sort achieves true linear O(N).",
        "code_path": "01_arrays_hashing/lc_0347_top_k_frequent_elements.cpp"
    },
    "LC 238: Product of Array Except Self": {
        "trigger": "Product of all except self WITHOUT division -> Prefix & Suffix running products.",
        "invariant": "ans[i] = (product of elements < i) * (product of elements > i).",
        "pitfall": "In-place prefix pass in output vector + reverse suffix scalar gives O(1) auxiliary space.",
        "code_path": "01_arrays_hashing/lc_0238_product_of_array_except_self.cpp"
    },
    "LC 128: Longest Consecutive Sequence": {
        "trigger": "Unsorted consecutive sequence in O(N) -> Hash Set streak start check.",
        "invariant": "Only start counting streak at x if (x - 1) is NOT in the set.",
        "pitfall": "Without the (x - 1) check, complexity degrades to O(N^2) on long chains.",
        "code_path": "01_arrays_hashing/lc_0128_longest_consecutive_sequence.cpp"
    },
    "LC 560: Subarray Sum Equals K": {
        "trigger": "Contiguous subarray sum with negative numbers -> Running Prefix Sum + Hash Map.",
        "invariant": "Subarray [j+1, i] sums to k iff prefix[i] - prefix[j] == k.",
        "pitfall": "MUST initialize map[0] = 1 to count subarrays starting from index 0.",
        "code_path": "01_arrays_hashing/lc_0560_subarray_sum_equals_k.cpp"
    },
    "LC 53: Maximum Subarray": {
        "trigger": "Max sum contiguous subarray -> Kadane's running sum reset.",
        "invariant": "If running sum drops below 0, it can only hurt future subarrays -> reset to 0.",
        "pitfall": "All-negative arrays: update global max BEFORE resetting running sum.",
        "code_path": "01_arrays_hashing/lc_0053_maximum_subarray.cpp"
    },
    "LC 75: Sort Colors": {
        "trigger": "3 distinct values in-place -> Dutch National Flag 3-pointer partition.",
        "invariant": "[0..low-1] is 0, [low..mid-1] is 1, [high+1..N-1] is 2.",
        "pitfall": "After swap(mid, high), decrement high but do NOT advance mid (incoming value unknown!).",
        "code_path": "01_arrays_hashing/lc_0075_sort_colors.cpp"
    },
    "LC 54: Spiral Matrix": {
        "trigger": "Clockwise 2D layer traversal -> 4 boundary pointers (top, bottom, left, right).",
        "invariant": "Peel outer rectangular perimeter, then shrink boundaries inward.",
        "pitfall": "Check top <= bottom before moving Left, and left <= right before moving Up.",
        "code_path": "01_arrays_hashing/lc_0054_spiral_matrix.cpp"
    },
    "LC 167: Two Sum II - Input Array Is Sorted": {
        "trigger": "Sorted array pair sum -> Opposite direction Two Pointers (l, r).",
        "invariant": "sum > target -> r--; sum < target -> l++. Sorted order strictly eliminates candidates.",
        "pitfall": "Problem requires 1-based indices in result.",
        "code_path": "02_two_pointers_sliding_window/lc_0167_two_sum_ii.cpp"
    },
    "LC 15: 3Sum": {
        "trigger": "Triplets summing to 0 -> Sort array, fix nums[i], two pointers on remaining pair.",
        "invariant": "Sorting enables Two Sum II + easy duplicate elimination by skipping equal elements.",
        "pitfall": "Skip duplicate elements with while loops guarded by l < r to prevent out-of-bounds.",
        "code_path": "02_two_pointers_sliding_window/lc_0015_three_sum.cpp"
    },
    "LC 11: Container With Most Water": {
        "trigger": "Max area between two vertical lines -> Greedy Two Pointers from extremities.",
        "invariant": "Area = min(h[l], h[r]) * (r - l). Always move the SHORTER line inward.",
        "pitfall": "Moving the taller line while decreasing width cannot possibly increase area.",
        "code_path": "02_two_pointers_sliding_window/lc_0011_container_with_most_water.cpp"
    },
    "LC 3: Longest Substring Without Repeating Characters": {
        "trigger": "Contiguous substring with all distinct chars -> Dynamic Sliding Window.",
        "invariant": "Window [l..r] contains no duplicates. Jump l to last_seen[c] + 1 on duplicate.",
        "pitfall": "l = max(l, last_seen[c] + 1) to prevent l from jumping backward to stale indices.",
        "code_path": "02_two_pointers_sliding_window/lc_0003_longest_substring_without_repeating_characters.cpp"
    },
    "LC 424: Longest Repeating Character Replacement": {
        "trigger": "Longest substring after k flips -> Dynamic Window with frequency invariant.",
        "invariant": "Window valid if (window_len - max_frequency) <= k.",
        "pitfall": "max_freq never needs to decrement on shrink; only a strictly higher max_freq expands the record.",
        "code_path": "02_two_pointers_sliding_window/lc_0424_longest_repeating_character_replacement.cpp"
    },
    "LC 567: Permutation in String": {
        "trigger": "Contiguous substring anagram -> Fixed-size window of length s1.length().",
        "invariant": "Window slides 1 step: subtract outgoing char, add incoming char in O(1).",
        "pitfall": "Maintain a matches counter (0..26) for O(1) comparison rather than 26-vector diff.",
        "code_path": "02_two_pointers_sliding_window/lc_0567_permutation_in_string.cpp"
    },
    "LC 438: Find All Anagrams in a String": {
        "trigger": "All starting indices of anagram substring -> Fixed window of size p.length() with running character counts.",
        "invariant": "Only 2 chars change per slide: evict left s[i-m], admit right s[i]. Equal freq vector = anagram match.",
        "pitfall": "Off-by-one: accessing s[r+1] after r++ skips characters and overflows. Use canonical 1-loop (i and i - m).",
        "code_path": "02_two_pointers_sliding_window/lc_0438_find_all_anagrams_in_a_string.cpp"
    },
    "LC 209: Minimum Size Subarray Sum": {
        "trigger": "Shortest subarray with sum >= target (positive numbers) -> Dynamic Sliding Window.",
        "invariant": "Monotonicity holds because all numbers are positive. Expand r; shrink l while sum >= target.",
        "pitfall": "If array contained negatives, sliding window fails -> requires Prefix Sum + Monotonic Deque.",
        "code_path": "02_two_pointers_sliding_window/lc_0209_minimum_size_subarray_sum.cpp"
    },
    "LC 42: Trapping Rain Water": {
        "trigger": "Water trapped above elevation bars -> Height bounded by min(left_max, right_max).",
        "invariant": "Bottleneck is always the smaller boundary. If left_max <= right_max, process left & advance.",
        "pitfall": "Two pointers eliminates the O(N) memory requirement of prefix/suffix arrays to O(1) space.",
        "code_path": "02_two_pointers_sliding_window/lc_0042_trapping_rain_water.cpp"
    },
    "LC 1004: Max Consecutive Ones III": {
        "trigger": "At most k zero flips to 1 -> Longest window with <= k zeros.",
        "invariant": "zero_count <= k. Expand r counting zeros; shrink l when zero_count > k.",
        "pitfall": "Window size can be maintained non-shrinking for optimal 1-pass O(N).",
        "code_path": "02_two_pointers_sliding_window/lc_1004_max_consecutive_ones_iii.cpp"
    },
    "LC 713: Subarray Product Less Than K": {
        "trigger": "Subarray product < k (positive numbers) -> Dynamic Sliding Window with count += (r - l + 1).",
        "invariant": "Every valid subarray ending at index r has starting indices in [l..r], giving (r - l + 1) subarrays.",
        "pitfall": "k <= 1: return 0 immediately since all positive integers >= 1.",
        "code_path": "02_two_pointers_sliding_window/lc_0713_subarray_product_less_than_k.cpp"
    },
    "LC 904: Fruit Into Baskets": {
        "trigger": "Longest contiguous subarray with at most 2 distinct elements -> Dynamic Sliding Window with hash map.",
        "invariant": "Window valid iff map.size() <= 2. When map.size() > 2, shrink l until key hits 0 and erase.",
        "pitfall": "Must call map.erase() when frequency drops to 0, otherwise map.size() still counts empty key.",
        "code_path": "02_two_pointers_sliding_window/lc_0904_fruit_into_baskets.cpp"
    },
    "LC 33: Search in Rotated Sorted Array": {
        "trigger": "Rotated sorted array search in O(log N) -> Decouple sorted half; check if target is inside.",
        "invariant": "At least one half [l..mid] or [mid..r] is strictly sorted. Range check determines which half to keep.",
        "pitfall": "Use <= when comparing nums[mid] and nums[r] so single/two-element subarrays don't branch incorrectly.",
        "code_path": "03_binary_search/lc_0033_search_in_rotated_sorted_array.cpp"
    },
    "LC 153: Find Minimum in Rotated Sorted Array": {
        "trigger": "Minimum in rotated sorted array in O(log N) -> Compare nums[mid] with nums[r] for inflection point.",
        "invariant": "If nums[mid] > nums[r], drop is to the right (l = mid + 1). Else mid or left is candidate (r = mid).",
        "pitfall": "Never do r = mid - 1 on the right-sorted branch, or you will exclude the minimum when nums[mid] is the min.",
        "code_path": "03_binary_search/lc_0153_find_minimum_in_rotated_sorted_array.cpp"
    },
    "LC 74: Search a 2D Matrix": {
        "trigger": "Search in row-sorted + cross-row strictly increasing grid -> Virtual 1D binary search in O(log(M*N)).",
        "invariant": "Grid is isomorphic to sorted 1D array of length M*N: row = mid / cols, col = mid % cols.",
        "pitfall": "Always divide and modulo by column count (cols), NOT row count. Divisor by rows causes out-of-bounds.",
        "code_path": "03_binary_search/lc_0074_search_a_2d_matrix.cpp"
    },
    "LC 240: Search a 2D Matrix II": {
        "trigger": "Rows and cols sorted without cross-row guarantee -> Top-right corner staircase walk in O(M+N).",
        "invariant": "At cell (row, col): val > target prunes column (col--); val < target prunes row (row++).",
        "pitfall": "Cannot flatten into 1D (monotonicity drops across rows). Top-left corner fails because both branches increase.",
        "code_path": "03_binary_search/lc_0240_search_a_2d_matrix_ii.cpp"
    },
    "LC 875: Koko Eating Bananas": {
        "trigger": "Minimum integer rate to complete discrete workloads within time H -> Binary search on answer [1, max(piles)].",
        "invariant": "Total hours f(k) = sum(ceil(p/k)) is monotonically non-increasing. f(k) <= h defines valid speeds.",
        "pitfall": "Accumulator total_hours will overflow 32-bit signed int when k=1 and piles reach 10^9. Must use long long.",
        "code_path": "03_binary_search/lc_0875_koko_eating_bananas.cpp"
    },
    "LC 1011: Capacity To Ship Packages Within D Days": {
        "trigger": "Minimum ship capacity to transport ordered packages in D days -> Binary search on [max(weights), sum(weights)].",
        "invariant": "Greedy sequential bin-packing is optimal: accumulate weights until exceeding cap, then increment days.",
        "pitfall": "Lower bound cannot be 1; must be max(weights) or include `if (w > cap) return false;` to prevent sinking ship.",
        "code_path": "03_binary_search/lc_1011_capacity_to_ship_packages_within_d_days.cpp"
    },
    "LC 84: Largest Rectangle in Histogram": {
        "trigger": "Largest rectangle under bar heights -> Monotonic Increasing Stack of indices.",
        "invariant": "For bar i popped by smaller bar r, its left limit is the previous stack element, right limit is r.",
        "pitfall": "Append dummy 0-height bar at the end to flush all remaining elements in stack.",
        "code_path": "04_stack_monotonic_stack/lc_0084_largest_rectangle_in_histogram.cpp"
    },
    "LC 51: N-Queens": {
        "trigger": "Placing N non-attacking pieces on N×N board -> Row-by-row backtracking with O(1) diagonal sets.",
        "invariant": "One queen per row. Column `col`, Main diag `row - col + n`, Anti diag `row + col` must be free.",
        "pitfall": "Never scan the board in O(N) to check diagonals. Use 3 boolean lookup sets. Revert state on backtrack.",
        "code_path": ""
    },
    "LC 146: LRU Cache": {
        "trigger": "O(1) get, put, and eviction of least recently used -> Hash Map + Doubly Linked List.",
        "invariant": "Head = Most Recently Used (MRU), Tail = Least Recently Used (LRU). Map stores node pointers.",
        "pitfall": "Use dummy head and dummy tail nodes to avoid null pointer edge cases on insert/remove.",
        "code_path": "22_design_data_structures/lc_0146_lru_cache.cpp"
    },
    "LC 300: Longest Increasing Subsequence": {
        "trigger": "Longest increasing subsequence in O(N log N) -> Patience Sorting / Tails Array with std::lower_bound.",
        "invariant": "tails[len] stores the smallest ending value among all increasing subsequences of length len+1.",
        "pitfall": "tails array is sorted, but it does NOT store the actual LIS elements (only their lengths).",
        "code_path": "14_dp_1d_classics/lc_0300_longest_increasing_subsequence.cpp"
    },
    "LC 3963: Create Grid With Exactly One Path": {
        "trigger": "Grid path construction with exactly 1 path from top-left to bottom-right -> L-Shape perimeter.",
        "invariant": "Row 0 and Col N-1 open (length M + N - 1); all internal cells blocked with '#' to prevent branching.",
        "pitfall": "Avoid leaving open any 2x2 empty square which immediately creates multiple alternate paths.",
        "code_path": "leetcode_problem_of_the_day/2026-10/2026_10_27_lc_3963_create_grid_with_exactly_one_path.cpp"
    },
    "LC 1614: Maximum Nesting Depth of the Parentheses": {
        "trigger": "Max depth of valid parentheses -> Single-pass counter tracking open '(' and close ')'.",
        "invariant": "Depth at character i = current open bracket count. Global max = max(global_max, current_depth).",
        "pitfall": "Ignore non-bracket characters; strictly update max on '(' and decrement on ')'.",
        "code_path": "leetcode_problem_of_the_day/2026-09/2026_09_28_lc_1614_maximum_nesting_depth_of_the_parentheses.cpp"
    }
}

def build_web_graph():
    nodes = []
    links = []
    node_set = set()

    def add_node(nid, name, group, ntype, val=8, details=None):
        if nid not in node_set:
            node_set.add(nid)
            nodes.append({
                "id": nid,
                "name": name,
                "group": group,
                "type": ntype,
                "val": val,
                "details": details or {}
            })

    def add_link(source, target, value=1, link_type="structural"):
        if source in node_set and target in node_set and source != target:
            links.append({
                "source": source,
                "target": target,
                "value": value,
                "type": link_type
            })

    # 1. Galaxy Core (Central Anchor)
    add_node("root", "Master DSA Constellation", "root", "Core Constellation", 14, {
        "title": "Master DSA Constellation",
        "cluster": "Core",
        "description": "Unified 27-Module Algorithmic Master Brain"
    })

    # 2. 27 Curriculum Modules (with punchy short names to prevent label collisions)
    for mod_name, mdata in MODULE_DETAILS.items():
        mid = f"mod:{mod_name}"
        short_name = SHORT_MODULE_NAMES.get(mod_name, mod_name)
        add_node(mid, short_name, "module", "Curriculum Module", 8.5, {
            "title": mod_name,
            "short_name": short_name,
            "cluster": mdata["cluster"],
            "focus": mdata["focus"]
        })
        add_link("root", mid, 1.8, "module-root")

    # 3. Concepts
    for cname, (cmod, cdesc) in CONCEPTS.items():
        cid = f"concept:{cname}"
        add_node(cid, cname, "concept", "Algorithmic Pattern", 5.5, {
            "name": cname,
            "module": cmod,
            "cluster": MODULE_DETAILS.get(cmod, {}).get("cluster", "Core"),
            "intuition": cdesc
        })
        add_link(f"mod:{cmod}", cid, 1.4, "module-concept")

    # 4. Target Companies (Positioned harmoniously without collapsing onto Module 01)
    all_companies = set()
    for prob in PROBLEMS:
        for c in prob[6]:
            all_companies.add(c)

    for comp in sorted(all_companies):
        cid = f"company:{comp}"
        add_node(cid, comp, "company", "Target MNC", 6.5, {
            "name": comp,
            "tier": "Tier-1 Tech Titan"
        })

    # 5. Progressive Ladder Mapping
    prev_map = {b: a for a, b in SEMANTIC_BRIDGES}
    next_map = {a: b for a, b in SEMANTIC_BRIDGES}

    # 6. Problems with Full Brain Memory Metadata
    for ptitle, pmod, pconcept, pdiff, pcomp, pintuition, pcompanies in PROBLEMS:
        pid = f"prob:{ptitle}"
        bmeta = BRAIN_METADATA.get(ptitle, {})

        details = {
            "title": ptitle,
            "module": pmod,
            "cluster": MODULE_DETAILS.get(pmod, {}).get("cluster", "Core"),
            "concept": pconcept,
            "difficulty": pdiff,
            "complexity": pcomp,
            "companies": pcompanies,
            "intuition": pintuition,
            "trigger": bmeta.get("trigger", f"Core 15-second trigger: {pconcept} pattern match."),
            "invariant": bmeta.get("invariant", f"Maintain invariant for {pconcept} across all state transitions."),
            "pitfall": bmeta.get("pitfall", "Carefully verify boundary termination and duplicate deduplication."),
            "code_path": bmeta.get("code_path", ""),
            "ladder_prev": prev_map.get(ptitle, None),
            "ladder_next": next_map.get(ptitle, None)
        }

        add_node(pid, ptitle, "problem", "Problem Node", 4.0, details)

        # Primary link to its Concept Hub
        add_link(f"concept:{pconcept}", pid, 1.2, "problem-concept")

        # Soft company links (lightweight so they don't drag company nodes into knots)
        for comp in pcompanies:
            add_link(f"company:{comp}", pid, 0.35, "problem-company")

    # 7. Semantic Progressive Ladders (Highlight progressive pattern ladders)
    for a, b in SEMANTIC_BRIDGES:
        pid_a = f"prob:{a}"
        pid_b = f"prob:{b}"
        if pid_a in node_set and pid_b in node_set:
            add_link(pid_a, pid_b, 1.6, "ladder")

    graph_data = {
        "nodes": nodes,
        "links": links
    }

    OUTPUT_FILE.write_text(json.dumps(graph_data, indent=2), encoding="utf-8")
    print(f"✅ Generated Web Brain Knowledge Graph {OUTPUT_FILE}: {len(nodes)} nodes, {len(links)} links")

if __name__ == "__main__":
    build_web_graph()
