#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	set<int> S;
	while(k--){
		int x;
		cin >> x;
		S.insert(x);
	}
	int res = m;
	while(m--){
		int x,cmp = 0;
		cin >> x;
		while(x--){
			int y;
			cin >> y;
			if(S.find(y)!=S.end()) cmp = 1;
		}
		res -= cmp;
	}
	cout << res;
}