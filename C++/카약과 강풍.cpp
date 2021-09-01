#include <bits/stdc++.h>

using namespace std;

int n,s,r,a[15],b[15],res;
int main(){
	scanf("%d %d %d",&n,&s,&r);
	for(int i=0;i<s;i++){
		int x;
		scanf("%d",&x);
		a[x] = 1;
	}
	for(int i=0;i<r;i++){
		int x;
		scanf("%d",&x);
		b[x] = 1;
	}
	for(int i=1;i<=n;i++){
		if(a[i]){
			if(b[i-1]){
				b[i-1] = 0;
				s--;
			}else if(b[i]){
				b[i] = 0;
				s--;
			}else if(b[i+1]){
				b[i+1] = 0;
				s--;
			}
		}
	}
	printf("%d",max(s,0));
}