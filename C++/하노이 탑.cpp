#include <bits/stdc++.h>

using namespace std;

int n;
void f(int n,int st,int en,int path){
	if(n == 1){
		cout << st << ' ' << en << "\n";
		return;
	}
	f(n-1,st,path,en);
	cout << st << ' ' << en << "\n";
	f(n-1,path,en,st);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin >> n;
	cout << ((1<<n) - 1) <<"\n";
	f(n,1,3,2);
}