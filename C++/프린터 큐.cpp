#include <bits/stdc++.h>

#define N 100
 
using namespace std;
 
typedef struct
{
    int value;
    int index;
}v;
int main()
{
    queue <v> q;
    int a,b,c,k,cnt=0,e,ans[N]={0},br[N];
    v temp;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d %d",&b,&c);
        for(int j=0;j<b;j++)
        {
            scanf("%d",&br[j]);
            q.push({br[j],j});
        }
        sort(br,br+b,greater<int>());
        cnt=0;
        while(1)
        {
            if(br[cnt] == q.front().value)
            {
                if(q.front().index == c){
                	printf("%d\n",cnt+1);
                	break;
                }
                q.pop();
                cnt++;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
     //   printf("\n*%d*",ans[i]);
    }
}