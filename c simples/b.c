#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <ctype.h> 

/*
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47
*/

char getCHAR(int n)
{
	char ok[]="~!@#$%^&*:;'\",{}|<>=";
	return ok[n];
}

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
 
void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

int main(void) {
    char name[20];
    int x,y,l,n;
	long int i,j;
    printf("Please type a name (max 20 character):\t");
    fgets(name,20,stdin);
	i=j=0;
    char color[6][10]= {"\033[1;32m","\033[1;33m","\033[1;34m","\033[1;35m","\033[1;36m","\033[1;37m"};//color list لیست رنگها
	x=1; y=20;
	system("clear");
    n = 0;
	while(!kbhit())
	{
        if(n == strlen(name)){
            n = 0;
        }
        //l = rand() % strlen(name)-1; // (l) is random character position
		x=rand()%((150-1+1)+1);
		y=rand()%((50-1+1)+1);
		gotoxy(x,y);
        sleep(1);
        system("clear");
        printf("%s", color[rand()%5]);
		printf("%c", toupper(name[n]));
        n++;
	}
    return 0;
}