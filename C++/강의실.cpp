#include <bits/stdc++.h>

using namespace std;

int n,res;
vector<pair<int,int>> les;
priority_queue<int,vector<int>,greater<int>> Q;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		les.push_back({b,c});
	}
	sort(les.begin(),les.end());
	for(int i=0;i<n;i++){
		if(Q.empty()){
			res++;
			Q.push(les[i].second);
		}else{
			if(Q.top()<=les[i].first){
				Q.pop();
				Q.push(les[i].second);
			}else{
				res++;
				Q.push(les[i].second);
			}
		}
	}
	printf("%d",res);
}