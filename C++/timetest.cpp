#include <iostream>
#include <time.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	auto st = clock();
	for(int i=0;i<10000;i++){
		cout << i << "\n";
	}
	auto en = clock();
	cout << (en-st);
}