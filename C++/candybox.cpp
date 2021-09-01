#include <bits/stdc++.h>
#define idx 1048576

using namespace std;

int seg[idx*2];
void update(int pos,int v)
{
    pos |= idx;
    seg[pos]+=v;
    while(pos >>= 1)
        seg[pos] = seg[pos<<1] + seg[pos<<1|1];
}
int find(int val)
{
    int start = 1;
    int sum = 0;
    while(start<=idx)
    {
        if((seg[start<<1])+sum>=val)
            start<<=1;
        else{
            sum += seg[start<<1];
            start = (start<<1)|1;
        }
    }
    update(start,-1);
    return start-idx;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a;
        scanf("%d",&a);
        if(a==2){
            int b,c;
            scanf("%d %d",&b,&c);
            update(b,c);
        }
        if(a==1){
            int b;
            scanf("%d",&b);
            printf("%d\n",find(b));
        }
    }
}