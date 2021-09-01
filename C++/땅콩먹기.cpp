#include <bits/stdc++.h>

using namespace std;

int abs(int x){
	if(x<0) return -x;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m,e;
	cin >> n >> m >> e;
	vector<int> aa(m);
	for(int i=0;i<n;i++) cin >> aa[i];
	sort(aa.begin(),aa.end());
	int l = (int)(lower_bound(aa.begin(),aa.end(),e) - aa.begin()) - 1;
	int r = l+1;
	int ll,rr,res=0;
	ll = rr = e;
	while(m--){
		if(l < 0){
			res += abs(aa[r]-rr);
			rr = aa[r];
			r++;
		}else if(r >= n){
			res += abs(aa[l]-ll);
			ll = aa[l];
			l--;
		}else{
			if(abs(aa[l]-ll) < abs(aa[r]-rr)){
				res += abs(aa[l]-ll);
				ll = aa[l];
				l--;
			}else{
				res += abs(aa[r]-rr);
				rr = aa[r];
				r++;
			}
		}
	}
	cout << res;
}