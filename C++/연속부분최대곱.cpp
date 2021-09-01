#include <bits/stdc++.h>

using namespace std;

int n;
double res;
vector<double> num;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double x;
		scanf("%lf",&x);
		num.push_back(x);
	}
	for(int i=0;i<n;i++){
		double s = 1;
		for(int j=i;j<n;j++){
			s*=num[j];
			res = max(res,s);
		}
	}
	printf("%.3lf",res);
}