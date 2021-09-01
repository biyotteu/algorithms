#include <bits/stdc++.h>

using namespace std;

int d[10000005],res;
vector<int> a;
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		a.push_back(x);
		d[x]++;
	}
	for(auto i:a){
		if(d[i] && i < m && d[m-i]){
			if(i == m-i && d[i] < 2) continue;
			d[i]--,d[m-i]--;
			res++;
		}
	}
	cout << res;
}