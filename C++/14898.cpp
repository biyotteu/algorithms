#include <bits/stdc++.h>
#define max_n 1000005

using namespace std;

struct Node{
	Node *l,*r;
	int v;
	Node(){l=r=NULL,v=0;}
};

Node *root[max_n*2];
int n,q,par[max_n],rt[max_n];

void init(Node *node,int s,int e){
	if(s == e) return;
	node->l = new Node();
	node->r = new Node();
	init(node->l,s,(s+e)/2);
	init(node->r,(s+e)/2+1,e);
	node->v = node->l->v + node->r->v;
}

void add(Node *pre,Node *now,int s,int e,int idx,int v){
	if(idx < s || idx > e){
		now = pre;
		return;
	}
	now->v = pre->v + v;
	if(s == e) return;
	int mid = (s+e)/2;
	if(idx <= mid){
		now->l = new Node();
		now->r = pre->r;
		add(pre->l,now->l,s,mid,idx,v);
	}else{
		now->r = new Node();
		now->l = pre->l;
		add(pre->r,now->r,mid+1,e,idx,v);
	}
	// cout << s << ' ' << e <<  ' ' << idx << ' ' << v << ' ' << now->v<< "@@@\n";
}

int sum(Node *node,int s,int e,int l,int r){
	if(s > r || e < l) return 0;
	if(s == e) return node->v;
	return sum(node->l,s,(s+e)/2,l,r) + sum(node->r,(s+e)/2+1,e,l,r);
}
bool cmp(pair<int,int> A,pair<int,int> B){
	return A.second < B.second;
}
vector<int> a,b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	a.resize(n);
	b.resize(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=0;i<=n;i++) a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin() + 1;
	root[0] = new Node();
	init(root[0],1,n);
	int last = 0;
	for(int i=1;i<=n;i++){
		int now = a[i-1];
		root[++last] = new Node();
		add(root[last-1],root[last],1,n,i,1);
		if(par[now]){
			root[++last] = new Node();
			add(root[last-1],root[last],1,n,par[now],-1);
		}
		par[now] = i;
		rt[i] = last;
	}
	cin >> q;
	last = 0;
	while(q--){
		int x,r,l;
		cin >> x >> r;
		l = x + last;
		// cout << l << ' ' << r << ' ' << rt[r] << "###\n";
		last = sum(root[rt[r]],1,n,l,r);
		cout << last<<"\n";
	}
}