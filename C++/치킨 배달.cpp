#include <bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

int n,m,res = 2e9;
vector<int> visit;
vector<pp> home,chi;
int dist(pp a,pp b){
	return (int)abs(a.first - b.first) + (int)abs(a.second - b.second);
}
void f(int v,int be){
	if(v == m){
		int sum = 0;
		for(int i=0;i<home.size();i++){
			int cur = 2e9;
			for(int j=0;j<chi.size();j++){
				if(!visit[j]) continue;
				cur = min(cur,dist(home[i],chi[j]));
			}
			sum += cur;
		}
		res = min(res,sum);
		return;
	}
	for(int i=be;i<chi.size();i++){
		if(visit[i]) continue;
		visit[i] = 1;
		f(v+1,i+1);
		visit[i] = 0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			int x;
			cin >> x;
			if(x == 1) home.push_back({i,j});
			if(x == 2) chi.push_back({i,j});
		}
	}
	visit.resize(chi.size());
	f(0,0);
	cout << res;
}