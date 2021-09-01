#include <bits/stdc++.h>

using namespace std;

struct info{
	int color,size,idx;
	bool operator<(info A)const{
		return size < A.size;
	}	
};
vector<info> ball;
vector<int> color,res;
int sum,s[2005];
int main(){
	int n;
	cin >> n;
	color.resize(n+1);
	res.resize(n);
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		ball.push_back({x,y,i});
	}
	sort(ball.begin(),ball.end());
	for(int i=0,j=0;i<ball.size();i++){
		for(;ball[j].size<ball[i].size;j++){ 
			sum+=ball[j].size;
			color[ball[j].color]+=ball[j].size;
		}
		res[ball[i].idx] = sum - color[ball[i].color];
	}
	for(int i=0;i<n;i++)
		cout << res[i] << '\n';
}