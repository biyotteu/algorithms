#include <bits/stdc++.h>

using namespace std;

int n,visit[1000005];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(x>1000000) continue;
		visit[x] = 1;
	}
	for(int i=1;i<=1000000;i++){
		if(!visit[i]){
			printf("%d",i);
			return 0;
		}
	}
}