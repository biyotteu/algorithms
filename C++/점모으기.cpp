#include <bits/stdc++.h>

using namespace std;

int n,m,res;
vector<int> X,Y;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		X.push_back(x);
		Y.push_back(y);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for(int i=0;i<m;i++) res += (int)abs(X[i] - X[m/2]) + (int)abs(Y[i] - Y[m/2]);
	printf("%d",res);
}