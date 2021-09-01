#include <bits/stdc++.h>
#define MOD 1000

using namespace std;

long long n,m;
vector<vector<long long>> a;
vector<vector<long long>> multi(vector<vector<long long>> a,vector<vector<long long>> b){
	vector<vector<long long>> tmp;
	tmp.resize(n);
	for(int i=0;i<n;i++){
		tmp[i].resize(n,0);
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++) tmp[i][j] = (tmp[i][j] + (a[i][k]*b[k][j]))%MOD;
	}
	return tmp;
}
vector<vector<long long>> f(long long v){
	if(v == 1) return a;
	vector<vector<long long>> cur = f(v/2);
	cur = multi(cur,cur);
	if(v%2 == 0) return cur;
	else return multi(cur,a);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n >> m;
	a.resize(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			long long x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector<vector<long long>> res = f(m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout << res[i][j]%MOD << ' ';
		cout << "\n";
	}
}