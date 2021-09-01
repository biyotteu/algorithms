#include <bits/stdc++.h>

using namespace std;

class Random{
public:
	Random(){
		srand(time(NULL));
	}
	int next(){
		return rand();
	}
	int nexInRange(int st,int en){
		return rand()%(en-st) + st;
	}
};
int main(){
	Random r;
	cout << "-- 0 " << RAND_MAX << " 10 " << endl;
	for(int i=0;i<10;i++){
		cout << r.next() << ' ';
	}
	cout << endl << endl << " 2~4 " << endl;
	for(int i=0;i<10;i++){
		cout << r.nexInRange(2,4) << ' ';
	} 
	cout << endl;
	system("pause");
	return 0;
}