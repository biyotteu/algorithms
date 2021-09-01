#include <bits/stdc++.h>

using namespace std;

int size;
int n,mp[50][50];
int get_max(int x,int y,int x1,int y1){
	int cur = 0;
	for(int i=x;i<=x1;i++){
		for(int j=y;j<=y1;j++) cur = max(cur,mp[i][j]);
	}
	return cur;
}
int res(int x1,int y1,int x2,int y2){

	if(x1 == x2 && y2-y1 == 1) return max(mp[x1][y1],mp[x1][y2]);
	if(x1 - x2 == 1 && y2 == y1) return max(mp[x1][y1],mp[x2][y2]);
	int cur = 0;
	if(x1 != x2){
		cur = max(cur,res(x1,y1,(x1+x2)/2,y2) + get_max((x1+x2)/2+1,y1,x2,y2));
		cur = max(cur,res((x1+x2)/2+1,y1,x2,y2) + get_max(x1,y1,(x1+x2)/2,y2));
	}
	if(y2 != y1){
		cur = max(cur,res(x1,y1,x2,(y1+y2)/2) + get_max(x1,(y1+y2)/2+1,x2,y2));
		cur = max(cur,res(x1,(y1+y2)/2+1,x2,y2) + get_max(x1,y1,x2,(y1+y2)/2));
	}
	return cur;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;
			cin >> x;
			mp[i][j] = x;
		}
	}
	cout << res(1,1,n,n);
}