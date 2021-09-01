#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> food[3];
int main(){
	scanf("%d ",&n);
	for(int i=0;i<3;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			int y;
			scanf("%d",&y);
			food[i].push_back(j);
		}
	}
	
}