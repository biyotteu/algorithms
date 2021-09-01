#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	vector<int> num;
	int sum = 0,cmp = 0;
	cin >> str;
	for(auto i:str){
		if(i == '0') cmp = 1;
		sum += (i-48);
		num.push_back(i-48);
	}
	if(cmp == 0 || (sum%3 != 0)) puts("-1");
	else{
		sort(num.rbegin(),num.rend());
		for(auto i:num) printf("%d",i);
	}
}