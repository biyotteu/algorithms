#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int seg[(1<<18)];
int n,q,k,ch[100005];
void update(int p,int v){
	int idx = (k|p);
	seg[idx] ^= v;
	while(idx>>=1) seg[idx] = seg[(idx<<1)] ^ seg[(idx<<1)+1];
}
int sum(int a,int b){
	int ret = 0;
	a|=k,b|=k;
	while(a<=b){
		if(a%2) ret^=seg[a++];
		if(b%2 == 0) ret^=seg[b--];
		a >>= 1, b >>= 1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream ifn("cowland.in");
	ofstream ofn("cowland.out");
	ifn >> n >> q;
	for(k=1;k<n;k<<=1);
	for(int i=1;i<=n;i++){
		int x;
		ifn >> x;
		update(i,x);
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		ifn >> a >> b;
		if(a > b) swap(a,b);
		if(b-a <= 1) continue;
		update(b,sum(a+1,b-1));
		ch[b] = sum(a+1,b-1);
	}
	while(q--){
		int a,b,c;
		ifn >> a >> b >> c;
		if(a == 1) update(b,(c|seg[(b|k)]));
		else ofn << (sum(b,c)^ch[b]) <<"\n";
	}
	ifn.close();
	ofn.close();
	return 0;
}