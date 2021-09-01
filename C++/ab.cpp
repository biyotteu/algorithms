#include <bits/stdc++.h>

using namespace std;

int pal[2505][2505],res = 1;
int main()
{
	string str;
	cin >> str;
    for(int i=1;i<str.size();i++){
        for(int j=0;j+i<str.size();j++){
            if(str[j] == str[j+i]){
            	if(j+1 == j+i-1) pal[j][j+i] = 3;
            	else if(j+2 == j+i-1) pal[j][j+i] = 2;
            	else{
            		cout << j << ' ' << j+i << ' ' << pal[j+1][j+i-1]<< endl; 1 5
            	 pal[j][j+i] = pal[j+1][j+i-1] + 2;
            	}
            }
            res = max(res,pal[j][j+i]);   
        }
    }
    printf("%d",res);
}