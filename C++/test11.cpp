#include <bits/stdc++.h>

using namespace std;

int a[10000000],cnt,n,v=1;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	while(++v){
		if(a[v]) continue;
		cnt++;
		if(cnt == n){
			cout << v;
			return 0;
		}
		for(int i=v;i<10000000;i+=v) a[i] = 1;
	}
}