#include <bits/stdc++.h>

using namespace std;

int n,m;
queue<int> Q;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) Q.push(i);
	printf("<");
	while(!Q.empty()){
		if(Q.size() == 1){
			printf("%d>",Q.front());
			break;
		}
		for(int i=1;i<m;i++){
			Q.push(Q.front());
			Q.pop();
		}
		printf("%d, ",Q.front());
		Q.pop();
	}
}