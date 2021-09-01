#include <bits/stdc++.h>

using namespace std;

int n,s,dp[50];
long long res;
map<int,int> num;
void f(int v,int sum){
	if(n/2 == v) {num[s-sum]++;return;}
	f(v+1,sum);
	f(v+1,sum+dp[v]);
}
void g(int v,int sum){
	if(n == v) {res += num[sum];return;}
	g(v+1,sum);
	g(v+1,sum+dp[v]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for(int i=0;i<n;i++) cin >> dp[i];
	f(0,0);
	g(n/2,0);
	if(s == 0) res--;
	cout << res;
}