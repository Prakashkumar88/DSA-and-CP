#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++) {
        //left triagle
        for (int col = 1; col <= n - row + 1; col++){
            cout<<col;
        }

        //mid triangle
        for (int star = 1; star <= 2 * row - 2; star++) {
            cout << "*";
        }

        //right triangle
        for(int col =n - row + 1; col >= 1; col--){
            cout<<col;
        }
        cout<<endl;
    }
}