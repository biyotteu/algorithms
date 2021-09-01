#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> vil;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	double n,xsum=0,ysum=0;
	cin >> n;
	for(int i=0;i<n;i++){
		double x,y;
		cin >> x >> y;
		xsum+=(double)x/n;
		ysum+=(double)y/n;
	}
	cout << (double)xsum << ' ' << (double)ysum;
}