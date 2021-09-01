#include <bits/stdc++.h>

using namespace std;

int ch[30000];
int num(int v){
	if(!v) return 0;
	return v%10+num(v/10);
}
int main()
{
	for(int i=1;i<=10000;i++) ch[i+num(i)]=1;
	for(int i=1;i<=10000;i++)
		if(ch[i]==0) cout << i << endl;
	
}