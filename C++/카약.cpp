#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> a;
vector<int> res;
int main(){
	int n,m;
	cin >> n >> m;
	res.resize(n+1);
	while(n--){
		string str;
		cin >> str;
		for(int i=m-1;i>=0;i--){
			if(str[i] >= '0' && str[i] <= '9'){
				a.push_back({m-1-i,str[i]-'0'});
				break;
			}
		}
	}
	sort(a.begin(),a.end());
	int cnt = 1;
	int last = a[0].first;
	res[a[0].second] = 1;
    for(int i=1;i<a.size();i++){
    	if(last != a[i].first){
    		cnt++;
    		last = a[i].first;
    	}
    	res[a[i].second] = cnt;
    }
    for(int i=1;i<10;i++) cout << res[i] <<"\n";
}