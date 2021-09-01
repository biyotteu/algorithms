#include <bits/stdc++.h>

using namespace std;

int n,k,J,singer[100005];
vector<int> tree[100005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k >> J;
	for(int i=2;i<=n;i++){
		int x;
		cin >> x;
		tree[i].push_back(x);
	}
	for(int i=1;i<=n;i++) cin >> singer[i];
}