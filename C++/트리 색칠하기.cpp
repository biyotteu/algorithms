#include <bits/stdc++.h>

using namespace std;

vector<int> tree[100005];
int n,res=987654321,visit[100005],dp[100005][21];
int f(int v,int cc){
	int &ret = dp[v][cc];
	if(ret) return ret;
	visit[v] = 1;
	ret += cc;
	for(auto next:tree[v]){
		if(visit[next]) continue;
		int k = 987654321;
		for(int i=1;i<=20;i++){
			if(cc == i) continue;
			k = min(k,f(next,i));
		}
		ret += k;
	}
	visit[v] = 0;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	for(int i=1;i<=20;i++)
		res = min(res,f(1,i));
	cout << res;
}