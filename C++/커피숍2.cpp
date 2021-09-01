#include <bits/stdc++.h>

using namespace std;

vector<long long int> tree;
int n,size,q;
void update(int node,int start,int end,int idx,int v){
	if(start > idx || end < idx) return;
	if(start == end){
		tree[node] = v;
		return;
	}	
	update(node*2,start,(start+end)/2,idx,v);
	update(node*2+1,(start+end)/2+1,end,idx,v);
	tree[node] = tree[node*2] + tree[node*2+1];
}
long long int sum(int node,int start,int end,int l,int r){
	if(start > r || end < l) return 0;
	if(l <= start && end <= r) return tree[node];
	return sum(node*2,start,(start+end)/2,l,r) + sum(node*2+1,(start+end)/2+1,end,l,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	size = (int)ceil(log2(n));
	tree.resize((1<<(size+1)));
	for(int i=0;i<n;i++){
		long long int x;
		cin >> x;
		update(1,0,n-1,i,x);
	}
	while(q--){
		int x,y,a,b;
		cin >> x >> y >> a >> b;
		if(y < x) swap(x,y);
		cout << sum(1,0,n-1,x-1,y-1) << "\n";
		update(1,0,n-1,a-1,b);
	}
}