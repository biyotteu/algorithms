#include <bits/stdc++.h>

using namespace std;

int dp[25][25][25];
int w(int a,int b,int c){
	if(a <= 0 || b <= 0 || c <= 0) return 1;
	if(a > 20 || b > 20 || c > 20) return w(20, 20, 20);
	int &ret = dp[a][b][c];
	if(ret) return ret;
	if(a < b && b < c) return  ret = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
	else return ret = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		int a,b,c;
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1) return 0;
		cout << "w("<<a << ", " << b << ", " << c <<") = "<<w(a,b,c) << "\n";
	}
}