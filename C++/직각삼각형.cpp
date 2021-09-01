#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	while(1){
		vector<int> a(3);
		for(int i=0;i<3;i++) cin >> a[i];
		if(accumulate(a.begin(),a.end(),0) == 0) break;
		sort(a.begin(),a.end());
		if(a[0]*a[0] + a[1]*a[1] == a[2]*a[2]) cout << "right\n";
		else cout << "wrong\n";
	}
}