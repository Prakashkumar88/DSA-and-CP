//To Find the Maximum Sum of a sub array : The largest possible sum of a sequence of consicutive values in the array.
// in Three Different Time Complexity.

#include <iostream>
using namespace std;

int main() {
    int arr[8] = {-1, 2, 4, -3, 5, 2, -5, 2};
    int best = 0, sum = 0;
    for(int i = 0; i < 8; i++){
        sum = max(arr[i], sum+arr[i]);
        best = max(sum, best);                                     //Time Complexity - O(n)
    }
    
    cout << best <<"\n";
    return 0;
}



// int main() {
//     int arr[8] = {-1, 2, 4, -3, 5, 2, -5, 2};

//     int best = 0;
//     for(int i = 0; i < 8; i++){
//       int sum = 0;
//       for(int j = i; j < 8; j++){
//         sum += arr[i];                                             //Time Complexity - O(n*n)
//         best = max(best, sum);
//       }                                    
    
//       cout << best <<"\n";
//     return 0;
// }



// int main() {
//     int arr[8] = {-1, 2, 4, -3, 5, 2, -5, 2};

//     int best = 0;
//     for(int i = 0; i < 8; i++){
//       int sum = 0;
//       for(int j = i; j < 8; j++){
//         for(int k = i; k <= j; k++){                                 //Time Complexity - O(n*n*n)
//           sum += arr[k];
//         } 
//         best = max(best, sum);
//       } 
//     }  
//     cout << best <<"\n";
//     return 0;
// }
