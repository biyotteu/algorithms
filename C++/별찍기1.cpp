#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==i) printf("\\");
			else printf(" ");
		}
		printf("|");
		for(int j=0;j<n;j++){
			if(n-i-1 == j) printf("/");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<n;i++) printf("-");
	printf("*");
	for(int i=0;i<n;i++) printf("-");
	printf("\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==n-i-1) printf("/");
			else printf(" ");
		}
		printf("|");
		for(int j=0;j<n;j++){
			if(i == j) printf("\\");
			else printf(" ");
		}
		printf("\n");
	}
}