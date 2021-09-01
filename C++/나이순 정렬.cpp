#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,pair<int,string>>> a;
	for(int i=0;i<n;i++){
		int x;
		string y;
		cin >> x >> y;
		a.push_back({x,{i,y}});
	}
	sort(a.begin(),a.end());
	for(auto i:a) cout << i.first << ' ' << i.second.second << "\n";
}