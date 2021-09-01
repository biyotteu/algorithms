#include <bits/stdc++.h>

using namespace std;

map<string,pair<long long int,long long int>> A;
int main(){
	A["black"] = make_pair(0,1);
	A["brown"] = make_pair(1,10);
	A["red"] = make_pair(2,100);
	A["orange"] = make_pair(3,1000);
	A["yellow"] = make_pair(4,10000);
	A["green"] = make_pair(5,100000);
	A["blue"] = make_pair(6,1000000);
	A["violet"] = make_pair(7,10000000);
	A["grey"] = make_pair(8,100000000);
	A["white"] = make_pair(9,1000000000);
	string a,b,c;
	cin >> a >> b >> c;
	cout << (A[a].first*10+A[b].first)*A[c].second;

}