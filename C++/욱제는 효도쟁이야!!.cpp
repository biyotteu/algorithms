#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,sum=0,MM=0;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		sum+=x;
		MM = max(MM,x);
	}
	printf("%d",sum-MM);
}