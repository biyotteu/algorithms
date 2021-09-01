#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

int main()
{
    while (1)
    {
        system("cls");
        double pi = 0;
        int k = 0, limit;
        printf("----------------------------------\n");
        printf("| BETA Experiment!! (2.Integral) |\n");
        printf("----------------------------------\n\n");
        printf("input limit:");
        scanf("%d", &limit);
        for (int k = 1; k <= limit; k++)
        {
            if ( k % 2 ) pi += 4.0 / (2.0 * k - 1.0);
            else pi -= 4.0 / (2.0 * k - 1.0);
        }
        printf("\npi = %.15f\n\n", pi);
        printf("--------------------\n");
        printf("| try again? (Y|N) |\n");
        printf("--------------------\n");
        printf("put Y or N   ");
        char c;
        scanf(" %c",&c);
        if(c=='N' || c=='n') break;
    }
    return 0;
}
