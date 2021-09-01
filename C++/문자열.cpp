#include <bits/stdc++.h>

using namespace std;

int main(){
	string a,b;
	cin >> a >> b;
	int res = 50;
	for(int i=0;i<=b.size()-a.size();i++){
		int cmp = 0;
		for(int j=0;j<a.size();j++)
			if(a[j] != b[i+j]) cmp++;
		res = min(res,cmp);
	}
	cout << res;
}