#include <bits/stdc++.h>

using namespace std;

int n,num[31],idx;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		while(num[idx]) idx = (idx+1)%n;
		num[idx] = x;
		idx = (idx+x)%n; 
	}
	cout << n << '\n' ;
	for(int i=0;i<n;i++) cout << num[i]<<' ';
}