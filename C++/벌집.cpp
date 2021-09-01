#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,cnt;
	scanf("%d",&n);
	n-=1;
	while(1){
		n-=cnt*6,cnt++;
		if(n<=0) break;
	}	
	printf("%d",cnt);
}