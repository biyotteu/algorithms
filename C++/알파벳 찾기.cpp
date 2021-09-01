#include <bits/stdc++.h>

using namespace std;

int main(){
	string a;
	cin >> a;
	vector<int> b(26,-1);
	for(int i=0;i<a.size();i++) if(b[a[i]-'a'] == -1) b[a[i]-'a'] = i;
	for(auto i:b) cout << i << ' ';
}