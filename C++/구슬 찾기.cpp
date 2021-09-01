#include <bits/stdc++.h>

using namespace std;

int n,m,res,cnt;
vector<int> ch[100],pa[100];
void f(int v){
	cnt++;
	for(auto i:ch[v]) f(i);
}
void g(int v){
	cnt++;
	for(auto i:pa[v]) g(i);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		ch[x].push_back(y);
		pa[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		cnt = 0;
		f(i);
		if(cnt>=(n+1)/2) res++;
		cnt = 0;
		g(i);
		if(cnt>=(n+1)/2) res++;
	}
	cout << res;
}