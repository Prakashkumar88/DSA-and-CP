//Task is to find the number of element common in both the arrays.

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[5] = {1, 5, 8, 2, 6};
    int b[5] = {4, 5, 7, 2, 1};
    int n = 5; 

    sort(a, a + n); 
    sort(b, b + n); 

    int ptr1 = 0, ptr2 = 0, count = 0;
    while (ptr1 < n && ptr2 < n) {
        if (a[ptr1] == b[ptr2]) {
            count++;
            ptr1++;
            ptr2++;                                      //Time Complexity - n*log(n) fastest
        } else if (a[ptr1] < b[ptr2]) {
            ptr1++;
        } else {
            ptr2++;
        }
    }
    cout << count << endl;

    // unordered_set<int> s;
    // for (int i = 0; i < n; ++i) {
    //     s.insert(a[i]);
    // }
    // for (int i = 0; i < n; ++i) {
    //     if (s.find(b[i]) != s.end()) {                 //Time Complexity - n fast
    //         count++;
    //     }
    // }
    // cout << count << endl; 


    // set<int > s;
    // for(int i = 0; i < n; i++){
    // 	s.insert(a[i]);
    // }
    // for(int i = 0; i < n; i++){
    // 	if(s.find(b[i]) != s.end()){                      //Time Complexity - n*log(n) slowest
    // 		count++;
    // 	}
    // }
    // cout << count <<endl;


    return 0;
}
