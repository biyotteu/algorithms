#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	set<int> num;
	long long int sum = 0;
	int n,m;
	cin >> n >> m;
	while(n--){
		int x;
		cin >> x;
		sum += x;
		num.insert(x);
	}
	while(m--){
		int x;
		cin >> x;
		if(num.find(x) == num.end()) sum+=x;
		else sum -= x;
	}
}