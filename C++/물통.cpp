#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

struct info{
	int x,y,z,r;
};
queue<info> Q;
int dp[2005][2005][6];
int main(){
	scanf("%d %d %d",&AL,&BL,&CL);
	scanf("%d %d %d",&A,&B,&C);
	Q.push({0,0,0,0});
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();
		if(cur.x == A && cur.y == B && cur.z == C){
			prinf("%d",cur.z);
			return 0;
		}
		if(dp[cur.x][cur.y][cur.z]) continue;
		dp[cur.x][cur.y][cur.z] = cur.r;
		if(cur.z == 0){
			Q.push({cur.x,cur.y,1});
			Q.push({0,cur.y,0});
			Q.push({cur.x,0,0});
		}
		if(cur.z == 1){

		}
		if(cur.z == 2){

		}
		if(cur.z == 3){
			
		}
		if(cur.z == 4){

		}
		if(cur.z == 5){
			
		}
			}
	printf("-1");
}