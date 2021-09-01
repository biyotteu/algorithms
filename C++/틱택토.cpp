#include <bits/stdc++.h>

using namespace std;

string str;
int pp(int a,int b,int c,char k){
	int sum = 0;
	if(k == str[a]) sum++;
	if(k == str[b]) sum++;
	if(k == str[c]) sum++;
	return sum;

}
int diff(int a,int b,int c){
	if(pp(a,b,c,'O') == 3) return 1;
	else if(pp(a,b,c,'X') == 3) return 1;
	return 0;
}
int diff1(int a,int b,int c){
	int o = pp(a,b,c,'O'), x = pp(a,b,c,'X'), ll = pp(a,b,x,'.');
	if(o + ll == 3 || x + ll == 3) return 1;
	return 0;
}
int main(){
	while(1){
		cin >> str;
		int dn = 0;
		for(auto i:str) if(i == '.') dn++;
		if(str.compare("end") == 0) return 0;
		int cnt = 0,cnt1;
		cnt = diff(0,1,2) + diff(3,4,5) + diff(6,7,8) + diff(0,3,6) + diff(1,4,7) + diff(2,5,8),cnt1 = diff(0,4,8) + diff(2,4,6);
		cnt1 =diff(0,4,8) + diff(2,4,6);
		cout << diff(0,1,2) << diff(3,4,5) << diff(6,7,8) << diff(0,3,6) << diff(1,4,7) << diff(2,5,8) << diff(0,4,8) << diff(2,4,6);
		cout << cnt << ' ';
		if(cnt == 1) cout << "valid\n";
		else if(cnt > 1) cout << "invalid\n";
		else{
			cnt = diff1(0,1,2) + diff1(3,4,5) + diff1(6,7,8) + diff1(0,3,6) + diff1(1,4,7) + diff1(2,5,8) + diff1(0,4,8) + diff1(2,4,6);
			if(cnt || dn == 0) cout << "valid\n";
			else cout << "invalid\n";
			cout << cnt << "##";
		}
	}
}