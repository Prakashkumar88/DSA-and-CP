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
map<int, pair<int, int>> tme;
int t = 0;
void dfs(int node, vi adj[],int par){
    //we are entering the node
    tme[node].first = t;
    t++;
    // cout << node << sp;
    trav(child, adj[node]){
        if(child == par) continue;
        dfs(child, adj, node);
    }
    //we are leaving the node
    tme[node].second = t;
    t++;
    
} 

bool isAncestor(int u, int v) {
    return (tme[u].first <= tme[v].first && tme[u].second >= tme[v].second);
}
void solve(){
    int n;
    cin >> n;

    vi adj[n+1];
    f0r(i, n-1){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1, adj, 0);
    int q;
    cin >> q; 
    while (q--) {
        int u, v;
        cin >> u >> v;
        if (isAncestor(u, v))
            cout << u << " is an ancestor of " << v << "\n";
        else
            cout << u << " is NOT an ancestor of " << v << "\n";
    }


}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    auto start = chrono::high_resolution_clock::now();
    int t;
    cin >> t;
    while(t--)
        solve();

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms";
    return 0;
}
