#include <bits/stdc++.h>

using namespace std;

bool compare(const string &a,const string &b){
	if(a.size() == b.size()) return a.compare(b) < 0;
	else return a.size() < b.size();
}

int main(){
	int t;
	cin >> t;
	vector<string> str(t);
	for(auto &i:str) cin >> i;
	sort(str.begin(),str.end(),compare);
	auto k = unique(str.begin(),str.end());
	for(auto i = str.begin(); i < k; i++) cout << *i << "\n";
}