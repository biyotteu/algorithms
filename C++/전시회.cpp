#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n;
vector<pair<ll,ll>> art;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i=0;i<n;i++){
		long long a,b;
		cin >> a >> b;
		art.push_back({a,b});
	}
	sort(art.begin(),art.end());
	int l=0,r=0;
	ll s = art[0].second,res = 0;
	while(r<n-1){
		r++;
		s += art[r].second;
		if(s - art[r].first + art[l].first < art[r].second){
			l = r;
			s = art[r].second;
		}
		res = max(res,s - art[r].first + art[l].first);
	}
	cout << res;
}