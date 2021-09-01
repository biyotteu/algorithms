#include <bits/stdc++.h>

using namespace std;

int n,q,size;
char str[1000005];
vector<int> po,ro;
pair<int,int> potime(int l,int r,int v,int l1,int r1){
	auto x = lower_bound(po.begin(),po.end(),l);
	auto y = upper_bound(po.begin(),po.end(),r);
	auto k = lower_bound(po.begin(),po.end(),v);
	if(x == (y+1)){
		if(l1){
			return {0,size - v};
		}else if(r1){
			return {0,v};
		}else{
			return {0,size - v};
		}
	}else{
		vector<int> L,R,tmp;
		int res = 0, cnt = 0;
		if(r1){
			int xx=0,yy=0;
			for(auto i = x;i<k;i+=1){
				xx++;
				res += (v-*i)*2;
			} 
			cnt += xx;
			for(auto i = k;i<y;i+=1){
				if(i-k > xx) break;
				res += (*i-v)*2;
				cnt++;
			}
			yy = y-k;
			if(yy <= xx){
				res += (xx - yy +1)*(v-l);
			}
		}else if(l1){
			int xx=0,yy=0;
			for(auto i = k;i<y;i+=1){
				yy++;
				res += (*i-v)*2;
			}
			cnt += yy;
			for(auto i = x;i<k;i+=1){
				if()
				xx++;
				res += (v-*i);
			} 
			xx = k-i;
			if(yy >= xx){
				res += (yy - xx +1)*(v-l);
			}
		}else{
			int xx = k-x,yy = y-k;
			if ()
		}
		return {cnt,res};
	}
}
int main(){
	scanf("%d %d",&n,&q);
	scanf(" %s",str);
	size = strlen(str);
	for(int i=0;i<size;i++){
		if(str[i] == 'P') po.push_back(i);
		if(str[i] == 'R') ro.push_back(i);
	}
	pair<int,int> cur;

	while(q--){
		int x;
		cin >> x;
		x--;
		auto k = lower_bound(ro.begin(),ro.end(),x);
		if(ro.size() >= 1){
			if(k == ro.begin()){
				cur = potime(-1,*ro.begin(),x,0,1);
			}else if(k == ro.end()){
				cur = potime(ro.back(),size,x,1,0);
			}else{
				if(po.size()>0)
					cur = {(int)(lower_bound(po.begin(),po.end(),*k)-lower_bound(po.begin(),po.end(),*(k-1))),-1};
				else
					cur = {0,-1};
			}
		}else{
			cur = potime(-1,size,x,0,0);
		}
		printf("%d %d\n",cur.first,cur.second);
	}
}