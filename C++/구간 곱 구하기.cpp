#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n,m,k,size;
vector<long long int> seg;
void update(int node,int st,int en,int idx,int v){
	if(st > idx || en < idx) return;
	if(st == en){
		seg[node] = v;
		return;
	}
	update(node*2,st,(st+en)/2,idx,v);
	update(node*2+1,(st+en)/2+1,en,idx,v);
	seg[node] = (seg[node*2] * seg[node*2+1])%MOD;
}
long long multi(int node,int st,int en,int l,int r){
	if(st > r || en < l) return 1;
	if(l <= st && en <= r) return seg[node];
	return (multi(node*2,st,(st+en)/2,l,r)*multi(node*2+1,(st+en)/2+1,en,l,r))%MOD;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	size = (int)ceil(log2(n));
	seg.resize((1<<(size+1)),1);
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		update(1,0,n-1,i,x);
	}
	for(int i=0;i<m+k;i++){
		int a,b,c;
		cin >> a >> b >> c;
		if(a == 1) update(1,0,n-1,b-1,c);
		else cout << multi(1,0,n-1,b-1,c-1) << "\n";
	}
}