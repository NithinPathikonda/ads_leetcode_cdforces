---
title: "LC 438: Find All Anagrams in a String"
module: "02 Two Pointers & Sliding Window"
concept: "Fixed Sliding Window"
difficulty: "Medium"
complexity: "O(N)"
space_complexity: "O(1)"
companies:
  - Meta
  - Amazon
  - Microsoft
  - Google
  - Apple
type: "problem-card"
tags:
  - problem
  - medium
  - sliding-window
  - two-pointers
  - string
---

# 🟡 LC 438: Find All Anagrams in a String

> [!abstract] 📋 Executive Problem Card
> - **Module**: [[02 Two Pointers & Sliding Window]]
> - **Core Concept**: [[Fixed Sliding Window]]
> - **Difficulty**: Medium 🟡
> - **Time Complexity**: $\mathcal{O}(N)$ where $N = |s|$
> - **Space Complexity**: $\mathcal{O}(1)$ auxiliary space (26-int frequency vectors)
> - **Target MNCs**: [[Meta]], [[Amazon]], [[Microsoft]], [[Google]], [[Apple]]

---

## ⚡ 15-Second Interview Mental Trigger
> [!tip] ⚡ How to Recognize this Pattern in an Interview
> - **Key Clue / Signal**: "Find all starting indices of anagrams of $p$ in $s$." Anagram = identical character frequency vector.
> - **Immediate Strategy**: Fixed-size sliding window of length $m = |p|$. As the window shifts right by 1 step:
>   1. Evict outgoing character on the left ($s[l]$) $\implies \text{count}[s[l]]--$
>   2. Admit incoming character on the right ($s[r]$) $\implies \text{count}[s[r]]++$
> - **Interview Delivery**: Avoid checking all $m$ characters from scratch ($\mathcal{O}(M \cdot N)$). Transition window state in $\mathcal{O}(1)$ per character slide.

---

## 🛡️ The Golden Invariant & Mathematical Proof
> [!note] 🛡️ Window State Invariant
> Let $W(i) = s[i - m + 1 \dots i]$ represent the active window of length $m$.
> - **Frequency Vector Invariant**:
>   $$\text{freq}(W(i))[c] = \text{freq}(W(i-1))[c] + [s[i] = c] - [s[i - m] = c] \quad \forall c \in ['a'\dots'z']$$
> - **Equivalence Guarantee**: Because $|W| \equiv |p| = m$ at all times, testing $\text{freq}(W) = \text{freq}(p)$ is both **necessary and sufficient** to prove $W$ is a valid permutation of $p$.

---

## ⚠️ Sneaky Interview Traps & Pitfalls
> [!warning] ⚠️ Critical Gotchas to Avoid
> 1. **The Double-Advance Skip Trap (`r+1` after `r++`)**:
>    When incrementing `r++`, accessing `s[r+1]` causes a double skip and triggers an out-of-bounds heap-buffer-overflow when $r = n - 1$.
>    ```cpp
>    // ❌ BUG: Double jump + out of bounds at string end
>    r++;
>    if (r < n) s1[s[r + 1] - 'a']++;
>    
>    // ✅ FIX: Access the newly incremented index r directly
>    r++;
>    if (r < n) s1[s[r] - 'a']++;
>    ```
> 2. **Base Guard Against $n < m$**:
>    If $s$ is shorter than $p$, no anagram can exist. Immediately return `{}` before initializing the window to avoid reading out of bounds.
> 3. **Modifying In-Window Elements**:
>    Never touch elements that remain inside the window. Only modify the leaving char (`s[l]`) and the entering char (`s[r]`).

---

## 🪜 Progressive Pattern Ladder & Variations
- ⬅ **Prerequisite**: [[LC 242 Valid Anagram]] — Frequency counting baseline
- ⬅ **Sister Problem**: [[LC 567 Permutation in String]] — Returns `bool` if any permutation is found
- 🎯 **Current Anchor**: [[LC 438 Find All Anagrams in a String]] — Returns all matching start indices
- ➔ **Next Boss Variation**: [[LC 76 Minimum Window Substring]] — Dynamic contraction variable window (Hard)

