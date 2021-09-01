#include <bits/stdc++.h>

using namespace std;

vector<int> pac;
vector<vector<int>> beh;
int n,dp[20][250000],p;
int f(int v,int on){
	if(v <= 0) return 0;
	int &ret = dp[v][on];
	if(ret != -1) return ret;
	for(int i=1;i<=n;i++){
		if(on & (1<<i)){
			for(int j=1;j<=n;j++){
				if(i == j || on & (1 << j)) continue;
				if(ret == -1) ret = f(v-1,on | (1<<j)) + beh[i][j];
				else ret = min(ret,f(v-1,on | (1<<j)) + beh[i][j]);
			}
		}
	}
	return ret;
}
int main(){
	cin >> n;
	beh.resize(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin >> beh[i][j];
	string str;
	cin >> str;
	int x = 0,y;
	for(int i=1;i<=str.size();i++) if(str[i-1] == 'Y') x|=(1<<i),y--;
	cin >> p;
	memset(dp,-1,sizeof(dp));
	cout << f(p+y,x);
}