#include <bits/stdc++.h>

using namespace std;

int n,m,lv[32005];
vector<int> ta[32005],res;
queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		lv[y]++;
		ta[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!lv[i])	Q.push(i);
	while(Q.size()){
		int cur = Q.front();
		Q.pop();
		for(auto i:ta[cur]){
			lv[i]--;
			if(!lv[i]){
				Q.push(i);
				res.push_back(i);
			}
		}
	}
	for(auto i:res) cout << i << ' ';
}