#include <bits/stdc++.h>

using namespace std;

vector<string> str;
unsigned int n;
int main(){
	for(int i=0;i<5;i++){
		string x;
		cin >> x;
		str.push_back(x);
		if(n < (int)x.length()) n = (int)x.length();
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			if(str[j].size() < i+1) continue;
			cout<< str[j][i];
		}
	}
}