//The provided code snippet attempts to solve the N-Queens problem using backtracking
//Using backtracking algorithm.

#include<bits/stdc++.h>
using namespace std;

void search(int y, int n, int* col, int* diag1, int* diag2, int& solutionCount) {
    if (y == n) {
        solutionCount++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (col[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1, n, col, diag1, diag2, solutionCount);
        col[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main() {
    int n;
    cout << "Enter the size of the chessboard (n): ";
    cin >> n;

    int solutionCount = 0;
    int col[n] = {0};
    int diag1[2 * n - 1] = {0};
    int diag2[2 * n - 1] = {0};

    search(0, n, col, diag1, diag2, solutionCount);

    cout << "Number of solutions for N-Queens problem with n = " << n << ": " << solutionCount << endl;

    return 0;
}
