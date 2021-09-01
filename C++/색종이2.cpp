#include <bits/stdc++.h>

using namespace std;

int n;
int wh[105][105],cnt;
int main(){
	scanf("%d",&n);
	while(n--){
		int x,y;
		scanf("%d %d",&x,&y);
		for(int i=x;i<x+10;i++){
			for(int j=y;j<y+10;j++){
				if(wh[i][j]) continue;
				cnt++;
				wh[i][j] = 1;
			}
		}
	}
	printf("%d",cnt);
}