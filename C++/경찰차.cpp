#include <bits/stdc++.h>
#define INF (1<<29)
using namespace std;

int n,m,dp[1005][1005];
vector<pair<int,int>> Wx,Wy;
vector<int> res;
int dist(pair<int,int> A,pair<int,int> B){
	return abs(A.first - B.first) + abs(A.second-B.second);
}
int f(int x,int y){
	if(max(x,y) == m) return 0;
	int &ret = dp[x][y];
	if(ret!=-1) return ret;
	int next = max(x,y)+1;
	ret = f(next,y)+dist(Wx[next],Wx[x]);
	ret = min(ret,f(x,next)+dist(Wy[next],Wy[y]));
	return ret;
}
void g(int x, int y) {
    if (max(x,y) == m) return;
    int next = max(x, y) + 1;
    int a = f(next,y)+dist(Wx[next],Wx[x]);
    int b = f(x,next)+dist(Wy[next],Wy[y]);
    if (a > b) {
        res.push_back(2);
        g(x, next);
    }
    else {
        res.push_back(1);
        g(next, y);
    }
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	Wx.push_back({1,1});
	Wy.push_back({n,n});
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		Wx.push_back({x,y});
		Wy.push_back({x,y});
	}
	cout << f(0,0) << '\n';
	g(0,0);
	for(auto i:res) cout << i << '\n';
}
