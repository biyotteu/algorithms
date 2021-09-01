#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

long long int ret[55][55],A[55][55],tmp[55][55];
int main()
{
	int n,lastx,lasty;
	int x,y;
	scanf("%d",&n);
	scanf("%d %d",&x,&y);
	for(int i=1;i<=x;i++)
		for(int j=1;j<=y;j++) scanf("%lld",&ret[i][j]);
	lastx = x,lasty =y;
	for(int idx=1;idx<n;idx++){
		scanf("%d %d",&x,&y);
		if(lasty != x){
			printf("-1");
			return 0;
		}
		for(int i=1;i<=x;i++) for(int j=1;j<=y;j++) scanf("%lld",&A[i][j]);
		for(int i=1;i<=lastx;i++){
			for(int j=1;j<=y;j++){
				long long int sum = 0;
				for(int p=1;p<=x;p++){
					sum += ret[i][p] * A[p][j]; 
					sum %= mod;
				}
				tmp[i][j] = sum;
			}
		}
		for(int i=1;i<=lastx;i++)
			for(int j=1;j<=y;j++) ret[i][j] = tmp[i][j];
		lasty = y;
	}
	long long int res = 0;
	for(int i=1;i<=lastx;i++){
		for(int j=1;j<=lasty;j++){
			res += ret[i][j];
			res %= mod;
		}
	}
	printf("%lld",res);
}