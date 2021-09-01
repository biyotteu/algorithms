#include <bits/stdc++.h>

using namespace std;

int n,c;
int main(){
	scanf("%d %d",&n,&c);
	while(c--){
		int a,b;
		scanf("%d %d",&a,&b);
		int aa = abs(a-b);
		int bb = n - max(a,b);
		if(a == b){
			puts("1");
			continue;
		}
		if(a < b){
			if(aa - bb <= 1) puts("1");
			else puts("0");
		}else{
			if(aa - bb <= 2) puts("1");
			else puts("0");
		}
	}
}