#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.length(); i++){
        if(s[i] != s[s.length() -1 -i]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout << "Palindrom\n";
    }else{
        cout << "Not Palindrom\n";;
    }
    return 0;
}

// if(s[i] != s[s.length() -1 -i]) {...}: Inside the loop, this condition checks whether the character at position i from the start of the string (s[i]) is not 
// equal to the character at position i from the end of the string (s[s.length() - 1 - i]).
// If this condition is true, it means the string is not a palindrome, and the flag is set to false.

// if(flag) {...} else {...}: After the loop, this if statement checks the value of the flag variable. If flag is true, it means the string is a palindrome,
// so it prints "Palindrom\n". Otherwise, it prints "Not Palindrom\n".


