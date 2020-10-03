//telegram : https://t.me/tempestas
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void setcolor(int ForgC){
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}


int main(void)
{
  system("color 07");
//print all colors
for(int i=1;i<17;i++){
setcolor(i);
printf("%d. color\n",i);
}

  getchar();
  return 0;
}
