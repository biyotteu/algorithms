#include <bits/stdc++.h>

using namespace std;

int main(){
	while(1){
		long long a,b;
		cin >> a >> b;
		if(a == 0 && b == 0) return 0;
		if(a<b) swap(a,b);
		unsigned long long res = 1;
		long long k = 2;
		for(long long i = a+b;i>a;i--){
			res*=i;
			if(k<=b && res%k == 0) res/=k++;
		}
		cout << res << "\n";
	}
}