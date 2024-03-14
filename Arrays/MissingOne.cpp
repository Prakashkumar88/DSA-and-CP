// Below Code is given to find the number that is missing any element in one array after Comparing both the arrays.

#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arrn[n], arrm[m];
    for (int i = 0; i < n; i++) {
        cin >> arrn[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arrm[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arrn[i] == arrm[j]) {
                arrn[i] = 0;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if(arrn[i] != 0){
            cout<<arrn[i]<<" ";
        }
    }

    return 0;
}


// int arrn[n], arrm[m];: This declares two arrays arrn and arrm of sizes n and m respectively. Note that this is not standard C++,
// it's a C99 feature called Variable Length Arrays (VLA) which is supported by some compilers as an extension.

// The next two for loops read the elements of the two arrays arrn and arrm from the standard input.
// The nested for loop is used to iterate over each element of arrn and arrm and compare their elements.
// In the inner loop, if an element of arrn is found to be equal to an element of arrm, it sets the element of arrn to 0 and then breaks out of the loop.
// This effectively removes the element from arrn.
