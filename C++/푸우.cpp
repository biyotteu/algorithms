#include <bits/stdc++.h>

using namespace std;

struct info{
	int x,y;
	info(){}
	info(int a,int b){
		x = a, y =b;
	}
};
struct pos{
	info a,b;
	int e;
	bool operator<(pos A)const{
		return e < A.e;
	}
};
int n,m,X[4]={1,0,-1,0},Y[4]={0,1,0,-1};
char gr[805][805];
info parent[805][805];
priority_queue<pos> pq;
info _find(info v){
	if(v.x == parent[v.x][v.y].x && v.y == parent[v.x][v.y].y) return v;
	return parent[v.x][v.y] = _find(parent[v.x][v.y]);
}
bool _union(info a,info b){
	info aa = _find(a);
	info bb = _find(b);
	if(aa.x == bb.x && aa.y == bb.y) return false;
	parent[aa.x][aa.y] = bb;
	return true;
}
vector<vector<int>> spfa(vector<info> start){
	vector<vector<int>> dist(n+1,vector<int>(n+1,-1)),inQ(n+1,vector<int>(n+1,0));
	queue<info> Q;
	for(auto i:start){ 
		Q.push(i);
		dist[i.x][i.y] = 0;
		inQ[i.x][i.y] = 1;
	}
	while(!Q.empty()){
		info cur = Q.front();
		Q.pop();
		inQ[cur.x][cur.y] = 0;
		for(int i=0;i<4;i++){
			int nx = cur.x + X[i], ny = cur.y + Y[i];
			if(nx < 1 || nx > n || ny < 1 || ny > n || gr[nx][ny] == 'T' || gr[nx][ny] == 'D') continue;
			if(dist[nx][ny] == -1 || dist[nx][ny] > dist[cur.x][cur.y] + 1){
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				if(!inQ[nx][ny]){
					inQ[nx][ny] = 1;
					Q.push({nx,ny});
				}
			}
		}
	}
	return dist;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	vector<info> B,P;
	info en;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> gr[i][j];
			if(gr[i][j] == 'H')	B.push_back({i,j});
			if(gr[i][j] == 'M'){
				P.push_back({i,j});
				en.x = i , en.y = j;
			}
		}
	
	vector<vector<int>> bee = spfa(B), poo = spfa(P);
	int dist[805][805],inQ[805][805];
	queue<info> Q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			bee[i][j] = ((m*bee[i][j]-poo[i][j])/m-1);
			if(gr[i][j] == 'D') bee[i][j] = 987654321;
			cout <<bee[i][j] << ' ';
			parent[i][j] = info(i,j);
		}
		cout << '\n';
	}
	info enn,stt;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int i=0;i<4;i++){
				int nx = i + X[i], ny = j+ Y[i];
				if(nx < 1 || nx > n || ny < 1 || ny > n || gr[nx][ny] == 'T') continue;
				pq.push({info(i,j),info(nx,ny),min(bee[i][j],bee[nx][ny])});
			}
			if(gr[i][j] == 'M') stt = info(i,j);
			if(gr[i][j] == 'D') enn = info(i,j);
		}
	}
	while(!pq.empty()){
		pos v = pq.top();
		pq.pop();
		_union(v.a,v.b);
		info aa = _find(stt);
		info bb = _find(enn);
		printf("%d %d %d %d\n",aa.x,aa.y,bb.x,bb.y);
		if(aa.x == bb.x && aa.y == bb.y){
			cout << v.e;
			return 0;
		}
	}
}