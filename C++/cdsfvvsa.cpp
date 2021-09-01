#include <bits/stdc++.h>

using namespace std;

int main(){
	for(int i=400;i>=0;i--){
		if(600%i==0&&400%i==0&&800%i==0&&1200%i==0){
			cout << i;
			break;
		}
	}
}