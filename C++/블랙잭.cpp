#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,res = -1;
	cin >> n >> m;
	vector<int> cd(n);
	for(int i=0;i<n;i++) cin >> cd[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++){
				if(i == k || k == j || i == j) continue;
				int ret = cd[i] + cd[j] + cd[k];
				if(ret <= m &&(res == -1 || res < ret)) res = ret;
			}
	cout << res;
}