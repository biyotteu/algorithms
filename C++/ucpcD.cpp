#include <bits/stdc++.h>

using namespace std;

int visit[300005],d,j;
vector<int> node[300005];
vector<int> dfs(int v){
	visit[v] = 1;
	int a3,a2,a1;
	vector<int> k(3,0);
	a1 = a2 = a3 = 0;
	int vsize = node[v].size();
	if(vsize >= 3)
		j += (vsize)*(vsize-1)*(vsize-2)/6;
	for(auto i:node[v]){
		if(visit[i]) continue;
		k = dfs(i);
		a1++;
		a2 += k[0];
		a3 += k[1];
	}
	//cout << a1 << ' ' << a2 << ' ' <<a3 << ' ' << v << "####\n";
	d += ((a1-1)*a2 + a3);
	k[0] = a1,k[1] = a2, k[2] = a3;
	return k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	dfs(1);
	if(d > j*3) cout << "D";
	else if(d < j*3) cout << "G";
	else cout << "DUDUDUNGA";
	//cout << d << ' ' << j ;
}