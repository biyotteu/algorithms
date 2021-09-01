#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		long long x,y,dist;
		cin >> x >> y;
		dist = y-x;
		for(long long i=1;;i++){
			if((i%2) && (i*i-1)/4 < dist && dist <= (i+1)*(i+1)/4){
				cout << i << "\n";
				break;
			}
			if(!(i%2) && (i*i)/4 < dist && dist <= i/2*(i/2+1)){
				cout << i << "\n";
				break;
			}
		}
	}
}