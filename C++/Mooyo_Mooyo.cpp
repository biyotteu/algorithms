#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int n,k,X[4]={1,0,-1,0},Y[4]={0,1,0,-1},visit[105][15],tmp[105][15];
vector<pair<int,int> > ch;
int moo[105][15];
void f(int x,int y,int co){
	visit[x][y] = 1;
	ch.push_back({x,y});
	for(int i=0;i<4;i++){
		int nx = x + X[i];
		int ny = y + Y[i];
		if(nx < 1 || ny < 1 || nx > n || ny > 10) continue;
		if(visit[nx][ny] || co != moo[nx][ny]) continue;
		f(nx,ny,co);
	}
}
int main(){
	ifstream ifn("mooyomooyo.in");
	ofstream ofn("mooyomooyo.out");
	ifn >> n >> k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			char x;
			ifn >> x;
			moo[i][j] = (x-48);
		}
	}
	while(1){
		memset(visit,0,sizeof(visit));
		memset(tmp,0,sizeof(tmp));

		int cmp = 0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=10;j++){
				if(visit[i][j] || !moo[i][j]) continue;
				ch.clear();
				f(i,j,moo[i][j]);
				if(ch.size()>=k){
					cmp = 1;
					for(int q=0;q<ch.size();q++){
						tmp[ch[q].first][ch[q].second] = -1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=10;j++)
				if(tmp[i][j] == -1) moo[i][j] = 0;
		memset(tmp,0,sizeof(tmp));
		for(int i=1;i<=10;i++){
			int start = n;
			for(int j=n;j>=1;j--) 
				if(moo[j][i]) tmp[start--][i] = moo[j][i];
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=10;j++){
				moo[i][j] = tmp[i][j];
			}
		}
		if(!cmp) break;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=10;j++){
			ofn << moo[i][j];
		}
		ofn << endl;
	}
	ifn.close();
	ofn.close();
	return 0;
}