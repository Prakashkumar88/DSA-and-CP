#include <bits/stdc++.h>
//https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/description/
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
const ll MOD = 1e9 + 7;

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
ll calcXsum(ll x, set<pair<ll, ll>> &st)
{
    ll sum = 0, count = x;
    for (auto it = st.rbegin(); it != st.rend() && count > 0; it++, count--)
    {
        sum += (it->first) * (it->second);
    }
    return sum;
}
void solve()
{
    vll v;
    int temp;
    while (cin >> temp)
    {
        v.pb(temp);
        if (cin.peek() == nl) break;
    }
    ll k, x;
    cin >> k >> x;

    map<ll, ll> mp;
    set<pair<ll, ll>> st;
    ll n = len(v);
    for (int i = 0; i < k && i < n; i++)
    {
        mp[v[i]]++;
        st.insert({mp[v[i]], v[i]});
    }

    vll ans;
    ans.pb(calcXsum(x, st));

    for (int i = k; i < n; i++)
    {
        ll remove = v[i - k];
        ll add = v[i];

        st.erase({mp[remove], remove});
        mp[remove]--;
        if (mp[remove] > 0)
        {
            st.insert({mp[remove], remove});
        }

        st.erase({mp[add], add});
        mp[add]++;
        st.insert({mp[add], add});
        ans.pb(calcXsum(x, st));
    }

    trav(e, ans)
    {
        cout << e << sp;
    }
    cout << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
