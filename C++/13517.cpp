#include <bits/stdc++.h>
#define max_n 100005

using namespace std;

struct Node{
	Node *l,*r;
	int v;
	Node(){v=0,l=r=NULL;}
};

Node *root[max_n];
int n,m,st[max_n][20],lvl[max_n];
vector<int> dt,cp,edg[max_n];

void init(Node *node,int s,int e){
	if(s == e) return;
	node->l = new Node();
	node->r = new Node();
	init(node->l,s,(s+e)/2);
	init(node->r,(s+e)/2+1,e);
}
void add(Node *prv,Node *now,int s,int e,int idx){
	if(s == e){
		now->v = 1;
		return;
	}
	int mid = (s+e)>>1;
	if(idx <= mid){
		now->l = new Node();
		now->r = prv->r;
		add(prv->l,now->l,s,mid,idx);
	}else{
		now->r = new Node();
		now->l = prv->l;
		add(prv->r,now->r,mid+1,e,idx);
	}
	now->v = now->l->v + now->r->v;
}
int query(Node *x,Node *y,Node *par,Node *gpar,int s,int e,int k){
	if(s==e) return s;
	int sum = x->l->v + y->l->v - par->l->v - gpar->l->v;
	if(sum >= k) return query(x->l,y->l,par->l,gpar->l,s,(s+e)/2,k);
	else return query(x->r,y->r,par->r,gpar->r,(s+e)/2+1,e,k-sum);
}
void dfs(int v,int par){
	root[v] = new Node();
	add(root[par],root[v],1,n,dt[v-1]);
	for(int next:edg[v]){
		if(next == par) continue;
		lvl[next] = lvl[v] + 1;
		st[next][0] = v;
		dfs(next,v);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		dt.push_back(x);
		cp.push_back(x);
	}
	sort(cp.begin(),cp.end());
	for(int &i:dt) i = lower_bound(cp.begin(),cp.end(),i)-cp.begin() + 1; 
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	root[0] = new Node();
	init(root[0],1,n);
	dfs(1,0);	
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++){
			st[i][j] = st[st[i][j-1]][j-1];
		}
	}
	cin >> m;
	while(m--){
		int a,b;
		int x,y,k;
		cin >> x >> y >> k;
		a = x, b = y;
		if(lvl[x] > lvl[y]) swap(x,y);
		for(int j=19;j>=0;j--){
			if(lvl[y] - lvl[x] >= (1<<j)){
				y = st[y][j];
			}
		}
		if(x!=y){
			for(int j=19;j>=0;j--){
				if(st[x][j] != st[y][j]){
					x = st[x][j];
					y = st[y][j];
				}
			}
			x = st[x][0];
		}
		int res = query(root[a],root[b],root[x],root[st[x][0]],1,n,k);
		cout << cp[res-1] << "\n";
	}
}
