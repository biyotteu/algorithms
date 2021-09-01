#include <bits/stdc++.h>

using namespace std;

struct info{
	long long x,y,z;
	bool operator<(info A)const{
		return y < A.y;
	}
};
int n,res;
long long w;
vector<info> num;
priority_queue<info> Q;
bool cmp(info a,info b){
	return a.x*b.y < a.y*b.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> w;
	for(int i=0;i<n;i++){
		long long x,y;
		cin >> x >> y;
		num.push_back({x,y,i+1});
	}
	sort(num.begin(),num.end(),cmp);
	long long sum = 0;
	double rs=987654321989LL;
	for(int i=0;i<n;i++){
		Q.push(num[i]);
		sum += num[i].y;
		while(!Q.empty() && sum*num[i].x > w*num[i].y){
			sum -= Q.top().y;
			Q.pop();
		}
		if(res < (int)Q.size()){
			rs = sum*(double)num[i].x/(double)num[i].y;
			res = (int)Q.size();
		}else if(res == (int)Q.size()) rs = min(rs,(double)sum*(double)num[i].x/(double)num[i].y);
	}
	cout << res <<"\n";
	while(!Q.empty()) Q.pop();
	sum = 0;
	for(int i=0;i<n;i++){
		Q.push(num[i]);
		sum += num[i].y;
		while(!Q.empty() && sum*num[i].x > w*num[i].y){
			sum -= Q.top().y;
			Q.pop();
		}
		if(res == (int)Q.size() && (double)sum*num[i].x/(double)num[i].y == rs){
			while(!Q.empty()){
				cout << Q.top().z << "\n";
				Q.pop();
			}
			break;
		}
	}
}
