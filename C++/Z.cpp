#include <bits/stdc++.h>

using namespace std;

int n,r,c,N;
int f(int x1,int y1,int x2,int y2){
	int nx = (x1+x2)/2, ny=(y1+y2)/2;
	if(x1 == r &&  y1 == c && x2 ==r && y2 == c) return 0;
 	int k = 0, m = (x2-nx)*(y2-ny);
 	if(r<=nx && c<=ny){
		x2 = nx , y2 = ny , k = 0;
	}else if(r<=nx && c>ny){
		x2 = nx , y1 = ny+1 , k = m;
	}else if(r>nx && c<=ny){
		x1 = nx+1 , y2 = ny , k = 2*m;
	}else if(r>nx && c>ny){
		x1 = nx+1 , y1 = ny+1 , k =3*m;
	}
	return f(x1,y1,x2,y2)+k;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> r >> c;
	N = pow(2,n);
	cout << f(0,0,N-1,N-1);
}