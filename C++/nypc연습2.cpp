#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,res=0;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			string x;
			cin >> x;
			if(!x.compare("NEXON")) res++;
		}
	}
	cout << res;
}