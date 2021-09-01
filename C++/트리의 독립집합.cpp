#include <bits/stdc++.h>

using namespace std;
using pp = pair<vector<int>,int>;

int n,w[10005],visit[10005];
pp dp[10005][2];
vector<int> graph[10005];
pp f(int v,int cc){
	visit[v] = 1;
	pp &ret = dp[v][cc];
	if(ret.second) return ret;
	if(cc){
		ret.second += w[v];
		ret.first.push_back(v);
		for(auto i:graph[v]){
			if(visit[i]) continue;
			pp k = f(i,0);
			ret.second += k.second;
			for(auto j:k.first) ret.first.push_back(j);
		}
	}else{
		for(auto i:graph[v]){
			if(visit[i]) continue;
			pp a = f(i,0), b = f(i,1),k;
			if(a.second > b.second) k = a;
			else k = b;
			ret.second += k.second;
			for(auto j:k.first) ret.first.push_back(j);
		}
	}
	visit[v] = 0;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> w[i];
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	pp x = f(1,0), y = f(1,1),res;
	if(x.second > y.second) res = x;
	else res = y;
	cout << res.second << '\n';
	sort(res.first.begin(),res.first.end());
	for(auto i:res.first)
		cout << i << ' ';
}