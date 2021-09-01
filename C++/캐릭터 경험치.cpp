#include <bits/stdc++.h>

using namespace std;

int n,m;
long long dp[10005][1005],res;
int 
parent[10005][1005],ret,re;
vector<pair<int,int>> cun;
vector<int> result;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> m >> n;
	cun.push_back({0,0});
	for(int i=1;i<=n;i++){
		int x,y;
		cin >> x >> y;
		cun.push_back({x,y});
	}
	for(int i=1;i<=n;i++){
		for(int j=cun[i].first;j<=m;j++){
			long long x = dp[j-cun[i].first][i-1]+cun[i].second;
			long long y = dp[j][i-1];
			dp[j][i] = max(x,y);
			if(x>y){
				parent[j][i] = i;
			}else{
				parent[j][i] = parent[j][i-1];
			}
			if(res < dp[j][i]){
				res = dp[j][i];
				re = j;
				if(x>y) ret = i;
				else ret = parent[j][i-1];
			}
		}
	}
	cout << res << '\n';
	while(parent[re][ret]){
		result.push_back(parent[re][ret]);
		re -= cun[ret].first;
		ret--;
	}
	cout << result.size() << '\n';
	for(int i=result.size()-1;i>=0;i--) cout << result[i] << ' ';
}