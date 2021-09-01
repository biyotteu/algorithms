#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	long long Nam_Hyuk[100005],n,min_i = 16769023;
	Nam_Hyuk[1] = 2;
	cin >> n;
	for(int love = 2;love <=n; love++){
		if(love%2) Nam_Hyuk[love] = (Nam_Hyuk[love - 1]*2)%min_i;
		else Nam_Hyuk[love] = Nam_Hyuk[love-1];
	}
	cout << Nam_Hyuk[n];
}