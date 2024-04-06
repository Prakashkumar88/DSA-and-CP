//generating subset from 0 to n using recursion.

#include<bits/stdc++.h>
using namespace std;

vector<int> subset;
int n; 

void search(int k){
	if(k==n){
		for (int num : subset) {
			cout << num << " ";
		}
		cout << endl;
	}else{
		search(k+1);
		subset.push_back(k);
		search(k+1);
		subset.pop_back();
	}
}

int main(){
    n = 3; 
    search(0); 
    return 0;
}