---

## 💻 Optimal C++20 Implementations

### Approach 1: Explicit Two Pointers ($l$ & $r$) — Your Intuitive Sliding Window
```cpp
// Time Complexity: O(26 * N) = O(N) | Space Complexity: O(1)
class SolutionTwoPointers {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s1(26, 0), p1(26, 0);
        vector<int> ans;

        // Seed initial window [0, m - 1]
        for (int i = 0; i < m; i++) {
            s1[s[i] - 'a']++;
            p1[p[i] - 'a']++;
        }

        int l = 0, r = m - 1;
        while (r < n) {
            if (s1 == p1) {
                ans.push_back(l);
            }
            // 1. Evict left character
            s1[s[l++] - 'a']--;

            // 2. Expand right boundary
            r++;
            if (r < n) {
                s1[s[r] - 'a']++;
            }
        }
        return ans;
    }
};
```

---

### Approach 2: Canonical 1-Loop Sliding Window — Recommended Interview Standard
> [!tip] 🌟 Immune to Off-by-One Pointer Errors
> Index `i` enters on the right; `i - m` leaves on the left. No separate `l` and `r` variables to manage.

```cpp
// Time Complexity: O(26 * N) = O(N) | Space Complexity: O(1)
class SolutionCanonical {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s_count(26, 0), p_count(26, 0);
        vector<int> ans;

        // Seed initial window of size m
        for (int i = 0; i < m; ++i) {
            s_count[s[i] - 'a']++;
            p_count[p[i] - 'a']++;
        }

        if (s_count == p_count) {
            ans.push_back(0);
        }

        // Slide window by 1 character on each iteration
        for (int i = m; i < n; ++i) {
            s_count[s[i] - 'a']++;       // Incoming char on right
            s_count[s[i - m] - 'a']--;   // Outgoing char on left

            if (s_count == p_count) {
                ans.push_back(i - m + 1); // Start index of matching window
            }
        }

        return ans;
    }
};
```

---

### Approach 3: Ultra-Optimal Match Counter — Meta & Google Staff Engineer Standard
> [!tip] 🚀 Eliminates the 26-Vector Equality Check on Every Slide
> Tracks scalar `matches` count ($0 \dots 26$). Drops per-slide cost from $26$ operations to strictly $\mathcal{O}(1)$ arithmetic updates.

```cpp
// Time Complexity: Strictly O(N) scalar ops | Space Complexity: O(1)
class SolutionMatchesCounter {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        if (n < m) return {};

        vector<int> s_count(26, 0), p_count(26, 0);
        vector<int> ans;

        for (int i = 0; i < m; ++i) {
            s_count[s[i] - 'a']++;
            p_count[p[i] - 'a']++;
        }

        int matches = 0;
        for (int c = 0; c < 26; ++c) {
            if (s_count[c] == p_count[c]) matches++;
        }

        if (matches == 26) {
            ans.push_back(0);
        }

        for (int i = m; i < n; ++i) {
            int in_char = s[i] - 'a';
            int out_char = s[i - m] - 'a';

            if (in_char == out_char) {
                if (matches == 26) ans.push_back(i - m + 1);
                continue;
            }

            // 1. Process incoming character
            s_count[in_char]++;
            if (s_count[in_char] == p_count[in_char]) {
                matches++;
            } else if (s_count[in_char] == p_count[in_char] + 1) {
                matches--;
            }

            // 2. Process outgoing character
            s_count[out_char]--;
            if (s_count[out_char] == p_count[out_char]) {
                matches++;
            } else if (s_count[out_char] == p_count[out_char] - 1) {
                matches--;
            }

            if (matches == 26) {
                ans.push_back(i - m + 1);
            }
        }

        return ans;
    }
};
```
