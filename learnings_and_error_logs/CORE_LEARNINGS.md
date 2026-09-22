# 💡 Core Learnings & High-Yield Insights

> A collection of algorithmic epiphanies, high-impact C++ STL tricks, and mental models discovered during practice.

---

## ⚡ C++ STL Performance & Interview Tips

### 1. Hash Maps: `unordered_map` vs `vector` as Map
- When keys are bounded (e.g., lowercase English letters $a-z$ or ASCII $0-127$ or numbers $\le 10^5$), always use a direct `vector<int> freq(26, 0)` or array instead of `unordered_map`. It is **$10\times$ faster** and avoids hash overhead.

### 2. Fast I/O in C++ (Critical for Online Assessments & Codeforces)
```cpp
std::ios_base::sync_with_stdio(false);
std::cin.tie(NULL);
```

### 3. Avoiding Hash Collision DOS in `unordered_map`
- In competitive programming or strict test cases, `unordered_map<long long, int>` can be hacked to $O(N^2)$ with anti-hash test cases. Use a custom splitmix64 hash or `std::map` if constraints are small.

### 4. Binary Search Boundaries
- For standard binary search:
  - `while (low <= high)` $\implies$ `mid = low + (high - low) / 2`
  - To avoid integer overflow: always use `low + (high - low) / 2` instead of `(low + high) / 2`.

---

## 🧠 Algorithmic Epiphanies Log

| Date | Topic | Key Insight / Epiphany |
| :--- | :--- | :--- |
| *YYYY-MM-DD* | *Arrays* | *Prefix sums allow $O(1)$ range sum queries on static arrays after $O(N)$ preprocessing.* |
