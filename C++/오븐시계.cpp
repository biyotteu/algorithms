#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h,m;
	cin >> h >> m;
	int v;
	cin >> v;
	h+=v/60;
	m+=v%60;
	if(m>=60){
		h++;
		m-=60;
	}
	if(h>=24){
		h-=24;
	}
	cout << h << ' '<< m;
}
