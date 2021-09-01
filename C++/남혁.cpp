#include <stdio.h>
#include <stdio.h>
#include <algorithm>

int c[1001];
int d[1001];
int e[1001];


int main()
{
	int n, b, t,x=0;
	int max = 0;
	scanf("%d %d", &n, &b);
	t=b;
	for(int i=0; i<n; i++)
	{
		scanf("%d %d", &d[i], &e[i]);
	}
	for(int i=0; i < n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(j==i)
				c[j] = d[j]/2 + e[j];
			else
				c[j] = d[j] + e[j];
		}
		std::sort(c, c+n);
		b=t;
		int cnt = 0;
		for(int j=0; j<n; j++)
		{
			if(c[j] > b) break;
			cnt++;
			max = std::max(max,cnt);
			b -= c[j];
		}
	}
    printf("%d\n", max);
}