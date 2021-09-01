#include <bits/stdc++.h>

using namespace std;

int alpha[26]={3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
vector<int> sum;
int main(){
    std::ios::sync_with_stdio(false);
	string a,b;
	cin >> a >> b;
	for(int i=0;i<a.size();i++){
		sum.push_back(alpha[a[i]-'A']);
		sum.push_back(alpha[b[i]-'A']);
	}
	while(sum.size() != 2){
		vector<int> tmp;
		for(int i=0;i<sum.size()-1;i++) tmp.push_back((sum[i] + sum[i+1])%10);
		sum = tmp;
	}
	cout << sum[0] << sum[1];
}