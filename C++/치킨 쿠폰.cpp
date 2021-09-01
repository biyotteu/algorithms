#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	while(scanf("%d %d",&n,&k)!=EOF){
		int res = n;
		while(n>=k){
			n-=k;
			n++;
			res++;
		}
		printf("%d\n",res);
	}
}