#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,a,b;
	a = b = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		if(x) a++;
		else b++;
	}
	if(a > b) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
}