#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int m,cmp = 0;
		vector<int> A(5,0),B(5,0);
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int x;
			scanf("%d",&x);
			A[x]++;
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int x;
			scanf("%d",&x);
			B[x]++;
		}
		for(int i=4;i>=1;i--){
			if(A[i] > B[i]){
				printf("A\n");
				cmp = 1;
				break;
			}else if(A[i] < B[i]){
				printf("B\n");
				cmp = 1;
				break;
			}
		}
		if(!cmp) printf("D\n");
	}
}