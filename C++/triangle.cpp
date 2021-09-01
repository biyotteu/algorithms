#include <bits/stdc++.h>

using namespace std;

int main()
{
	int cnt=0;
	while(++cnt){
		int n,DP[100005][5];
		scanf("%d",&n);
		if(n==0) return 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) scanf("%d",&DP[i][j]);

		DP[1][0] = DP[1][0]+DP[0][1];
        DP[1][1] = min(DP[1][1]+DP[1][0],min(DP[0][1]+DP[0][2]+DP[1][1], DP[1][1]+DP[0][1]));
        DP[1][2] = min(DP[1][1]+DP[1][2], min(DP[1][2] + DP[0][1], DP[1][2]+DP[0][1]+DP[0][2]));

        for (int i = 2; i < n; i++) {
            DP[i][0] += min(DP[i - 1][0], min(DP[i - 1][1],DP[i-1][1]));
            DP[i][1] += min(min(DP[i][0],DP[i-1][0]), min(DP[i-1][2],DP[i-1][1]));
            DP[i][2] += min(DP[i][1], min(DP[i - 1][2], DP[i - 1][1]));
        }
		printf("%d. %d\n",cnt,DP[n-1][1]);

	}
}
