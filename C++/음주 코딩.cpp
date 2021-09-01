#include <bits/stdc++.h>

using namespace std;

int seg[(1<<18)],h,n,k;
void update(int i,int v){
	i += h;
	seg[i] = v;
	while(i/=2) seg[i] = seg[i*2] * seg[i*2+1];
}
int sum(int a,int b){
	int ret = 1;
	a+=h,b+=h;
	while(a<=b){
		if(a%2) ret *= seg[a++];
		if(b%2 == 0) ret *= seg[b--];
		a/=2,b/=2;
	}
	return ret;
}
int abc(int v){
	if(v > 0) return 1;
	if(v < 0) return -1;
	return 0;
}
int main(){
	while(scanf("%d %d",&n,&k) != EOF){
		for(h=1;h<n;h*=2);
		for(int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			update(i,abc(x));
		}
		while(k--){
			char c;
			int a,b;
			scanf(" %c %d %d",&c,&a,&b);
			if(c == 'C'){ 
				update(a,abc(b));
			}
			else{
				int ret = sum(a,b);
				if(ret == 0) printf("0");
				if(ret < 0) printf("-");
				if(ret > 0) printf("+");
			}
		}
		printf("\n");
	}
}