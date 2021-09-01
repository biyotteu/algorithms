#include <bits/stdc++.h>

using namespace std;

int n;
int main(){
	cin >> n;
	for(int i=1;i<min(n,987654);i++){
		set<int> s;
		int a = i, b = n-i,cmp=0;
		while(a){
			if(s.find(a%10)!=s.end()) {
				cmp=1;
				break;
			}
			else s.insert(a%10);
			a/=10;
		}
		if(cmp) continue;
		while(b){
			if(s.find(b%10)!=s.end()){
				cmp=1;
				break;
			}
			else s.insert(b%10);
			b/=10;
		}
		if(!cmp){
			printf("%d + %d",i,n-i);
			return 0;
		}
	}
	printf("-1");
}