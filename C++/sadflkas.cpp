#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int res = 0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++) res++;
	cout << res*5000;
}