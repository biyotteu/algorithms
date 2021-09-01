#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
    int arr[150] = { 0 };
    int Max = 0;
    char res;
    getline(cin, s);
	for(auto i:s){
		if(i>96) arr[i-32]++;
		else arr[i]++;
	}
	for(int i=65;i<=90;i++){
		if(Max<arr[i]){
			res = i;]
			Max = arr[i];
		}
		else if(Max == arr[i])
			res = '?';
	}
	cout << res;
    return 0;	
}