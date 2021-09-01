#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> a;
	while(n--){
		int x,y;
		cin >> x >> y;
		a.push_back({y,x});
	}
	sort(a.begin(),a.end());
	for(auto i:a) cout << i.second << ' ' << i.first << "\n";
}