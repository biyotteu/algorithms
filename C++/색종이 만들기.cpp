#include <bits/stdc++.h>

using namespace std;

int n,c[130][130],resw,resc;
pair<int,int> f(int x ,int y, int len){
	if(len == 1)
		if(c[x][y]) return make_pair(0,1);
		else return make_pair(1,0);
	for(int i=x;i<x+len;i++)
		for(int j=y;j<y+len;j++){
			if(c[i][j] != c[x][y]){
				pair<int,int> cur;
				cur.first = f(x,y,len/2).first+f(x+len/2,y,len/2).first+f(x,y+len/2,len/2).first+f(x+len/2,y+len/2,len/2).first;
				cur.second = f(x,y,len/2).second+f(x+len/2,y,len/2).second+f(x,y+len/2,len/2).second+f(x+len/2,y+len/2,len/2).second;
				return cur;

			}
		}
	if(c[x][y]) return make_pair(0,1);
	else return make_pair(1,0);
	
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++) cin >> c[i+1][j+1];
	pair<int,int> res = f(1,1,n);
	cout << res.first << "\n" << res.second;
}