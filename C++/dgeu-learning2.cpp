#include <bits/stdc++.h>

using namespace std;
using iii = pair<int, pair<int, int>>;
using ii = pair<int,int>;

int n, m, q;
vector<int> par,res;

int _find(int v) {
	if (v == par[v]) return v;
	return par[v] = _find(par[v]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	par.resize(n+1);
	for(int i=1;i<=n;i++) par[i] = i;
	res.resize(q+1);
	priority_queue<iii> pq;
	for (int i = 0; i < m; i++) {
		int a, b, v;
		cin >> a >> b >> v;
		q.push({v, {a, b}});
	}
	for(int i=0;i<q;i++)
	while (!pq.empty()) {
		iii cur = pq.front(); pq.pop();
		int x = _find(cur.second.first), y = _find(cur.second.second);
		if (x == y) continue;
		par[x] = y;
	}
}