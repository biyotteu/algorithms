#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	for(int p=1;p<=t;p++){
		int n;
		char c[100005];
		scanf("%d",&n);
		scanf(" %s",c);
		printf("case #%d: ",p);
		int size = strlen(c);
		for(int i=0;i<size;i++){
			if(c[i] == 'S') printf("E");
			else printf("S");
		}
		printf("\n");	
	}
}