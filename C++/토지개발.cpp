#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<int,long long>> seg;
void init(int node,int start,int end,int idx,int value){
	if(start > idx || end < idx) return;
	if(start == end){
		seg[node].first = seg[node].second = value;
		return;
	}
	pair<int,long long> ll,rr;
	init(node*2,start,(start+end)/2,idx,value);
	init(node*2+1,(start+end)/2+1,end,idx,value);
	ll = seg[node*2];
	rr = seg[node*2+1];
	seg[node].first = max(ll.first,rr.first);
	if(end-start==1){
		seg[node].second = seg[node].first;
		return;
	}
	if(ll.first + rr.second > rr.first + ll.second){
		seg[node].second = ll.first + rr.second;
	}else{
		seg[node].second = rr.first + ll.second;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(1+size));
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		init(1,1,n,i,x);
	}
	cout << seg[1].second;
}