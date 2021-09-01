#include <bits/stdc++.h>
#define MX 66000

using namespace std;

int n,k;
long long res;
vector<int> seg,a;
void update(int node,int x,int y,int idx,int v){
	if(x > idx || y < idx) return;
	if(x == y){
		seg[node] += v;
		return;
	}
	update(node*2,x,((x+y)>>1),idx,v);
	update(node*2+1,((x+y)>>1)+1,y,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int sum(int node,int x,int y,int v){
	if(x == y) return xww	if(seg[node*2] >= v) return sum(node*2,x,((x+y)>>1),v);
	else return sum(node*2+1,((x+y)>>1)+1,y,v - seg[node*2]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	a.resize(n,0);
	seg.resize((1<<((int)ceil(log2(MX))+1)));
	int q = (k+1)/2,cnt=0;
	for(int i=0;i<n;i++){
		if(i>=k){
			cnt++;
			res += sum(1,0,MX,q);
			update(1,0,MX,a[i-k],-1);
		}
		cin >> a[i];
		update(1,0,MX,a[i],1);

	}
	cout << res + sum(1,0,MX,q);
}