#include <bits/stdc++.h>

using namespace std;

int n;
vector<long long> seg,lazy;
void unlazy(){
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	int size = (int)ceil(log2(n));
	seg.resize(1<<(size+1));
	lazy.resize(1<<(size+1));

}