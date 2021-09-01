#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y,z;
};
int R,C,k,wl[1005][1005],visit[1005][1005],d[4],dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
info res;
pair<int,int> start;
int ret;
queue<info> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> k;
	for(int i=0;i<k;i++){
		int x,y;
		cin >> x >> y;
		wl[x][y] = 1;
	}
	cin >> start.first >> start.second;
	for(int i=0;i<4;i++) cin >> d[i];
	Q.push({start.first,start.second,0});
	visit[start.first][start.second] = 1;
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();
		if(visit[cur.x][cur.y] > ret){
			res = cur;
			ret = visit[cur.x][cur.y];
		}
		int cnt = cur.z;
		for(int i=0;i<4;i++){
			int nx = cur.x + dx[d[cnt]], ny = cur.y + dy[d[cnt]];
			if(nx>=0 && nx < R && ny>=0 && ny < C && !wl[nx][ny] && !visit[nx][ny]){
				Q.push({nx,ny,cnt});
				visit[nx][ny] = visit[cur.x][cur.y] + 1;
				break;
			}
			cnt++;	
			cnt%=4;
		}
	}
	cout << res.x << ' ' <<res.y;
}