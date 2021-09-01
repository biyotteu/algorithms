#include <bits/stdc++.h>

using namespace std;

struct info{
	string team;
	int mi;
	double sec;
	bool operator<(info A){
		if(mi == A.mi) return sec < A.sec;
		else return mi < A.mi;
	}
};
int score[8] = {10,8,6,5,4,3,2,1};
bool check(info a,info b){
	if(a.mi == b.mi && (((double)a.sec >= (double)b.sec) && ((double)a.sec - (double)b.sec < (double)10.0))) return true;
	if(a.mi-1 == b.mi && ((double)a.sec < (double)b.sec) && (60.0 + (double)a.sec - (double)b.sec < (double)10.0)) return true;
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--){
		vector<info> play;
		string mode;
		cin >> mode;
		for(int i=0;i<8;i++){
			string tea;
			char a,b;
			double time;
			cin >> tea;
			cin >> a;
			cin >> b;
			cin >> time;
			play.push_back({tea,a-48,time});
			//cout << tea << ' ' << a << ' ' << time << endl;
		}
		sort(play.begin(),play.end());
		if(mode == "item") cout << play[0].team << "\n";
		else{
			int cnt = 0;
			int bsum = 0, rsum = 0;
			for(int i=0;i<8;i++){
				if(check(play[i],play[0])){
					if(play[i].team == "blue") bsum += score[cnt];
					else rsum += score[cnt];
					cnt++;
				}
				else break;
			} 
			if(bsum == rsum) cout << play[0].team << "\n";
			else{
				if(bsum > rsum) cout << "blue\n";
				else cout << "red\n";
			} 
		}
	}
}