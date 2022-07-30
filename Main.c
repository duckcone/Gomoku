#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "FiveInARow.h"

int main(int argc, char *argv[])
{
  char chessboard[19][19];
  char loc[] = "ABCDEFGHIJKLMNOPQRS";
  int i = 0, j = 0;
  int b = 0, w = 0;
  int quit = 0;
  int x=0, y=0;

  for(i=0;i<19;i++)
  {
    for(j=0;j<19;j++)
    {
      scanf(" %c",&chessboard[i][j]);
      if( chessboard[i][j]=='1')
        b++;
      else if(chessboard[i][j]=='0')
        w++;
    }
  }

/*
  printf("   A B C D E F G H I J K L M N O P Q R S\n");
  for (i = 0; i < 19; i++)
  {
    printf("%2d ", i + 1);
    for(j=0;j<19;j++)
    {
      printf("%c ", chessboard[i][j]);
    }
    printf("\n");
  }
*/

  if( (strcmp(argv[1],"Black")==0) && (b==0) && (w==0) )
  {
    printf("J, 10\n");
    exit(0);
  }

  char color;

  if( strcmp(argv[1],"Black")==0)
  {
    color = 'b';
  }
  else if(strcmp(argv[1],"White")==0)
  {
    color = 'w';
  }

  check4Winner(chessboard);
  beststep(color);
}
