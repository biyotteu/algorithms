#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int n,m,c,res;
vector<int> cow;
int diff(int v){
	int start = cow[0],cnt = 1,ret = 1;
	for(int i=1;i<n;i++){
		if(cow[i]-start<=v && cnt < c){
			cnt++;
		}else{
			start = cow[i];
			cnt=1;
			ret++;
		}
	}
	return ret;
}
int main(){
	ifstream ifn("convention.in");
	ofstream ofn("convention.out");
	ifn >> n >> m >> c;
	for(int i=0;i<n;i++){
		int x;
		ifn >> x;
		cow.push_back(x);
	}
	sort(cow.begin(),cow.end());
	int l = 0,r = 1000000000;
	while(l<r){
		int mid = (l+r)/2;
		if(diff(mid) <= m) r = mid;
		else l = mid + 1;
	}
	ofn << r;
	ifn.close();
	ofn.close();
	return 0;
}