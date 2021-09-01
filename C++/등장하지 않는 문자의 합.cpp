#include <bits/stdc++.h>

using namespace std;

int al[26];
int main(){
	int n,m=0;
	for(int i = 'A';i<='Z';i++) m+=i;
	cin >> n;
	while(n--){
		memset(al,0,sizeof(al));
		string str;
		cin >> str;
		int res = 0;
		for(auto i:str){
			if(al[i-'A']) continue;
			al[i-'A'] = 1;
			res += i;
		}
		cout << m - res << '\n';
	}
}