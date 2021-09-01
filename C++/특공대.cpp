#include <bits/stdc++.h>
#define ll long long
#define SIZE 1000005
using namespace std;

int n,a,b,c,pvot=1,top=1;
ll sum[SIZE],rad[SIZE],dp[SIZE],idx[SIZE];
ll f(ll x){
	return (ll)a*x*x+(ll)b*x+c;
}
double ip(int x,int y){
	return (double)((dp[y]+a*sum[y]*sum[y]-b*sum[y])-(dp[x]+a*sum[x]*sum[x]-b*sum[x]))/((-2*a*sum[x])-(-2*a*sum[y]));
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cin >> a >> b >> c;
	for(int i=1;i<=n;i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	dp[1] = f(sum[1]);
	idx[1] = -2e9;
	rad[1] = 1;
	for(int i=2;i<=n;i++){
		dp[i] = f(sum[i]);
		//cout << i << ' ' << idx[pvot+1] << "-" << sum[i] << "####"; 
		//cout << i << " "<< idx[pvot+1] << " " << sum[i] << "##\n";
		while(pvot<top && idx[pvot+1] < sum[i]) pvot++;
		dp[i] = max(dp[i],dp[rad[pvot]] + f(sum[i] - sum[rad[pvot]]));
		//cout << pvot <<" " << dp[rad[pvot]] << " " <<  f(sum[i] - sum[rad[pvot]]) << "###\n";
		while(top>1 && idx[top] > ip(rad[top],i)) top--;
		top++;
		rad[top] = i;
		//cout << rad[top-1] << "######@@@#!@#!@#";
		//cout << sum[rad[top-1]]  <<" " << sum[rad[top]] << ' ' << ip(rad[top-1],i)<< "##\n" ;
		idx[top] = ip(rad[top-1],i);
		if(pvot > top) pvot = top;
	}
	//for(int i=1;i<=n;i++) cout << dp[i] << " ";
	cout << dp[n] << "\n";
} 