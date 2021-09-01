#include <bits/stdc++.h>
#define max_n 100005

using namespace std;
using ll = long long;

struct node{
	node *l,*r;
	ll v;
	node(){v=0,l=r=NULL;}
};

node *root[max_n];
ll arr[max_n];
int n,m;
void init(node *cur,int start,int end){
	if(start == end){
		cur->v = arr[start];
		return;
	}
	cur->l = new node();
	cur->r = new node();
	init(cur->l,start,(start+end)/2);
	init(cur->r,(start+end)/2+1,end);
	cur->v = cur->l->v + cur->r->v;
}

void add(node *pre, node *cur, int start,int end,int idx,int value){
	if(start == end){
		cur->v = value;
		return;
	}
	int mid = (start+end)/2;
	if(idx <= mid){
		cur->l = new node();
		cur->r = pre->r;
		add(pre->l,cur->l,start,mid,idx,value);
	}else{
		cur->r = new node();
		cur->l = pre->l;
		add(pre->r,cur->r,mid+1,end,idx,value);
	}
	cur->v = cur->l->v + cur->r->v;
}
ll sum(node *cur,int start,int end,int l,int r){
	if(r < start || end < l) return 0;
	if(l <= start && end <= r) return cur->v;
	return sum(cur->l,start,(start+end)/2,l,r) + sum(cur->r,(start+end)/2+1,end,l,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	root[0] = new node();
	init(root[0],1,n);
	cin >> m;
	int cnt = 1;
	while(m--){
		int q;
		cin >> q;
		if(q == 1){
			int idx,v;
			cin >> idx >> v;
			root[cnt] = new node();
			add(root[cnt-1],root[cnt],1,n,idx,v);
			cnt++;
		}else{
			int x,y,k;
			cin >> k >> x >> y;
			cout << sum(root[k],1,n,x,y) << "\n";
		}
	}
}	