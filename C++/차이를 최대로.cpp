#include <bits/stdc++.h>

using namespace std;

int d[10],a[10],n,visit[10];
int res;
void f(int v){
	if(v == n+1){
		int sum = 0;
		for(int i=1;i<n;i++) sum += (int)abs(d[i]-d[i+1]);
		res = max(res,sum);
		return;
	}
	for(int i=1;i<=n;i++){
		if(visit[i]) continue;
		visit[i] = 1;
		d[v] = a[i];
		f(v+1);
		visit[i] = 0;
	}
	return;
}
int main(){
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	f(1);
	cout << res;
}