#include <bits/stdc++.h>

using namespace std;

class xy{
public:
	int x;
	long long int y;
	xy(){x=0,y=0;}
	xy(int a,long long int b){x=a,y=b;}
};
struct info{
	int x,y;
	long long int z;
	bool operator<(info A) const{
		return z > A.z;
	}
};
vector<xy> graph[200005];
vector<bool> visit; 
stack<int> st;
vector<vector<int>> scc;
vector<int> parent,tmp;
long long int res;
void dfs(int v){
	if(visit[v]) return;
	visit[v] = true;
	for(auto i:graph[v]) dfs(i.x); 
	st.push(v);
}
void f(int v){
	if(visit[v]) return;
	visit[v] = true;
	tmp.push_back(v);
	for(auto i:graph[v]) f(i.y);
}
int _find(int v){
	if(parent[v] == v) return v;
	return parent[v] = _find(parent[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m,n;	
	cin >> m >> n;
	visit.resize(m,false);
	parent.resize(m);
	for(int i=0;i<m;i++) parent[i] = i;
	for(int i=0;i<n;i++){
		int x,y;
		long long int z;
		cin >> x >> y >> z;
		graph[x].push_back(xy(y,z));
		graph[y].push_back(xy(x,z));
	}
	for(int i=0;i<m;i++){
		if(visit[i]) continue;
		dfs(i);
	}
	visit.clear();
	visit.resize(m,false);
	while(!st.empty()){
		int cur = st.top();
		st.pop();
		if(visit[cur]) continue;
		tmp.clear();
		f(cur);
		scc.push_back(tmp);
	}
	for(int i=0;i<scc.size();i++){
		priority_queue<info> pq;
		for(auto cur:scc[i]){
			for(auto next:graph[cur]){
				pq.push({cur,next.x,next.y});
			}
		}
		while(!pq.empty()){
			info cur = pq.top();
			pq.pop();
			int a = _find(cur.x);
			int b = _find(cur.y);
			if(a!=b){
				res += cur.z;
				parent[a] = b;
			}
		}
	}
	cout << res;
}