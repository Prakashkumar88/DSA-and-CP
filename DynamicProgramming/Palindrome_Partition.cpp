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
#define fOrd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define f0rd(i, a) for (int i = (a) - 1; i >= 0; i--)
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
ll nCk(ll n, ll k)
{
    ll res = 1;
    for (ll i = 0; i < k; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}
ll power(ll a, ll b, ll mod)
{
    if (b == 0)
        return 1;
    ll res = power(a, b / 2, mod);
    res = (res * res) % mod;
    if (b % 2 != 0)
        res = (res * a) % mod;
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
bool isPalindrome(const string &s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int costMult(const string &s, int i, int j)
{

    if (i >= j || isPalindrome(s, i, j))
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int mn = INF;
    for (int k = i; k < j; k++)
    {
        int left = (dp[i][k] != -1) ? dp[i][k] : costMult(s, i, k);
        int right = (dp[k + 1][j] != -1) ? dp[k + 1][j] : costMult(s, k + 1, j);

        dp[i][k] = left;
        dp[k + 1][j] = right;

        int temp = left + right + 1;
        mn = min(mn, temp);
    }

    return dp[i][j] = mn;
}
void solve()
{
    string s;
    cin >> s;
    int n = len(s);
    dp.assign(n + 1, vi(n + 1, -1));

    cout << costMult(s, 0, n - 1) << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while (t--)
    solve();

    return 0;
}
