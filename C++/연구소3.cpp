#include <bits/stdc++.h>

#define pp pair<int,int>
using namespace std;

int vcnt,n,m,visit[10],lab[50][50],cnt,X[4]={1,0,-1,0},Y[4]={0,1,0,-1},res=2e9;
vector<pp> vir;
int cul(vector<int> a){
	int lb[50][50];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) lb[i][j] = lab[i][j];
 	queue<pp> Q;
	for(int i=0;i<a.size();i++){
		lb[vir[a[i]].first][vir[a[i]].second] = -1;
		Q.push({vir[a[i]].first,vir[a[i]].second});
	}
	int ccnt = cnt;
	int time = 0;
	while(ccnt>0){
		int k = Q.size();
		if(!k){
			time = 2e9;
			break;
		}
		for(int i=0;i<k;i++){
			pp cur = Q.front();
			Q.pop();
			for(int j=0;j<4;j++){
				int nx = cur.first + X[j];
				int ny = cur.second + Y[j];
				if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
				if(lb[nx][ny] == 1 || lb[nx][ny] == -1) continue;
				if(lb[nx][ny] == 2){
					Q.push({nx,ny});
					lb[nx][ny] = -1;
				} 
				else{
					ccnt--;
					Q.push({nx,ny});
					lb[nx][ny] = -1;
				}
			}
		}
		time++;
	}
	return time;
}
void f(int v,int be){
	if(v == m){
		vector<int> a;
		for(int i=0;i<vcnt;i++)
			if(visit[i]) a.push_back(i);
		/*for(int i=0;i<vcnt;i++) cout << visit[i] << ' ';
			cout << endl;
		cout << cul(a) << endl;
*/
		
		res = min(res,cul(a));
		return;
	}
	for(int i=be+1;i<vcnt;i++){
		if(visit[i]) continue;
		visit[i] = 1;
		f(v+1,i);
		visit[i] = 0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m; 
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin >> lab[i][j];
			if(!lab[i][j]) cnt++;
			if(lab[i][j] == 2){
				vir.push_back({i,j}); 
				vcnt++;
			}
		}

	f(0,-1);
	if(res == 2e9) res = -1;
	cout << res;
}