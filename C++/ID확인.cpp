#include <bits/stdc++.h>

using namespace std;

map<char,int> mp;
int main(){
	for(char i='A';i<='Z';i++) mp[i] = 1;
	for(char i='a';i<='z';i++) mp[i] = 1;
	for(char i='0';i<='9';i++) mp[i] = 1;
	mp['-'] = 1;
	mp['.'] = 1;
	int n;
	cin >> n;
	while(n--){
		string a;
		int cmp = 0,go = 0;
		cin >> a;
		if(a[0] == '@' || a.back() == '@'){
			cout << "No\n";
			continue;
		}
		for(auto i:a){
			if(i == '@'){
				go++;
				continue;
			}
			if(!mp[i]){
				cmp = 1;
				break;
			}
		}
		if(cmp == 0 && go == 1) cout << "Yes\n";
		else cout << "No\n";
	}
}