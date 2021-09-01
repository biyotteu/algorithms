#include <bits/stdc++.h>

using namespace std;

int main(){
	string n;
	cin >> n;
	int a = 0,b = 0;
	for(int i=0;i<n.size()/2;i++){
		a += (n[i]-'0');
		b += (n[n.size()-i-1]-'0');
	}
	if(a == b) cout << "LUCKY";
	else cout << "READY";
}