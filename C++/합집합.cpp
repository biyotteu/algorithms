#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<int> s;
	int a,b,cnt = 0;
	cin >> a >> b;
	while(a--){
		cnt++;
		int x;
		cin >> x;
		s.insert(x);
	}
	while(b--){
		int x;
		cin >> x;
		if(s.find(x) == s.end()) cnt++;
		else cnt--;
	}
	cout << cnt;
}