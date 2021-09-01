#include <bits/stdc++.h>

using namespace std;

int n,res,Q[16];
void f(int v){
	if(v > n){
		res++;
		return;
	}
	for(int i=1;i<=n;i++){
		int cmp = 0;
		for(int j=1;j<v;j++){
			if(Q[j] == i || i - Q[j] == v - j || Q[j] - i == v - j){
				cmp = 1;
				break;
			}
		}
		if(cmp) continue;
		Q[v] = i;
		f(v+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	f(1);
	cout << res;
}