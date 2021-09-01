#include <bits/stdc++.h>
#define max_n 1001005

using namespace std;

struct Node{
	int l,r,v;
};

vector<Node> seg;
int n,q;

void makeNode(){
	seg.push_back({-1,-1,0});
}

void init(int node,int s,int e){
	if(s == e) return;
	makeNode();
	seg[node].l = seg.size()-1;
	makeNode();
	seg[node].r = seg.size()-1;
	init(seg[node].l,s,(s+e)/2);
	init(seg[node].r,(s+e)/2+1,e);
}

void add(int pre,int now,int s,int e,int idx,int v){
	if(idx<s || idx>e){
		seg[now] =seg[pre];
		return; 
	}
	seg[now].v = seg[pre].v + v; 
	if(s == e) return;
	int mid = (s+e)/2;
	if(idx <= mid){
		seg[now].r = seg[pre].r;
		makeNode();
		seg[now].l = seg.size()-1;
		add(seg[pre].l,seg[now].l,s,mid,idx,v); 
	}else{
		seg[now].l = seg[pre].l;
		makeNode();
		seg[now].r = seg.size()-1;;
		add(seg[pre].r,seg[now].r,mid+1,e,idx,v);
	}
}

int sum(int node,int s,int e,int l,int r){
	if(e < l || r < s) return 0;
	if(l<=s&&e<=r) return seg[node].v;
	return sum(seg[node].l,s,(s+e)/2,l,r) + sum(seg[node].r,(s+e)/2+1,e,l,r);
}
bool cmp(pair<int,int> A,pair<int,int> B){
	return A.second < B.second;
}

int a[max_n];
vector<int> b,pi[max_n];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	seg.reserve(12500000);
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b.push_back(a[i]);
	}
	sort(b.begin(),b.end());
	b.erase(unique(b.begin(),b.end()),b.end());
	for(int i=1;i<=n;i++) a[i] = lower_bound(b.begin(),b.end(),a[i]) - b.begin();
	for(int i=0;i<=n;i++) pi[i].push_back(0);
	for(int i=1;i<=n;i++) pi[a[i]].push_back(i);
	for(int i=0;i<=n;i++){
		for(int j=1;j<pi[i].size();j++) a[pi[i][j]] = pi[i][j-1];
	}	
	int last = 0;
	for(int i=0;i<=2*n;i++) makeNode();
	init(0,1,n);
	
	for(int i=1;i<=n;i++){
		if(a[i]){
			last++;
			add(last-1,last,1,n,a[i],-1);
		}
		last++;
		add(last-1,last,1,n,i,1);
		b[i-1] = last;
	}
	cin >> q;
	last = 0;
	while(q--){
		int x,r;
		cin >> x >> r;
		last = sum(b[r-1],1,n,x+last,r);
		cout << last<<"\n";
	}
}