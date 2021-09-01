#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;

int w,h,x,y,p,res;
pp c1,c2;
int dist(pp a,pp b){
	return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}
bool ch(int a,int b){
	if(dist(c1,{a,b}) <= (h/2)*(h/2)) return true;
	if(dist(c2,{a,b}) <= (h/2)*(h/2)) return true;
	if(a <= x+w && b <= y+h && x<=a && y<=b) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> h >> x >> y >> p;
	c1.first = x, c1.second = y+h/2;
	c2.first = x+w, c2.second = y+h/2;
	for(int i=0;i<p;i++){
		int a,b;
		cin >> a >> b;
		if(ch(a,b)) res++;
	}
	cout << res;
}