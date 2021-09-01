#include <bits/stdc++.h>

using namespace std;

int main(){
	map<string,int> book;
	set<string> s;
	int n;
	cin >> n;
	while(n--){
		string str;
		cin >> str;
		book[str]++;
		s.insert(str);
	}
	string res;
	int cnt = 0;
	for(auto i:s){
		if(cnt < book[i]){
			res = i;
			cnt = book[i];
		}
	}
	cout << res;
}