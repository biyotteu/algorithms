#include <bits/stdc++.h>

using namespace std;

int A[105],B[105],tmpA[105],tmpB[105];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x,y,res=0;
		scanf("%d %d",&x,&y);
		A[x]++,B[y]++;
		for(int i=1;i<=100;i++) tmpA[i] = A[i],tmpB[i] = B[i];
		int ina=1,inb=100;	
		while(ina <= 100 && inb >= 1){
			while(!tmpA[ina]) ina++;
			while(!tmpB[inb]) inb--;
			if(ina > 100 || inb < 1) break;
			int k = min(tmpA[ina],tmpB[inb]);
			tmpA[ina] -= k;
			tmpB[inb] -= k;
			res = max(res,ina+inb);
			
		}	
		printf("%d\n",res);
	}
}