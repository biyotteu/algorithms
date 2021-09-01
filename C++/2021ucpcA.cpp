#include <bits/stdc++.h>

using namespace std;

int main(){
	string str;
	cin >> str;
	int a,b,cmp = 0;
	a = b= 0;
	a = atoi(str.substr(0,1).c_str());
	int cnt = 1;
	for(int i=1;i<str.size();i+=cnt){
		if(a+1 == 10 || a+1 == 100) cnt++;
		if(a+1 == atoi(str.substr(i,cnt).c_str())) a++;
		else{
			cmp = 1;
			break;
		}
	}
	if(!cmp){
		cout << str[0] << ' ' << str.substr(str.size()-cnt,cnt);
		return 0;
	}
	int start;
	cmp = 0;
	a = start = atoi(str.substr(0,2).c_str());
	cnt = 2;
	for(int i=cnt;i<str.size();i+=cnt){
		if(a+1 == 100) cnt++;
		if(a+1 == atoi(str.substr(i,cnt).c_str())) a++;
		else{
			cmp = 1;
			break;
		}
	}
	if(!cmp){
		cout << start << ' ' << str.substr(str.size()-cnt,cnt);
		return 0;
	}
	cmp = 0;
	a = start = atoi(str.substr(0,3).c_str());
	cnt = 3;
	for(int i=cnt;i<str.size();i+=cnt){
		if(a+1 == atoi(str.substr(i,cnt).c_str())) a++;
		else{
			cmp = 1;
			break;
		}
	}
	if(!cmp){
		cout << start << ' ' << str.substr(str.size()-cnt,cnt);
		return 0;
	}

	//cout << str;
}