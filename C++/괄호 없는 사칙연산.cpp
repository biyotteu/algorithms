#include <bits/stdc++.h>

using namespace std;

int f(int x,int y,char o){
	if(o == '+') return x+y;
	else if(o == '-') return x-y;
	else if(o == '*') return x*y;
	else return x/y;
}
int main(){
	int a,b,c;
	char d1,d2;
	cin >> a >> d1 >> b >> d2 >> c;
	int X = f(a,f(b,c,d2),d1);
	int Y = f(f(a,b,d1),c,d2);
	cout <<min(X,Y)<<"\n"<<max(X,Y);
}