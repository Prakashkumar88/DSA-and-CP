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
    vector<pair<vll, ll>> tree;
    vll lazy;
    ll n;

    pair<vll, ll> merge(const pair<vll, ll>& left, const pair<vll, ll>& right) {
        pair<vll, ll> result;
        result.second = left.second + right.second;
        result.first.resize(22);
        for (int i = 0; i < 22; i++) {
            result.first[i] = left.first[i] + right.first[i];
        }
        return result;
    }

    vll binaryRepresentation(ll x) {
        vll bits(22, 0);
        for (int i = 0; i <= 21; i++) {
            if ((1LL << i) & x)
                bits[i]++;
        }
        return bits;
    }

    void propagate(ll node, ll start, ll end) {
        if (lazy[node] != 0) {
            applyUpdate(tree[node], lazy[node], start, end);
            if (start != end) { 
                lazy[2 * node] ^= lazy[node];
                lazy[2 * node + 1] ^= lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void applyUpdate(pair<vll, ll>& node, ll value, ll start, ll end) {
        ll total = 0;
        for (int i = 0; i <= 21; i++) {
            if ((1LL << i) & value) {
                node.first[i] = (end - start + 1) - node.first[i];
            }
            total += (1LL << i) * node.first[i];
        }
        node.second = total;
    }

    void build(ll node, ll start, ll end, const vll& arr) {
        if (start == end) {
            tree[node].second = arr[start];
            tree[node].first = binaryRepresentation(arr[start]);
            return;
        }
        ll mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void updateRange(ll node, ll start, ll end, ll L, ll R, ll value) {
        propagate(node, start, end);
        if (R < start || L > end) return;
        if (L <= start && end <= R) {
            lazy[node] ^= value;
            propagate(node, start, end);
            return;
        }
        ll mid = (start + end) / 2;
        updateRange(2 * node, start, mid, L, R, value);
        updateRange(2 * node + 1, mid + 1, end, L, R, value);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    ll queryRange(ll node, ll start, ll end, ll L, ll R) {
        propagate(node, start, end);
        if (R < start || L > end) return 0;
        if (L <= start && end <= R) return tree[node].second;
        ll mid = (start + end) / 2;
        ll left = queryRange(2 * node, start, mid, L, R);
        ll right = queryRange(2 * node + 1, mid + 1, end, L, R);
        return left + right;
    }

public:
    SegmentTree(const vll& arr) {
        n = arr.size();
        tree.resize(4 * n, make_pair(vll(22, 0), 0));
        lazy.resize(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void update(ll L, ll R, ll value) {
        updateRange(1, 0, n - 1, L, R, value);
    }

    ll query(ll L, ll R) {
        return queryRange(1, 0, n - 1, L, R);
    }
};

void solve() {
    int n;
    cin >> n;

    vll arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SegmentTree segTree(arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r;
            cin >> l >> r;
            cout << segTree.query(l - 1, r - 1) << nl;
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            segTree.update(l - 1, r - 1, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}
