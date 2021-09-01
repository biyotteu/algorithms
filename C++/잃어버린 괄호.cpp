#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	int size = str.size();
	int num = 0,cmp = 0,res = 0;
	for(int i=0;i<size;i++){
		if(str[i] == '-'){
			if(cmp) res -= num;
			else res += num;
			cmp = 1;
			num = 0;
		}
		else if(str[i] == '+'){
			if(cmp) res -= num;
			else res += num;
			num = 0;
		}
		else{
			num*=10;
			num += (str[i] - '0');
		}
	}
	if(cmp) res -= num;
	else res += num;
	cout << res;
}