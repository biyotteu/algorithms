#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

void setcolor(int foreground,int background){
	int color = foreground + background*16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
}
int main(){
	setcolor(0,1);
	cout << ' ';
	setcolor(15,0);
	
}