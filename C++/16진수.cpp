#include <bits/stdc++.h> 

using namespace std;

map<char,int> d;
int main(){
	string str;
	cin >> str;
	for(char i='0';i<='9';i++) d[i] = (i-'0');
	for(char i='A';i<='F';i++) d[i] = (i-'A'+10);
	int a = 1;
	int res = 0;
	for(int i=str.size()-1;i>=0;i--){
		res += a*d[str[i]];
		a *= 16;
	}
	cout << res;
}