#include <bits/stdc++.h>

using namespace std;

int ma,x,y;
int main(){
	for(int i=1;i<10;i++)
		for(int j=1;j<10;j++){
			int k;
			scanf("%d",&k);
			if(k>ma){
				ma = k;
				x = i;
				y = j;
			}
		}
	printf("%d\n%d %d",ma,x,y);
}