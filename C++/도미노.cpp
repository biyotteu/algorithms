#include <bits/stdc++.h>

using namespace std;

int n,sum;
int main(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum += (i+j);
		}
	}
	printf("%d",sum);
}
