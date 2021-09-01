#include <bits/stdc++.h>

using namespace std;

vector<int> bu(10,0);
bool diff(int x){
	do{
		if(bu[x%10]) return false;
		x/=10;
	}while(x);
	return true;
}
int cul(int x){
	int cnt = 0;
	do{
		x/=10;
		cnt++;
	}while(x);
	return cnt;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x;
		cin >> x;
		bu[x]++;
	}
	int res = abs(n-100);
	for(int i=0;i<=1000000;i++)
		if(diff(i)) res = min(res,abs(n-i) + cul(i));
	cout << res;
}