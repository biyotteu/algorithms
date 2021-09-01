#include <bits/stdc++.h>
#define MX 500005

using namespace std;

int n,t,idx;
long long res;
vector<int> a,seg;
void update(int node,int x,int y,int idx,int v){
	if(y < idx || x > idx) return;
	if(x == y){
		seg[node] += v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v);
	update(node*2+1,((x+y)>>1)+1,y,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
long long sum(int node,int x,int y,int v){
	if(!seg[node]) return 0;
	if(y <= v) return seg[node];
	int p = x/v+(x%v ? 1:0);
	int q = y/v+(y%v ? 1:0);
	if(x==y) return p*seg[node];
	if(p == q){
	 return seg[node]*p;
	}
	return sum(node*2,x,(x+y)>>1,v) + sum(node*2+1,((x+y)>>1)+1,y,v); 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	int size = (int)ceil(log2(MX));
	seg.resize((1<<(size+1)),0);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) {
		res += a[i];
		update(1,1,MX,a[i],1);
	}
	cin >> t;
	res = (t+1)*res;
	idx = 1;
	int mm = *max_element(a.begin(),a.end());
	for(int i=2;i<=mm;i++){
		long long ret = sum(1,1,MX,i);
		if(ret*(t+i) < res){
			res = ret*(t+i);
			idx = i;
		}
	}
	cout << res << ' ' << idx;
}