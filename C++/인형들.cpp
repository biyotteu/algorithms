//백준 15954번
//구현문제 
//문제 그대로 구현하면 된다.
#include <bits/stdc++.h>

using namespace std;

double n,k,res = (1<<29);
vector<double> dll;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		double x;
		cin >> x;
		dll.push_back(x);
	}
	for(int q=k;q<=n;q++){
		for(int i=0;i<=n-q;i++){
			double sum = 0;
			for(int j=i;j<i+q;j++)
				sum += dll[j];
			sum/=q;
			double ret = 0;
			for(int j=i;j<i+q;j++)
				ret += (dll[j] - sum) * (dll[j] - sum);
			ret /= q;
			res = min((double)sqrt(ret),res);
		}
	}
	printf("%.15lf",res);
}