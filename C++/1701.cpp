#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	int res = 0;
	cin >> str;
	vector<int> pi(str.size());
	for(int k=0;k<str.size();k++){
		int j=0;
		for(int i=k+1;i<str.size();i++){
			while(j>0 && str[i]!=str[j+k]) j = pi[j-1];
			if(str[i] == str[j+k]) res = max(res,++j);
			pi[i-k] = j;
		}
	}
	cout << res;
}