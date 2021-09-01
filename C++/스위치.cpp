//백준 1395
//lazy propagation 응용 문제
//i~j구간에 스위치를 반전시키면 켜진 수위치는 꺼지고 꺼진 스위치는 켜짐으로
//꺼진 스위치와 켜진 스위치의 수가 서로 바뀐다
//tree = 켜진 스위치의 개수 총합, lazy 나중에 업데이트할 스위치 상태 

#include <bits/stdc++.h>

using namespace std;

vector<int> tree,lazy;
void unlazy(int node,int x,int y){
	if(!lazy[node]) return;
	tree[node] = (y-x+1) - tree[node];
	if(x!=y){
		lazy[node*2] = !lazy[node*2];
		lazy[node*2+1] = !lazy[node*2+1];
	}
	lazy[node] = 0;
}
void uprange(int node,int start,int end,int left,int right){
	unlazy(node,start,end);
	if(start > right || end < left) return;
	if(left <= start && end <= right){
		lazy[node] = !lazy[node];
		unlazy(node,start,end);
		return;
	}
	uprange(node*2,start,(start+end)/2,left,right);
	uprange(node*2+1,(start+end)/2+1,end,left,right);
	tree[node] = tree[node*2] + tree[node*2+1];
}
int sum(int node,int start,int end,int left,int right){
	unlazy(node,start,end);
	if(start > right || end < left) return 0;
	if(left <= start && end <= right) return tree[node];
	return sum(node*2,start,(start+end)/2,left,right) + sum(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	int n,m,size;
	scanf("%d %d",&n,&m);
	size = (int)ceil(log2(n));
	tree.resize(1<<(size+1));
	lazy.resize(1<<(size+1));
	for(int i=0;i<m;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		if(x) printf("%d\n",sum(1,0,n-1,y-1,z-1));
		else uprange(1,0,n-1,y-1,z-1);
	}
}