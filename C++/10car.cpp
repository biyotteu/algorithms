#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n,cnt=0;
	cin >> n;
	for(int i=0;i<5;i++){
		int x;
		cin >> x;
		if(n%10 == x%10) cnt++;
	}
	cout << cnt;
}