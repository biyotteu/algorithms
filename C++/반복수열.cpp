#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m;
	vector<int> a;
	cin >> n >> m;
	set<int> s;
	int sum;
	while(1){
		sum = 0;
		s.insert(n);
		a.push_back(n);
		while(n){
			int tmp = 1;
			for(int i=0;i<m;i++)
				tmp *= n%10;
			sum += tmp;
			n/=10;
		}
		if(s.find(sum) != s.end()) break;
		n = sum;
	}
	int cnt = 0;
	for(int i:a){
		if(i == sum) break;
		cnt++;
	}
	cout << cnt;
}