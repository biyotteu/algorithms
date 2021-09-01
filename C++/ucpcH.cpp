#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int one=0,two=0,a;
	while(n--){
		int x;
		cin >> x;
		if(x%2 == 0) a++; 
		if(x%3 == 1) one++;
		else if(x%3 == 2) two++;
	}
	if(abs(two - one)%3==0) cout << "YES";
	else cout << "NO";

}