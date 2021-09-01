#include <bits/stdc++.h>

using namespace std;

int visit[1005],res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<pair<int,int>> work;
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		work.push_back({y,x});
	}
	sort(work.rbegin(),work.rend());
	for(auto i:work){
		for(int j=i.second;j>=1;j--){
			if(!visit[j]){
				res += i.first;
				visit[j] = 1;
				break;
			}
		}
	}
	cout << res;
}