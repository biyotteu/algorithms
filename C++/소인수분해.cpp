#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin >> n;
	m = n;
	for(int i=2;m != 1;i++){
		while(m%i == 0){
			m/=i;
			cout << i <<"\n";
		}
	}
}