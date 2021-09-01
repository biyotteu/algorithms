#include <stdio.h>

int main(){
	int i,k;
	FILE *wfp;
	wfp =  fopen("C:/tmp/gugu.txt","w");
	for(i=2;i<=9;i++)
		fprintf(wfp, "#제%d단# ",i);
	fprintf(wfp,"\n\n");
	for(i=1;i<=9;i++){
		for(k=2;k<=9;k++){
			switch(k){
				case 9:
					fprintf(wfp,"%dX %d= %d\n",k,i,k*i);
					break;
				default: 
					fprintf(wfp,"%dX %d= %d ",k,i,k*i);
			}
		}
	}
	fclose(wfp);
}