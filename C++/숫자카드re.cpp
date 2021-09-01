#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<int> A(101,0),B(101,0);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while(n--){
		int x,y;
		res = 0;
		cin >> x >> y;
		A[x]++;
		B[y]++;
		vector<int> a = A;
		vector<int> b = B;
		int l = 1, r= 100;
		while(l<=100 && r >= 1){
			while(!a[l]) l++;
			while(!b[r]) r--;
			if(l > 100 || r < 0) break;
			int ret = min(a[l],b[r]);
			a[l] -= ret;
			b[r] -= ret;
			res = max(l+r,res);
		}
		cout << res <<"\n";
	}
}