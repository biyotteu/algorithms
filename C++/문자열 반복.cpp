#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int a;
		string b;
		cin >> a >> b;
		for(auto i:b)
			for(int j=0;j<a;j++) cout << i;
		cout << "\n";
	}
}