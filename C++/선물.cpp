#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
	return (a.first+a.second) < (b.first+b.second);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,d;
	cin >> n >> d;
	vector<pair<int,int>> arr;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		arr.push_back({x,y});
	}
	sort(arr.begin(),arr.end(),cmp);
	int res = 0;
	for(int i=0;i<n;i++){
		vector<int> cur;
		for(int j=0;j<n;j++){
			if(i == j) cur.push_back(arr[j].first/2 + arr[j].second);
			else cur.push_back(arr[j].first + arr[j].second);
		}
		sort(cur.begin(),cur.end());
		int cnt = 0;
		int total = d;
		for(auto j:cur){
			if(j > total) break;
			cnt++;
			total -= j;
		}
		res = max(res,cnt);
	}
	cout << res;
}

