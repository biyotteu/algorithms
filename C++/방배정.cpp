#include <bits/stdc++.h>

using namespace std;

int n,k,sd[2][7],res;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		sd[x][y]++;
	}
	for(int i=0;i<2;i++){
		for(int j=1;j<=6;j++){
			res += sd[i][j]/k;
			res += (sd[i][j]%k > 0);
		}
	}
	printf("%d",res);
}