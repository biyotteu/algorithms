#include <bits/stdc++.h>

using namespace std;

struct info{
	int x;
	bool operator<(info A)const{
		return x > A.x;
	}
};
int main(){
	priority_queue<info> Q;
	Q.push({1});
	Q.push({2});
	Q.push({3});
	Q.push({4});
	Q.push({5});
	Q.push({6});
	Q.push({7});
	while(!Q.empty()){
		cout << Q.top().x << endl;
		Q.pop();
	}
}