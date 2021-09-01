#include <bits/stdc++.h>
#define INF (1<<29)

using namespace std;

int n1,n2,m,cost[200005],ret=-(INF);
vector<int> su[6];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n1 >> n2;
	cin >> m;
	cost.resize(n2+1,-INF);
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		if(x == 0){
			if(y>0) ret+=y;
			continue;
		}
		su[x].push_back(y);
	}
	for(int i=0;i<6;i++)
		sort(su[i].begin(),su[i].end());
	for(int i=1;i<=min(su[i].size(),n2);i++){
		cost[i] = cost[i-1]+su[i-1];
		if(i>=n1) res = max(res,cost[1][i]);
	}
	
}
