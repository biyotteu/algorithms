#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> con,par;
int _find(int v){
	if(par[v] == v) return v;
	return par[v] = _find(par[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	con.resize(n+1,0);
	par.resize(n+1);
	for(int i=1;i<=n;i++){
		cin >> con[i];
		par[i] = i;
	}
	while(m--){
		int o,p,q;
		cin >> o >> p >> q;
		if(o == 1){
			p = _find(p);
			q = _find(q);
			con[p] += con[q];
			con[q] = 0;
			par[q] = p;
		}else{
			p = _find(p);
			q = _find(q);
			if(con[p] > con[q]){
				con[p] -= con[q];
				con[q] = 0;
				par[q] = p;
			}else if(con[q] > con[p]){
				con[q] -= con[p];
				con[p] = 0;
				par[p] = q;
			}else{
				par[p] = par[q] = con[p] = con[q] = 0;
			}
		}
	}
	vector<int> res;
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(par[i] == i){
			cnt++;
			res.push_back(con[i]);
		}
	}
	sort(res.begin(),res.end());
	cout << cnt << "\n";
	for(auto i:res) cout << i << ' ';
}