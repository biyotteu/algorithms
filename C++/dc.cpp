#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<int> gr;
int diff(int v){
	int cnt=0;
	bool cmp = true;
	for(auto i:gr){
		if(cmp && i > v) cnt++,cmp = false;
		if(i <= v) cmp = true;
	}
	return cnt;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	gr.resize(n);
	for(int i=0;i<n;i++) cin >> gr[i];
	int l = 0, r = *max_element(gr.begin(),gr.end());
	for(int k=0;k<100;k++){
		int mid1 = (l*2+r)/3;
		int mid2 = (l+r*2)/3;
		res = max(res,diff(mid1));
		res = max(res,diff(mid1));
		if(diff(mid1) > diff(mid2)) r = mid2;
		else l = mid1;
	}
	cout << max(res,max(diff(l),diff(r)));
}