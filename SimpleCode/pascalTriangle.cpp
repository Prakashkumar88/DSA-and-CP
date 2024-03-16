/*Pascal's Triangle Generation:
For each test case, a 2D array a of size n x n is created to store the values of Pascal's triangle.
The values at the edges of each row (first and last element) are set to 1 as they are always 1.
Then, it iterates over each row of the triangle (excluding the first row, as it's already initialized):
Sets the first element of each row to 1.
Sets the last element of each row to 1.
Calculates the values in between by adding the corresponding values from the previous row (diagonally left and diagonally right).*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n][n];
        a[0][0] = 1;
        for (int i = 1; i < n; i++) {
            a[i][0] = 1;
            a[i][i] = 1;

            for (int j = 1; j < i; j++) {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
