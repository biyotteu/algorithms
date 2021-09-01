#include <bits/stdc++.h>

using namespace std;

int card[21];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i=1;i<=20;i++) card[i] = i;
	for(int i=0;i<10;i++){
		int a,b;
		cin >> a >> b;
		vector<int> tmp;
		for(int j=a;j<=b;j++) tmp.push_back(card[j]);
		for(int j=a;j<=b;j++){
			card[j] = tmp.back();
			tmp.pop_back();
		}
	}
	for(int i=1;i<=20;i++) cout << card[i] << ' ';
}