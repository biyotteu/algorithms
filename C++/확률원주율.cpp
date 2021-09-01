#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

double get_random() {
	return ((double)(rand() % RAND_MAX) / (double)RAND_MAX);
}
int main()
{
	while (1) {
		system("cls");
		double PI, x, y, co, Total_cnt, cnt = 0;
		srand(time(NULL));
		printf("--------------------------------------------\n");
		printf("| BETA Experiment!! (1.Monte Carlo method) |\n");
		printf("--------------------------------------------\n\n");
		printf("input Total_cnt: ");
		scanf("%lf", &Total_cnt);
		for (int i = 0; i < Total_cnt; i++) {
			double x = get_random(), y = get_random();
			co = (x * x) + (y * y);
			if (co <= 1) {
				cnt++;
				PI = 4 * (cnt / Total_cnt);
			}
		}
		printf("\npi = %.15f\n\n", PI);
		printf("--------------------\n");
        printf("| try again? (Y|N) |\n");
        printf("--------------------\n");
        printf("\nput Y or N   ");
        char c;
        scanf(" %c",&c);
        if(c=='N' || c=='n') break;
	}
}
