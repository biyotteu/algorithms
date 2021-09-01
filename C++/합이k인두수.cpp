#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[50006];
int check[50006] = {0, };
int negative[50006] = {0, };
int main()
{
    int n;
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
        if(arr[i]<0)
        {
            //arr[i] = arr[i]*(-1);
            negative[-arr[i]] = 1;
        }
        else{
            check[arr[i]] = 1;
        }
    }
    int hap;
    scanf("%d", &hap);
    int j;
    int a, b;
    int bleh = 0;
    sort(arr, arr+n);
 
    for(i=0; i<n; i++)
    {
        a = arr[i];
        //if(negative[a]==1)
          //  a = a*(-1);
        b = hap - a;
        if(b < -50000 || b > 50000) continue;
        //if(b<0)
            //b= b* (-1);
        if(b!=a)
        {
            if(b<0)
            {
                if(negative[-b] == 1)
                {
                    bleh++;
                    printf("%d %d\n", a, b);
                    return 0;
                }
            }
            else{
                if(check[b] !=0)
                {
                    bleh++;
                    printf("%d %d\n", a, b);
                    return 0;
                }
            }
        }
    }
    if(bleh==0)
        printf("0 0");
    return 0;
}