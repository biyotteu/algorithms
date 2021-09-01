#include <bits/stdc++.h>

using namespace std;


int main(){
	int a =0 , b = 0, lastwin = 0,A[10],B[10];
	for(int i=0;i<10;i++) cin >> A[i];
	for(int i=0;i<10;i++) cin >> B[i];
	for(int i=0;i<10;i++){
		if(A[i] > B[i]) a+=3,lastwin = 1;
		else if(A[i] < B[i]) b+=3,lastwin = 2;
		else a++,b++;
	}
	cout << a << ' ' << b << '\n';
	if(a>b) cout << "A";
	else if(a<b) cout << "B";
	else{
		if(!lastwin) cout << 'D';
		else{
			if(lastwin == 1) cout << 'A';
			else cout << 'B';
		}
		return 0;
	}
}