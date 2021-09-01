#include <bits/stdc++.h>

using namespace std;

int n,m;
pair<int,int> start,end;
char mmap[26][26];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;<=n;j++){
			char c;
			scanf(" %c",&c);
			mmap[i][j] = c;
			if(c == 'M') start = make_pair(i,j);
			if(c == 'Z') end = make_pair(i,j);
		}
	}
}