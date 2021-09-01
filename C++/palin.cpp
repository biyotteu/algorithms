    #include <bits/stdc++.h>

    using namespace std;

    string str;
    int n;
    bool ch(int s,int e){
        while(s<e){
            if(str[s]!=str[e]) return 0;
            s++,e--;
        }
        return 1;
    }
    int main()
    {
        cin >> str;
        n = str.size();
        for(int i=0;i<n;i++){
            if(ch(i,n-1)){
                printf("%d",i+n);
                return 0;
            }
        }
        printf("%d",n*2-1);
    }
