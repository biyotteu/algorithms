#include <bits/stdc++.h>

using namespace std;

int main()
{
	string a;
	cin >> a;
	char last = 'a';
	int sum = 0;
	for(int i=0;i<a.size();i++){
		if(last!=a[i]){ 
			sum+=10;
			last = a[i];
		}
		else sum+=5;
	}
	cout << sum;
}
