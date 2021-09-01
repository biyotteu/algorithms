#include <bits/stdc++.h>

using namespace std;

int X[4]={0,-1,0,1},Y[4]={1,0,-1,0};
int main()
{
	int n,flag=0,D=0,k,x=0,y=0;
	scanf("%d %d",&n,&k);
	while(k--){
		string a;
		int b;
		cin >> a >> b;
		if(a.compare("TURN") == 0){
			if(b){
				D+=1;
				D%=4;
			}
			else{
				D-=1;
				if(D<0) D = 3;
			}
		}
		else{
			x+=X[D]*b;
			y+=Y[D]*b;
			if(x<0 || y<0 || x>n || y>n){ flag = 1;
			}
		}
	}
	if(flag) printf("-1");
	else printf("%d %d",y,x);
}
