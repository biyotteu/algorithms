#include <bits/stdc++.h>

using namespace std;

int f(int v){
	int ret = 0;
	while(v){
		ret += v%10;
		v/=10;
	}
	return ret;
}
int main(){
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		if(i + f(i) == n){
			cout << i;
			return 0;
		}
	}
	cout << "0";
}