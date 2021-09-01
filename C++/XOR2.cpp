//백준 12844
//lazy propagation문제
//기본적인 lazy propagation문제로 top down segment tree를 구현하여 풀면된다.
//tree = segment tree 배열, lazy = 나중에 업데이트할 lazy 배열

#include <bits/stdc++.h>

using namespace std;

vector<long long int> lazy,tree;
void unlazy(int node,int start,int end){
	if(!lazy[node]) return;
	if((end-start+1)%2) tree[node] ^= lazy[node];
	if(start!=end){
		lazy[node*2] ^= lazy[node];
		lazy[node*2+1] ^= lazy[node];
	}
	lazy[node] = 0;
}
void update(int node,int start,int end,int idx,int v){
	if(start > idx || end < idx) return;
	if(start == end) {
		tree[node] = v;
		return;
	}
	update(node*2,start,(start+end)/2,idx,v);
	update(node*2+1,(start+end)/2+1,end,idx,v);
	tree[node] = tree[node*2+1] ^ tree[node*2];
}
void uprange(int node,int start,int end,int left,int right,int v){
	unlazy(node,start,end);
	if(start > right || end < left) return;
	if(left <= start && end <= right){
		lazy[node] ^= v;
		unlazy(node,start,end);
		return;
	}
	uprange(node*2,start,(start+end)/2,left,right,v);
	uprange(node*2+1,(start+end)/2+1,end,left,right,v);
	tree[node] = tree[node*2] ^ tree[node*2+1];
}
long long int sum(int node,int start,int end,int left,int right){
	unlazy(node,start,end);
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(node*2,start,(start+end)/2,left,right) ^ sum(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	int n,size,m;
	scanf("%d",&n);
	size = (int)ceil(log2(n));
	tree.resize(1<<(size+1));
	lazy.resize(1<<(size+1));
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		update(1,0,n-1,i,x);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		if(x == 2){
			int a,b;
			scanf("%d %d",&a,&b);
			if(a>b) swap(a,b);
			printf("%lld\n",sum(1,0,n-1,a,b));
			
		}else{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
			if(a>b) swap(a,b);
			uprange(1,0,n-1,a,b,c);
		}
	}
}