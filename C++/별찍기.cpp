#include <bits/stdc++.h>

using namespace std;

int A[500000][55];
int n,rr[20],ll[20];
void f(int x,int y,int v){
	for(int i=y;i<y+ll[v];i++) A[x][i] = 1;
	for(int i=x;i<x+rr[v]/2+1;i++) A[i][y+ll[v]-1] = 1;
	for(int i=y;i<y+ll[v];i++) A[x+rr[v]/2][i] = 1;
	for(int i=x+rr[v]/2+1;i<x+rr[v];i++) A[i][y] = 1;
	for(int i=y;i<y+ll[v];i++) A[x+rr[v]-1][i] = 1;
}
void g(int x,int y,int v){
	if(v == 0) return;
	f(x,y,v);
	g(x+2,y+1,v-1);
	g(x+rr[v]/2+2,2+y,v-1);

}
int main(){
	scanf("%d",&n);
	rr[1] = 5;
	ll[1] = 3;
	for(int i=2;i<=n;i++){ 
		rr[i] = rr[i-1]*2+7;
		ll[i] = ll[i-1]+3;
	}
	g(1,1,n);
	for(int i=1;i<=rr[n];i++){
		for(int j=1;j<=ll[n];j++){
			if(A[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}