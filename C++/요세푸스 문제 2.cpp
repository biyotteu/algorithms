#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> seg;

void update(int node,int start,int end,int idx,int v){
	if(start > idx || end < idx) return;
	if(start == end){
		seg[node] = v;
		return;
	}
	update(node*2,start,(start+end)/2,idx,v);
	update(node*2+1,(start+end)/2+1,end,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int getSum(int node,int start,int end,int l,int r){
	if(start > r || end < l) return 0;
	if(l <= start && end <= r) return seg[node];
	return getSum(node*2,start,(start+end)/2,l,r) + getSum(node*2+1,(start+end)/2+1,end,l,r);
}
int getIdx(int node,int start,int end,int v){
	if(start == end) return start;
	if(v <= seg[node*2]) return getIdx(node*2,start,(start+end)/2,v);
	else return getIdx(node*2 + 1,(start+end)/2+1,end,v-seg[node*2]);
}
int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);cin.tie(0);
	cin >> n >> k;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(size+1));
	for(int i=1;i<=n;i++) update(1,1,n,i,1);
	int cur = 1;
	cout << '<';
	for(int i=1;i<=n;i++){
		cur += k-1;
		if(!(cur%(n-i+1))) cur = (n-i+1);
		else if(cur > n-i+1) cur %= (n-i+1);
		int next = getIdx(1,1,n,cur);
		update(1,1,n,next,0);
		cout << next; //<< "####\n";
		if(i!=n) cout << ", ";
		//for(int i=1;i<=n;i++) cout << getSum(1,1,n,i,i) << ' ';
	}
	cout << '>';
}