#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,sum = 0,cnt = 0;
	cin >> a >> b >> c;
	while(sum < c){
		cnt++;
		if(cnt%7 == 0) sum+=b;
		sum+=a;
	}
	cout << cnt;
}