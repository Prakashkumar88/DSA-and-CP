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
    ll hashValue(string string, ll radix, ll m){
        ll ans = 0, factor = 1;
        for(ll i = m - 1; i >= 0; i--){
            ans += ((string[i] - 'a') * factor)%mod;
            factor = (factor * radix)%mod;
        }
        return ans%mod;
    }
    int strStr(string haystack, string needle) {
        ll n = len(haystack), m = len(needle);
        
        if(n < m) return -1;
        ll radix = 26, maxWeight = 1;
        for(ll i = 1; i <= m; i++){
            maxWeight = (maxWeight*radix)%mod;
        }

        ll hashNeedle = hashValue(needle, radix, m), hashHay = 0;

        for(ll i = 0; i <= n - m; i++){
            if(i == 0){
                hashHay = hashValue(haystack, radix, m);
            }else{
                hashHay = ((hashHay*radix)%mod - ((haystack[i-1] - 'a')*maxWeight)%mod +                          (haystack[i+m-1] - 'a') + mod)%mod;
            }


            if(hashNeedle == hashHay){
                for(ll j = 0; j < m; j++){
                    if(needle[j] != haystack[j+i]) break;
                    if(j == m - 1) return i;
                }
            }
        }
        return -1;
    }
};
