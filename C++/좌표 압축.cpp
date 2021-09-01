#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n;
	cin >> n;
	vector<pair<long long,int>> a(n);
	vector<int> b(n);
	for(int i=0;i<n;i++){
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(),a.end());
	long long cur=a[0].first, cnt = 0;
	b[a[0].second] = 0;
	for(int i=1;i<n;i++){
		if(cur != a[i].first){
			cnt++;
			cur = a[i].first;
		}
		b[a[i].second] = cnt;
	}
	for(auto i:b) cout << i << ' ';
}