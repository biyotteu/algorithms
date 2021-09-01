#include <bits/stdc++.h>

using namespace std;

int a[9],b[9],A,B;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=0;i<9;i++) cin >> a[i];
	for(int i=0;i<9;i++){
		A += a[i];
		if(A > B){
			printf("Yes");
			return 0;
		}
		cin >> b[i];
		B += b[i];
	}
	printf("No");
}