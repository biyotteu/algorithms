#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> num[105];
vector<int> getpi(vector<int> pp){
	vector<int> pi(k,0);
	for(int i=1,j=0;i<pp.size();i++){
		while(j>0 && pp[i] != pp[j]) j = pi[j-1];
		if(pp[i] == pp[j]) pi[i] = ++j;
	}
	return pi;
}

bool kmp(vector<int> A,vector<int> B,vector<int> pi){
	for(int i=0,j=0;i<A.size();i++){
		while(j>0 && A[i] != B[j]) j = pi[j-1];
		if(A[i] == B[j]){
			if(j == k-1) return 1;
			else j++;
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		int m;
		cin >> m;
		num[i].resize(m);
		for(int j=0;j<m;j++) cin >> num[i][j];
	}
	for(int i=0;i<=num[0].size()-k;i++){
		vector<int> pi,rpi,re,pp;
		for(int j=i;j<i+k;j++){
			pp.push_back(num[0][j]);
			re.push_back(num[0][2*i+k-1-j]);
		}

		pi = getpi(pp);
		rpi = getpi(re);
		int res = 1;
		for(int o=1;o<n;o++){
			if(kmp(num[o],pp,pi)) res++;
			else if(kmp(num[o],re,rpi)) res++;
			else break;
		}
		if(res == n){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}