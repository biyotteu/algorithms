#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,dist;
	bool operator<(info A)const{
		return dist < A.dist;
	}
};
int n;
long long res;
vector<pair<int,int>> cook,ret;
priority_queue<info> Q;
vector<int> parent,tree[1005];
int f(pair<int,int> A,pair<int,int> B){
	return (A.second+B.second)/abs(A.first-B.first);
}
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
bool _union(int a,int b){
	int A = _find(a);
	int B = _find(b);
	if(A == B) return false;
	parent[B] = A;
	return true;
}
void dfs(int v,int pp){
	for(auto i:tree[v])
		if(i!= pp)	dfs(i,v);
	if(pp!=-1) cout << pp << ' ' << v << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	parent.resize(n+1);
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		cook.push_back({x,y});
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			Q.push({i+1,j+1,f(cook[i],cook[j])});
		}
	}
	for(int i=1;i<=n;i++) parent[i] = i;
	while(!Q.empty()){
		info cur = Q.top();
		Q.pop();
		if(_union(cur.x,cur.y)){
			ret.push_back({cur.x,cur.y});
			res += cur.dist;
			tree[cur.x].push_back(cur.y);
			tree[cur.y].push_back(cur.x);
		}
	}
	cout << res << '\n';
	dfs(1,-1);
}