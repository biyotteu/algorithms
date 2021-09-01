#include <bits/stdc++.h>

using namespace std;

int n,res[100005];
vector<int> seg;
int find_idx(int node,int v,int x,int y){
	if(x == y) return x;
	if(v < seg[node*2]) return find_idx(node*2,v,x,((x+y)>>1));
	else return find_idx(node*2+1,v-seg[node*2],((x+y)>>1)+1,y);
}
void update(int node,int x,int y,int idx,int v){
	if(idx<x || y<idx) return;
	if(x == y){
		seg[node] = v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v);
	update(node*2+1,((x+y)>>1)+1,y,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(size+1));
	for(int i=1;i<=n;i++) update(1,1,n,i,1);
	for(int i=1;i<=n;i++){
		int k,x;
		cin >> x;
		k = find_idx(1,x,1,n);
		res[k] = i;
		update(1,1,n,k,0);
	}
	for(int i=1;i<=n;i++)
		cout << res[i] << ' ';
}