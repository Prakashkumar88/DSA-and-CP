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
unordered_map<string, int> mp;
string makeKey(int i, int j, bool isTrue){
    return to_string(i) + "_" + to_string(j) + "_" +(isTrue == true ? "T" : "F");
}
int waysTrue(string s, int i, int j, bool isTrue){
    if(i > j) return 0;
    if(i == j){
        if(isTrue) return s[i] == 'T';
        else return s[i] == 'F';
    }

    string key = makeKey(i, j, isTrue);
    if(mp.find(key) != mp.end()) return mp[key];

    int ways = 0;
    for(int k = i + 1; k < j; k+=2){
        int leftTrue = waysTrue(s, i, k-1, true);
        int leftFalse = waysTrue(s, i, k-1, false);
        int rightTrue = waysTrue(s, k+1, j, true);
        int rightFalse = waysTrue(s, k+1, j, false);

        char op = s[k];
        if(op == '&'){
            if(isTrue) ways += leftTrue*rightTrue;
            else ways += leftFalse*rightFalse + leftFalse*rightTrue + leftTrue*rightFalse;
        }else if(op == '|'){
            if(isTrue) ways += leftTrue*rightTrue + leftTrue*rightFalse + leftFalse*rightTrue;
            else ways += leftFalse*rightFalse;
        }else if(op == '^'){
            if(isTrue) ways += leftTrue*rightFalse + leftFalse*rightTrue;
            else ways += leftTrue*rightTrue + leftFalse*rightFalse;
        }
    }

    return mp[key] = ways;
}
void solve(){
    string s;
    cin >> s;

    int n = len(s);
    cout << waysTrue(s, 0, n-1, true) << nl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t;
    // cin >> t;
    // while(t--)
        solve();

    return 0;
}
