#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n == 1){
		printf("*");
		return 0;
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<2*n-2-i;j++) printf(" ");
		printf("*");
		if(i==0){
			printf("\n");
			continue;
		}
		for(int j=1;j<=2*i-1;j++) printf(" ");
		printf("*\n");
	}
	for(int i=0;i<4*n-3;i++){
		if(i>= 0 && i<n) printf("*");
		else if(i>=3*n-3 && i<4*n-3) printf("*");
		else printf(" ");
	}
	printf("\n");
	for(int i=0;i<n-1;i++){
		for(int j=0;j<4*n-3;j++){
			if(j == i+1 || j == 4*n-5-i)printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	for(int i=0;i<n-2;i++){
		for(int j=0;j<4*n-3;j++){
			if(j == n-i-2 || j == 3*n-2+i)printf("*");
			else printf(" ");
		}
		printf("\n");	
	}
	for(int i=0;i<4*n-3;i++){
		if(i>= 0 && i<n) printf("*");
		else if(i>=3*n-3 && i<4*n-3) printf("*");
		else printf(" ");
	}
	printf("\n");
	for(int i=n-2;i>=0;i--){
		for(int j=0;j<2*n-2-i;j++) printf(" ");
		printf("*");
		if(i==0){
			printf("\n");
			continue;
		}
		for(int j=1;j<=2*i-1;j++) printf(" ");
		printf("*\n");
	}
}