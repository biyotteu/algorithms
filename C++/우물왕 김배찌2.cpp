#include <bits/stdc++.h>

using namespace std;

vector<double> X,Y;
double diff(vector<double> &cur,double v){
	double sum = 0;
	for(auto i:cur){
		sum += (i-v)*(i-v);
	}
	return sum;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	double lex = 0,rix = 0,ley =0 ,riy = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		double x,y;
		scanf("%lf %lf",&x,&y);
		X.push_back(x);
		Y.push_back(y);
		rix = max(rix,x);
		riy = max(riy,y);
	}
	for(int i=0;i<100;i++){
		double aab = (2*lex + rix) / 3;
		double abb = (lex + 2*rix) / 3;
		if(diff(X,aab) > diff(X,abb)) lex = aab;
		else rix = abb;
	}
	for(int i=0;i<100;i++){
		double aab = (2*ley + riy) / 3;
		double abb = (ley + 2*riy) / 3;
		if(diff(Y,aab) > diff(Y,abb)) ley = aab;
		else riy = abb;

	}
	printf("%.3lf %.3lf",(double)(lex+rix)/2,(double)(ley+riy)/2);
}