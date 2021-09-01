#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<char> str;
vector<int> ch;
void f(int i,int a,int b,int len,string s){
	if(len==n){
        if(a<1 || b<2) return;
        cout << s << endl;
        return;
	}
	if(i>=m) return;
	int k;
	if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u') f(i+1,a+1,b,len+1,s+str[i]);
	else f(i+1,a,b+1,len+1,s+str[i]);
	f(i+1,a,b,len,s);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		char c;
		cin >> c;
		str.push_back(c);
	}
	sort(str.begin(),str.end());
	f(0,0,0,0,"");
}
