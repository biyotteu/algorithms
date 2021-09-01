#include <bits/stdc++.h>

using namespace std;
int n,N[105],A[105],B[105],size,cnt;
int f(int v,int c){
    if(v > size-1){
    	if(c == 0){
    		for(int i=0;i<size;i++){
    			if(A[i]) break;
    			if(i == size-1) return 0;
    		}
    		for(int i=0;i<size;i++){
    			if(B[i]) break;
    			if(i == size-1) return 0;
    		}
    		printf("case #%d: ",cnt);
    		int i=0;
    		while(A[i] == 0) i++;
    		for(;i<size;i++) printf("%d",A[i]);
    		printf(" ");
    		i = 0;
    		while(B[i] == 0) i++;
    		for(;i<size;i++) printf("%d",B[i]);
    		return 1;
    	}
    	else return 0;
    }
    if(c == 1){
    	for(int i=1;i<10;i++){
    		for(int j=10-i;j<10;j++){
    			if(j == 4 || i == 4) continue;
    			if((i+j)%10 == N[v]){
    				A[v] = i;
    				B[v] = j; 
    				if(f(v+1,0)) return 1;
    			}
    			if((i+j)%10 + 1 == N[v]){ 
    				A[v] = i;
    				B[v] = j;
    				if(f(v+1,1)) return 1;
    			}
    		}	
    	}
    	if(N[v] == 0){
	    	for(int i=1;i<9;i++){
	    		for(int j=9-i;i+j<10;j++){
	    			if(i ==4 || j == 4) continue;
	    			A[v] = i;
    				B[v] = j;
	    			if(f(v+1,1)) return 1;
	    		}
	    	}
    	}
    }
    else{
    	for(int i=0;i<10;i++){
    		for(int j=0;i+j<10 && j<9;j++){
    			if(j == 4 || i == 4) continue;
    			if((i+j)%10 == N[v]){
    				A[v] = i;
    				B[v] = j; 
    				if(f(v+1,0)) return 1;
    			}
    			if(i+j!=9){
    				A[v] = i;
    				B[v] = j;
    				if((i+j)%10 + 1 == N[v]) if(f(v+1,1)) return 1;
    			}
    		}
    	}
    }
}
int main(){
    int t;
    scanf("%d",&t);
    for(cnt = 1;cnt<=t;cnt++){
        scanf("%d",&n);
        vector<int> cmp;
       	while(n){
       		cmp.push_back(n%10);
       		n/=10;
       	}
       	size = cmp.size();
       	for(int i=size-1;i>=0;i--) N[size-1-i] = cmp[i];
        //printf("%d\n",size);
        f(0,0);
        printf("\n");
    }
}