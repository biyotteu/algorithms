#include <bits/stdc++.h>

using namespace std;

int n,res=(1<<29),visit[15],w[15][15];
void f(int v,int start,int cnt,int sum){
	if(v == start && cnt == n){
		res = min(sum,res);
		return;
	}
	for(int i=0;i<n;i++){
		if(!visit[i] && w[v][i]){
			visit[i] = 1;
			f(i,start,cnt+1,sum+w[v][i]);
			visit[i] = 0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin >> w[i][j];
	for(int i=0;i<n;i++) f(i,i,0,0);
	cout << res;
}