#include <bits/stdc++.h>

using namespace std;

int n,m,p=123456789,q=123456789;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		p = min(p,x);
		q = min(q,y);
	}
	p = min(p,q*6);
	printf("%d",n/6*p + min(p,(n%6)*q));
}