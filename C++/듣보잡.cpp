#include <bits/stdc++.h>

using namespace std;

int n,m;
set<string> s;
vector<string> res;
int main(){
	cin >> n >> m;
	while(n--){
		string str;
		cin >> str;
		s.insert(str);
	}
	while(m--){
		string str;
		cin >> str;
		if(s.find(str) != s.end()) res.push_back(str);
	}
	sort(res.begin(),res.end());
	cout << res.size() << '\n';
	for(auto i:res) cout << i << '\n';
}