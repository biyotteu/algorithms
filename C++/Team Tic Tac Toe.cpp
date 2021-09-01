#include <bits/stdc++.h>

using namespace std;

vector<char> check;
set<char> s;
char cow[3][3];
int cnt1, cnt2;
int main(){
	for(int i=0;i<3;i++){
		
		for(int j=0;j<3;j++){
			cin >> cow[i][j];
			if(s.find(cow[i][j]) == s.end()){
				check.push_back(cow[i][j]);
				s.insert(cow[i][j]);
			}
		}
	}
	for(int i=0;i<3;i++){
		if(cow[0][i] == cow[1][i] && cow[1][i] == cow[2][i]) cnt1++;
		if(cow[i][0] == cow[i][1] && cow[i][1] == cow[i][2]) cnt1++;
	}
	if(cow[0][0] == cow[1][1] && cow[1][1] == cow[2][2]) cnt1++;
	if(cow[0][2] == cow[1][1] && cow[1][1] == cow[2][0]) cnt1++;
	//for(auto i:check) cout << i << ' ' << endl;
	sort(check.begin(),check.end());
	for(int i=0;i<check.size();i++){
		for(int j=i+1;j<check.size();j++){
			if(i ==j) continue;
			for(int k=0;k<3;k++){
				if((cow[0][k] == check[i] || cow[0][k] == check[j]) && (cow[2][k] == check[i] || cow[2][k] == check[j]) && (cow[1][k] == check[i] || cow[1][k] == check[j])) cnt2++;
				if((cow[k][0] == check[i] || cow[k][0] == check[j]) && (cow[k][2] == check[i] || cow[k][2] == check[j]) && (cow[k][1] == check[i] || cow[k][1] == check[j])) cnt2++;
			}
			if((cow[0][0] == check[i] || cow[0][0] == check[j]) && (cow[2][2] == check[i] || cow[2][2] == check[j]) && (cow[1][1] == check[i] || cow[1][1] == check[j])) cnt2++;
			if((cow[0][2] == check[i] || cow[0][2] == check[j]) && (cow[2][0] == check[i] || cow[2][0] == check[j]) && (cow[1][1] == check[i] || cow[1][1] == check[j])) cnt2++;
			//cout << check[i] << ' ' << check[j] << ' ' << cnt2 << endl; 	
		}
	}
	cout << cnt1 << "\n" << cnt2;
}