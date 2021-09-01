#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,cnt = 65;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i;j++) printf("%c ",cnt++);
		printf("\n");
	}
}