#include <bits/stdc++.h>

using namespace std;

int visit[100001],qt[100001],nx[100001],n,res;
bool dfs(int v){
	visit[v] = 1;
	if(!visit[nx[v]]) dfs(nx[v]);
	if(!qt[nx[v]]){
		for(int i=nx[v];i != v;i = nx[i]) res--;
		res--;
	}
	qt[v] = 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		res = n;
		for(int  i=1;i<=n;i++) visit[i] = qt[i] = 0;
		for(int i=1;i<=n;i++) cin >> nx[i];
		for(int i=1;i<=n;i++) if(!visit[i]) dfs(i);
		cout << res << "\n";
	}
}