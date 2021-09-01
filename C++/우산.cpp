#include <bits/stdc++.h>

using namespace std;

int n,m,b,visit[15],res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >>b;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		if(x == b) continue;
		if(y == 0){
			b = x;
		}else{
			if(visit[b]){
				visit[b]--;
				b = x;
				visit[b]++;
			}else{
				res++;
				b = x;
				visit[b]++;
			}
		}
	}
	cout << res;
}