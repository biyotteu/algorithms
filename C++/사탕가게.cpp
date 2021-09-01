#include <bits/stdc++.h>
#define INF (1<<29);
using namespace std;

vector<pair<int,int>> can;
int n,M[10005];
double m;
int f(int sum){
	int &ret = M[sum];
	if(ret) return ret;
	for(auto i:can)	if(i.second <= sum) ret = max(ret,f(sum-i.second) + i.first);
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		memset(M,0,sizeof(M));
		can.clear();
		cin >> n >> m;
		if(n+m == 0) return 0;
		for(int i=0;i<n;i++){
			int x;
			double y;
			cin >> x >> y;
			can.push_back({x,(int)(y*100+0.5)});
		}
		cout << f((int)(m*100+0.5)) << "\n";
	}
}