#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int maxValue = n;
    int patternSize = 2 * n - 1;

    for (int i = 0; i < patternSize; ++i) {
        for (int j = 0; j < patternSize; ++j) {
            int minValue = min({i, j, patternSize - i - 1, patternSize - j - 1});
            cout << maxValue - minValue << " ";
        }
        cout << endl;
    }

    return 0;
}
