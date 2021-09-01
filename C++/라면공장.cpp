#include <bits/stdc++.h>

using namespace std;
using pp = pair<int,int>;
priority_queue<pp> Q;
vector<pp> fl;
int stock, vector<int> dates, vector<int> supplies, int k
int main(){
	cin >> stock;
	for(int i=0;)
	int answer = 0;
    for(int i=0;i<dates.size();i++)
        fl.push_back({dates[i],supplies[i]});
    sort(fl.begin(),fl.end());
    for(auto i:fl){
        if(stock >= i.first)
            Q.push({i.second,i.first});
        else{
            answer++;
            stock+=Q.top().first;
            Q.pop();
        }
    }
    while(stock < k){
        stock += Q.top().first;
        Q.pop();
        answer++;
    }
    return answer;
}