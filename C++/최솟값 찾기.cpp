#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin >> n >> m;
	priority_queue<pair<int,int>> q;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		q.push({-x,i});
		while(!q.empty() && q.top().second <= i - m) q.pop();
		cout << -q.top().first << " ";
	}
}