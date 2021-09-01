#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<pair<int,int>> num;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		num.push_back({x,y});
	}
	sort(num.begin(),num.end());
	if(n == 1){
		cout << num[0].second - num[0].first;
		return 0;
	}
	int res = 0;
	pair<int,int> be = num[0];
	for(int i=1;i<n;i++){
		if(be.second >= num[i].first){
			be.second = max(num[i].second,be.second);
			continue;
		}
		res += (be.second - be.first);
		be = num[i];
	}
	res += (be.second - be.first);
	cout << res;
}