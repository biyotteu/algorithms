#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int n,m,k,s[5005],c[5005],sum[5005];
int e[5005];
vector<int> cc[5005];
long long res=1,ss;
long long ccc[5005];
long long power(long long a,long long b) 
{ 
    long long pow = 1; 
    while (b) 
    { 
     if (b & 1) 
     { 
      	pow = pow * a;
      	pow %= MOD; 
      	--b; 
     } 
     a = a*a; 
     a %= MOD;
     b = b/2; 
    } 
    return pow%MOD; 
} 
int main(){
	ifstream ifn("poetry.in");
	ofstream ofn("poetry.out");
	ifn >> n >> m >> k;
	for(int i=1;i<=n;i++){
		int x;
		ifn >> s[i] >> c[i];
		cc[c[i]].push_back(s[i]);
	}
	for(int i=1;i<=m;i++){
		char x;
		ifn >> x;
		e[x-64]++;
	}
	sum[0] = 1;
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			if(i>=s[j]){
				sum[i] += sum[i-s[j]];
				sum[i] %= MOD;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(auto j:cc[i]){
			ccc[i] += sum[k-j];
			ccc[i] %=MOD;
		}
		ss += ccc[i];
		ss %= MOD;
	}
	for(int i=1;i<=26;i++){
		if(e[i]>=2){
			long long cur = 0;
			for(int j=1;j<=n;j++){
				if(ccc[j] == 0) continue;
				cur += power(ccc[j],e[i]);
				cur %= MOD;
			}
			res *= cur;
			res %= MOD;
		}
		if(e[i] == 1){
			res *= ss;
			res %= MOD;
		}
	}
	ofn << res;
	ifn.close();
	ofn.close();
	return 0;
}
