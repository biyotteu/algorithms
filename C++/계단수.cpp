#include <bits/stdc++.h>
#define MOD 1000000000;
using namespace std;

int n;
long long dp[105][10][1024],res;
long long f(int v,int num,int sum){
	if(v == 1){
		if(num && sum == 1023) return 1;
		else return 0;
	}
	long long &ret = dp[v][num][sum];
	if(ret) return ret;
	if(num!=9) ret = f(v-1,num+1,sum|(1<<(num+1)));
	if(num) ret += f(v-1,num-1,sum|(1<<(num-1))); 
	ret %= MOD;
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<10;i++){
		res += f(n,i,(1<<i));
		res %= MOD;
	}
	cout << res;
}