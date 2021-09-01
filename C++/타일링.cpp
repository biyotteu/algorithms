#include <bits/stdc++.h>

using namespace std;

string dp[255];
string sum(string a,string b){
    int sum = 0;
	string res;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) sum += a.back() - '0', a.pop_back();
		if (!b.empty()) sum += b.back() - '0', b.pop_back();
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	dp[1] = "1";
	dp[2] = "2";
	for(int i=3;i<=250;i++) dp[i] = sum(dp[i-1],dp[i-2]);
	while(cin >> n) cout << dp[n] << "\n";
}