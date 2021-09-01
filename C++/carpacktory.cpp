#include <bits/stdc++.h>
#define xx first
#define yy second

using namespace std;

int n,m,seg[2<<20],lazy[2<<20],cnt;
vector<pair<int,int>> child;
vector<int> cost;
vector<vector<int>> R;
int dfs(int v){
	child[v].xx = ++cnt;
	for(auto i:R[v]) if(!child[i].xx) dfs(i);
	child[v].yy = cnt;
}
void unlazy(int v,int x,int y){
	if(!lazy[v]) return;
	seg[v] += lazy[v]*(y - x + 1);
	if(x!=y){
		lazy[v*2] += lazy[v];
		lazy[v*2+1] += lazy[v];
	}
	lazy[v] = 0;
}
int update(int cur,int value,int x,int y,int curx,int cury){
	unlazy(cur,x,y);
	if(y<curx || x>cury) return seg[cur];
	if(curx <= x && cury >= y){
		lazy[cur] += value;
		unlazy(cur,x,y);
		return seg[cur];
	}
	int mid = (x+y)>>1;
	return seg[cur] = update(cur*2,value,x,mid,curx,cury) + update(cur*2+1,value,mid+1,y,curx,cury);
}
int _find(int cur,int x,int y,int curx,int cury){
	unlazy(cur,x,y);
	if(curx > y || cury < x) return 0;
	if(curx<=x && y<=cury) return seg[cur];
	int mid = (x+y)>>1;
	return _find(cur*2,x,mid,curx,cury) + _find(cur*2+1,mid+1,y,curx,cury);
}
int main()
{
	scanf("%d %d",&n,&m);
	cost.resize(n+1);
	child.resize(n+1);
	R.resize(n+1);
	scanf("%d",&cost[1]);
	for(int i=2;i<=n;i++){
		int x;
		scanf("%d %d",&cost[i],&x);
		R[x].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=n;i++) update(1,cost[i],1,n,child[i].xx,child[i].xx);
	while(m--){
		char c;
		scanf(" %c",&c);
		if(c=='p'){
			int a,x;
			scanf("%d %d",&a,&x);
			if(child[a].xx == child[a].yy) continue;
			update(1,x,1,n,child[a].xx+1,child[a].yy);
		}
		if(c=='u'){
			int a;
			scanf("%d",&a);
			printf("%d\n",_find(1,1,n,child[a].xx,child[a].xx));
		}
	}
}
