#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<i-1;j++) cout << ' ';
		for(int j=0;j<2*(n-i+1)-1;j++) cout << '*';
		cout << "\n";
	}
	for(int i=n-1;i>=1;i--){
		for(int j=0;j<i-1;j++) cout << ' ';
		for(int j=0;j<2*(n-i+1)-1;j++) cout << '*';
		cout << "\n";
	}
}