#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define sp ' '
#define pi 2 * acos(0.0)
const int INF = 1e9 + 10;

#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define f0r(i, a) for (int i = 0; i < (a); i++)
#define fOrd(i, a, b) for (int i = (b) - 1; i >= a; i--)
#define f0rd(i, a) for (int i = (a) - 1; i >= 0; i--)
#define trav(a, x) for (auto &a : x)

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

#define len(x) int((x).size())
#define pb push_back
#define all(n) n.begin(), n.end()
#define rall(n) n.rbegin(), n.rend()

const ll mod = 1e9 + 7;

class LazySegmentTree {
private:
    vll tree, lazy;
    ll n;

    void build(vll &a, ll node, ll l, ll r) {
        if (l == r) {
            tree[node] = a[l];
        } else {
            ll mid = (l + r) / 2;
            build(a, 2 * node, l, mid);
            build(a, 2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void push(ll node, ll l, ll r) { //push == propagate (same same)
        if (lazy[node]) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(ll node, ll l, ll r, ll L, ll R, ll val) {
        push(node, l, r);
        if (r < L || R < l) return;

        if (L <= l && r <= R) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        ll mid = (l + r) / 2;
        update(2 * node, l, mid, L, R, val);
        update(2 * node + 1, mid + 1, r, L, R, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    ll query(ll node, ll l, ll r, ll L, ll R) {
        push(node, l, r);
        if (r < L || R < l) return 0;

        if (L <= l && r <= R) return tree[node];

        ll mid = (l + r) / 2;
        return query(2 * node, l, mid, L, R) + query(2 * node + 1, mid + 1, r, L, R);
    }

public:
    LazySegmentTree(vll &a) {
        n = len(a);
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(a, 1, 0, n - 1);
    }

    void range_update(ll l, ll r, ll val) {
        update(1, 0, n - 1, l, r, val);
    }

    ll range_query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    ll n, q;
    cin >> n >> q;
    vll a(n);
    f0r(i, n) cin >> a[i];

    LazySegmentTree seg(a);

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            ll l, r, val;
            cin >> l >> r >> val;
            seg.range_update(l, r - 1, val); // 0-indexed range
        } else {
            ll l, r;
            cin >> l >> r;
            cout << seg.range_query(l, r - 1) << nl; // 0-indexed range
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t; cin >> t;
    // while (t--) solve();
    solve();

    return 0;
}
