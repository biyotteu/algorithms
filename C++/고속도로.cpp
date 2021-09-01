#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(1){
		A.clear(),B.clear();
		cin >> n;
		if(n == 0) return 0;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			A.push_back(x);
		}
		cin >> m;
		for(int i=0;i<m;i++){
			int x;
			cin >> x;
			B.push_back(x);
		}
		int x = 0, y= 0;
		long long res = 0,a =0 , b=0;
		while(1){
			//cout << x << ' ' << y << endl;
			if(x >= n && y>=m) break;
			if(A[x] == B[y]){
				res += max(a,b);
				res += A[x];
				x++,y++;
				a = 0 , b = 0;
				continue;
			}
			if(x >= n || (A[x] > B[y]) && y<m){
				b += B[y];
				y++;
				continue;
			}
			if(y >= m || (A[x] < B[y]) && x<n){
				a += A[x];
				x++;
				continue;
			}
		}
		cout << max(res + a,res + b) << '\n';
	}
}