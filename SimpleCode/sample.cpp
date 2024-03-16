/*Monk loves Primes, whether it is number or word

Rules to convert a string to a number:
1. Convert the UpperCase letters to LowerCase letters
2. Convert the LowerCase letters to UpperCase letters

Add the ASCII values of all the UpperCase letters and subract the ASCII values of all the LowerCase letters. The resultant number is X.
Note: If X is negative take absolute value of it
Print 1 if X is a prime number and 0 if not
(Prime Number: A number which is divisble by the number one and itself, i.e, it has 2 divisors)*/


#include<bits/stdc++.h>
using namespace std;

char upper(char c){
	return 'A' + (c - 'a');
}

char lower(char c){
	return 'a' + (c - 'A');
}

int main(){
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			s[i] = upper(s[i]);
		}else if(s[i] >= 'A' && s[i] <= 'Z'){
			s[i] = lower(s[i]);
		}
	}
	int result = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z'){
			result -= s[i];
		}else if(s[i] >= 'A' && s[i] <= 'Z'){
			result += s[i];
		}
	}

	if(result < 0){
		result = result*(-1);
	}

	int flag = 0;
	for(int i = 2; i < result; i++){
		if(result%i == 0){
			flag = 1;
			break;
		}
	}
	if(flag == 0){
		cout << 1 <<endl;
	}else{
		cout << 0 <<endl;
	}
}