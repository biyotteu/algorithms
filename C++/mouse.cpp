#include <Windows.h>
#include <stdio.h>

void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
 POINT a;
 HWND hWnd;
 int width=0;
 RECT window_size;

 a.x=0;
 a.y=0;
  

 while(1)
 {
  
  
  GetCursorPos(&a);
  hWnd=WindowFromPoint(a);
  ScreenToClient(hWnd,&a);
  GetWindowRect(hWnd, &window_size);
  width = (window_size.right-window_size.left);

  if((0<a.x)&&(a.x<(int)(width/2)))
  {
   gotoxy(1,30);
   printf("X point = %d, Y point = %d\n\r", a.x, a.y);
   }
  
  else if(((int)(width/2)<a.x)&&(a.x<(int)width))
  {
   gotoxy(1,30);
   printf("Y point = %d, X point = %d\n\r", a.y, a.x);
   }
  }
  Sleep(500);
 }

