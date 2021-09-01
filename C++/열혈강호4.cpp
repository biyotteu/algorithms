#include <bits/stdc++.h>

using namespace std;

int n,m,k;
int visit[1005],A[1005],B[1005],res;
vector<int> edg[1005];
int flow(int v){
	visit[v] = 1;
	for(auto i:edg[v]){
		if(B[i] == -1 || (!visit[B[i]] && flow(B[i]))){
			A[v] = i;
			B[i] = v;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			edg[i].push_back(y);
		}
	}
	memset(A,-1,sizeof(A));
	memset(B,-1,sizeof(B));
	for(int i=1;i<=n;i++){
		memset(visit,0,sizeof(visit));
		if(flow(i)) res++;
	}
	int cmp = 1;
	while(k>0 && cmp){
		for(int j=1;j<=n;j++){
			memset(visit,0,sizeof(visit));
			if(flow(j)){
				cmp = 1;
				res++;
				k--;
				break;
			}else cmp = 0;
		}
	}
	printf("%d",res);
}