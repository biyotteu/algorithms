#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pp;

bool cmp(pp a,pp b){
	if(a.first == b.first) return a.second < b.second;
	else return a.first > b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a) cin >> i;
	sort(a.begin(),a.end());
	cout << round(accumulate(a.begin(),a.end(),0)/(double)n) <<"\n";
	cout << a[n/2]<<"\n";
	vector<pair<int,int>> b;
	int last = a[0],cnt = 1,res,cc=0; 
	for(int i=1;i<n;i++){
		if(last != a[i]){
			b.push_back({cnt,last});
			cnt = 1;
			last = a[i];
		}else{
			cnt++;
		}
	}
	b.push_back({cnt,last});
	sort(b.begin(),b.end(),cmp);
	cout << (b.size() > 1 && b[0].first == b[1].first ? b[1].second : b[0].second) << "\n";
	cout << a[n-1] - a[0] << "\n"; 
}