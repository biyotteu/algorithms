#include <bits/stdc++.h>

using namespace std;

int n,m,l,k;
long long int tree[2500000],sum;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n>> m >> l;
    for(k=1;k<n;k*=2);
    for(int i=k;i<k+n;i++)
        cin >> tree[i];
    for(int i=(k+n-1)/2;i>=1;i--)
        tree[i]=tree[i*2]+tree[i*2+1];
    long long int a,b,c;
    for(int i=1;i<=m+l;i++)
    {
        cin >> a >> b >> c;
        if(a==1)
        {
            tree[k+b-1]=c;
            int tmp=(k+b-1)/2;
            while(tmp>0)
            {
                tree[tmp]= tree[tmp*2]+tree[tmp*2+1];
                tmp/=2;
            }
            continue;
        }
        if(a==2)
        {
            int x=k+b-1;
            int y=k+c-1;
            sum=0;
            while(x<=y)
            {
                if(x%2==1)
                {
                    sum +=tree[x];
                    x++;
                }
                if(y%2==0)
                {
                    sum +=tree[y];
                    y--;
                }
                x/=2;
                y/=2;
            }
            cout << sum << "\n";
        }
    }
}