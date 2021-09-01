#include <bits/stdc++.h>
#define INF (1<<29);
using namespace std;

int n,size;
vector<int> tree;
vector<pair<int,int>> num;
int init(int node,int start,int end){
	if(start == end) return tree[node] = 1;
	else tree[node] = init(node*2,start,(start+end)/2) + init(node*2+1,(start+end)/2+1,end);
}
void update(int node,int start,int end,int index,int v){
	if(start > index || index > end) return;
	tree[node] += v;
	if(start != end){
		update(node*2,start,(start+end)/2,index,v);
		update(node*2+1,(start+end)/2+1,end,index,v);
	}a
}
int query(int node,int start,int end,int left,int right){
	if(start > right || end < left) return 0;
	if(start >= left && end <= right) return tree[node];
	return query(node*2,start,(start+end)/2,left,right) + query(node*2+1,(start+end)/2+1,end,left,right);
}
int main(){
	scanf("%d",&n);
	int h = (int)ceil(log2(n));
	int size = (1<<(h+1));
	tree.resize(n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		num.push_back({x,i});
		init(1,0,n-1);
	}
	sort(num.begin(),num.end());
	int x = 0,y = num.size()-1;
	while(x<=y){
		if(x==y){
			printf("%d\n",query(1,0,n-1,0,num[x].second-1));
			return 0;
		}
		printf("%d\n",query(1,0,n-1,0,num[x].second-1));
		update(1,0,n-1,num[x].second,-1);
		printf("%d\n",query(1,0,n-1,num[y].second+1,n-1));
		update(1,0,n-1,num[x].second,-1);
		x++,y--;
	}
}