#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(1){
		string str;
		cin >> str;
		if(str.size() == 1 && str[0] == '0') return 0;
		int l = 0,r = str.size()-1,cmp=1;
		while(l<r){
			if(str[l] == str[r]) l++,r--;
			else{
				cmp = 0;
				break;
			}
		}
		if(cmp) cout << "yes\n";
		else cout << "no\n";
	}
}