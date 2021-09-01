#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	vector<string> res;
	cin >> str;
	for(int i=0;i<str.size();i++) res.push_back(str.substr(i));
	sort(res.begin(),res.end());
	for(auto i:res) cout << i <<"\n";
}