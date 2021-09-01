#include <bits/stdc++.h>

using namespace std;

int n,m;
long long int res,cnt1[205],cnt2[205][205];	
int graph[205][205];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	for(int p=1;p<=n;p++){
		for(int i=p+1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				if(graph[p][i] && graph[p][j] && graph[i][j]){
					cnt1[i]++,cnt1[j]++,cnt1[p]++;
					cnt2[p][j]++,cnt2[p][i]++,cnt2[i][j]++;
				}
			}
	}
	for(int i=1;i<=n;i++){
		if(cnt1[i]<2) continue;
		res += cnt1[i]*(cnt1[i]-1)/2;
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			if(cnt2[i][j]<2) continue; 
			res -= cnt2[i][j]*(cnt2[i][j]-1);
		}
	cout << res;
}