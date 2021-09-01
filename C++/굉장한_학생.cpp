#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

struct info{
	int x,y,z;
	info(){}
	info(int a,int b,int c){
		x = a, y = b, z = c;
	}
	bool operator<(info A) const{
		return A.x > x;
	}
};
int n,h,size;
vector<info> st;
vector<int> tree;
int min_find(int node,int start,int end,int left,int right){
	if(start > right || end < left) return INF;
	if(left <= start && end <= right) return tree[node];
	return min(min_find(node*2,start,(start+end)/2,left,right),min_find(node*2+1,(start+end)/2+1,end,left,right));
}
void update(int node,int start,int end,int index,int v){
	if(index < start || index > end) return;
	if(start == end){
	 	tree[node] = v;
	 	return;
	 }
	update(node*2,start,(start+end)/2,index,v);
	update(node*2+1,(start+end)/2+1,end,index,v);
	tree[node] = min(tree[node*2],tree[node*2+1]);
}
int main(){
	scanf("%d",&n);
	st.resize(n);
	int h = (int)ceil(log2(n));
	int size = (1<<(h+1));
	tree.resize(size,INF);
	//(i 등수 k 학생)
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		st[k-1].x = i;
	}
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		st[k-1].y = i;
	}
	for(int i=0;i<n;i++){
		int k;
		scanf("%d",&k);
		st[k-1].z = i;
	}
	sort(st.begin(),st.end());
	int res = 0 ;
	for(int i=0; i<n; i++){
		if(min_find(1,0,n-1,0,st[i].y) > st[i].z) res++;
		update(1,0,n-1,st[i].y,st[i].z);
	}
	printf("%d",res);
}