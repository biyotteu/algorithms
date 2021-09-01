#include <bits/stdc++.h>

using namespace std;

int n,m,r[105],w[2005];
pair<int,int> cc[20005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> r[i];
	for(int i=1;i<=m;i++) cin >> w[i];
	int cnt = 1;
	long long res = 0;
	queue<int> car;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;
	for(int i=1;i<=n;i++) Q.push({i,r[i]});
	for(int i=1;i<=m*2;i++){
		int x;
		cin >> x;
		if(x>0){
			car.push(x);
			if(cnt <= n){
				int cur = car.front();
				car.pop();
				res += Q.top().second*w[cur];
				cc[cur] = Q.top();
				Q.pop();
				cnt++;
			}
		}
		if(x<0){
			x *= -1;
			Q.push(cc[x]);
			cnt--;
			if(!car.empty() && cnt <= n){
				int cur = car.front();
				car.pop();
				res += Q.top().second*w[cur];
				cc[cur] = Q.top();
				Q.pop();
				cnt++;
			}
		}
	}
	cout << res;
}