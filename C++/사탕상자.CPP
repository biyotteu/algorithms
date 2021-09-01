#include <bits/stdc++.h>

using namespace std;

int n,size,idx;
vector<int> seg;
void update(int node,int st,int en,int idx,int v){
	if(st > idx || en < idx) return;
	if(st == en){
		seg[node] += v;
		if(seg[node] < 0) seg[node] = 0;
		return;
	}
	update(node*2,st,(st+en)/2,idx,v);
	update(node*2+1,(st+en)/2+1,en,idx,v);
	seg[node] = seg[node*2] + seg[node*2+1];
}
int tasty(int node,int st,int en,int v){
	if(st == en){
		update(1,0,1000004,st,-1);
		return st;
	}
	int ret;
	if(seg[node*2] >= v) ret = tasty(node*2,st,(st+en)/2,v);
	else ret = tasty(node*2+1,(st+en)/2+1,en,v - seg[node*2]);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	size = (int)ceil(log2(1000005));
	seg.resize((1<<(size+1)));
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		if(a == 2){
			int b,c;
			cin >> b >> c;
			update(1,0,1000004,b,c);
		}
		else{
			int b;
			cin >> b;
			cout << tasty(1,0,1000004,b) << "\n";
		}
	}
}

