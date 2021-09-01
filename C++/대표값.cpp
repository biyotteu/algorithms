#include <bits/stdc++.h>

using namespace std;

int cnt[1005],sum,idx,ret;
int main(){
	for(int i=0;i<10;i++){
		int x;
		cin >> x;
		sum += x;
		cnt[x]++;
		if(ret < cnt[x]){
			ret = cnt[x];
			idx = x;
		}
	}
	cout << sum/10 << '\n' << idx;
}