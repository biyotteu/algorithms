#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
	bool operator<(info A)const{
		return z > A.z;
	}
};
int n,gr[1005][1005],parent[1005];
priority_queue<info> pq;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
bool _union(int x,int y){
	int xx = _find(x);
	int yy = _find(y);
	if(xx == yy) return false;
	parent[xx] = yy;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cin >> gr[i][j];
		parent[i] = i;
	}


	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) if(gr[i][j]) pq.push({i,j,gr[i][j]});
	long long res = 0;
	while(!pq.empty()){
		info cur = pq.top();
		pq.pop();
		if(_union(cur.x,cur.y)) res += cur.z;
	}
	cout << res;
}