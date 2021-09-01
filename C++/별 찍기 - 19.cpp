#include <bits/stdc++.h>

using namespace std;

int p[500][500];

int main(){
	int n;
	cin >> n;
	int v = 1;
	for(int i=n;i>0;i--){
		for(int j=v;j<=v+4*(i-1);j++) p[j][v] = p[j][v+4*(i-1)] = p[v+4*(i-1)][j] = p[v][j] =1;
		v+=2;
	}
	for(int i=1;i<=4*(n-1)+1;i++){
		for(int j=1;j<=4*(n-1)+1;j++) cout << (p[i][j] ? "*":" ");
		cout << "\n";
	}
}