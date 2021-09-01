#include <bits/stdc++.h>

using namespace std;

int n,m,res = (1<<29),cnt;
vector<int> A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int x;
		cin >> x;
		A.push_back(x);
	}
	cin >> m;
	for(int i=1;i<=m;i++){
		int x;
		cin >> x;
		B.push_back(x);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	int x=0,y=0;
	res = abs(A[x]-B[y]);
	while(1){
		if(x == n-1 && y == m-1) break;
		if(x == n-1){
			y++;
			int k = abs(A[x]-B[y]);
			if(res == k) cnt++;
			else if(res > k) res = k, cnt = 1;
			continue;
		}
		if(y == m-1){
			x++;
			int k = abs(A[x]-B[y]);
			if(res == k) cnt++;
			else if(res > k) res = k, cnt = 1;
			continue;
		}
		if(abs(A[x+1]-B[y]) < abs(A[x]-B[y+1])) x++;
		else y++;
		int k = abs(A[x]-B[y]);
		if(res == k) cnt++;
		else if(res > k) res = k, cnt = 1;
			
	}
	cout << cnt;
}