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

class SegmentTree
{
private:
    vi tree;
    int n;

    int merge(int left, int right)
    {
        return left + right;
    }

    int query(int node, int start, int end, int L, int R)
    {
        if (R < start || L > end)
        {
            return 0; 
        }
        if (L <= start && end <= R)
        {
            return tree[node]; 
        }

        int mid = (start + end) / 2;
        int leftResult = query(2 * node, start, mid, L, R);
        int rightResult = query(2 * node + 1, mid + 1, end, L, R);
        return merge(leftResult, rightResult);
    }

    void update(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            tree[node] = value; 
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, value);
            else
                update(2 * node + 1, mid + 1, end, idx, value);

            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
    }

public:
    SegmentTree(int size)
    {
        n = size;
        tree.resize(4 * n, 0); 
    }

    void update(int idx, int value)
    {
        update(1, 1, n, idx, value);
    }

    int query(int L, int R)
    {
        return query(1, 1, n, L, R);
    }
};

void solve()
{
    int n;
    cin >> n;

    vi pos(2 * n + 1, 0), ans(n + 1);
    SegmentTree segTree(2 * n);

    FOR(i, 1, 2 * n + 1)
    {
        int num;
        cin >> num;

        if (pos[num] == 0)
        {
            pos[num] = i; 
        }
        else
        {
            ans[num] = segTree.query(pos[num], i);
            segTree.update(pos[num], 1);
        }
    }

    FOR(i, 1, n + 1)
    {
        cout << ans[i] << sp;
    }
    cout << nl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
