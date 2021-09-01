#include <stdio.h>

char a[5][16] = {NULL,};
int main()
{
	int i,j; 
	for(i=0; i<5; i++)
	{
		scanf("%s", a[i]);
	}
	for(j=0; j<15; j++)
	{
		for(i=0; i<5; i++)
		{
			if(a[i][j]!='\0')
			{
				printf("%c",a[i][j]);
			}
		}
	}
}