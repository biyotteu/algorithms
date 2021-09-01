#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int limit[3];
int bucket[3];
char inputString[300];
int main(){
	ifstream ifn("mixmilk.in");
	ofstream ofn("mixmilk.out");
	for(int i=0;i<3;i++){
		ifn >> limit[i] >> bucket[i];
	}
	int cnt = 1;
	for(int i=0;i<100;i++){
		if(cnt == 0){
			if(limit[0] < bucket[0]+bucket[2]){
				bucket[2] -= (limit[0] - bucket[0]); 
				bucket[0] = limit[0];
			}
			else{
				bucket[0] += bucket[2];
				bucket[2] = 0;
			}
		}
		if(cnt == 1){
			if(limit[1] < bucket[0]+bucket[1]){
				bucket[0] -= (limit[1] - bucket[1]); 
				bucket[1] = limit[1];
			}
			else{
				bucket[1] += bucket[0];
				bucket[0] = 0;
			}
		}
		if(cnt == 2){
			if(limit[2] < bucket[2]+bucket[1]){
				bucket[1] -= (limit[2] - bucket[2]); 
				bucket[2] = limit[2];
			}
			else{
				bucket[2] += bucket[1];
				bucket[1] = 0;
			}
		}
		cnt++;
		cnt%=3;
	}
	for(int i=0;i<3;i++){
		ofn << bucket[i] << "\n";
	}
	ifn.close();
	ofn.close();
	return 0;
}