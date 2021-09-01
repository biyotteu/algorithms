#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	sort(str.rbegin(),str.rend());
	for(auto i:str) cout << i;
}