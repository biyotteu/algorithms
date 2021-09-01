//백준 2602번
//DP문제
//dp[j][i][k] j = 돌다리의 위치, i = 두루마리의 글자 차례,k = 천사,악마다리
//전 스펠링의 반대편 돌다리의 경우의 수를 더해준다.
//roll = 두루마리 , en = 천사다리 , de = 악마다리 , dp = DP테이블 
#include <bits/stdc++.h>

using namespace std;

int dp[105][25][2];
string roll,en,de;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> roll >> en >> de;
	for(int i=0;i<roll.size();i++){
		for(int j=0;j<en.size();j++)
		{
			if(i == 0){
				if(en[j] == roll[0]) dp[j][i][0] = 1;
				if(de[j] == roll[0]) dp[j][i][1] = 1;
			}else{
				for(int k=j-1;k>=0;k--){
					if(en[j] == roll[i]) dp[j][i][0] += dp[k][i-1][1];
					if(de[j] == roll[i]) dp[j][i][1] += dp[k][i-1][0];
				}
			}
		}
	}
	int res = 0;
	for(int i=0;i<en.size();i++) res+=(dp[i][roll.size()-1][1]+dp[i][roll.size()-1][0]);
	cout << res;
}