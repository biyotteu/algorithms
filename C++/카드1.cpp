#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	deque<int> q;
	for(int i=1;i<=n;i++) q.push_back(i);
	while(!q.empty()){
		cout << q.front() << ' ';
		q.pop_front();
		if(q.empty()) break;
		q.push_back(q.front());
		q.pop_front();
	}
}