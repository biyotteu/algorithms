#include <bits/stdc++.h>

using namespace std;

int n,b,c;
long long res;
vector<int> st,p;
int f(int a,int b){
	return a/b + (a%b != 0);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	st.resize(n);
	for(auto &i:st) cin >> i;
	cin >> b >> c;
	for(auto i:st) res += f(max(0,i-b),c) + 1;
	cout << res;
}