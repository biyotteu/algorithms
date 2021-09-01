#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,w=0,turn = 1;
	scanf("%d",&n);
	while(n--){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		turn = y*(turn/x);
		if(z == 1) w = !w;
	}
	printf("%d %d",w,turn);
}