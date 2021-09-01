#include <bits/stdc++.h>

using namespace std;

vector<int> seg;
int n;
long long res;
void update(int node,int start,int end,int idx,int value){
	if(start > idx || end < idx) return;
	if(start == end){
		seg[node] = value;
		return;
	}
	update(node*2,start,(start+end)/2,idx,value);
	update(node*2+1,(start+end)/2+1,end,idx,value);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int sum(int node,int start,int end,int l,int r){
	if(l>end || r<start) return 0;
	if(l<=start && end<=r) return seg[node];
	return sum(node*2,start,(start+end)/2,l,r) + sum(node*2+1,(start+end)/2+1,end,l,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(size+1));
	vector<pair<int,int>> num;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		num.push_back({x,i});
	}
	sort(num.begin(),num.end());
	for(auto i:num){
		res += sum(1,1,n,i.second+1,n);
		update(1,1,n,i.second,1);
	}
	cout << res;
}