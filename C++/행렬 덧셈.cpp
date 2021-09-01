#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int Nam,Hyuk;
	cin >> Nam >> Hyuk;
	int min[Nam][Hyuk];
	for(int i=0;i<Nam;i++)
		for(int j=0;j<Hyuk;j++) cin >> min[i][j];
	for(int i=0;i<Nam;i++){
		for(int j=0;j<Hyuk;j++){
			int x;
			cin >> x;
			cout << min[i][j] + x << ' ';
		}	
		cout << "\n";
	}
}