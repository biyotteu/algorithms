#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cout << i;
		if(!(i%m)) cout << "\n";
		else cout << " ";
	}
}