#include <bits/stdc++.h>
#define MOD 987654321
using namespace std;

long long dp[10005];
long long f(int v){
	long long &ret = dp[v];
	if(ret) return ret;
	for(int i=1;i<v;i+=2){ 
		ret += f(i-1)*f(v-(i+1))%MOD;
		ret %= MOD;
	}
	return ret;
}
int main(){
	int n;
	scanf("%d",&n);
	dp[0] = 1;
	dp[1] = 1;
	printf("%lld",f(n));
}