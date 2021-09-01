#include <bits/stdc++.h>

using namespace std;

int n,k,c,color[40][40],cnt,visit[40][40];
vector<int> gr[1000];
int dist(int x,int y,int x1,int y1){
	return (x-x1)*(x-x1) + (y-y1)*(y-y1);
}
int f(int x,int y,int sum){
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++){
			if(visit[i][j] && dist(x,y,i,j) < c*c) return 0;
		}
		if(sum == n){
		cout << x << ' ' << y << endl;
		return 1;
	}
	visit[x][y] = 1;
	for(int i=0;i<k;i++)
		for(int j=0;j<k;j++){
			if(visit[i][j] == 0 && dist(x,y,i,j) >= c*c){
				if(f(i,j,sum+1)){
					cout << x << ' ' << y << endl;
					return 1;
				}
			}
		}
	visit[x][y] = 0;
	return 0;
	
}
int main(){
	cin >> n >> k >> c;
	f(0,0,1);
}