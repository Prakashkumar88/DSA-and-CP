#include <bits/stdc++.h>
//Given a permutation pi of n elements, find for each i the number of j such that j<i and pj>pi.
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

class SegmentTree
{
private:
    vll tree;
    vll arr;
    ll n;

    ll merge(ll left, ll right)
    {
        return left + right;  
    }

    void build(ll node, ll start, ll end)
    {
        if (start == end)
        {
            tree[node] = 0;  
        }
        else
        {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node;   
            ll rightChild = 2 * node + 1;

            build(leftChild, start, mid);
            build(rightChild, mid + 1, end);

            tree[node] = merge(tree[leftChild], tree[rightChild]); 
        }
    }

    void update(ll node, ll start, ll end, ll idx, ll value)
    {
        if (start == end)
        {
            arr[idx] = value;
            tree[node] = value;
        }
        else
        {
            ll mid = (start + end) / 2;
            ll leftChild = 2 * node;
            ll rightChild = 2 * node + 1;

            if (idx <= mid)
            {
                update(leftChild, start, mid, idx, value);
            }
            else
            {
                update(rightChild, mid + 1, end, idx, value);
            }

            tree[node] = merge(tree[leftChild], tree[rightChild]);
        }
    }

    ll query(ll node, ll start, ll end, ll L, ll R)
    {
        if (R < start || L > end)
        {
            return 0; 
        }
        if (L <= start && end <= R)
        {
            return tree[node];
        }

        ll mid = (start + end) / 2;
        ll leftResult = query(2 * node, start, mid, L, R);
        ll rightResult = query(2 * node + 1, mid + 1, end, L, R);
        return merge(leftResult, rightResult);
    }

public:
    SegmentTree(vll inputArray)
    {
        n = inputArray.size();
        arr = inputArray;
        tree.resize(4*n, 0); 
        build(1, 0, n-1); 
    }

    void update(ll idx, ll value)
    {
        update(1, 0, n-1, idx, value); 
    }

    ll query(ll L, ll R)
    {
        return query(1, 0, n-1, L, R); 
    }
};

void solve()
{
    int n;
    cin >> n;

    vll v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
        v[i]--;
    }
    SegmentTree segTree(v);

    f0r(i, n){
        cout << segTree.query(v[i]+1, n-1) << sp;
        segTree.update(v[i], 1);
    }
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


