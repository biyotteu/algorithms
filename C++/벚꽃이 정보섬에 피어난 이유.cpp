#include <bits/stdc++.h>

using namespace std;

int n,num[15];
long long res;
long long f(int a,int b){
	long long ret = 1;
	for(int i=a;i<=b;i++) ret *= num[i];
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<=n;i++){
		for(int j=1;i+j<=n;j++){
			for(int k=1;i+j+k<n;k++){
				long long cur = f(1,i) + f(i+1,i+j) + f(i+j+1,i+j+k) + f(i+j+k+1,n); 
				res = max(cur,res);
			}
		}
	}
	printf("%d",res);
}