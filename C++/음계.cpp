#include <bits/stdc++.h>

using namespace std;

int main(){
	int a[10],i;
	for(i=1;i<=8;i++) cin >> a[i];
	for(i=1;i<=8;i++) if(i!=a[i]) break;
	if(i == 9){ 
		printf("ascending");
		return 0;
	}
	for(i=8;i>=1;i--) if(i!=a[9-i]) break;
	if(i == 0){
		printf("descending");
		return 0;
	}
	printf("mixed");
}