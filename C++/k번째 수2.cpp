#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<vector<int>> seg;
void update(int node,int start,int end,int idx,int v){
	if(start > idx || end < idx) return;
	seg[node].push_back(v);
	if(start == end) return;
	update(node*2,start,(start+end)/2,idx,v);
	update(node*2+1,(start+end)/2+1,end,idx,v);
}
int query(int node,int start,int end,int l,int r,int x){
	if(start > r || end < l) return 0;
	if(l<=start && end <= r) return upper_bound(seg[node].begin(),seg[node].end(),x) - seg[node].begin();
	return query(node*2,start,(start+end)/2,l,r,x) + query(node*2+1,(start+end)/2+1,end,l,r,x);
}
int main(){
	scanf("%d %d",&n,&m);
	int size = (int)ceil(log2(n));
	seg.resize((1<<(size+1)));
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		update(1,0,n-1,i,x);
	}
	for(auto &i:seg) sort(i.begin(),i.end());
	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int l = -1e9, r = 1e9;
		while(l<=r){
			int mid = (l+r)/2;
			if(query(1,0,n-1,a-1,b-1,mid) < c) l = mid + 1;
			else r = mid - 1;
		}
		printf("%d\n",l);
	}
}