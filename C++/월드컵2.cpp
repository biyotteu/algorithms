#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int n = 6,m = 15;
int A[15],B[15],res;
vector<info> team,now;
void f(int v){
	if(v == m){
		res = 1;
		return;
	}
	int a = A[v];
	int b = B[v];
	++now[a].x,++now[b].z;
	if (now[a].x<=team[a].x && now[b].z<=team[b].z) f(v+1);
	--now[a].x,--now[b].z;
	++now[a].y,++now[b].y;
	if(now[a].y<=team[a].y && now[b].y<=team[b].y) f(v+1);
	--now[a].y,--now[b].y;
	++now[a].z,++now[b].x;
	if(now[a].z<=team[a].z && now[b].x <= team[b].x) f(v+1);
	--now[a].z,--now[b].x;
}
int main(){
	for(int p=0;p<4;p++){
		team.clear();
		team.resize(n);
		now.clear();
		now.resize(n);
		int cmp = 0;
		for(int j=0;j<n;j++){
			scanf("%d %d %d",&team[j].x,&team[j].y,&team[j].z);
			if(team[j].x + team[j].y + team[j].z != n-1) cmp = 1;
		}
		if(cmp){
			printf("0 ");
			continue;
		}
		res = 0;
		int cnt = 0;
		for(int l=0;l<n;l++){
			for(int r=l+1;r<n;r++)
			{
				A[cnt] = l;
				B[cnt] = r;
				cnt++;
			}
		}
		f(0);
		printf("%d ",res);
	}
}