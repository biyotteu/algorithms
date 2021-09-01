#include <bits/stdc++.h>
#define MM 300005

using namespace std;

vector<int> gr[MM],res;
int n,m,k,x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n >> m >> k >> x;
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		gr[a].push_back(b);
	}
	vector<int> visit(n+1,0);
	queue<int> Q;
	Q.push(x);
	visit[x] = 1;
	int cnt = 0;
	while(Q.size()){
		int size = Q.size();
		for(int i=0;i<size;i++){
			int cur = Q.front();Q.pop();
			for(auto j:gr[cur]){
				if(visit[j]) continue;
				visit[j] = 1;
				Q.push(j);
			}
		}
		if(++cnt == k){
			vector<int> res;
			while(Q.size()){
				res.push_back(Q.front());
				Q.pop();
			}
			sort(res.begin(),res.end());
			for(auto i:res) cout << i << "\n";
			return 0;
		}
	}
	cout << -1;
}