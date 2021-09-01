#include <bits/stdc++.h>

using namespace std;

int n,k,m;
vector<int> seg;
void update(int node,int x,int y,int idx,int v){
	if(x > idx || y < idx) return;
	if(x == y){
		seg[node] = v;
		return;
	}
	update(node*2,x,(x+y)/2,idx,v);
	update(node*2+1,(x+y)/2+1,y,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int sum(int node,int x,int y,int l,int r){
	if(x > r || y < l) return 0;
	if(l <= x && y <= r) return seg[node];
	return sum(node*2,x,(x+y)/2,l,r) + sum(node*2+1,(x+y)/2+1,y,l,r);
}
int sfind(int x,int y,int ss){
	if(x == y) return x;
	int o = sum(1,1,n,x,(x+y)/2);
	if(o < ss) return sfind((x+y)/2+1,y,ss - o);
	else return sfind(x,(x+y)/2,ss);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> m;
	seg.resize((1<<((int)ceil(n))));
	for(int i=1;i<=n;i++) update(1,1,n,i,1);
	int cur = 1,cnt = 0;
	while(1){
		int all = sum(1,1,n,1,n);
		if(all < k) k %= all;
		int p = sum(1,1,n,cur,n),idx;
		if(p >= k)	idx = sfind(cur,n,k);
		else idx = sfind(1,cur-1,k-p);
		cnt++;
		if(idx == m){
			cout << cnt;
			break;
		}
		cur = idx;
	 	update(1,1,n,idx,0);
		cout << cur <<"\n";
	}
}	