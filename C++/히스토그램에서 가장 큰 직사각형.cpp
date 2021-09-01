#include <bits/stdc++.h>

using namespace std;

int n,size;
vector<int> num;
vector<int> seg;
void update(int node,int st,int en){
	if(st == en){
		seg[node] = st;
		return;
	}
	update(node*2,st,(st+en)/2);
	update(node*2+1,(st+en)/2+1,en);
	if(num[seg[node*2]] < num[seg[node*2+1]]) seg[node] = seg[node*2];
	else seg[node] = seg[node*2+1];
}
int get_min(int node,int st,int en,int l,int r){
	if(st > r || en < l) return -1;
	if(l <= st && en <= r) return seg[node];	
	int x = get_min(node*2,st,(st+en)/2,l,r);
	int y = get_min(node*2+1,(st+en)/2+1,en,l,r);
	if(x == -1) return y;
	if(y == -1) return x;
	return num[x] < num[y] ? x:y;
}
long long int ret(int l,int r){
	long long int res = 0;
	int idx = get_min(1,0,n-1,l,r);
	res = (long long)num[idx]*(r-l+1);
	if(idx > l) res = max(res,ret(l,idx-1));
	if(idx < r) res = max(res,ret(idx+1,r));
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		num.clear();
		seg.clear();
		cin >> n;
		if(!n) return 0;
		size = (int)ceil(log2(n));
		seg.resize((1<<(size+1)));
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			num.push_back(x);
		}
		update(1,0,n-1);
		cout << ret(0,n-1) << "\n";
	}
}