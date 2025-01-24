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
//https://codeforces.com/contest/482/problem/B
const int MAXBIT = 30;
struct SegmentTree {
    vi tree, lazy;
    int n;

    SegmentTree(int size) : n(size), tree(4 * size, (1 << MAXBIT) - 1), lazy(4 * size, -1) {}

    void propagate(int node, int start, int end) {
        if (lazy[node] != -1) {
            tree[node] &= lazy[node];
            if (start != end) {
                if (lazy[node * 2] == -1)
                    lazy[node * 2] = lazy[node];
                else
                    lazy[node * 2] &= lazy[node];

                if (lazy[node * 2 + 1] == -1)
                    lazy[node * 2 + 1] = lazy[node];
                else
                    lazy[node * 2 + 1] &= lazy[node];
            }
            lazy[node] = -1;
        }
    }

    void build(int node, int start, int end, vi &a) {
        if (start == end) {
            tree[node] = a[start];
            return;
        }
        int mid = (start + end) / 2;
        build(node * 2, start, mid, a);
        build(node * 2 + 1, mid + 1, end, a);
        tree[node] = tree[node * 2] & tree[node * 2 + 1];
    }

    void update(int node, int start, int end, int l, int r, int value) {
        propagate(node, start, end);

        if (start > r || end < l) return;

        if (l <= start && end <= r) {
            lazy[node] = value;
            propagate(node, start, end);
            return;
        }

        int mid = (start + end) / 2;
        update(node * 2, start, mid, l, r, value);
        update(node * 2 + 1, mid + 1, end, l, r, value);
        tree[node] = tree[node * 2] & tree[node * 2 + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (start > r || end < l) return (1 << MAXBIT) - 1;

        if (l <= start && end <= r) return tree[node];

        int mid = (start + end) / 2;
        int left = query(node * 2, start, mid, l, r);
        int right = query(node * 2 + 1, mid + 1, end, l, r);
        return left & right;
    }

    void build(vi &a) {
        build(1, 0, n - 1, a);
    }

    void update(int l, int r, int value) {
        update(1, 0, n - 1, l, r, value);
    }

    int query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> queries(m);
    f0r(i, m) {
        int l, r, q;
        cin >> l >> r >> q;
        l--; r--;
        queries[i] = {l, r, q};
    }

    vi a(n, 0);
    f0r(bit, MAXBIT + 1) {
        vi sum(n, 0);
        trav(q, queries) {
            int l, r, val;
            tie(l, r, val) = q;
            if ((val >> bit) & 1) {
                sum[l]++;
                if (r + 1 < n) sum[r + 1]--;
            }
        }

        f0r(i, n) {
            if (i > 0) sum[i] += sum[i - 1];
            if (sum[i] > 0) a[i] |= (1 << bit);
        }
    }

    SegmentTree segTree(n);
    segTree.build(a);

    trav(q, queries) {
        int l, r, val;
        tie(l, r, val) = q;
        if (segTree.query(l, r) != val) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    trav(x, a) cout << x << sp;
    cout << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t; 
    while (t--) solve();

    return 0;
}
