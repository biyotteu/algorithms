#include <bits/stdc++.h>
#define MX 100005
using namespace std;

int n,a[MX],res[MX];
vector<int> seg;
void update(int node,int x,int y,int idx,int v){
	if(x > idx || y < idx) return;
	if(x == y){
		seg[node] = v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v);
	update(node*2+1,((x+y)>>1)+1,y,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int sum(int node,int x,int y,int v){
	if(x == y) return x;
	if(seg[node*2+1] > v) return sum(node*2+1,((x+y)>>1)+1,y,v);
	else return sum(node*2,x,((x+y)>>1),v-seg[node*2+1]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize((1<<(size+1)));
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++) update(1,1,n,i,1);
	for(int i=n;i>0;i--){
		int k = sum(1,1,n,a[i]);
		res[k] = i;
		update(1,1,n,k,0);
	}
	for(int i=1;i<=n;i++) cout << res[i] << ' ';
}