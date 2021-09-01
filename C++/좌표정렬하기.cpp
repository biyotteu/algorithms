#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a.begin(),a.end());
	for(auto i:a) cout << i.first << ' ' << i.second << "\n";
}