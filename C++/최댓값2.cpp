#include <bits/stdc++.h>

using namespace std;

int main(){
	int n=0,m,k;
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=9;j++){
			int x;
			scanf("%d",&x);
			if(n < x){
				n = x;
				m = i;
				k = j;
			}
		}
	}
	printf("%d\n%d %d",n,m,k);
}