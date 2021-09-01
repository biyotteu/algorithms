#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a=0,b=0;
	for(int i=2;i<=n;i++){
		int x = i;
		while(!(x%2) || !(x%5)){
			if(!(x%2)){
				x/=2;
				a++;
			}
			if(!(x%5)){
				x/=5;
				b++;
			}
		}
	}
	cout << min(a,b);	
}