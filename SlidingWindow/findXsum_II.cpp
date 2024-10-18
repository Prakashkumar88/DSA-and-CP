#include <bits/stdc++.h>

using namespace std;

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

void findXSum(vector<int>& nums, int k, int x) {
    int n = nums.size(); 
    unordered_map<long long, long long> freq;   
    set<pair<long long, long long>> left, right; 
    long long sum = 0;              
    vector<long long> ans;          

    auto add_right = [&](long long count, long long value) {
        right.insert({count, value}); 
        sum += count * value;   
        if (right.size() > x) {        
            auto smallest = *right.begin();   
            sum -= smallest.first * smallest.second; 
            left.insert(smallest);    
            right.erase(right.begin()); 
        }
    };

    auto remove_right = [&](long long count, long long value) {
        auto smallest = *right.begin(); 
        auto current = make_pair(count, value); 
        if (current >= smallest) {  
            sum -= count * value; 
            right.erase(current);    
            if (left.size() && right.size() < x) { 
                auto largest = *left.rbegin(); 
                sum += largest.first * largest.second; 
                right.insert(largest); 
                left.erase(largest);   
            }
        } else {
            left.erase(current); 
        }
    };

    int i = 0; 
    for (int j = 0; j < n; j++) { 
        
        if (freq[nums[j]] > 0) {
            remove_right(freq[nums[j]], nums[j]); 
        }
        freq[nums[j]]++; 
        add_right(freq[nums[j]], nums[j]); 

        if (j - i + 1 > k) { 
            remove_right(freq[nums[i]], nums[i]); 
            freq[nums[i]]--; 
            if (freq[nums[i]] > 0) { 
                add_right(freq[nums[i]], nums[i]);
            }
            i++; 
        }

        if (j - i + 1 == k) {
            ans.push_back(sum); 
        }
    }

    for (auto &result : ans) {
        cout << result << sp;
    }
    cout << nl;
}

void solve() {
    vector<int> v;
    int temp;
    while (cin >> temp) {
        v.pb(temp);
        if (cin.peek() == nl) break;
    }

    ll k, x;
    cin >> k >> x;

    findXSum(v, k, x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
