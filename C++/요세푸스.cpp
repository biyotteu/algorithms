#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,cnt=0;
	cin >> n >> k;
	queue<int> q;
	for(int i=1;i<=n;i++) q.push(i);
	cout << "<";
	while(!q.empty()){
		cnt++;
		if(cnt == k){
			cnt = 0;
			cout << q.front();
			if(q.size() != 1) cout << ", ";
		}else q.push(q.front());
		q.pop();
	}
	cout << ">";
}	