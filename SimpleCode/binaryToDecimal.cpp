#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		long long result = 0, power_2 = 1;
		for(int i = s.size()-1; i >= 0; i--){
			int binary = s[i] - '0';
			result += (binary*power_2);
			power_2 *= 2;
		}

		cout << result <<endl;
	}
}