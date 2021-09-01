#include <bits/stdc++.h>

using namespace std;

int n,A[105],B[105][105];
int main(){
	scanf("%d",&n);
	for(int k=1;k<=n;k++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for(int i=b;i<b+d;i++)
			for(int j=a;j<a+c;j++) B[i][j] = k;
	}
	for(int k=1;k<=n;k++){
		int res = 0;
		for(int i=0;i<=101;i++)
			for(int j=0;j<=101;j++) if(B[i][j] == k) res++;
		printf("%d\n",res);
	}
}