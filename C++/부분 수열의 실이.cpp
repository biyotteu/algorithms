#include <bits/stdc++.h>
#define INF (1<<29)
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		int n,x,res = INF;
		long long int sum = 0;
		vector<int> num;
		deque<int> Q;
		cin >> n >> x;
		num.resize(n);
		for(int i=0;i<n;i++) cin >> num[i];
		for(int i=0;i<n;i++){
			sum += num[i];
			Q.push_back(num[i]);
			while(Q.size()>=2 && (sum - Q.front() >= x)){
				sum -= Q.front();
				Q.pop_front();
			}
			if(sum >= x) res = min(res,(int)Q.size());
		}
		if(sum >= x) res = min(res,(int)Q.size());
		if(res == INF || res == 0) cout << "-1\n";
		else cout << res << "\n";
	}
}