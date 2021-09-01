#include <bits/stdc++.h>

using namespace std;

long long n,pa[1050][1050];
int main(){
	cin >> n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin >> pa[i][j];
		}
	int x = n/2, y = n/2,ho = n,ve = n;
	while(x || y){
		for(int j=1;j<=ve;j++){
			for(int i=1;i<=x;i++){
				pa[j][i]+=pa[j][ho+1-i];
			}
		}
		ho/=2,x/=2;
		for(int j=1;j<=ho;j++){
			for(int i=1;i<=y;i++){
				pa[i][j]+=pa[ve+1-i][j];
			}
		}
		ve/=2,y/=2;
	}
	cout << pa[1][1];
}