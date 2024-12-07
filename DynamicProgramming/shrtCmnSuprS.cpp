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
vvi dp;
int shrtCmnSuprS(string s1, string s2, int n, int m){
    if(n == 0 || m == 0) return 0;

    if(dp[n][m] != -1) return dp[n][m];

    if(s1[n-1] == s2[m-1]){
        return dp[n][m] = 1 + shrtCmnSuprS(s1, s2, n-1, m-1);
    }
    else{
        return dp[n][m] = max(shrtCmnSuprS(s1, s2, n, m-1), shrtCmnSuprS(s1, s2, n-1, m));
    }

    return dp[n][m];
}
void solve(){
    string s1, s2;
    cin >> s1 >> s2;
                                                 // s1 = “geek”, s2 = “eke”
    int n = len(s1), m = len(s2);                // output - 5
    dp.assign(n + 1, vector<int>(m + 1, -1));    //Explanation: String “geeke” has both string “geek” and “eke” as subsequences.

    cout << n+m-shrtCmnSuprS(s1, s2, n, m) << nl;
    
    int i = n, j = m;
    string ans;
    
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
            i--;
            j--;
        }else{
            (dp[i-1][j] > dp[i][j-1] ? (ans += s1[i-1], i--) : (ans += s2[j-1], j--));
        }
    }
    while (i > 0) {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0) {
        ans += s2[j - 1];
        j--;
    }
    reverse(all(ans));
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while(t--)
        solve();

    return 0;
}
