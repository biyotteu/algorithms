//백준 10999번
//대표적인 lazy propagation문제
//tree = 구간합 segment tree, lazy 나중에 갱신할 업데이트 값
//쿼리 요청시 lazy값을 갱신해준다.

#include <bits/stdc++.h>

using namespace std;

vector<long long int> tree,lazy;
void unlazy(int node,int x,int y){
	if(!lazy[node]) return;
	tree[node] += lazy[node] * (y-x+1);
	if(x!=y){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}
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
void uprange(int node,int start,int end,int left,int right,int v){
	unlazy(node,start,end);
	if(start > right || end < left) return;
	if(left <= start && end <= right){
		lazy[node] += v;
		unlazy(node,start,end);
		return;
	}
	uprange(node*2,start,(start+end)/2,left,right,v);
	uprange(node*2+1,(start+end)/2+1,end,left,right,v);
	tree[node] = tree[node*2] + tree[node*2+1];
}
long long int sum(int node,int start,int end,int left,int right){
	unlazy(node,start,end);
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(node*2,start,(start+end)/2,left,right) + sum(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	ios::sync_with_stdio(false);
	int n,m,k,size;
	cin >> n >> m >> k;
	size = (int)ceil(log2(n));
	tree.resize(1<<(size+1));
	lazy.resize(1<<(size+1));
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		update(1,0,n-1,i,x);
	}
	for(int i=0;i<m+k;i++){
		int x;
		cin >> x;
		if(x == 1){
			int a,b,c;
			cin >> a >> b >> c;
			uprange(1,0,n-1,a-1,b-1,c);
		}else{
			int a,b;
			cin >> a >> b;
			cout << sum(1,0,n-1,a-1,b-1) << "\n";
		}
	}
}