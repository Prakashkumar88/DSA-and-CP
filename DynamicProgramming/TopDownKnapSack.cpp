#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")

#define nl '\n'
#define vi vector<int>
#define vvi vector<vector<int>>

int maxProfit(const vi &cost, const vi &w, int n, int m) {
    // Initialize the DP table
    vvi dp(n + 1, vi(m + 1, 0));

    // Fill the table iteratively
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (w[i - 1] > j) {
                // Current item weight exceeds capacity, exclude the item
                dp[i][j] = dp[i - 1][j];
            } else {
                // Maximize profit by including or excluding the current item
                dp[i][j] = max(dp[i - 1][j], cost[i - 1] + dp[i - 1][j - w[i - 1]]);
            }
        }
    }

    // Return the maximum profit, which is stored in dp[n][m]
    return dp[n][m];
}

void solve() {
    int n, m;
    cin >> n >> m;

    vi cost(n), w(n);
    for (int i = 0; i < n; i++) cin >> cost[i];
    for (int i = 0; i < n; i++) cin >> w[i];

    cout << maxProfit(cost, w, n, m) << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
