#include <bits/stdc++.h>

using namespace std;

int n,cnt;
queue<long long int> Q;
int main(){
	std::ios::sync_with_stdio(false);
	cin >> n;
	if(!n){ 
		cout << 0;
		return 0;
	}
	for(int i=1;i<=9;i++) Q.push(i);
	while(!Q.empty()){
		long long int v = Q.front();
		Q.pop();
		cnt++;
		if(cnt == n){
			cout << v;
			return 0;
		}
		for(int i=0;i<v%10;i++){
			Q.push(v*10+i);
		}
	}
	cout << -1;
}