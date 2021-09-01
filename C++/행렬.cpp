#include <bits/stdc++.h>

using namespace std;

int n,m,A[55][55],B[55][55],res;
void check(){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(A[i][j] != B[i][j]){
				printf("-1");
				return;	
			}
	printf("%d",res);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char x;
			scanf(" %c",&x);
			A[i][j] = (x - '0');
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			char x;
			scanf(" %c",&x);
			B[i][j] = (x - '0');
		}
	if(n>=3 && m>=3){
		for(int i=1;i<=n-2;i++)
			for(int j=1;j<=m-2;j++){
				if(A[i][j] != B[i][j]){
					res++;
					for(int p=i;p<=i+2;p++)
						for(int q=j;q<=j+2;q++) A[p][q] = !A[p][q];
				}
			}
	}
	check();
}