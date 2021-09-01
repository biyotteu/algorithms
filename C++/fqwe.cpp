#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,res = 0;
	vector<int> a(n+1);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=3;i++){
		queue<int> q;
		vector<int> visit(n+1,0);
		visit[i] = 1;
		q.push(i);
		int cnt = 1;
		while(!q.empty()){
			int cur = q.front();q.pop();
			cnt++;
			if(cur+a[cur] < 0 || cur + a[cur] > n|| visit[cur+a[cur]]) continue;
			visit[cur+a[cur]] = 1;
			q.push(cur+a[cur]);
		}
		res = max(res,cnt);
	}
	cout << res;
}