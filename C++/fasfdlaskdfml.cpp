#include <bits/stdc++.h>

using namespace std;

vector<string> aa;
bool cmp(string a,string b){
	if(a.size() == b.size()){
		int cura=0,curb=0;
		for(auto i:a) if('0'<=i && i<='9') cura += (i-'0');
		for(auto i:b) if('0'<=i && i<='9') curb += (i-'0');
		if(cura == curb) return a < b;
		else return cura < curb;
	}
	else return a.size()<b.size();
}
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		string x;
		cin >> x;
		aa.push_back(x);
	}
	sort(aa.begin(),aa.end(),cmp);
	for(auto i:aa) cout << i << '\n';
}