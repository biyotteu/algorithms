#include <bits/stdc++.h>

using namespace std;

int n,q1,q2,q3,q4,axis;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	while(n--){
		int x,y;
		cin >> x >> y;
		if(x > 0 && y > 0) q1++;
		if(x < 0 && y < 0) q3++;
		if(x > 0 && y < 0) q4++;
		if(x < 0 && y > 0) q2++;
		if(x == 0 || y == 0) axis++;
	}
	cout << "Q1: " << q1 << "\n";
	cout << "Q2: " << q2 << "\n";
	cout << "Q3: " << q3 << "\n";
	cout << "Q4: " << q4 << "\n";
	cout << "AXIS: " << axis << "\n";
}