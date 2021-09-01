#include <bits/stdc++.h>

using namespace std;

int n,mm,st,res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> st;
	mm = st;
	n--;
	while(n--){
		int x;
		cin >> x;
		if(mm < x){
			mm = x;
			res = max(mm-st,res);
		}else{
			st = x;
			mm = x;
		}
	}
	res = max(res,mm-st);
	cout << res;
}