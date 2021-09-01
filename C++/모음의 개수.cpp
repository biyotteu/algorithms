#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	int cnt = 0;
	for(auto i:str)
		if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') cnt++;
	cout << cnt;
}