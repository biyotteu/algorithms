#include <bits/stdc++.h>

using namespace std;

int n;
int res;
vector<int> seg;
vector<pair<int,int>> num;
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
	if(start > l || end < r) return 0;
	if(l <= start && end <= r) return seg[node];
	return sum(node*2,start,(start+end)/2,l,r) + sum(node*2+1,(start+end)/2+1,end,l,r);
}
int f(int l,int r,int cnt){
	if(cnt >= n) return 0;
	if(l > r) return 0;
	if(l == r) return num[cnt].first;
	cout << l << ' ' << r << ' ' << cnt << "\n";
	int cur = (r-l+1)*num[cnt].first;
	cur = max(cur,f(l,num[cnt].second-1,cnt+1));
	cur = max(cur,f(num[cnt].second+1,r,cnt+1));
	return cur;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(size+1));
	
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		num.push_back({x,i});
	}
	sort(num.begin(),num.end());
	cout << f(1,n,0);
}