//generating subsets using bit manipulation 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 3; 
    vector<int> set = {1, 2, 3}; 

    for (int i = 0; i < (1 << n); ++i) {
        vector<int> subset;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subset.push_back(set[j]);
            }
        }
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
