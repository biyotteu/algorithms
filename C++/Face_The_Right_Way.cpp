#include <bits/stdc++.h>

using namespace std;

int n,res = (1<<29),idx;
vector<int> num,tmp;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		char a;
		scanf(" %c",&a);
		if(a == 'B') num.push_back(0);
		else num.push_back(1);
	}

	for(int k=1;k<=n;k++){
		tmp = num;
		deque<int> q;
		int cnt = 0,cmp = 1;
		for(int i=0;i<n;i++){
			while(!q.empty()&&(q.front() <i-k+1)) q.pop_front(); 
			tmp[i] += q.size();
			tmp[i] %= 2;
			if(tmp[i]!=1 && i<n-k+1){
				q.push_back(i);
				cnt++;
			}
		}
		for(int i=n-k+1;i<n;i++){
			if(tmp[i]!=1) cmp = 0;
		}
		if(cmp){
			if(cnt < res){
				res = cnt;
				idx = k;
			}
		}
	}
	printf("%d %d",idx,res);
}