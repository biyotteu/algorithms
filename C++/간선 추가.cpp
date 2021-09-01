#include <bits/stdc++.h>

using namespace std;

int edg[1005],parent[1005],odd[1005],cnt,res,visit[1005];
int n,m; 
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) parent[i] = i;
	while(m--){
		int x,y;
		cin >> x >> y;
		edg[x]++;edg[y]++;
		parent[_find(x)] = _find(y);
	}
	for(int i=1;i<=n;i++) odd[_find(i)] += (edg[i])%2;
	int a = 0,b = 0;
	for(int i=1;i<=n;i++){
		int nx = _find(i);
		if(visit[nx]) continue;
		visit[nx] = 1;
		if(odd[nx]){
			res += odd[nx];
			a++;
		} 
		else{
			b++;
		} 
			cnt++;
	}
	if(cmp) cnt--;
	cout << max(0,(res/2-1)) + cnt;
}