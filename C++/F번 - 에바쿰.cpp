//백준 15967
//구간 합 구하기 2와 동일한 문제
//lazy propagation문제
//tree = 구간합 트리, lazy = 나중에 업데이트할 구간

#include <bits/stdc++.h>

using namespace std;

int n,q1,q2;
vector<long long int> lazy,tree;
void unlazy(int node,int x,int y){
	if(!lazy[node]) return;
	tree[node] += lazy[node] * (y-x+1);
	if(x!=y){
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}
int uplazy(int node,int start,int end,int left,int right,int v){
	unlazy(node,start,end);
	if(start > right || end < left) return 0;
	if(left <= start && end <= right){
		lazy[node] += v;
		unlazy(node,start,end);
		return tree[node];
	}
	uplazy(node*2,start,(start+end)/2,left,right,v);
	uplazy(node*2+1,(start+end)/2+1,end,left,right,v);
	tree[node] = tree[node*2+1] +tree[node*2];
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
long long int sum(int node,int start,int end,int left,int right){
	unlazy(node,start,end);
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(node*2,start,(start+end)/2,left,right) + sum(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q1 >> q2;
	int size = (int)ceil(log2(n));
	tree.resize(1<<(size+1));
	lazy.resize(1<<(size+1));
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		update(1,0,n-1,i,x);
	}
	for(int i=0;i<q1+q2;i++){
		int x;
		cin >> x;
		if(x == 2){
			int a,b,c;
			cin >> a >> b >> c;
			uplazy(1,0,n-1,a-1,b-1,c);
		}else{
			int a,b;
			cin >> a >> b;
			cout << sum(1,0,n-1,a-1,b-1) <<"\n";
		}
	}
}