#include <bits/stdc++.h>

using namespace std;

vector<long long> seg; 
int n,m,size;
void update(int node,int start,int end,int idx,int v){
	if(start > idx || end < idx) return;
	if(start == end){
		seg[node] = v;
		return;
	}
	update(node*2,start,(start+end)/2,idx,v);
	update(node*2+1,(start+end)/2+1,end,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
long long sum(int node,int start,int end,int left,int right){
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return seg[node];
	return sum(node*2,start,(start+end)/2,left,right) + sum(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	scanf("%d %d",&n,&m);
	size = (int)ceil(log2(n));
	seg.resize((1<<(1+size)),0);
	while(m--){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x) update(1,0,n-1,y-1,z);
		else{ 
			if(y > z) swap(y,z);
			printf("%lld\n",sum(1,0,n-1,y-1,z-1));
		}
	}
}