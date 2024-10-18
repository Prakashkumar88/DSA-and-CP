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
const ll MOD = 1e9 + 7;

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

ll calcXsum(ll x, ll &topXSum, multiset<ll> &topXSet, multiset<ll> &remainingSet)
{
    return topXSum;  
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
    multiset<ll> topXSet, remainingSet;
    ll topXSum = 0;

    ll n = len(v);
    for (int i = 0; i < k && i < n; i++)
    {
        mp[v[i]]++;
        ll freq = mp[v[i]];

        if (topXSet.size() < x)
        {
            topXSet.insert(freq);
            topXSum += freq;
        }
        else
        {
            remainingSet.insert(freq);
        }
    }

    vll ans;
    ans.pb(calcXsum(x, topXSum, topXSet, remainingSet));

    for (int i = k; i < n; i++)
    {
        ll remove = v[i - k];
        ll add = v[i];

        ll oldFreqRemove = mp[remove];
        mp[remove]--;
        ll newFreqRemove = mp[remove];

        if (topXSet.find(oldFreqRemove) != topXSet.end())
        {
            topXSet.erase(topXSet.find(oldFreqRemove));
            topXSum -= oldFreqRemove;
        }
        else
        {
            remainingSet.erase(remainingSet.find(oldFreqRemove));
        }

        if (newFreqRemove > 0)
        {
            if (topXSet.size() < x)
            {
                topXSet.insert(newFreqRemove);
                topXSum += newFreqRemove;
            }
            else if (newFreqRemove > *topXSet.begin())
            {
                ll smallestTopX = *topXSet.begin();
                topXSet.erase(topXSet.find(smallestTopX));
                topXSum -= smallestTopX;
                remainingSet.insert(smallestTopX);
                topXSet.insert(newFreqRemove);
                topXSum += newFreqRemove;
            }
            else
            {
                remainingSet.insert(newFreqRemove);
            }
        }

   
        ll oldFreqAdd = mp[add];
        mp[add]++;
        ll newFreqAdd = mp[add];

        if (topXSet.find(oldFreqAdd) != topXSet.end())
        {
            topXSet.erase(topXSet.find(oldFreqAdd));
            topXSum -= oldFreqAdd;
        }
        else
        {
            remainingSet.erase(remainingSet.find(oldFreqAdd));
        }
        if (newFreqAdd > 0)
        {
            if (topXSet.size() < x)
            {
                topXSet.insert(newFreqAdd);
                topXSum += newFreqAdd;
            }
            else if (newFreqAdd > *topXSet.begin())
            {
                ll smallestTopX = *topXSet.begin();
                topXSet.erase(topXSet.find(smallestTopX));
                topXSum -= smallestTopX;
                remainingSet.insert(smallestTopX);
                topXSet.insert(newFreqAdd);
                topXSum += newFreqAdd;
            }
            else
            {
                remainingSet.insert(newFreqAdd);
            }
        }

        ans.pb(calcXsum(x, topXSum, topXSet, remainingSet));
    }

    trav(e, ans)
    {
        cout << e << sp;
    }
    cout << nl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}
