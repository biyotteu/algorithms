#include <bits/stdc++.h>

using namespace std;

struct info{
	int idx,score,cnt;
	bool operator<(info A)const{
		if(score == A.score){
			if(cnt == A.cnt) return idx < A.idx;
			return cnt > A.cnt;	
		} 
		return score > A.score;
	}
};
int n,t,p;
int score[2005],play[2005][2005];
vector<info> res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> t >> p;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=t;j++){
			int x;
			cin >> x;
			score[j] += !x;
			play[i][j] = x;
		}
	}
	for(int i=1;i<=n;i++){
		int sum = 0,cnt = 0;
		for(int j=1;j<=t;j++) 
			if(play[i][j]){
				sum += score[j];
				cnt++;
			}
		res.push_back({i,sum,cnt});
	}
	sort(res.begin(),res.end());
	for(int i=0;i<n;i++){
		if(res[i].idx == p) cout << res[i].score << ' ' << i+1;
	}
}