//백준 1509번
//DP문제
//res[i] = i번째까지의 최소 팰린드롬 수
//pallin[i][j] = i부터 j까지가 팰린드롬인지 아닌지
#include <bits/stdc++.h>

using namespace std;

int pallin[2505][2505],res[2505];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string A;
	cin >> A;
	for(int i=0;i<A.size();i++) pallin[i][i] = 1;
	for(int i=0;i<A.size();i++) if(A[i] == A[i+1]) pallin[i][i+1] = 1;
	for(int i=1;i<A.size();i++){
		for(int j=0;j+i<A.size();j++){
			if(A[j] == A[j+i]) pallin[j][j+i] = j+i-1 > j+1 ? pallin[j+1][j+i-1] : 1;
		}
	}	
	res[0] = 1;
	for(int i=0;i<A.size();i++) if(pallin[0][i]) res[i] = 1;
	for(int i=1;i<A.size();i++){
		if(!res[i]) res[i] = res[i-1] + 1;
		else res[i] = min(res[i-1]+1,res[i]);
		for(int j=i+1;j<A.size();j++)
		{
			if(pallin[i][j]){
				if(!res[j]) res[j] = res[i-1] + 1;
			  	else res[j] = min(res[j],res[i-1] + 1);
			}	
		}
	}
	cout << res[A.size()-1];
}