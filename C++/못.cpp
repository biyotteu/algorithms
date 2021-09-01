#include <bits/stdc++.h>

using namespace std;

int n,m,tr[5005][5005],res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int a,b,x;
		cin >> a >> b >> x;
		tr[a][b] = x+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(j==1) tr[i][j] = max(tr[i][j],tr[i-1][j]-1);
			else if(j == i) tr[i][j] = max(tr[i][j],tr[i-1][j-1]-1);
			else tr[i][j] = max(tr[i][j],max(tr[i-1][j]-1,tr[i-1][j-1]-1));
			if(tr[i][j]) res++;
		}
	}
	cout << res;
}