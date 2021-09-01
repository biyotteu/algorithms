#include <bits/stdc++.h>

using namespace std;

int n,k;
long long res;
map<int,int> M;
vector<int> num;
void f(int v,int sum){
	if(v == (n+1)/2){
		M[sum]++;
		return;
	}
	f(v+1,sum+num[v]);
	f(v+1,sum);
}
void g(int v,int sum){
	if(v == n){
		if(M.find(k-sum) != M.end())
			res += M[k-sum];
		return;
	}
	g(v+1,sum+num[v]);
	g(v+1,sum);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		num.push_back(x);
	}
	if(n == 1){
		if(num[0] == k) cout << '1';
		else cout << '0';
		return 0;
	}
	f(0,0);
	g((n+1)/2,0);
	if(!k) res--;
	cout << res;
}