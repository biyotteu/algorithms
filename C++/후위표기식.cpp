#include <bits/stdc++>

using namespace std;

string str;
bool isc(char a){
	if(a == '+' || a == '-' || a == '*' || a == '/') return true;
	else return false;
}
string f(int x,int y){
	int cnt = 0,l = 0;
	for(int i=x;i<y;i++){
		if(!cnt && isc(str[i])){
			res.append(f(l,i));
			l = i+1;
		}else l++;
	}
}
int main(){
	cin >> str;
	string res;
	cout << f(0,str.size());
}