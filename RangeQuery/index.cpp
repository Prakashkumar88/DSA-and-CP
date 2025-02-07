// 1 l r v : add the value v to the segment from l to r-1;
// 2 i: find the value of the element with index i
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

class SegmentTree {
private:
    vll tree; 
    int n;

    ll merge(ll left, ll right) {
        return left + right;
    }

    ll query(int node, int start, int end, int idx) {
        if (start == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            return merge(tree[node], query(2 * node, start, mid, idx));
        } else {
            return merge(tree[node], query(2 * node + 1, mid + 1, end, idx));
        }
    }

    void update(int node, int start, int end, int l, int r, ll value) {
        if (r < start || l > end) { 
            return;
        }
        if (l <= start && end <= r) { 
            tree[node] += value;
            return;
        }
        int mid = (start + end) / 2;
        update(2 * node, start, mid, l, r, value);       
        update(2 * node + 1, mid + 1, end, l, r, value); 
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n, 0);
    }

    void range_update(int l, int r, ll value) {
        update(1, 0, n - 1, l, r - 1, value);
    }

    ll point_query(int idx) {
        return query(1, 0, n - 1, idx);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    SegmentTree segTree(n);

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) { 
            int l, r, val;
            cin >> l >> r >> val;
            segTree.range_update(l, r, val);
        } else if (op == 2) { 
            int index;
            cin >> index;
            cout << segTree.point_query(index) << nl;
        } else {
            assert(false); 
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
