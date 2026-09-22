/**
 * Competitive Programming Master Template (C++20)
 * Optimized for: Codeforces (Div 2/1) & LeetCode Hard
 * Includes: Fast I/O, Modular Arithmetic, Custom Hash (Anti-Hack)
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <chrono>

using namespace std;

// Type Aliases
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;

// Constants
constexpr ll INF64 = 1e18;
constexpr int INF32 = 1e9;
constexpr ll MOD = 1e9 + 7;       // Default CP modulo
constexpr ll MOD_998 = 998244353; // NTT modulo

// Anti-Hash Collision (Prevents O(N^2) hacks on unordered_map in Codeforces)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// Modular Exponentiation: (base^exp) % mod in O(log exp)
ll mod_pow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

// Modular Inverse via Fermat's Little Theorem (mod must be prime)
ll mod_inv(ll n, ll mod = MOD) {
    return mod_pow(n, mod - 2, mod);
}

// Fast I/O Initialization
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve() {
    // Problem logic here
}

int main() {
    fast_io();
    int t = 1;
    // cin >> t; // Uncomment if multiple test cases
    while (t--) {
        solve();
    }
    return 0;
}
