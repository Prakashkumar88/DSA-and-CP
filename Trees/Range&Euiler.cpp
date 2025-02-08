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

int cnt = 0;
vll flatTree;

void dfs(int node, int par, vi adj[], vii &index)
{
    index[node].first = cnt;
    flatTree.pb(node);
    cnt++;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node, adj, index);
        }
    }
    index[node].second = cnt;
    flatTree.pb(node);
    cnt++;
}

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
            tree[node] = arr[start];
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
        return merge(query(2 * node, start, mid, L, R),
                     query(2 * node + 1, mid + 1, end, L, R));
    }

public:
    SegmentTree(vll &inputArray)
    {
        n = inputArray.size();
        arr = inputArray;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void update(ll idx, ll value)
    {
        update(1, 0, n - 1, idx, value);
    }

    ll query(ll L, ll R)
    {
        return query(1, 0, n - 1, L, R);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vi v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vi adj[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vii index(n + 1);
    dfs(1, 0, adj, index);

    vll segtree(cnt);
    for (int i = 0; i < cnt; i++)
    {
        segtree[i] = (i % 2 == 0) ? v[flatTree[i]] : 0;
    }

    SegmentTree segTree(segtree);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 2)
        {
            ll node;
            cin >> node;
            cout << segTree.query(index[node].first, index[node].second) << nl;
        }
        else
        {
            ll node, val;
            cin >> node >> val;
            segTree.update(index[node].first, val);
            segTree.update(index[node].second, 0);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
