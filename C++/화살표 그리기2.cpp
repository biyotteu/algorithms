#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<vector<int>> color;
	int n;
	long long res = 0;
	scanf("%d",&n);
	color.resize(n+1);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		color[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		sort(color[i].begin(),color[i].end());
		for(int j=0;j<color[i].size();j++){
			if(j!=0 && j != color[i].size()-1)
				res += min(color[i][j] - color[i][j-1],color[i][j+1] - color[i][j]);
			if(j==0) res += (color[i][j+1] - color[i][j]);
			if(j == color[i].size()-1) res += (color[i][j]- color[i][j-1]);
		}
	}
	printf("%lld",res);
}