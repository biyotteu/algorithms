#include <bits/stdc++.h>

using namespace std;

int main(){
	FILE *fp = fopen("C:/Users/tjqtj/Desktop/4.jpg","rb");
	fseek(fp,0,SEEK_END);
	int len = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char *buf = (char *)malloc(len);
	fread(buf,len,1,fp);
	bool bf = true;
	for()
}