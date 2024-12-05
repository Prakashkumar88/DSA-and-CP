void collectSubsets(vvi &dp, vi &v, int n, int sum, vi &currentSubset, vector<vi> &allSubsets) {
  
    if (sum == 0) {
        allSubsets.push_back(currentSubset);
        return;
    }
    if (n == 0) return;
    if (dp[n - 1][sum]) {
        collectSubsets(dp, v, n - 1, sum, currentSubset, allSubsets);
    }
    if (sum >= v[n - 1] && dp[n - 1][sum - v[n - 1]]) {
        currentSubset.push_back(v[n - 1]);
        collectSubsets(dp, v, n - 1, sum - v[n - 1], currentSubset, allSubsets);
        currentSubset.pop_back(); 
    }
}


bool equalPartition(vi &v, int sum, vector<vi> &subsets) {
    int n = v.size();
    vvi dp(n + 1, vi(sum + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (v[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - v[i - 1]];
            }
        }
    }

    if (dp[n][sum]) {
        vi currentSubset;
        collectSubsets(dp, v, n, sum, currentSubset, subsets);
    }

    return dp[n][sum];
}

void solve() {
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0);

    if (sum % 2 != 0) {
        cout << "No" << nl;
        return;
    }

    vector<vi> subsets;
    if (equalPartition(v, sum / 2, subsets)) {
        cout << "Yes" << nl;
        cout << "Subsets forming the partition:" << nl;
        for (const auto &subset : subsets) {
            for (int num : subset) {
                cout << num << " ";
            }
            cout << nl;
        }
    } else {
        cout << "No" << nl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
