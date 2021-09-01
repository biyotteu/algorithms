#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int a,b,c,sum=0;
		scanf("%d %d %d",&a,&b,&c);
		printf("#%d ",t);
		if(c<11){
			b--;
			sum += (c+49);
		}
		else
			sum += (c-11);
		if(b<11){
			a--;
			sum += (b+13)*60;
		}
		else 
			sum += (b-11)*60;
		if(a<11){
			printf("-1\n");
			continue;
		}
		else sum += (a-11)*24*60;
		printf("%d\n",sum);
	}
}