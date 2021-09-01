#include <bits/stdc++.h>

using namespace std;

struct pos{
    int x,y,z;
};
vector<pos> race;
vector<pos> tmp;
int n;
void merge_sort(int L,int R)
{
    if(L>=R)
        return;
    int mid = (L+R)/2;
    int l=L;
    int r=mid+1;
    merge_sort(l,mid);
    merge_sort(r,R);
    for(int i=L;i<=R;i++)
    {
        if(r>R||(l<mid+1&&race[l].x<race[r].x))
            tmp[i]=race[l++];
        else
        {
            tmp[i]=race[r++];
            tmp[i].z+=mid-l+1;
        }
    }
    for(int i=L;i<=R;i++)
        race[i]=tmp[i];
    return;
}
int main()
{
    scanf("%d",&n);
    race.resize(n);
    tmp.resize(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&race[i].x);
        race[i].y=i;
    }
    merge_sort(0,n-1);
    vector<int> ans;
    ans.resize(n);
    for(int i=0;i<n;i++)
        ans[race[i].y]=race[i].z;
    for(auto i:ans)
        printf("%d ",i+1);
}
