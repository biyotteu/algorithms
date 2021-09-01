#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i=1;;i++){
		int n;
		cin >> n;
		if(!n) return 0;
		cout << i << "\n";
		vector<string> str(n);
		getline(cin.ignore(),str[0]);
		for(int j=1;j<n;j++) getline(cin,str[j]);
		sort(str.begin(),str.end());
		for(auto j:str) cout << j << "\n";
	}
}