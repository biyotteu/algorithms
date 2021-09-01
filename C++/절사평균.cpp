#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<double> score;
double sum;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		double x;
		scanf("%lf",&x);
		score.push_back(x);
	}
	sort(score.begin(),score.end());
	for(int i=k;i<n-k;i++) sum += score[i];
	printf("%.2lf\n",sum/(double)(n-2*k) + 1e-9);
	sum += (score[k] + score[n-k-1])*k;
	printf("%.2lf",sum/(double)n + 1e-9);
}
