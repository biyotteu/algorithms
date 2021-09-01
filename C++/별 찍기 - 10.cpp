#include <bits/stdc++.h>

using namespace std;

char st[3000][3000];
void f(int n,int x,int y){
	if(n==1){
		st[x][y] = '*';
		return;
	}
	int tmp = n/3;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i == 1 && j == 1) continue;
			f(tmp,x+tmp*i,y+tmp*j);
		}
	}
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) st[i][j] = ' ';
	}
	f(n,1,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout << st[i][j];
		cout << "\n";
	}
}