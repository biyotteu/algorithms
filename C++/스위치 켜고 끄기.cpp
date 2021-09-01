#include <bits/stdc++.h>

using namespace std;

int n,swt[105],m;
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> swt[i];
	cin >> m;
	while(m--){
		int x,y;
		cin >> x >> y;
		if(x == 1)	for(int i=y;i<=n;i+=y) swt[i]^=1;
		else{
			int i;
			for(i=1;;i++) if(y-i < 1 || y+i > n || swt[y-i] != swt[y+i]) break;
			i--;
			swt[y]^=1;
			for(int j=1;j<=i;j++) swt[y-j]^=1, swt[y+j]^=1;
		}
	}
	for(int i=1;i<=n;i++){
		cout << swt[i] << ' ';
		if(i%20 == 0) cout << "\n";	
	} 
}