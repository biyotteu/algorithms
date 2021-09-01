#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		double n,sum = 0,cnt = 0;
		cin >> n;
		vector<double> a((int)n);
		for(auto &i:a){
			cin >> i;
			sum += i;
		} 
		sum /= n;
		for(auto i:a)
			if(i > sum) cnt+=1;
		cout << fixed;
		cout.precision(3);
		cout << (double)(cnt*100.0/n) << "%\n";
	}
}