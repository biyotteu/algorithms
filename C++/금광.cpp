#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct info{
	ll x,y,z,r;
};
vector<info> gd;
vector<ll> xseg,yseg;
int n;
ll res;
bool cmpx(const info &A,const info &B){
	return A.x < B.x;
}
bool cmpy(const info &A,const info &B){
	return A.y < B.y;
}
void update(int node,int x,int y,int idx,ll v,vector<ll> &tree){
	if(x > idx || idx > y) return;
	if(x == y){
		tree[node] = v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v,tree);
	update(node*2+1,((x+y)>>1)+1,y,idx,v,tree);
	tree[node] = tree[node*2] + tree[node*2+1]; 
}
ll sum(int node,int x,int y,int start,int end,vector<ll> &tree){
	if(y < start || x > end) return 0;
	if(start <= x && y <= end) return tree[node];
	return	sum(node*2,x,((x+y)>>1),start,end,tree) + sum(node*2+1,((x+y)>>1)+1,y,start,end,tree); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	xseg.resize((1<<(size+1)));
	yseg.resize((1<<(size+1)));
	for(int i=0;i<n;i++){
		ll x,y,z;
		cin >> x >> y >> z;
		gd.push_back({x,y,z,0});
		res = max(res,z);
	}
	sort(gd.begin(),gd.end(),cmpy);
	for(int i=0;i<n;i++){
		update(1,0,n,i,gd[i].z,yseg);
		gd[i].r = i;
	}
	sort(gd.begin(),gd.end(),cmpx);
	for(int i=0;i<n;i++) update(1,0,n,i,gd[i].z,xseg);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++){
			int a = gd[i].r, b = gd[j].r;
			if(a > b) swap(a,b);
			long long k = sum(1,0,n,i,j,xseg);
			if(a > 0) k -= sum(1,0,n,0,a-1,yseg);
			if(b < n-1) k -= sum(1,0,n,b+1,n-1,yseg);
			res = max(res,k);
			cout << k << "####\n";
		}
	cout << res;
}