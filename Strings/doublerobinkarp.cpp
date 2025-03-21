#include <bits/stdc++.h>

using namespace std;

// Add the necessary include paths to the compiler flags
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
const int INF = 1e9 + 10;

// Control Flow
#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define f0r(i, a) for (int i = 0; i < (a); i++)
#define fOrd(i, a, b) for (int i = (b)-1; i >= a; i--)
#define f0rd(i, a) for (int i = (a)-1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

// Types
#define ui unsigned int
#define us unsigned short
#define ull unsigned long long
#define ll long long
#define ld long double
#define vstr vector<string>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vii vector<pair<int, int>>
#define pii pair<int, int>

// Utils
#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

// Constants
const ll mod = 1e9 + 7;

// Helper Functions
ll nCk(ll n, ll k){
    ll res = 1;
    for (ll i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}
ll power(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    ll res = power(a, b / 2, mod);
    res = (res * res) % mod;
    if (b % 2 != 0) res = (res * a) % mod;
    return res;
}
/*
    ___        __              __   ______          __        _____ __             __          __  __
   /   | _____/ /___  ______ _/ /  / ____/___  ____/ /__     / ___// /_____ ______/ /______   / / / /__  ________
  / /| |/ ___/ __/ / / / __ `/ /  / /   / __ \/ __  / _ \    \__ \/ __/ __ `/ ___/ __/ ___/  / /_/ / _ \/ ___/ _ \
 / ___ / /__/ /_/ /_/ / /_/ / /  / /___/ /_/ / /_/ /  __/   ___/ / /_/ /_/ / /  / /_(__  )  / __  /  __/ /  /  __/
/_/  |_\___/\__/\__,_/\__,_/_/   \____/\____/\__,_/\___/   /____/\__/\__,_/_/   \__/____/  /_/ /_/\___/_/   \___/
*/

class Solution {
public:
    const long long mod1 = 1e9 + 7, mod2 = 1e9 + 33;
    const long long radix1 = 31, radix2 = 37;

    pair<long long, long long> hashValue(const string &s, long long m) {
        long long hash1 = 0, hash2 = 0;
        for (long long i = 0; i < m; i++) {  
            hash1 = (hash1 * radix1 + (s[i] - 'a' + 1)) % mod1;
            hash2 = (hash2 * radix2 + (s[i] - 'a' + 1)) % mod2;
        }
        return {hash1, hash2};
    }

    int strStr(string haystack, string needle) {
        long long n = haystack.size(), m = needle.size();
        if (n < m) return -1;

        long long maxWeight1 = 1, maxWeight2 = 1;
        for (long long i = 1; i < m; i++) {
            maxWeight1 = (maxWeight1 * radix1) % mod1;
            maxWeight2 = (maxWeight2 * radix2) % mod2;
        }

        auto needleHash = hashValue(needle, m);
        auto hayHash = hashValue(haystack, m);

        if (hayHash == needleHash && haystack.substr(0, m) == needle) return 0; 

        for (long long i = 1; i <= n - m; i++) {
            hayHash.first = ((hayHash.first - (haystack[i - 1] - 'a' + 1) * maxWeight1 % mod1 + mod1) % mod1 * radix1 + (haystack[i + m - 1] - 'a' + 1)) % mod1;
            hayHash.second = ((hayHash.second - (haystack[i - 1] - 'a' + 1) * maxWeight2 % mod2 + mod2) % mod2 * radix2 + (haystack[i + m - 1] - 'a' + 1)) % mod2;

            if (hayHash == needleHash && haystack.substr(i, m) == needle) return i; 
        }

        return -1;
    }
};

