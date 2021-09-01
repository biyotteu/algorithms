#include <bits/stdc++.h>

using namespace std;

int n,m,q,l[100005],r[100005],par[100005],cnt[100005];
vector<pair<int,pair<int,int>>> edg;
vector<pair<int,int>> Q,res;

int _find(int v){
	if(v == par[v]) return v;
	return par[v] = _find(par[v]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		edg.push_back({z,{x,y}});
	}
	sort(edg.begin(),edg.end());
	cin >> q;
	res.resize(q);
	fill(r,r+q,m+1);

	for(int i=0;i<q;i++){
		int x,y;
		cin >> x >> y;
		Q.push_back({x,y});
	}
	while(1){
		vector<int> mid[m+5];
		// break;
		int con = 1;
		for(int i=0;i<q;i++){
			if(l[i]+1 < r[i]){
				con = 0;
				mid[(l[i]+r[i])>>1].push_back(i);
			}
		}
		if(con) break;
		for(int i=1;i<=n;i++) par[i] = i,cnt[i] = 1;
		for(int i=0;i<m;i++){
			int x = edg[i].second.first;
			int y = edg[i].second.second;
			x = _find(x);
			y = _find(y);
			if(x != y){
			par[y] = x;
			cnt[x] += cnt[y];
			}
			for(int j:mid[i+1]){
				x = _find(Q[j].first);
				y = _find(Q[j].second);
				if(x == y){
					r[j] = i+1;
					res[j].first = edg[i].first;
					res[j].second = cnt[x];
				}
				else l[j] = i+1;
			}
		}
	}
	for(int i=0;i<q;i++){
		if(l[i] == m) cout << "-1\n";
		else cout << res[i].first << ' ' << res[i].second << "\n";
	}
}