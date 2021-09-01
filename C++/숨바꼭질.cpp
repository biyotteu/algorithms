#include <bits/stdc++.h>

using namespace std;

int n,k,visit[200005],res;
queue<int> Q;
int main(){
	scanf("%d %d",&n,&k);
	Q.push(n);
	visit[n] = 1;
	for(res = 0; ;res++){
		int size = Q.size();
		bool flag = false;
		for(int i=0;i<size;i++){
			int cur = Q.front();
			Q.pop();
			if(cur == k){
				flag = true;
				break;
			}
			if(cur * 2 <= 100000 && !visit[cur*2]){
				visit[cur*2] = 1;
				Q.push(cur*2);
			}
			if(cur + 1 <= 100000 && !visit[cur+1]){
				visit[cur+1] = 1;
				Q.push(cur+1);
			}
			if(cur - 1 >= 0 && !visit[cur-1]){
				visit[cur-1] = 1;
				Q.push(cur-1);
			}
		}
		if(flag) break;
	}
	printf("%d",res);
}
