#include <bits/stdc++.h>

using namespace std;

char str[12] = {'I','J','K','L','A','B','C','D','E','F','G','H'};
int num[10] = {6,7,8,9,0,1,2,3,4,5};
int main(){
	int n;
	cin >> n;
	printf("%c%d",str[n%12],num[n%10]);
}