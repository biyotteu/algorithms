#include <bits/stdc++.h>

using namespace std;

int n,q,size,posize,rosize;
long long sum[1000005];
char str[1000005];

vector<int> po,ro;
int main(){
	scanf("%d %d",&n,&q);
	scanf(" %s",str);
	size = strlen(str);
	for(int i=1;i<=size;i++){
		if(str[i-1] == 'P'){
			sum[posize + 1] = sum[posize++] + (long long)i;
			po.push_back(i);
		} 
		if(str[i-1] == 'R'){
			rosize++;
			ro.push_back(i);
		} 
	}
	while(q--){
		int x;
		scanf("%d",&x);
		long long int res = 0;
		int cnt = 0;
		if(!rosize){
			auto idx = lower_bound(po.begin(),po.end(),x);
			int lsize = idx - po.begin();
			int rsize = po.end() - idx;
			if(lsize >= rsize){ // 오른쪽 탈출
				res = size - x + 1 + 2*(x*rsize - sum[lsize] + sum[lsize - rsize]) + 2*(sum[lsize+rsize] - sum[lsize] - x*rsize);
				cnt = 2*(rsize);
			}else{ // 왼쪽 탈출
				res = 2*(sum[lsize*2 + 1] - sum[lsize] - x*(lsize + 1)) + 2*(x*lsize - sum[lsize]) + x;
				cnt = (2*lsize + 1);
			}
		}else{
			if(x < ro[0]){ //왼쪽 탈출
				auto idx = lower_bound(po.begin(),po.end(),x);
				auto r = lower_bound(po.begin(),po.end(),ro[0]);
				int lsize = idx - po.begin();
				int rsize = r - idx;
				if(lsize < rsize){ 
					res = 2*(sum[lsize*2 + 1] - sum[lsize] - x*(lsize + 1)) + 2*(x*lsize - sum[lsize]) + x;
					cnt = 2*(lsize) + 1;
				}else{
					res = 2*(lsize*x - sum[lsize]) + 2*(sum[rsize + lsize] - sum[lsize] - rsize*x) + 2*(ro[0]-x)*(lsize-rsize+1) + x;
					cnt = (lsize) + (rsize);
				}
			}else if(ro[rosize - 1] < x){
				auto idx = lower_bound(po.begin(),po.end(),x);
				auto l = lower_bound(po.begin(),po.end(),ro[rosize - 1]);
				int lsize = idx - l;
				int rsize = po.end() - idx;
				int xsize = idx - po.begin();
				if(lsize >= rsize){
					res = size - x + 1 + 2*(sum[xsize + rsize] - sum[xsize] - x*rsize) + 2*(x*rsize - sum[xsize] + sum[xsize - rsize]);
					cnt = 2*(rsize);
				}else{
					res = size - x + 1 + 2*(sum[xsize + rsize] - sum[xsize] - x*rsize) + 2*(x*lsize - sum[xsize] + sum[xsize - lsize]) + 2*(x-ro[rosize-1])*(rsize - lsize);
					cnt = (lsize) + (rsize);
				}
			}else{
				auto idx = lower_bound(ro.begin(),ro.end(),x);
				cnt = lower_bound(po.begin(),po.end(),*idx)-lower_bound(po.begin(),po.end(),*(idx-1));
				res = -1;
			}
		}
		printf("%d %lld\n",cnt,res);
	}
	
}