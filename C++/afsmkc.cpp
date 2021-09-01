#include <bits/stdc++.h>

using namespace std;

struct info
{
	int x,y;
	long long int z;
	bool operator<(info A)const{
		return z > A.z;
	}
};
int n,m;
long long int res;
vector<int> parent;
int _find(int v){
	if(v == parent[v]) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		cin >> n >> m;
		if(n+m == 0) return 0;
		priority_queue<info> pq;
		parent.clear();
		res = 0;
		for(int i=0;i<n;i++) parent.push_back(i);
		for(int i=0;i<m;i++){
			int x,y;
			long long int z;
			cin >> x >> y >> z;
			pq.push({x,y,z});
			res+=z;
		}
		while(!pq.empty()){
			info cur = pq.top();
			pq.pop();
			int a = _find(cur.x);
			int b = _find(cur.y);
			if(a!=b){
				parent[a] = b;
				res -= cur.z;
			}
		}
		cout << res << "\n";
	}
}
