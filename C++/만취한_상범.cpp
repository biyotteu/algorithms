#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d",&n);
		for(k=1;k*k<=n;k++);
		k--;
		printf("%d\n",k);
	}
}