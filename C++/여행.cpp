#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=n;i>=0;i--){
		if(i == 0){ 
			if(n == 1) cout << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, "<<n<<" bottle of beer on the wall.\n";
			else cout << "No more bottles of beer on the wall, no more bottles of beer.\nGo to the store and buy some more, "<<n<<" bottles of beer on the wall.\n";
		}
		else if(i == 1) cout << "1 bottle of beer on the wall, 1 bottle of beer.\nTake one down and pass it around, no more bottles of beer on the wall.\n";
		else if(i == 2) cout << "2 bottles of beer on the wall, 2 bottles of beer.\nTake one down and pass it around, 1 bottle of beer on the wall.\n";
		else cout << i << " bottles of beer on the wall, "<< i <<" bottles of beer.\nTake one down and pass it around, "<< i-1<<" bottles of beer on the wall.\n";
		cout << "\n";
	}	
}