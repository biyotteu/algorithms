#include <bits/stdc++.h>

using namespace std;

string str[1005];
int main()
{
	int T;
	cin >> T;
	for(int t=1;t<=T;t++){
		cout << '#' << t << ' ';
		int n;
		cin >> n;
		for(int i=1;i<=n;i++) cin >> str[i];
		int x=1,y=(n+1)/2+1;
		for(int i=1;i<=n;i++){
			if(i%2) cout << str[x++];
			else cout << str[y++];
			cout << ' ';
		}
		cout << endl;
	}
}