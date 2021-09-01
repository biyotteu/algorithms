#include <bits/stdc++.h>

using namespace std;
using pp = pair<double,double>;

int n;
double dp[520][520];
vector<pp> ver;
double dist(pp a,pp b){
	return sqrt((a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second));
}
double f(int x,int y){
	if(y == n-1) return dist(ver[x],ver[y]);
	double &ret = dp[x][y];
	if(ret) return  ret;
	return dp[x][y] = min(f(x,y+1)+dist(ver[y],ver[y+1]),f(y,y+1)+dist(ver[x],ver[y+1]));
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		ver.clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			double x,y;
			scanf("%lf %lf",&x,&y);
			ver.push_back({x,y});
		}
		printf("%lf\n",f(0,0));

	}
}