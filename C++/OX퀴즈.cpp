#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string a;
		cin >> a;
		int cnt = 0,sum = 0;
		for(auto i:a){
			if(i == 'O')
				sum += ++cnt;
			else cnt = 0;
		}
		cout << sum << "\n";
	}
}