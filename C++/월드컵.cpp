#include <bits/stdc++.h>
using namespace std;
#define n 6 // n denotes the nubmer of teams
#define m 15 // m denotes the number of games = n choose 2

int win[6], lose[6], draw[6];
int genWin[6], genLose[6], genDraw[6];
int  p1[15], p2[15];
bool feasibility;
void recur( int cnt )
{
	if (cnt == 15)
	{
		feasibility = true;
		return;
	}
	int n1 = p1[cnt];
	int n2 = p2[cnt];
	//printf("%d %d %d##\n",n1,n2,cnt);
	genWin[n1]++; genLose[n2]++;
	if (genWin[n1]<=win[n1] && genLose[n2]<=lose[n2])
		recur(cnt+1);
	genWin[n1]--; genLose[n2]--;
	genDraw[n1]++; genDraw[n2]++;
	if (genDraw[n1]<=draw[n1] && genDraw[n2]<=draw[n2])
		recur(cnt+1);
	genDraw[n1]--; genDraw[n2]--;
	genLose[n1]++; genWin[n2]++;
	if (genLose[n1]<=lose[n1] && genWin[n2]<=win[n2])
		recur(cnt+1);
	genLose[n1]--; genWin[n2]--;
}
void process()
{
	int i, j, cnt = 0;
	feasibility = false;
	for (i=0; i<n; i++)
	{
		genWin[i] = 0;
		genLose[i] = 0;
		genDraw[i] = 0;
		if (win[i]+lose[i]+draw[i] != n-1) return;
	}
	for (i=0; i<n; i++)
		for (j=i+1; j<n; j++)
		{
			p1[cnt] = i;
			p2[cnt] = j;
			cnt++;
		}
		recur(0);
	for(int i=0;i<m;i++) printf("%d %d##\n",p1[i],p2[i]);
}

int main()
{
	for (int loop = 0; loop<4; loop++)
	{
		for (int i=0; i<n; i++)
			cin >> win[i] >> draw[i] >> lose[i];
		process();
		if (feasibility) cout << "1 ";
		else cout << "0 ";
	}
	return 0;
}