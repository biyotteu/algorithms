#include <bits/stdc++.h>

using namespace std;

int c,n,o;
vector<int> seg,lazy;
void unlazy(int node,int x,int y){
	if(!lazy[node]) return;
	seg[node] += lazy[node];
	if(x!=y){ 
		lazy[node*2] += lazy[node];
		lazy[node*2+1] += lazy[node];
	}
	lazy[node] = 0;
}
void update(int node,int x,int y,int idx,int v){
	unlazy(node,x,y);
	if(y < idx || x > idx) return;
	if(x == y){
		unlazy(node,x,y);
		seg[node] += v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v);
	update(node*2+1,((x+y)>>1)+1,y,idx,v);
}
void uprange(int node,int x,int y,int start,int end,int v){
	unlazy(node,x,y);
	if(end < x || y < start) return;
	if(start <= x && y <= end){
		lazy[node] += v;
		unlazy(node,x,y);
		return;
	}
	uprange(node,x,((x+y)>>1),start,end,v);
	uprange(node+1,((x+y)>>1)+1,y,start,end,v);
}
int vl(int node,int x,int y,int idx){
	unlazy(node,x,y);
	if(y < idx || x > idx) return 0;
	if(x == y) return seg[node];
	return vl(node*2,x,((x+y)>>1),idx) + vl(node*2+1,((x+y)>>1)+1,y,idx);
}
int main(){
	scanf("%d %d %d",&c,&n,&o);
	int size = (int)ceil(log2(c));
	seg.resize(1<<(size+1));
	lazy.resize(1<<(size+1));
	for(int i=0;i<o;i++){
		char X[15];
		scanf(" %s",X);
		if(X[0] == 's'){
			int x;
			scanf("%d",&x);
			printf("%d\n",vl(1,0,c,x));
		}
		if(X[0] == 'g'){
			int x,y,z;
			scanf("%d %d %d",&x,&y,&z);
			uprange(1,0,c,x,y,z);
			printf("%d\n",z);
		}
		if(X[0] == 'c'){
			int x,y;
			scanf("%d %d",&x,&y);
			update(1,0,c,x,y);
			printf("%d\n",y);
		}
	}
}