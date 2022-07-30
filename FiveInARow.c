#include <stdio.h>
#include "FiveInARow.h"

int BBR[19][19];
int WBR[19][19];
int btemp = 0;
int wtemp = 0;


void blackcompare(int i, int j, int br)
{
  int k, l;
  if (BBR[i][j] < br)
    BBR[i][j] = br;
  else if(BBR[i][j]==br)
    BBR[i][j] += 1;

  for (k = 0; k < 19; k++)
  {
    for (l = 0; l < 19; l++)
    {
      printf("At %d %d BR is %d \n", k, l, BBR[k][l]);
    }
  }
    
}

void whitecompare(int i, int j, int br)
{
  if(WBR[i][j]<br)
    WBR[i][j] = br;
  else if(WBR[i][j]==br)
    WBR[i][j] += 1;
}


//==================判斷連五========================
/*Player checkHorizontal(char (*p)[5]) //判斷橫向連五
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkVertical(char (*p)[19]) //判斷垂直連五
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkDiagonal(char (*p)[19])//判斷右下連五
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}

Player checkBackDiagonal(char (*p)[19])//判斷左下連五
{
  int i,b=0,w=0;
  for(i=0;i<5;i++)
  {
    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if(b==5) return Black;
  else if(w==5) return White;
  else return None;
}*/

//=============location of live 4==================
struct Live4point Blive4point[300];
struct Live4point Wlive4point[300];
int b = 0, w = 0;

void locationLive4(Player live4, int i, int j, int d)
{
  
  if(live4==Black)
  {
    switch(d)
    {
      case 0:
        blackcompare(i, j, 611);
        blackcompare(i, j+5, 611);
        Blive4point[b].y = i;
        Blive4point[b].x = j;
        Blive4point[b].direct = d;
        b++;
        Blive4point[b].y = i;
        Blive4point[b].x = j+5;
        Blive4point[b].direct = d;
        b++;
        break;
      case 45:
        blackcompare(i, j, 611);
        blackcompare(i+5, j+5, 611);
        Blive4point[b].y = i;
        Blive4point[b].x = j;
        Blive4point[b].direct = d;
        b++;
        Blive4point[b].y = i+5;
        Blive4point[b].x = j+5;
        Blive4point[b].direct = d;
        b++;
        break;
      case 90:
        blackcompare(i, j, 611);
        blackcompare(i+5, j, 611);
        Blive4point[b].y = i;
        Blive4point[b].x = j;
        Blive4point[b].direct = d;
        b++;
        Blive4point[b].y = i+5;
        Blive4point[b].x = j;
        Blive4point[b].direct = d;
        b++;
        break;
      case 135:
        blackcompare(i, j, 611);
        blackcompare(i-5, j+5, 611);
        Blive4point[b].y = i;
        Blive4point[b].x = j;
        Blive4point[b].direct = d;
        b++;
        Blive4point[b].y = i-5;
        Blive4point[b].x = j+5;
        Blive4point[b].direct = d;
        b++;
        break;
    }
   
  }
  else if(live4==White)
  {
    switch(d)
    {
      case 0:
        whitecompare(i, j, 611);
        whitecompare(i, j+5, 611);
        Wlive4point[w].y = i;
        Wlive4point[w].x = j;
        Wlive4point[w].direct = d;
        w++;
        Wlive4point[w].y = i;
        Wlive4point[w].x = j+5;
        Wlive4point[w].direct = d;
        w++;
        break;
      case 45:
        whitecompare(i, j, 611);
        whitecompare(i+5, j+5, 611);
        Wlive4point[w].y = i;
        Wlive4point[w].x = j;
        Wlive4point[w].direct = d;
        w++;
        Wlive4point[w].y = i+5;
        Wlive4point[w].x = j+5;
        Wlive4point[w].direct = d;
        w++;
        break;
      case 90:
        whitecompare(i, j, 611);
        whitecompare(i+5, j, 611);
        Wlive4point[w].y = i;
        Wlive4point[w].x = j;
        Wlive4point[w].direct = d;
        w++;
        Wlive4point[w].y = i+5;
        Wlive4point[w].x = j;
        Wlive4point[w].direct = d;
        w++;
        break;
      case 135:
        whitecompare(i, j, 611);
        whitecompare(i-5, j+5, 611);
        Wlive4point[w].y = i;
        Wlive4point[w].x = j;
        Wlive4point[w].direct = d;
        w++;
        Wlive4point[w].y = i-5;
        Wlive4point[w].x = j+5;
        Wlive4point[w].direct = d;
        w++;
        break;
    }
  }
}

struct Dead4point Bdead4point[300];
struct Dead4point Wdead4point[300];
int bb=0, ww=0;

struct Jump4point Bjump4point[300];
struct Jump4point Wjump4point[300];
int bj4 = 0, wj4 = 0;

//============location of live 3==============
struct Live3point Blive3point[300];
struct Live3point Wlive3point[300];
int bl3 = 0, wl3 = 0;

void locationLive3(Player live3, int i, int j, int d)
{
  
  if(live3==Black)
  {
    switch(d)
    {
      case 0:
        blackcompare(i, j, 411);
        blackcompare(i, j+4, 411);
        Blive3point[bl3].y = i;
        Blive3point[bl3].x = j;
        Blive3point[bl3].direct = d;
        bl3++;
        Blive3point[bl3].y = i;
        Blive3point[bl3].x = j+4;
        Blive3point[bl3].direct = d;
        bl3++;
        break;
      case 45:
        blackcompare(i, j, 411);
        blackcompare(i+4, j+4, 411);
        Blive3point[bl3].y = i;
        Blive3point[bl3].x = j;
        Blive3point[bl3].direct = d;
        bl3++;
        Blive3point[bl3].y = i+4;
        Blive3point[bl3].x = j+4;
        Blive3point[bl3].direct = d;
        bl3++;
        break;
      case 90:
        blackcompare(i, j, 411);
        blackcompare(i+4, j, 411);
        Blive3point[bl3].y = i;
        Blive3point[bl3].x = j;
        Blive3point[bl3].direct = d;
        bl3++;
        Blive3point[bl3].y = i+4;
        Blive3point[bl3].x = j;
        Blive3point[bl3].direct = d;
        bl3++;
        break;
      case 135:
        blackcompare(i, j, 411);
        blackcompare(i-4, j+4, 411);
        Blive3point[bl3].y = i;
        Blive3point[bl3].x = j;
        Blive3point[bl3].direct = d;
        bl3++;
        Blive3point[bl3].y = i-4;
        Blive3point[bl3].x = j+4;
        Blive3point[bl3].direct = d;
        bl3++;
        break;
    }
  }
  else if(live3==White)
  {
    switch(d)
    {
      case 0:
        whitecompare(i, j, 411);
        whitecompare(i, j+4, 411);
        Wlive3point[wl3].y = i;
        Wlive3point[wl3].x = j;
        Wlive3point[wl3].direct = d;
        wl3++;
        Wlive3point[wl3].y = i;
        Wlive3point[wl3].x = j+4;
        Wlive3point[wl3].direct = d;
        wl3++;
        break;
      case 45:
        whitecompare(i, j, 411);
        whitecompare(i+4, j+4, 411);
        Wlive3point[wl3].y = i;
        Wlive3point[wl3].x = j;
        Wlive3point[wl3].direct = d;
        wl3++;
        Wlive3point[wl3].y = i+4;
        Wlive3point[wl3].x = j+4;
        Wlive3point[wl3].direct = d;
        wl3++;
        break;
      case 90:
        whitecompare(i, j, 411);
        whitecompare(i+4, j, 411);
        Wlive3point[wl3].y = i;
        Wlive3point[wl3].x = j;
        Wlive3point[wl3].direct = d;
        wl3++;
        Wlive3point[wl3].y = i+4;
        Wlive3point[wl3].x = j;
        Wlive3point[wl3].direct = d;
        wl3++;
        break;
      case 135:
        whitecompare(i, j, 411);
        whitecompare(i-4, j+4, 411);
        Wlive3point[wl3].y = i;
        Wlive3point[wl3].x = j;
        Wlive3point[wl3].direct = d;
        wl3++;
        Wlive3point[wl3].y = i-4;
        Wlive3point[wl3].x = j+4;
        Wlive3point[wl3].direct = d;
        wl3++;
        break;
    }
  }
}

struct Dead3point Bdead3point[300];
struct Dead3point Wdead3point[300];
int bd3 = 0, wd3 = 0;

struct Jump3point Bjump3point[300];
struct Jump3point Wjump3point[300];
int bj3 = 0, wj3 = 0;



//==============location of live 2============
struct Live2point Blive2point[300];
struct Live2point Wlive2point[300];
int bl2 = 0, wl2 = 0;

void locationLive2(Player live2, int i, int j, int d)
{
  if(live2==Black)
  {
    switch(d)
    {
      case 0:
        blackcompare(i, j, 311);
        blackcompare(i, j+3, 311);
        Blive2point[bl2].y = i;
        Blive2point[bl2].x = j;
        Blive2point[bl2].direct = d;
        bl2++;
        Blive2point[bl2].y = i;
        Blive2point[bl2].x = j+3;
        Blive2point[bl2].direct = d;
        bl2++;
        break;
      case 45:
        blackcompare(i, j, 311);
        blackcompare(i+3, j+3, 311);
        Blive2point[bl2].y = i;
        Blive2point[bl2].x = j;
        Blive2point[bl2].direct = d;
        bl2++;
        Blive2point[bl2].y = i+3;
        Blive2point[bl2].x = j+3;
        Blive2point[bl2].direct = d;
        bl2++;
        break;
      case 90:
        blackcompare(i, j, 311);
        blackcompare(i+3, j, 311);
        Blive2point[bl2].y = i;
        Blive2point[bl2].x = j;
        Blive2point[bl2].direct = d;
        bl2++;
        Blive2point[bl2].y = i+3;
        Blive2point[bl2].x = j;
        Blive2point[bl2].direct = d;
        bl2++;
        break;
      case 135:
        blackcompare(i, j, 311);
        blackcompare(i-3, j+3, 311);
        Blive2point[bl2].y = i;
        Blive2point[bl2].x = j;
        Blive2point[bl2].direct = d;
        bl2++;
        Blive2point[bl2].y = i-3;
        Blive2point[bl2].x = j+3;
        Blive2point[bl2].direct = d;
        bl2++;
        break;
    } 
  }
  else if(live2==White)
  {
    switch(d)
    {
      case 0:
        whitecompare(i, j, 311);
        whitecompare(i, j+3, 311);
        Wlive2point[wl2].y = i;
        Wlive2point[wl2].x = j;
        Wlive2point[wl2].direct = d;
        wl2++;
        Wlive2point[wl2].y = i;
        Wlive2point[wl2].x = j+3;
        Wlive2point[wl2].direct = d;
        wl2++;
        break;
      case 45:
        whitecompare(i, j, 311);
        whitecompare(i+3, j+3, 311);
        Wlive2point[wl2].y = i;
        Wlive2point[wl2].x = j;
        Wlive2point[wl2].direct = d;
        wl2++;
        Wlive2point[wl2].y = i+3;
        Wlive2point[wl2].x = j+3;
        Wlive2point[wl2].direct = d;
        wl2++;
        break;
      case 90:
        whitecompare(i, j, 311);
        whitecompare(i+3, j, 311);
        Wlive2point[wl2].y = i;
        Wlive2point[wl2].x = j;
        Wlive2point[wl2].direct = d;
        wl2++;
        Wlive2point[wl2].y = i+3;
        Wlive2point[wl2].x = j;
        Wlive2point[wl2].direct = d;
        wl2++;
        break;
      case 135:
        whitecompare(i, j, 311);
        whitecompare(i-3, j+3, 311);
        Wlive2point[wl2].y = i;
        Wlive2point[wl2].x = j;
        Wlive2point[wl2].direct = d;
        wl2++;
        Wlive2point[wl2].y = i-3;
        Wlive2point[wl2].x = j+3;
        Wlive2point[wl2].direct = d;
        wl2++;
        break;
    }
  }
}

struct Dead2point Bdead2point[300];
struct Dead2point Wdead2point[300];
int bd2 = 0, wd2 = 0;

struct Jump2point Bjump2point[300];
struct Jump2point Wjump2point[300];
int bj2 = 0, wj2 = 0;

//==============location of live 1===========
struct Live1point Blive1point[300];
struct Live1point Wlive1point[300];
int bl1 = 0, wl1 = 0;

void locationLive1(Player live1, int i, int j, int d)
{
  if(live1==Black)
  {
    switch(d)
    {
      case 0:
        blackcompare(i, j, 211);
        blackcompare(i, j+2, 211);
        Blive1point[bl1].y = i;
        Blive1point[bl1].x = j;
        Blive1point[bl1].direct = d;
        bl1++;
        Blive1point[bl1].y = i;
        Blive1point[bl1].x = j+2;
        Blive1point[bl1].direct = d;
        bl1++;
        break;
      case 45:
        blackcompare(i, j, 211);
        blackcompare(i+2, j+2, 211);
        Blive1point[bl1].y = i;
        Blive1point[bl1].x = j;
        Blive1point[bl1].direct = d;
        bl1++;
        Blive1point[bl1].y = i+2;
        Blive1point[bl1].x = j+2;
        Blive1point[bl1].direct = d;
        bl1++;
        break;
      case 90:
        blackcompare(i, j, 211);
        blackcompare(i+2, j, 211);
        Blive1point[bl1].y = i;
        Blive1point[bl1].x = j;
        Blive1point[bl1].direct = d;
        bl1++;
        Blive1point[bl1].y = i+2;
        Blive1point[bl1].x = j;
        Blive1point[bl1].direct = d;
        bl1++;
        break;
      case 135:
        blackcompare(i, j, 211);
        blackcompare(i-2, j+2, 211);
        Blive1point[bl1].y = i;
        Blive1point[bl1].x = j;
        Blive1point[bl1].direct = d;
        bl1++;
        Blive1point[bl1].y = i-2;
        Blive1point[bl1].x = j+2;
        Blive1point[bl1].direct = d;
        bl1++;
        break;
    } 
  }
  else if(live1==White)
  {
    switch(d)
    {
      case 0:
        whitecompare(i, j, 211);
        whitecompare(i, j+2, 211);
        Wlive1point[wl1].y = i;
        Wlive1point[wl1].x = j;
        Wlive1point[wl1].direct = d;
        wl1++;
        Wlive1point[wl1].y = i;
        Wlive1point[wl1].x = j+2;
        Wlive1point[wl1].direct = d;
        wl1++;
        break;
      case 45:
        whitecompare(i, j, 211);
        whitecompare(i+2, j+2, 211);
        Wlive1point[wl1].y = i;
        Wlive1point[wl1].x = j;
        Wlive1point[wl1].direct = d;
        wl1++;
        Wlive1point[wl1].y = i+2;
        Wlive1point[wl1].x = j+2;
        Wlive1point[wl1].direct = d;
        wl1++;
      case 90:
        whitecompare(i, j, 211);
        whitecompare(i+2, j, 211);
        Wlive1point[wl1].y = i;
        Wlive1point[wl1].x = j;
        Wlive1point[wl1].direct = d;
        wl1++;
        Wlive1point[wl1].y = i+2;
        Wlive1point[wl1].x = j;
        Wlive1point[wl1].direct = d;
        wl1++;
        break;
      case 135:
        whitecompare(i, j, 211);
        whitecompare(i-2, j+2, 211);
        Wlive1point[wl1].y = i;
        Wlive1point[wl1].x = j;
        Wlive1point[wl1].direct = d;
        wl1++;
        Wlive1point[wl1].y = i-2;
        Wlive1point[wl1].x = j+2;
        Wlive1point[wl1].direct = d;
        wl1++;
        
        break;
    }
  }
}

struct Dead1point Bdead1point[300];
struct Dead1point Wdead1point[300];
int bd1 = 0, wd1 = 0;

//============判斷活一====================
Player live1Horizontal(char (*p)[3])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<3;i++)
  {
    if((i==0 || i==2) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if((b==1) && (j==2)) return Black;
  else if((w==1) && (j==2)) return White;
  else return None;
}

Player live1Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<3;i++)
  {
    if((i==0 || i==2) && (*p[i]==46))
      j++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if((b==1) && (j==2)) return Black;
  else if((w==1) && (j==2)) return White;
  else return None;
}

Player live1Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<3;i++)
  {
    if((i==0 || i==2) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }

  if((b==1) && (j==2)) return Black;
  else if((w==1) && (j==2)) return White;
  else return None;
}

Player live1BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<3;i++)
  {
    if((i==0 || i==2) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }

  if((b==1) && (j==2)) return Black;
  else if((w==1) && (j==2)) return White;
  else return None;
}

//===============判斷死一=======================

SekiroD1 dead1Horizontal(char (*p)[3]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 3; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (b==1) && (w==1) && (deadA==2) ) return Blackcenter_white;//開頭位置沒有棋子，結尾白   X10
  if( (b==1) && (w==1) && (deadB==2) ) return White_blackcenter;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==1) && (deadC==2) ) return Whitecenter_black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==1) && (deadD==2) ) return Black_whitecenter;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD1 dead1Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 3; i++)
  {
    if( (i==0 && *p[i]==46) || (i==2 && *p[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==2 && *p[i]==46) || (i==0 && *p[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && *p[i]==46) || (i==2 && *p[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==2 && *p[i]==46) || (i==0 && *p[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (b==1) && (w==1) && (deadA==2) ) return Blackcenter_white;//開頭位置沒有棋子，結尾白   X10
  if( (b==1) && (w==1) && (deadB==2) ) return White_blackcenter;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==1) && (deadC==2) ) return Whitecenter_black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==1) && (deadD==2) ) return Black_whitecenter;//開頭位置黑，結尾沒有棋子   10X
  else return None;

}

SekiroD1 dead1Diagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 3; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (b==1) && (w==1) && (deadA==2) ) return Blackcenter_white;//開頭位置沒有棋子，結尾白   X10
  if( (b==1) && (w==1) && (deadB==2) ) return White_blackcenter;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==1) && (deadC==2) ) return Whitecenter_black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==1) && (deadD==2) ) return Black_whitecenter;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD1 dead1BackDiagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 3; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==2 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==2 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (b==1) && (w==1) && (deadA==2) ) return Blackcenter_white;//開頭位置沒有棋子，結尾白   X10
  if( (b==1) && (w==1) && (deadB==2) ) return White_blackcenter;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==1) && (deadC==2) ) return Whitecenter_black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==1) && (deadD==2) ) return Black_whitecenter;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

//==================貼牆死一=======================
SekiroWallD1 walldead1Horizontal(char (*p)[2], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 2; i++)
  {
    if( i==1 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (e==0) && (b==1) && (deadA==1) ) return Wallblack;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==1) && (deadB==1) ) return Blackwall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==1) && (deadA==1) ) return Wallwhite;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==1) && (deadB==1) ) return Whitewall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD1 walldead1Vertical(char (*p)[19], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 2; i++)
  {
    if( i==1 && *p[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && *p[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (e==0) && (b==1) && (deadA==1) ) return Wallblack;//黑上牆，結尾沒有棋子   |1X
  if( (e==1) && (b==1) && (deadB==1) ) return Blackwall;//開頭沒棋子，黑下牆     X1|
  if( (e==0) && (w==1) && (deadA==1) ) return Wallwhite;//白上牆，結尾沒有棋子   |0X
  if( (e==1) && (w==1) && (deadB==1) ) return Whitewall;//開頭沒棋子，白下牆     X0|
  else return None;
}

SekiroWallD1 walldead1Diagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 2; i++)
  {
    if( i==1 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (e==0) && (b==1) && (deadA==1) ) return Wallblack;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==1) && (deadB==1) ) return Blackwall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==1) && (deadA==1) ) return Wallwhite;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==1) && (deadB==1) ) return Whitewall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD1 walldead1BackDiagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 2; i++)
  {
    if( i==1 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (e==0) && (b==1) && (deadA==1) ) return Wallblack;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==1) && (deadB==1) ) return Blackwall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==1) && (deadA==1) ) return Wallwhite;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==1) && (deadB==1) ) return Whitewall;//開頭沒棋子，白右牆     X0|
  else return None;
}

//===============判斷活二=======================
Player live2Horizontal(char (*p)[4])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<4;i++)
  {
    if((i==0 || i==3) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if((b==2) && (j==2)) return Black;
  else if((w==2) && (j==2)) return White;
  else return None;
}

Player live2Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<4;i++)
  {
    if((i==0 || i==3) && (*p[i]==46))
      j++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if((b==2) && (j==2)) return Black;
  else if((w==2) && (j==2)) return White;
  else return None;
}

Player live2Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<4;i++)
  {
    if((i==0 || i==3) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }

  if((b==2) && (j==2)) return Black;
  else if((w==2) && (j==2)) return White;
  else return None;
}

Player live2BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<4;i++)
  {
    if((i==0 || i==3) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }

  if((b==2) && (j==2)) return Black;
  else if((w==2) && (j==2)) return White;
  else return None;
}

//===============判斷死二===============
SekiroD2 dead2Horizontal(char (*p)[4]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 4; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (b==2) && (w==1) && (deadA==2) ) return Black2white;//開頭位置沒有棋子，結尾白   X10
  if( (b==2) && (w==1) && (deadB==2) ) return Whiteblack2;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==2) && (deadC==2) ) return White2black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==2) && (deadD==2) ) return Blackwhite2;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD2 dead2Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 4; i++)
  {
    if( (i==0 && *p[i]==46) || (i==3 && *p[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==3 && *p[i]==46) || (i==0 && *p[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && *p[i]==46) || (i==3 && *p[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==3 && *p[i]==46) || (i==0 && *p[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (b==2) && (w==1) && (deadA==2) ) return Black2white;//開頭位置沒有棋子，結尾白   X10
  if( (b==2) && (w==1) && (deadB==2) ) return Whiteblack2;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==2) && (deadC==2) ) return White2black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==2) && (deadD==2) ) return Blackwhite2;//開頭位置黑，結尾沒有棋子   10X
  else return None;

}

SekiroD2 dead2Diagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 4; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (b==2) && (w==1) && (deadA==2) ) return Black2white;//開頭位置沒有棋子，結尾白   X10
  if( (b==2) && (w==1) && (deadB==2) ) return Whiteblack2;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==2) && (deadC==2) ) return White2black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==2) && (deadD==2) ) return Blackwhite2;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD2 dead2BackDiagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 4; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==3 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==3 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (b==2) && (w==1) && (deadA==2) ) return Black2white;//開頭位置沒有棋子，結尾白   X10
  if( (b==2) && (w==1) && (deadB==2) ) return Whiteblack2;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==2) && (deadC==2) ) return White2black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==2) && (deadD==2) ) return Blackwhite2;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

//=================貼牆死二===============
SekiroWallD2 walldead2Horizontal(char (*p)[3], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 3; i++)
  {
    if( i==2 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (e==0) && (b==2) && (deadA==1) ) return Wallblack2;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==2) && (deadB==1) ) return Black2wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==2) && (deadA==1) ) return Wallwhite2;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==2) && (deadB==1) ) return White2wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD2 walldead2Vertical(char (*p)[19], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 3; i++)
  {
    if( i==2 && *p[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && *p[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (e==0) && (b==2) && (deadA==1) ) return Wallblack2;//黑上牆，結尾沒有棋子   |1X
  if( (e==1) && (b==2) && (deadB==1) ) return Black2wall;//開頭沒棋子，黑下牆     X1|
  if( (e==0) && (w==2) && (deadA==1) ) return Wallwhite2;//白上牆，結尾沒有棋子   |0X
  if( (e==1) && (w==2) && (deadB==1) ) return White2wall;//開頭沒棋子，白下牆     X0|
  else return None;
}

SekiroWallD2 walldead2Diagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 3; i++)
  {
    if( i==2 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (e==0) && (b==2) && (deadA==1) ) return Wallblack2;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==2) && (deadB==1) ) return Black2wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==2) && (deadA==1) ) return Wallwhite2;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==2) && (deadB==1) ) return White2wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD2 walldead2BackDiagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 3; i++)
  {
    if( i==2 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (e==0) && (b==2) && (deadA==1) ) return Wallblack2;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==2) && (deadB==1) ) return Black2wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==2) && (deadA==1) ) return Wallwhite2;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==2) && (deadB==1) ) return White2wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

//==================判斷跳二====================
SekiroJ2 jump2Horizontal(char (*p)[5])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    
    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
  }
  if((b==2) && (j==2) && (jumpA==1)) return Black11;
  if((w==2) && (j==2) && (jumpA==1)) return White11;
  else return None;
}

SekiroJ2 jump2Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] == 46))
      j++;

    if(i == 2 && *p[i] == 46)
      jumpA++;
    
    if (*p[i] == Black)
      b++;
    else if (*p[i] == White)
      w++;
  }
  if((b==2) && (j==2) && (jumpA==1)) return Black11;
  if((w==2) && (j==2) && (jumpA==1)) return White11;
  else return None;
}

SekiroJ2 jump2Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    
    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p++;
  }
  if((b==2) && (j==2) && (jumpA==1)) return Black11;
  if((w==2) && (j==2) && (jumpA==1)) return White11;
  else return None;
}

SekiroJ2 jump2BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    
    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p--;
  }
  if((b==2) && (j==2) && (jumpA==1)) return Black11;
  if((w==2) && (j==2) && (jumpA==1)) return White11;
  else return None;
}



//==================判斷活三========================
Player live3Horizontal(char (*p)[5])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<5;i++)
  {
    if((i==0 || i==4) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if((b==3) && (j==2)) return Black;
  else if((w==3) && (j==2)) return White;
  else return None;

}

Player live3Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<5;i++)
  {
    if((i==0 || i==4) && (*p[i]==46))
      j++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if((b==3) && (j==2)) return Black;
  else if((w==3) && (j==2)) return White;
  else return None;

}

Player live3Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<5;i++)
  {
    if((i==0 || i==4) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if((b==3) && (j==2)) return Black;
  else if((w==3) && (j==2)) return White;
  else return None;

}

Player live3BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<5;i++)
  {
    if((i==0 || i==4) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if((b==3) && (j==2)) return Black;
  else if((w==3) && (j==2)) return White;
  else return None;

}

//=================判斷死三==========================
SekiroD3 dead3Horizontal(char (*p)[5]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 5; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (b==3) && (w==1) && (deadA==2) ) return Black3white;//開頭位置沒有棋子，結尾白   X10
  if( (b==3) && (w==1) && (deadB==2) ) return Whiteblack3;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==3) && (deadC==2) ) return White3black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==3) && (deadD==2) ) return Blackwhite3;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD3 dead3Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 5; i++)
  {
    if( (i==0 && *p[i]==46) || (i==4 && *p[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==4 && *p[i]==46) || (i==0 && *p[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && *p[i]==46) || (i==4 && *p[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==4 && *p[i]==46) || (i==0 && *p[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (b==3) && (w==1) && (deadA==2) ) return Black3white;//開頭位置沒有棋子，結尾白   X10
  if( (b==3) && (w==1) && (deadB==2) ) return Whiteblack3;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==3) && (deadC==2) ) return White3black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==3) && (deadD==2) ) return Blackwhite3;//開頭位置黑，結尾沒有棋子   10X
  else return None;

}

SekiroD3 dead3Diagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 5; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (b==3) && (w==1) && (deadA==2) ) return Black3white;//開頭位置沒有棋子，結尾白   X10
  if( (b==3) && (w==1) && (deadB==2) ) return Whiteblack3;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==3) && (deadC==2) ) return White3black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==3) && (deadD==2) ) return Blackwhite3;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

SekiroD3 dead3BackDiagonal(char (*p)[19]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 5; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==4 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==4 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (b==3) && (w==1) && (deadA==2) ) return Black3white;//開頭位置沒有棋子，結尾白   X10
  if( (b==3) && (w==1) && (deadB==2) ) return Whiteblack3;//開頭位置白，結尾沒有棋子   01X
  if( (b==1) && (w==3) && (deadC==2) ) return White3black;//開頭位置沒有棋子，結尾黑   X01
  if( (b==1) && (w==3) && (deadD==2) ) return Blackwhite3;//開頭位置黑，結尾沒有棋子   10X
  else return None;
}

//===============貼牆死三=========================
SekiroWallD3 walldead3Horizontal(char (*p)[4], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 4; i++)
  {
    if( i==3 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (e==0) && (b==3) && (deadA==1) ) return Wallblack3;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==3) && (deadB==1) ) return Black3wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==3) && (deadA==1) ) return Wallwhite3;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==3) && (deadB==1) ) return White3wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD3 walldead3Vertical(char (*p)[19], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 4; i++)
  {
    if( i==3 && *p[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && *p[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (e==0) && (b==3) && (deadA==1) ) return Wallblack3;//黑上牆，結尾沒有棋子   |1X
  if( (e==1) && (b==3) && (deadB==1) ) return Black3wall;//開頭沒棋子，黑下牆     X1|
  if( (e==0) && (w==3) && (deadA==1) ) return Wallwhite3;//白上牆，結尾沒有棋子   |0X
  if( (e==1) && (w==3) && (deadB==1) ) return White3wall;//開頭沒棋子，白下牆     X0|
  else return None;
}

SekiroWallD3 walldead3Diagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 4; i++)
  {
    if( i==3 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (e==0) && (b==3) && (deadA==1) ) return Wallblack3;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==3) && (deadB==1) ) return Black3wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==3) && (deadA==1) ) return Wallwhite3;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==3) && (deadB==1) ) return White3wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

SekiroWallD3 walldead3BackDiagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 4; i++)
  {
    if( i==3 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (e==0) && (b==3) && (deadA==1) ) return Wallblack3;//黑左牆，結尾沒有棋子   |1X
  if( (e==1) && (b==3) && (deadB==1) ) return Black3wall;//開頭沒棋子，黑右牆     X1|
  if( (e==0) && (w==3) && (deadA==1) ) return Wallwhite3;//白左牆，結尾沒有棋子   |0X
  if( (e==1) && (w==3) && (deadB==1) ) return White3wall;//開頭沒棋子，白右牆     X0|
  else return None;
}

//=================判斷跳三=========================
SekiroJ3 jump3Horizontal(char (*p)[6])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0;

  for (i = 0; i < 6; i++)
  {
    if ((i == 0 || i == 5) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    if(i == 3 && (*p)[i] == 46)
      jumpB++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
  }
  if((b==3) && (j==2) && (jumpA==1)) return Black12;
  if((b==3) && (j==2) && (jumpB==1)) return Black21;
  if((w==3) && (j==2) && (jumpA==1)) return White12;
  if((w==3) && (j==2) && (jumpB==1)) return White21;
  else return None;
}

SekiroJ3 jump3Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0;

  for (i = 0; i < 6; i++)
  {
    if ((i == 0 || i == 5) && (*p[i] == 46))
      j++;

    if(i == 2 && *p[i] == 46)
      jumpA++;
    if(i == 3 && *p[i] == 46)
      jumpB++;

    if (*p[i] == Black)
      b++;
    else if (*p[i] == White)
      w++;
  }
  if((b==3) && (j==2) && (jumpA==1)) return Black12;
  if((b==3) && (j==2) && (jumpB==1)) return Black21;
  if((w==3) && (j==2) && (jumpA==1)) return White12;
  if((w==3) && (j==2) && (jumpB==1)) return White21;
  else return None;
}

SekiroJ3 jump3Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0;

  for (i = 0; i < 6; i++)
  {
    if ((i == 0 || i == 5) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    if(i == 3 && (*p)[i] == 46)
      jumpB++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p++;
  }
  if((b==3) && (j==2) && (jumpA==1)) return Black12;
  if((b==3) && (j==2) && (jumpB==1)) return Black21;
  if((w==3) && (j==2) && (jumpA==1)) return White12;
  if((w==3) && (j==2) && (jumpB==1)) return White21;
  else return None;
}

SekiroJ3 jump3BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0;

  for (i = 0; i < 6; i++)
  {
    if ((i == 0 || i == 5) && ((*p)[i] == 46))
      j++;

    if(i == 2 && (*p)[i] == 46)
      jumpA++;
    if(i == 3 && (*p)[i] == 46)
      jumpB++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p--;
  }
  if((b==3) && (j==2) && (jumpA==1)) return Black12;
  if((b==3) && (j==2) && (jumpB==1)) return Black21;
  if((w==3) && (j==2) && (jumpA==1)) return White12;
  if((w==3) && (j==2) && (jumpB==1)) return White21;
  else return None;
}


//==================判斷活四========================
Player live4Horizontal(char (*p)[6]) //判斷橫向活四
{
  int i, j=0, b=0,w=0;
  
  for(i=0;i<6;i++)
  {
    if((i==0 || i==5) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if((b==4) && (j==2)) return Black;
  else if((w==4) && (j==2)) return White;
  else return None;

}

Player live4Vertical(char (*p)[19]) //判斷垂直活四
{
  int i, j=0, b=0,w=0;
  for(i=0;i<6;i++)
  {
    if((i==0 || i==5) && *p[i]==46)
      j++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if((b==4) && (j==2)) return Black;
  else if((w==4) && (j==2)) return White;
  else return None;
}

Player live4Diagonal(char (*p)[19])//判斷右下活四
{
  int i, j=0, b=0,w=0;
  for(i=0;i<6;i++)
  {
    if((i==0 || i==5) && ((*p)[i]==46))
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if((b==4) && (j==2)) return Black;
  else if((w==4) && (j==2)) return White;
  else return None;
}

Player live4BackDiagonal(char (*p)[19])//判斷左下活四
{
  int i, j=0, b=0,w=0;
  for(i=0;i<6;i++)
  {
    if( (i==0 || i==5) && (*p)[i]==46 )
      j++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if((b==4) && (j==2)) return Black;
  else if((w==4) && (j==2)) return White;
  else return None;
}
//==================判斷死四========================

SekiroD4 dead4Horizontal(char (*p)[6]) //判斷橫向死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 6; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (b==4) && (w==1) && (deadA==2) ) return Black4white;//黑4白1 開頭位置沒有棋子，結尾白   X11110
  if( (b==4) && (w==1) && (deadB==2) ) return Whiteblack4;//白1黑4 開頭位置白，結尾沒有棋子   01111X
  if( (b==1) && (w==4) && (deadC==2) ) return White4black;//白4黑1 開頭位置沒有棋子，結尾黑   X00001
  if( (b==1) && (w==4) && (deadD==2) ) return Blackwhite4;//黑1白4 開頭位置黑，結尾沒有棋子   10000X
  else return None;

}

SekiroD4 dead4Vertical(char (*p)[19]) //判斷垂直死四
{
 int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 6; i++)
  {
    if( (i==0 && *p[i]==46) || (i==5 && *p[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==5 && *p[i]==46) || (i==0 && *p[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && *p[i]==46) || (i==5 && *p[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==5 && *p[i]==46) || (i==0 && *p[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (b==4) && (w==1) && (deadA==2) ) return Black4white;//黑4白1 開頭位置沒有棋子，結尾白   X11110
  if( (b==4) && (w==1) && (deadB==2) ) return Whiteblack4;//白1黑4 開頭位置白，結尾沒有棋子   01111X
  if( (b==1) && (w==4) && (deadC==2) ) return White4black;//白4黑1 開頭位置沒有棋子，結尾黑   X00001
  if( (b==1) && (w==4) && (deadD==2) ) return Blackwhite4;//黑1白4 開頭位置黑，結尾沒有棋子   10000X
  else return None;
}

SekiroD4 dead4Diagonal(char (*p)[19])//判斷右下死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
  for (i = 0; i < 6; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (b==4) && (w==1) && (deadA==2) ) return Black4white;//黑4白1 開頭位置沒有棋子，結尾白   X11110
  if( (b==4) && (w==1) && (deadB==2) ) return Whiteblack4;//白1黑4 開頭位置白，結尾沒有棋子   01111X
  if( (b==1) && (w==4) && (deadC==2) ) return White4black;//白4黑1 開頭位置沒有棋子，結尾黑   X00001
  if( (b==1) && (w==4) && (deadD==2) ) return Blackwhite4;//黑1白4 開頭位置黑，結尾沒有棋子   10000X
  else return None;
}

SekiroD4 dead4BackDiagonal(char (*p)[19])//判斷左下死四
{
  int i=0, j=0, b=0,w=0;
  int deadA=0, deadB=0, deadC=0, deadD=0;
 for (i = 0; i < 6; i++)
  {
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==White) )//開頭位置沒有棋子，結尾白
      deadA++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==White) )//開頭位置白，結尾沒有棋子
      deadB++;
    if( (i==0 && (*p)[i]==46) || (i==5 && (*p)[i]==Black) )//開頭位置沒有棋子，結尾黑
      deadC++;
    if( (i==5 && (*p)[i]==46) || (i==0 && (*p)[i]==Black) )//開頭位置黑，結尾沒有棋子
      deadD++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (b==4) && (w==1) && (deadA==2) ) return Black4white;//黑4白1 開頭位置沒有棋子，結尾白   X11110
  if( (b==4) && (w==1) && (deadB==2) ) return Whiteblack4;//白1黑4 開頭位置白，結尾沒有棋子   01111X
  if( (b==1) && (w==4) && (deadC==2) ) return White4black;//白4黑1 開頭位置沒有棋子，結尾黑   X00001
  if( (b==1) && (w==4) && (deadD==2) ) return Blackwhite4;//黑1白4 開頭位置黑，結尾沒有棋子   10000X
  else return None;
}

//================判斷貼牆死四======================
SekiroWallD4 walldead4Horizontal(char (*p)[5], int e) //判斷橫向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 5; i++)
  {
    if( i==4 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
  }
  if( (e==0) && (b==4) && (deadA==1) ) return Wallblack4;//黑四貼左牆，結尾沒有棋子   |1111X
  if( (e==1) && (b==4) && (deadB==1) ) return Black4wall;//開頭位置沒有棋子，黑四貼右牆   X1111|
  if( (e==0) && (w==4) && (deadA==1) ) return Wallwhite4;//白四貼左牆，結尾沒有棋子   |0000X
  if( (e==1) && (w==4) && (deadB==1) ) return White4wall;//開頭位置沒有棋子，白四貼右牆   X0000|
  else return None;
}

SekiroWallD4 walldead4Vertical(char (*p)[19], int e) //判斷直向貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 5; i++)
  {
    if( i==4 && *p[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && *p[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if(*p[i]==Black) b++;
    else if(*p[i]==White) w++;
  }
  if( (e==0) && (b==4) && (deadA==1) ) return Wallblack4;//黑四貼上牆，結尾沒有棋子   |1111X
  if( (e==1) && (b==4) && (deadB==1) ) return Black4wall;//開頭位置沒有棋子，黑四貼下牆   X1111|
  if( (e==0) && (w==4) && (deadA==1) ) return Wallwhite4;//白四貼上牆，結尾沒有棋子   |0000X
  if( (e==1) && (w==4) && (deadB==1) ) return White4wall;//開頭位置沒有棋子，白四貼下牆   X0000|
  else return None;
}

SekiroWallD4 walldead4Diagonal(char (*p)[19], int e) //右斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 5; i++)
  {
    if( i==4 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p++;
  }
  if( (e==0) && (b==4) && (deadA==1) ) return Wallblack4;//黑四貼上牆，結尾沒有棋子   |1111X
  if( (e==1) && (b==4) && (deadB==1) ) return Black4wall;//開頭位置沒有棋子，黑四貼下牆   X1111|
  if( (e==0) && (w==4) && (deadA==1) ) return Wallwhite4;//白四貼上牆，結尾沒有棋子   |0000X
  if( (e==1) && (w==4) && (deadB==1) ) return White4wall;//開頭位置沒有棋子，白四貼下牆   X0000|
  else return None;
}

SekiroWallD4 walldead4BackDiagonal(char (*p)[19], int e) //左斜貼牆死四
{
  int i, j=0, b=0,w=0;
  int deadA=0, deadB=0;
  for (i = 0; i < 5; i++)
  {
    if( i==4 && (*p)[i]==46 )//開頭位置牆，結尾無棋
      deadA++;
    if( i==0 && (*p)[i]==46 )//開頭位置無棋，結尾牆
      deadB++;

    if((*p)[i]==Black) b++;
    else if((*p)[i]==White) w++;
    p--;
  }
  if( (e==0) && (b==4) && (deadA==1) ) return Wallblack4;
  if( (e==1) && (b==4) && (deadB==1) ) return Black4wall;
  if( (e==0) && (w==4) && (deadA==1) ) return Wallwhite4;
  if( (e==1) && (w==4) && (deadB==1) ) return White4wall;
  else return None;
}

//==============判斷跳四==================
SekiroJ4 jump4Horizontal(char (*p)[5])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0, jumpC = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] != 46))
      j++;

    if(i == 1 && (*p)[i] == 46)
      jumpA++;
    if(i == 2 && (*p)[i] == 46)
      jumpB++;
    if(i == 3 && (*p)[i] == 46)
      jumpC++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
  }
  if((b==4) && (j==2) && (jumpA==1)) return Black13;
  if((b==4) && (j==2) && (jumpB==1)) return Black22;
  if((b==4) && (j==2) && (jumpC==1)) return Black31;
  if((w==4) && (j==2) && (jumpA==1)) return White13;
  if((w==4) && (j==2) && (jumpB==1)) return White22;
  if((w==4) && (j==2) && (jumpC==1)) return White31;
  else return None;
}

SekiroJ4 jump4Vertical(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0, jumpC = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && (*p[i] != 46))
      j++;

    if(i == 1 && *p[i] == 46)
      jumpA++;
    if(i == 2 && *p[i] == 46)
      jumpB++;
    if(i == 3 && *p[i] == 46)
      jumpC++;

    if (*p[i] == Black)
      b++;
    else if (*p[i] == White)
      w++;
  }
  if((b==4) && (j==2) && (jumpA==1)) return Black13;
  if((b==4) && (j==2) && (jumpB==1)) return Black22;
  if((b==4) && (j==2) && (jumpC==1)) return Black31;
  if((w==4) && (j==2) && (jumpA==1)) return White13;
  if((w==4) && (j==2) && (jumpB==1)) return White22;
  if((w==4) && (j==2) && (jumpC==1)) return White31;
  else return None;
}

SekiroJ4 jump4Diagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0, jumpC = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] != 46))
      j++;

    if(i == 1 && (*p)[i] == 46)
      jumpA++;
    if(i == 2 && (*p)[i] == 46)
      jumpB++;
    if(i == 3 && (*p)[i] == 46)
      jumpC++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p++;
  }
  if((b==4) && (j==2) && (jumpA==1)) return Black13;
  if((b==4) && (j==2) && (jumpB==1)) return Black22;
  if((b==4) && (j==2) && (jumpC==1)) return Black31;
  if((w==4) && (j==2) && (jumpA==1)) return White13;
  if((w==4) && (j==2) && (jumpB==1)) return White22;
  if((w==4) && (j==2) && (jumpC==1)) return White31;
  else return None;
}

SekiroJ4 jump4BackDiagonal(char (*p)[19])
{
  int i, j=0, b=0,w=0;
  int jumpA = 0, jumpB = 0, jumpC = 0;

  for (i = 0; i < 5; i++)
  {
    if ((i == 0 || i == 4) && ((*p)[i] != 46))
      j++;

    if(i == 1 && (*p)[i] == 46)
      jumpA++;
    if(i == 2 && (*p)[i] == 46)
      jumpB++;
    if(i == 3 && (*p)[i] == 46)
      jumpC++;

    if ((*p)[i] == Black)
      b++;
    else if ((*p)[i] == White)
      w++;
    p--;
  }
  if((b==4) && (j==2) && (jumpA==1)) return Black13;
  if((b==4) && (j==2) && (jumpB==1)) return Black22;
  if((b==4) && (j==2) && (jumpC==1)) return Black31;
  if((w==4) && (j==2) && (jumpA==1)) return White13;
  if((w==4) && (j==2) && (jumpB==1)) return White22;
  if((w==4) && (j==2) && (jumpC==1)) return White31;
  else return None;
}


//==================讀入判斷========================
Player check4Winner(char chessboard[19][19]) //判斷勝者
{
  int i,j, x;
  Player live4, dead4, walldead4, jump4;
  Player live3, dead3, walldead3, jump3;
  Player live2, dead2, walldead2, jump2;
  Player live1, dead1, walldead1;
 

  for(i=0;i<19;i++) 
  {
    for(j=0;j<19;j++)
    {    
      
      //===========活一判斷==========
      if(j<=16)
      {
        live1=live1Horizontal((char (*)[3])&chessboard[i][j]);
        locationLive1(live1, i, j, 0);
      }
      
      if(i<=16)
      {
        live1=live1Vertical((char (*)[19])&chessboard[i][j]);
        locationLive1(live1, i, j, 90);
      }

      if((i<=16) && (j<=16))
      {
        live1 = live1Diagonal((char(*)[19]) & chessboard[i][j]);
        locationLive1(live1, i, j, 45);
      }

      if((i<=16) && (j>=2))
      {
        live1 = live1BackDiagonal((char(*)[19]) & chessboard[i+2][j-2]);
        locationLive1(live1, i+2, j-2, 135);
      }
      
      //===========死一判斷=========
      if(j<=16)
      {
        dead1=dead1Horizontal((char (*)[3])&chessboard[i][j]);
        switch(dead1)
        {
          case Blackcenter_white:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case White_blackcenter:
            blackcompare(i, j+2, 201);
            Bdead1point[bd1].x = j+2;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Whitecenter_black:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          case Black_whitecenter:
            whitecompare(i, j+2, 201);
            Wdead1point[wd1].x = j+2;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          }
      }
      
      if(i<=16)
      {
        dead1=dead1Vertical((char (*)[19])&chessboard[i][j]);
        switch(dead1)
        {
          case Blackcenter_white:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case White_blackcenter:
            blackcompare(i+2, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i+2;
            bd1++;
            break;
          case Whitecenter_black:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          case Black_whitecenter:
            whitecompare(i+2, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i+2;
            wd1++;
            break;
        }

      }

      if((i<=16) && (j<=16))
      {
        dead1=dead1Diagonal((char (*)[19])&chessboard[i][j]);
        switch(dead1)
        {
          case Blackcenter_white:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case White_blackcenter:
            blackcompare(i+2, j+2, 201);
            Bdead1point[bd1].x = j+2;
            Bdead1point[bd1].y = i+2;
            bd1++;
            break;
          case Whitecenter_black:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          case Black_whitecenter:
            whitecompare(i+2, j+2, 201);
            Wdead1point[wd1].x = j+2;
            Wdead1point[wd1].y = i+2;
            wd1++;
            break;
        }

      }

      if((i<=16) && (j>=2))
      {
        dead1=dead1BackDiagonal((char (*)[19])&chessboard[i+2][j-2]);
        switch(dead1)
        {
          case Blackcenter_white:
            blackcompare(i+2, j-2, 201);
            Bdead1point[bd1].x = j-2;
            Bdead1point[bd1].y = i+2;
            bd1++;
            break;
          case White_blackcenter:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Whitecenter_black:
            whitecompare(i+2, j-2, 201);
            Wdead1point[wd1].x = j-2;
            Wdead1point[wd1].y = i+2;
            wd1++;
            break;
          case Black_whitecenter:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
        }
      }

      //=========貼牆死一==========
      if(j==0 || j==17)
      {
        walldead1 = walldead1Horizontal((char (*)[2])&chessboard[i][j],(j==0)?0:1);
        switch (walldead1)
        {
          case Wallblack:
            blackcompare(i, j+1, 201);
            Bdead1point[bd1].x = j + 1;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Blackwall:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Wallwhite:
            whitecompare(i, j+1, 201);
            Wdead1point[wd1].x = j + 1;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          case Whitewall:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
        }
      }

      if(i==0 || i==17)
      {
        walldead1 = walldead1Vertical((char (*)[19])&chessboard[i][j],(i==0)?0:1);
        switch (walldead1)
        {
          case Wallblack:
            blackcompare(i+1, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i + 1;
            bd1++;
            break;
          case Blackwall:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Wallwhite:
            whitecompare(i+1, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i + 1;
            wd1++;
            break;
          case Whitewall:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
        }
      }
      //右下斜線貼牆死一

      if( (i==0 && j<=17) || (i<=17 && j==0) ) //貼上貼左
      {
        walldead1=walldead1Diagonal((char (*)[19])&chessboard[i][j], 0);
        
        switch (walldead1)
        {
          case Wallblack:
            blackcompare(i+1, j+1, 201);
            Bdead1point[bd1].x = j+1;
            Bdead1point[bd1].y = i+1;
            bd1++;
            break;
          case Wallwhite:
            whitecompare(i+1, j+1, 201);
            Wdead1point[wd1].x = j+1;
            Wdead1point[wd1].y = i+1;
            wd1++;
            break;
          }
      }

      if( (i<=17 && j==17) || (i==17 && j<=17) )//貼下貼右
      {
        walldead1=walldead1Diagonal((char (*)[19])&chessboard[i][j], 1);
        
        switch (walldead1)
        {
          case Blackwall:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Whitewall:
            whitecompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
          }

      }

      //左下斜線貼牆死一
      if( (i==0 && j>=1) || (i<=17 && j==18) )//貼上貼右
      {
        walldead1=walldead1BackDiagonal((char (*)[19])&chessboard[i+1][j-1], 1);
        
        switch (walldead1)
        {
          case Blackwall:
            blackcompare(i+1, j-1, 201);
            Bdead1point[bd1].x = j-1;
            Bdead1point[bd1].y = i+1;
            bd1++;
            break;
          case Whitewall:
            whitecompare(i+1, j-1, 201);
            Wdead1point[wd1].x = j-1;
            Wdead1point[wd1].y = i+1;
            wd1++;
            break;
        }
      }

      if( (i<=17 && j==1) || (i==17 && j>=1) )//貼左貼下
      {
        walldead1=walldead1BackDiagonal((char (*)[19])&chessboard[i+1][j-1], 0);
        
        switch (walldead1)
        {
          case Wallblack:
            blackcompare(i, j, 201);
            Bdead1point[bd1].x = j;
            Bdead1point[bd1].y = i;
            bd1++;
            break;
          case Wallwhite:
            blackcompare(i, j, 201);
            Wdead1point[wd1].x = j;
            Wdead1point[wd1].y = i;
            wd1++;
            break;
        }
      }

      //=========活二判斷===========
      if(j<=15)
      {
        live2=live2Horizontal((char (*)[4])&chessboard[i][j]);
        locationLive2(live2, i, j, 0);
      }
      
      if(i<=15)
      {
        live2=live2Vertical((char (*)[19])&chessboard[i][j]);
        locationLive2(live2, i, j, 90);
      }

      if((i<=15) && (j<=15))
      {
        live2 = live2Diagonal((char(*)[19]) & chessboard[i][j]);
        locationLive2(live2, i, j, 45);
      }

      if((i<=15) && (j>=3))
      {
        live2 = live2BackDiagonal((char(*)[19]) & chessboard[i+3][j-3]);
        locationLive2(live2, i+3, j-3, 135);
      }
     
      //=========死二判斷===========
      
      if(j<=15)
      {
        dead2=dead2Horizontal((char (*)[4])&chessboard[i][j]);
        switch(dead2)
        {
          case Black2white:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Whiteblack2:
            blackcompare(i, j+3, 301);
            Bdead2point[bd2].x = j+3;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case White2black:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
          case Blackwhite2:
            whitecompare(i, j+3, 301);
            Wdead2point[wd2].x = j+3;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
          }
      }
      
      if(i<=15)
      {
        dead2=dead2Vertical((char (*)[19])&chessboard[i][j]);
        switch(dead2)
        {
          case Black2white:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Whiteblack2:
            blackcompare(i+3, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i+3;
            bd2++;
            break;
          case White2black:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
          case Blackwhite2:
            whitecompare(i+3, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i+3;
            wd2++;
            break;
        }
      }

      if((i<=15) && (j<=15))
      {
        dead2 = dead2Diagonal((char(*)[19])&chessboard[i][j]);
        switch(dead2)
        {
          case Black2white:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Whiteblack2:
            blackcompare(i+3, j+3, 301);
            Bdead2point[bd2].x = j+3;
            Bdead2point[bd2].y = i+3;
            bd2++;
            break;
          case White2black:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
          case Blackwhite2:
            whitecompare(i+3, j+3, 301);
            Wdead2point[wd2].x = j+3;
            Wdead2point[wd2].y = i+3;
            wd2++;
            break;
        }
      }

      if((i<=15) && (j>=3))
      {
        dead2 = dead2BackDiagonal((char(*)[19])&chessboard[i+3][j-3]);
        switch(dead2)
        {
          case Black2white:
            blackcompare(i+3, j-3, 301);
            Bdead2point[bd2].x = j-3;
            Bdead2point[bd2].y = i+3;
            bd2++;
            break;
          case Whiteblack2:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case White2black:
            whitecompare(i+3, j-3, 301);
            Wdead2point[wd2].x = j-3;
            Wdead2point[wd2].y = i+3;
            wd2++;
            break;
          case Blackwhite2:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
        }
      }

      //=========貼牆死二判斷===========

      if(j==0 || j==16)
      {
        walldead2 = walldead2Horizontal((char (*)[3])&chessboard[i][j],(j==0)?0:1);
        switch (walldead2)
        {
          case Wallblack2:
            blackcompare(i, j+2, 301);
            Bdead2point[bd2].x = j + 2;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Black2wall:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Wallwhite2:
            whitecompare(i, j+2, 301);
            Wdead2point[wd2].x = j + 2;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
          case White2wall:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
        }
      }

      if(i==0 || i==16)
      {
        walldead2 = walldead2Vertical((char (*)[19])&chessboard[i][j],(i==0)?0:1);
        switch (walldead2)
        {
          case Wallblack2:
            blackcompare(i+2, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i + 2;
            bd2++;
            break;
          case Black2wall:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Wallwhite2:
            whitecompare(i+2, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i + 2;
            wd2++;
            break;
          case White2wall:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
        }
      }
      //右下斜線貼牆死二

      if( (i==0 && j<=16) || (i<=16 && j==0) ) //貼上貼左
      {
        walldead2=walldead2Diagonal((char (*)[19])&chessboard[i][j], 0);
        
        switch (walldead2)
        {
          case Wallblack2:
            blackcompare(i+2, j+2, 301);
            Bdead2point[bd2].x = j+2;
            Bdead2point[bd2].y = i+2;
            bd2++;
            break;
          case Wallwhite2:
            whitecompare(i+2, j+2, 301);
            Wdead2point[wd2].x = j+2;
            Wdead2point[wd2].y = i+2;
            wd2++;
            break;
          }
      }

      if( (i<=16 && j==16) || (i==16 && j<=16) )//貼下貼右
      {
        walldead2=walldead2Diagonal((char (*)[19])&chessboard[i][j], 1);
        
        switch (walldead2)
        {
          case Black2wall:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case White2wall:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
        }

      }

      //左下斜線貼牆死二
      if( (i==0 && j>=2) || (i<=16 && j==18) )//貼上貼右
      {
        walldead2=walldead2BackDiagonal((char (*)[19])&chessboard[i+2][j-2], 1);
        
        switch (walldead2)
        {
          case Black2wall:
            blackcompare(i+2, j-2, 301);
            Bdead2point[bd2].x = j-2;
            Bdead2point[bd2].y = i+2;
            bd2++;
            break;
          case White2wall:
            whitecompare(i+2, j-2, 301);
            Wdead2point[wd2].x = j-2;
            Wdead2point[wd2].y = i+2;
            wd2++;
            break;
        }
      }

      if( (i<=16 && j==2) || (i==16 && j>=2) )//貼左貼下
      {
        walldead2=walldead2BackDiagonal((char (*)[19])&chessboard[i+2][j-2], 0);
        
        switch (walldead2)
        {
          case Wallblack2:
            blackcompare(i, j, 301);
            Bdead2point[bd2].x = j;
            Bdead2point[bd2].y = i;
            bd2++;
            break;
          case Wallwhite2:
            whitecompare(i, j, 301);
            Wdead2point[wd2].x = j;
            Wdead2point[wd2].y = i;
            wd2++;
            break;
        }
      }

      //=========跳二判斷===========
      if(j<=14)
      {
        jump2 = jump2Horizontal((char (*)[5])&chessboard[i][j]);
        switch(jump2)
        {
          case Black11:
            blackcompare(i, j+2, 311);
            Bjump2point[bj2].x = j + 2;
            Bjump2point[bj2].y = i;
            bj2++;
            break;
          case White11:
            whitecompare(i, j+2, 311);
            Wjump2point[wj2].x = j + 2;
            Wjump2point[wj2].y = i;
            wj2++;
            break;
        }
      }

      if(i<=14)
      {
        jump2 = jump2Vertical((char (*)[19])&chessboard[i][j]);
        switch(jump2)
        {
          case Black11:
            blackcompare(i+2, j, 311);
            Bjump2point[bj2].x = j;
            Bjump2point[bj2].y = i + 2;
            bj2++;
            break;
          case White11:
            whitecompare(i+2, j, 311);
            Wjump2point[wj2].x = j;
            Wjump2point[wj2].y = i + 2;
            wj2++;
            break;
        }
      }

      if((i<=14)&&(j<=14))
      {
        jump2 = jump2Diagonal((char (*)[19])&chessboard[i][j]);
        switch(jump2)
        {
          case Black11:
            blackcompare(i+2, j+2, 311);
            Bjump2point[bj2].x = j + 2;
            Bjump2point[bj2].y = i + 2;
            bj2++;
            break;
          case White11:
            whitecompare(i+2, j+2, 311);
            Wjump2point[wj2].x = j + 2;
            Wjump2point[wj2].y = i + 2;
            wj2++;
            break;
        }
      }

      if((i<=14)&&(j>=4))
      {
        jump2 = jump2BackDiagonal((char (*)[19])&chessboard[i+4][j-4]);
        switch(jump2)
        {
          case Black11:
            blackcompare(i+2, j-2, 311);
            Bjump2point[bj2].x = j - 2;
            Bjump2point[bj2].y = i + 2;
            bj2++;
            break;
          case White11:
            whitecompare(i+2, j-2, 311);
            Wjump2point[wj2].x = j - 2;
            Wjump2point[wj2].y = i + 2;
            wj2++;
            break;
        }
      }
      //=========活三判斷===========
      if(j<=14) //橫向活三
      {
        live3 = live3Horizontal((char (*)[5])&chessboard[i][j]);
        locationLive3(live3, i, j, 0);
      }

      if(i<=14)
      {
        live3 = live3Vertical((char(*)[19]) & chessboard[i][j]);
        locationLive3(live3, i, j, 90);
      }

      if(i<=14 && j<=14)
      {
        live3 = live3Diagonal((char(*)[19]) & chessboard[i][j]);
        locationLive3(live3, i, j, 45);
      }

      if(i<=14 && j>=4)
      {
        live3 = live3BackDiagonal((char(*)[19]) & chessboard[i+4][j-4]);
        locationLive3(live3, i+4, j-4, 135);

      }

      //===========死三判斷================
      if(j<=14)
      {
        dead3=dead3Horizontal((char (*)[5])&chessboard[i][j]);
        switch(dead3)
        {
          case Black3white:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Whiteblack3:
            blackcompare(i, j+4, 401);
            Bdead3point[bd3].x = j+4;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case White3black:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
          case Blackwhite3:
            whitecompare(i, j+4, 401);
            Wdead3point[wd3].x = j+4;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
          }
      }
      
      if(i<=14)
      {
        dead3=dead3Vertical((char (*)[19])&chessboard[i][j]);
        switch(dead3)
        {
          case Black3white:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Whiteblack3:
            blackcompare(i+4, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i+4;
            bd3++;
            break;
          case White3black:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
          case Blackwhite3:
            whitecompare(i+4, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i+4;
            wd3++;
            break;
        }
      }

      if((i<=14) && (j<=14))
      {
        dead3 = dead3Diagonal((char(*)[19])&chessboard[i][j]);
        switch(dead3)
        {
          case Black3white:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Whiteblack3:
            blackcompare(i+4, j+4, 401);
            Bdead3point[bd3].x = j+4;
            Bdead3point[bd3].y = i+4;
            bd3++;
            break;
          case White3black:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
          case Blackwhite3:
            whitecompare(i+4, j+4, 401);
            Wdead3point[wd3].x = j+4;
            Wdead3point[wd3].y = i+4;
            wd3++;
            break;
        }
      }

      if((i<=14) && (j>=4))
      {
        dead3 = dead3BackDiagonal((char(*)[19])&chessboard[i+4][j-4]);
        switch(dead3)
        {
          case Black3white:
            blackcompare(i+4, j-4, 401);
            Bdead3point[bd3].x = j-4;
            Bdead3point[bd3].y = i+4;
            bd3++;
            break;
          case Whiteblack3:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case White3black:
            whitecompare(i+4, j-4, 401);
            Wdead3point[wd3].x = j-4;
            Wdead3point[wd3].y = i+4;
            wd3++;
            break;
          case Blackwhite3:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
        }
      }

      //============貼牆死三===============
      if(j==0 || j==15)
      {
        walldead3 = walldead3Horizontal((char (*)[4])&chessboard[i][j],(j==0)?0:1);
        switch (walldead3)
        {
          case Wallblack3:
            blackcompare(i, j+3, 401);
            Bdead3point[bd3].x = j + 3;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Black3wall:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Wallwhite3:
            whitecompare(i, j+3, 401);
            Wdead3point[wd3].x = j + 3;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
          case White3wall:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
        }
      }

      if(i==0 || i==15)
      {
        walldead3 = walldead3Vertical((char (*)[19])&chessboard[i][j],(i==0)?0:1);
        switch (walldead3)
        {
          case Wallblack3:
            blackcompare(i+3, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i + 3;
            bd3++;
            break;
          case Black3wall:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Wallwhite3:
            whitecompare(i+3, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i + 3;
            wd3++;
            break;
          case White3wall:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
        }
      }
      //右下斜線貼牆死二

      if( (i==0 && j<=15) || (i<=15 && j==0) ) //貼上貼左
      {
        walldead3=walldead3Diagonal((char (*)[19])&chessboard[i][j], 0);
        
        switch (walldead3)
        {
          case Wallblack3:
            blackcompare(i+3, j+3, 401);
            Bdead3point[bd3].x = j+3;
            Bdead3point[bd3].y = i+3;
            bd3++;
            break;
          case Wallwhite3:
            whitecompare(i+3, j+3, 401);
            Wdead3point[wd3].x = j+3;
            Wdead3point[wd3].y = i+3;
            wd3++;
            break;
          }
      }

      if( (i<=15 && j==15) || (i==15 && j<=15) )//貼下貼右
      {
        walldead3=walldead3Diagonal((char (*)[19])&chessboard[i][j], 1);
        
        switch (walldead3)
        {
          case Black3wall:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case White3wall:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
        }

      }

      //左下斜線貼牆死二
      if( (i==0 && j>=3) || (i<=15 && j==18) )//貼上貼右
      {
        walldead3=walldead3BackDiagonal((char (*)[19])&chessboard[i+3][j-3], 1);
        
        switch (walldead3)
        {
          case Black3wall:
            blackcompare(i+3, j-3, 401);
            Bdead3point[bd3].x = j-3;
            Bdead3point[bd3].y = i+3;
            bd3++;
            break;
          case White3wall:
            whitecompare(i+3, j-3, 401);
            Wdead3point[wd3].x = j-3;
            Wdead3point[wd3].y = i+3;
            wd3++;
            break;
        }
      }

      if( (i<=15 && j==3) || (i==15 && j>=3) )//貼左貼下
      {
        walldead3=walldead3BackDiagonal((char (*)[19])&chessboard[i+3][j-3], 0);
        
        switch (walldead3)
        {
          case Wallblack3:
            blackcompare(i, j, 401);
            Bdead3point[bd3].x = j;
            Bdead3point[bd3].y = i;
            bd3++;
            break;
          case Wallwhite3:
            whitecompare(i, j, 401);
            Wdead3point[wd3].x = j;
            Wdead3point[wd3].y = i;
            wd3++;
            break;
        }
      }

      //============跳三判斷================
      if(j<=13)
      {
        jump3 = jump3Horizontal((char (*)[6])&chessboard[i][j]);
        switch(jump3)
        {
          case Black12:
            blackcompare(i, j+2, 411);
            Bjump3point[bj3].x = j + 2;
            Bjump3point[bj3].y = i;
            bj3++;
            break;
          case Black21:
            blackcompare(i, j+3, 411);
            Bjump3point[bj3].x = j + 3;
            Bjump3point[bj3].y = i;
            bj3++;
            break;
          case White12:
            whitecompare(i, j+2, 411);
            Wjump3point[wj3].x = j + 2;
            Wjump3point[wj3].y = i;
            wj3++;
            break;
          case White21:
            whitecompare(i, j+3, 411);
            Wjump3point[wj3].x = j + 3;
            Wjump3point[wj3].y = i;
            wj3++;
            break;
        }
      }

      if(i<=13)
      {
        jump3 = jump3Vertical((char (*)[19])&chessboard[i][j]);
        switch(jump3)
        {
          case Black12:
            blackcompare(i+2, j, 411);
            Bjump3point[bj3].x = j;
            Bjump3point[bj3].y = i+2;
            bj3++;
            break;
          case Black21:
            blackcompare(i+3, j, 411);
            Bjump3point[bj3].x = j;
            Bjump3point[bj3].y = i+3;
            bj3++;
            break;
          case White12:
            whitecompare(i+2, j, 411);
            Wjump3point[wj3].x = j;
            Wjump3point[wj3].y = i+2;
            wj3++;
            break;
          case White21:
            whitecompare(i+3, j, 411);
            Wjump3point[wj3].x = j;
            Wjump3point[wj3].y = i+3;
            wj3++;
            break;
        }
      }

      if((i<=13)&&(j<=13))
      {
        jump3 = jump3Diagonal((char (*)[19])&chessboard[i][j]);
        switch(jump3)
        {
          case Black12:
            blackcompare(i+2, j+2, 411);
            Bjump3point[bj3].x = j+2;
            Bjump3point[bj3].y = i+2;
            bj3++;
            break;
          case Black21:
            blackcompare(i+3, j+3, 411);
            Bjump3point[bj3].x = j+3;
            Bjump3point[bj3].y = i+3;
            bj3++;
            break;
          case White12:
            whitecompare(i+2, j+2, 411);
            Wjump3point[wj3].x = j+2;
            Wjump3point[wj3].y = i+2;
            wj3++;
            break;
          case White21:
            whitecompare(i+3, j+3, 411);
            Wjump3point[wj3].x = j+3;
            Wjump3point[wj3].y = i+3;
            wj3++;
            break;
        }
      }

      if((i<=13)&&(j>=5))
      {
        jump3 = jump3BackDiagonal((char (*)[19])&chessboard[i+5][j-5]);
        switch(jump3)
        {
          case Black12:
            blackcompare(i+3, j-3, 411);
            Bjump3point[bj3].x = j-3;
            Bjump3point[bj3].y = i+3;
            bj3++;
            break;
          case Black21:
            blackcompare(i+2, j-2, 411);
            Bjump3point[bj3].x = j-2;
            Bjump3point[bj3].y = i+2;
            bj3++;
            break;
          case White12:
            whitecompare(i+3, j-3, 411);
            Wjump3point[wj3].x = j-3;
            Wjump3point[wj3].y = i+3;
            wj3++;
            break;
          case White21:
            whitecompare(i+2, j-2, 411);
            Wjump3point[wj3].x = j-2;
            Wjump3point[wj3].y = i+2;
            wj3++;
            break;
        }
      }

      //===========活四判斷==========
      if(j<=13) //橫向活四判斷
      {
        live4 = live4Horizontal((char (*)[6])&chessboard[i][j]);
        locationLive4(live4, i, j, 0);
        
      }
      if(i<=13) //直向活四判斷
      {
        live4=live4Vertical((char (*)[19])&chessboard[i][j]);
        locationLive4(live4, i, j, 90);
        
      }
      if((i<=13)&&(j<=13)) //右下斜對角活四判斷
      {
        live4=live4Diagonal((char (*)[19])&chessboard[i][j]);
        locationLive4(live4, i, j, 45);
        
      }
      if((i<=13)&&(j>=5)) //左下斜對角活四判斷
      {
        live4=live4BackDiagonal((char (*)[19])&chessboard[i+5][j-5]);
        locationLive4(live4, i+5, j-5, 135);
        
      }

      //============死四判斷================
      if(j<=13) //橫向死四判斷
      {
        dead4 = dead4Horizontal((char (*)[6])&chessboard[i][j]);
        switch(dead4)
        {
          case Black4white:
              blackcompare(i, j, 501);
              Bdead4point[bb].x = j;
              Bdead4point[bb].y = i;
              bb++;
              break;
          case Whiteblack4:
              blackcompare(i, j+5, 501);              
              Bdead4point[bb].x = j+5;
              Bdead4point[bb].y = i;
              bb++;
              break;
          case White4black:
              whitecompare(i, j, 501);               
              Wdead4point[ww].x = j;
              Wdead4point[ww].y = i;
              ww++;
              break;
          case Blackwhite4:
              whitecompare(i, j+5, 501);              
              Wdead4point[ww].x = j+5;
              Wdead4point[ww].y = i;
              ww++;
              break;
        }
      }

      if(i<=13) //直向死四判斷
      {
        dead4=dead4Vertical((char (*)[19])&chessboard[i][j]);
        switch(dead4)
        {
          case Black4white:
              blackcompare(i, j, 501);
              Bdead4point[bb].x = j;
              Bdead4point[bb].y = i;
              bb++;
              break;
          case Whiteblack4:
              blackcompare(i+5, j, 501);
              Bdead4point[bb].x = j;
              Bdead4point[bb].y = i+5;
              bb++;
              break;
          case White4black :
              whitecompare(i, j, 501);
              Wdead4point[ww].x = j;
              Wdead4point[ww].y = i;
              ww++;
              break;
          case Blackwhite4:
              whitecompare(i+5, j, 501);
              Wdead4point[ww].x = j;
              Wdead4point[ww].y = i+5;
              ww++;
              break;
        }
      }
      
      if((i<=13)&&(j<=13)) //右下死四判斷
      {
        dead4=dead4Diagonal((char (*)[19])&chessboard[i][j]);
        switch(dead4)
        {
          case Black4white:
              blackcompare(i, j, 501);
              Bdead4point[bb].x = j;
              Bdead4point[bb].y = i;
              bb++;
              break;
          case Whiteblack4:
              blackcompare(i+5, j+5, 501);
              Bdead4point[bb].x = j+5;
              Bdead4point[bb].y = i+5;
              bb++;
              break;
          case White4black:
              whitecompare(i, j, 501); 
              Wdead4point[ww].x = j;
              Wdead4point[ww].y = i;
              ww++;
              break;
          case Blackwhite4:
              whitecompare(i+5, j+5, 501);
              Wdead4point[ww].x = j+5;
              Wdead4point[ww].y = i+5;
              ww++;
              break;
        }
      }
      
      if((i<=13)&&(j>=5)) //左下死四判斷
      {
        dead4=dead4BackDiagonal((char (*)[19])&chessboard[i+5][j-5]);
        switch(dead4)
        {
          case Black4white:
              blackcompare(i+5, j-5, 501);
              Bdead4point[bb].x = j-5;
              Bdead4point[bb].y = i+5;
              bb++;
              break;
          case Whiteblack4:
              blackcompare(i, j, 501);
              Bdead4point[bb].x = j;
              Bdead4point[bb].y = i;
              bb++;
              break;
          case White4black:
              whitecompare(i+5, j-5, 501); 
              Wdead4point[ww].x = j-5;
              Wdead4point[ww].y = i+5;
              ww++;
              break;
          case Blackwhite4:
              whitecompare(i, j, 501);
              Wdead4point[ww].x = j;
              Wdead4point[ww].y = i;
              ww++;
              break;
        }
      }

      //============貼牆死四判斷==========

      if(j==0 || j==14) //橫向貼牆死四判斷
      {
        walldead4=walldead4Horizontal((char (*)[5])&chessboard[i][j],(j==0)?0:1);
        switch (walldead4)
        {
          case Wallblack4:
            blackcompare(i, j+4, 501);
            Bdead4point[bb].x = j + 4;
            Bdead4point[bb].y = i;
            bb++;
            break;
          case Black4wall:
            blackcompare(i, j, 501);
            Bdead4point[bb].x = j;
            Bdead4point[bb].y = i;
            bb++;
            break;
          case Wallwhite4:
            whitecompare(i, j+4, 501);
            Wdead4point[ww].x = j + 4;
            Wdead4point[ww].y = i;
            ww++;
            break;
          case White4wall:
            whitecompare(i, j, 501);
            Wdead4point[ww].x = j;
            Wdead4point[ww].y = i;
            ww++;
            break;
        }
      }

      if(i==0 || i==14) //直向貼牆死四判斷
      {
        walldead4=walldead4Vertical((char (*)[19])&chessboard[i][j],(i==0)?0:1);
        
        switch (walldead4)
        {
          case Wallblack4:
            blackcompare(i+4, j, 501);
            Bdead4point[bb].x = j;
            Bdead4point[bb].y = i+4;
            bb++;
            break;
          case Black4wall:
            blackcompare(i, j, 501);
            Bdead4point[bb].x = j;
            Bdead4point[bb].y = i;
            bb++;
            break;
          case Wallwhite4:
            whitecompare(i+4, j, 501);
            Wdead4point[ww].x = j;
            Wdead4point[ww].y = i+4;
            ww++;
            break;
          case White4wall:
            whitecompare(i, j, 501);
            Wdead4point[ww].x = j;
            Wdead4point[ww].y = i;
            ww++;
            break;
          }
      }
      //右下斜線貼牆死四判斷
      if( (i==0 && j<=14) || (i<=14 && j==0) )
      {
        walldead4=walldead4Diagonal((char (*)[19])&chessboard[i][j], 0);
        
        switch (walldead4)
        {
          case Wallblack4:
            blackcompare(i+4, j+4, 501);
            Bdead4point[bb].x = j+4;
            Bdead4point[bb].y = i+4;
            bb++;
            break;
          case Wallwhite4:
            whitecompare(i+4, j+4, 501);
            Wdead4point[ww].x = j+4;
            Wdead4point[ww].y = i+4;
            ww++;
            break;
          }
      }

      if( (i==14 && j<=14) || (i<=14 && j==14))
      {
        walldead4=walldead4Diagonal((char (*)[19])&chessboard[i][j], 1);
        
        switch (walldead4)
        {
          case Black4wall:
            blackcompare(i, j, 501);
            Bdead4point[bb].x = j;
            Bdead4point[bb].y = i;
            bb++;
            break;
          case White4wall:
            whitecompare(i, j, 501);
            Wdead4point[ww].x = j;
            Wdead4point[ww].y = i;
            ww++;
            break;
          }
      }

      //左下斜線貼牆死四判斷
      if( (i==0 && j>=4) || (i<=14 && j==18) ) //貼上及貼右
      {
        walldead4=walldead4BackDiagonal((char (*)[19])&chessboard[i+4][j-4], 1);
        
        switch (walldead4)
        {
          case Black4wall:
            blackcompare(i+4, j-4, 501);
            Bdead4point[bb].x = j-4;
            Bdead4point[bb].y = i+4;
            bb++;
            break;
          case White4wall:
            whitecompare(i+4, j-4, 501);
            Wdead4point[ww].x = j-4;
            Wdead4point[ww].y = i+4;
            ww++;
            break;
          }
      }

      if( (i<=14 && j==4) || (i==14 && j>=4)) //貼左及貼下
      {
        walldead4=walldead4BackDiagonal((char (*)[19])&chessboard[i+4][j-4], 0);
        
        switch (walldead4)
        {
          case Wallblack4:
            blackcompare(i, j, 501);
            Bdead4point[bb].x = j;
            Bdead4point[bb].y = i;
            bb++;
            break;
          case Wallwhite4:
            whitecompare(i, j, 501);
            Wdead4point[ww].x = j;
            Wdead4point[ww].y = i;
            ww++;
            break;
          }
      }

      //===========跳四判斷=============
      if(j<=14)
      {
        jump4 = jump4Horizontal((char (*)[5])&chessboard[i][j]);
        switch(jump4)
        {
          case Black13:
            blackcompare(i, j+1, 501);
            Bjump4point[bj4].x = j + 1;
            Bjump4point[bj4].y = i;
            bj4++;
            break;
          case Black22:
            blackcompare(i, j+2, 501);
            Bjump4point[bj4].x = j + 2;
            Bjump4point[bj4].y = i;
            bj4++;
            break;
          case Black31:
            blackcompare(i, j+3, 501);
            Bjump4point[bj4].x = j + 3;
            Bjump4point[bj4].y = i;
            bj4++;
            break;
          case White13:
            whitecompare(i, j+1, 501);
            Wjump4point[wj4].x = j + 1;
            Wjump4point[wj4].y = i;
            wj4++;
            break;
          case White22:
            whitecompare(i, j+2, 501);
            Wjump4point[wj4].x = j + 2;
            Wjump4point[wj4].y = i;
            wj4++;
            break;
          case White31:
            whitecompare(i, j+3, 501);
            Wjump4point[wj4].x = j + 3;
            Wjump4point[wj4].y = i;
            wj4++;
            break;
        }
      }

      if(i<=14)
      {
        jump4 = jump4Vertical((char (*)[19])&chessboard[i][j]);
        switch(jump4)
        {
          case Black13:
            blackcompare(i+1, j, 501);
            Bjump4point[bj4].x = j;
            Bjump4point[bj4].y = i + 1;
            bj4++;
            break;
          case Black22:
            blackcompare(i+2, j, 501);
            Bjump4point[bj4].x = j;
            Bjump4point[bj4].y = i + 2;
            bj4++;
            break;
          case Black31:
            blackcompare(i+3, j, 501);
            Bjump4point[bj4].x = j;
            Bjump4point[bj4].y = i + 3;
            bj4++;
            break;
          case White13:
            whitecompare(i+1, j, 501);
            Wjump4point[wj4].x = j;
            Wjump4point[wj4].y = i + 1;
            wj4++;
            break;
          case White22:
            whitecompare(i+2, j, 501);
            Wjump4point[wj4].x = j;
            Wjump4point[wj4].y = i + 2;
            wj4++;
            break;
          case White31:
            whitecompare(i+3, j, 501);
            Wjump4point[wj4].x = j;
            Wjump4point[wj4].y = i + 3;
            wj4++;
            break;
        }
      }

      if((i<=14)&&(j<=14))
      {
        jump4 = jump4Diagonal((char (*)[19])&chessboard[i][j]);
        switch(jump4)
        {
          case Black13:
            blackcompare(i+1, j+1, 501);
            Bjump4point[bj4].x = j + 1;
            Bjump4point[bj4].y = i + 1;
            bj4++;
            break;
          case Black22:
            blackcompare(i+2, j+2, 501);
            Bjump4point[bj4].x = j + 2;
            Bjump4point[bj4].y = i + 2;
            bj4++;
            break;
          case Black31:
            blackcompare(i+3, j+3, 501);
            Bjump4point[bj4].x = j + 3;
            Bjump4point[bj4].y = i + 3;
            bj4++;
            break;
          case White13:
            whitecompare(i+1, j+1, 501);
            Wjump4point[wj4].x = j + 1;
            Wjump4point[wj4].y = i + 1;
            wj4++;
            break;
          case White22:
            whitecompare(i+2, j+2, 501);
            Wjump4point[wj4].x = j + 2;
            Wjump4point[wj4].y = i + 2;
            wj4++;
            break;
          case White31:
            whitecompare(i+3, j+3, 501);
            Wjump4point[wj4].x = j + 3;
            Wjump4point[wj4].y = i + 3;
            wj4++;
            break;
        }
      }

      if((i<=14)&&(j>=4))
      {
        jump4 = jump4BackDiagonal((char (*)[19])&chessboard[i+4][j-4]);
        switch(jump4)
        {
          case Black13:
            blackcompare(i+3, j-3, 501);
            Bjump4point[bj4].x = j - 3;
            Bjump4point[bj4].y = i + 3;
            bj4++;
            break;
          case Black22:
            blackcompare(i+2, j-2, 501);
            Bjump4point[bj4].x = j - 2;
            Bjump4point[bj4].y = i + 2;
            bj4++;
            break;
          case Black31:
            blackcompare(i+1, j-1, 501);
            Bjump4point[bj4].x = j - 1;
            Bjump4point[bj4].y = i + 1;
            bj4++;
            break;
          case White13:
            whitecompare(i+3, j-3, 501);
            Wjump4point[wj4].x = j - 3;
            Wjump4point[wj4].y = i + 3;
            wj4++;
            break;
          case White22:
            whitecompare(i+2, j-2, 501);
            Wjump4point[wj4].x = j - 2;
            Wjump4point[wj4].y = i + 2;
            wj4++;
            break;
          case White31:
            whitecompare(i+1, j-1, 501);
            Wjump4point[wj4].x = j - 1;
            Wjump4point[wj4].y = i + 1;
            wj4++;
            break;
        }
      }
    }
  }

  for (i = 0; i < 19; i++)
  {
    for (j = 0; j < 19; j++)
    {
      if(btemp<BBR[i][j])
      {
        btemp = BBR[i][j];
        
      }
    }
  }

  for (i = 0; i < 19; i++)
  {
    for (j = 0; j < 19; j++)
    {
      if(wtemp<WBR[i][j])
      {
        wtemp = WBR[i][j];
      }
    }
  }
/*
  //=============輸出活四=============
  int m, n;
  char letter;

  printf("Live4 Black\n");
  for (m = 0; m < b; m++)
  {
    letter = 'A' + Blive4point[m].x;
    printf("%c, %d\n", letter , Blive4point[m].y + 1);
  }
  if(b==0)
    printf("None\n");
  
  printf("Live4 White\n");
  for (m = 0; m < w; m++)
  {
    letter = 'A' + Wlive4point[m].x;
    printf("%c, %d\n", letter, Wlive4point[m].y + 1);
  }
  if(w==0)
    printf("None\n");

  //=============輸出死四==================
  printf("Dead4 Black\n");
  for (m = 0; m < bb; m++)
  {
    letter = 'A' + Bdead4point[m].x;
    printf("%c%d\n", letter, Bdead4point[m].y + 1);
  }
  if(bb==0)
    printf("None\n");

  printf("Dead4 White\n");
  for (m = 0; m < ww; m++)
  {
    letter = 'A' + Wdead4point[m].x;
    printf("%c%d\n", letter, Wdead4point[m].y + 1);
  }
  if(ww==0)
    printf("None\n");

  //==========輸出跳四================
  printf("Jump4 Black\n");
  for (m = 0; m < bj4; m++)
  {
    letter = 'A' + Bjump4point[m].x;
    printf("%c%d\n", letter, Bjump4point[m].y + 1);
  }
  if(bj4==0)
    printf("None\n");

  printf("Jump4 White\n");
  for (m = 0; m < wj4; m++)
  {
    letter = 'A' + Wjump4point[m].x;
    printf("%c%d\n", letter, Wjump4point[m].y + 1);
  }
  if(wj4==0)
    printf("None\n");


  //=============輸出活三============
  printf("Live3 w/o. empty Black\n");
  for(m = 0; m < bl3; m++)
  {
    letter = 'A' + Blive3point[m].x;
    printf("%c, %d\n", letter, Blive3point[m].y + 1);
  }
  if(bl3==0)
    printf("None\n");
  
  printf("Live3 w/o. empty White\n");
  for(m = 0; m < wl3; m++)
  {
    letter = 'A' + Wlive3point[m].x;
    printf("%c, %d\n", letter, Wlive3point[m].y + 1);
  }
  if(wl3==0)
    printf("None\n");

  //============輸出死三============
  printf("Dead3 Black\n");
  for (m = 0; m < bd3; m++)
  {
    letter = 'A' + Bdead3point[m].x;
    printf("%c, %d\n", letter , Bdead3point[m].y + 1);
  }
  if(bd3==0)
    printf("None\n");
  
  printf("Dead3 White\n");
  for (m = 0; m < wd3; m++)
  {
    letter = 'A' + Wdead3point[m].x;
    printf("%c, %d\n", letter, Wdead3point[m].y + 1);
  }
  if(wd3==0)
    printf("None\n");


  //===========輸出跳三=============
  printf("Live3 w/. empty Black\n");
  for (m = 0; m < bj3; m++)
  {
    letter = 'A' + Bjump3point[m].x;
    printf("%c%d\n", letter, Bjump3point[m].y + 1);
  }
  if(bj3==0)
    printf("None\n");

  printf("Live3 w/. empty White\n");
  for (m = 0; m < wj3; m++)
  {
    letter = 'A' + Wjump3point[m].x;
    printf("%c%d\n", letter, Wjump3point[m].y + 1);
  }
  if(wj3==0)
    printf("None\n");

  //============輸出活二=================
  printf("Live2 Black\n");
  for (m = 0; m < bl2; m++)
  {
    letter = 'A' + Blive2point[m].x;
    printf("%c, %d\n", letter, Blive2point[m].y + 1);
  }
  if(bl2==0)
    printf("None\n");

  printf("Live2 White\n");
  for (m = 0; m < wl2; m++)
  {
    letter = 'A' + Wlive2point[m].x;
    printf("%c, %d\n", letter, Wlive2point[m].y + 1);
  }
  if(wl2==0)
    printf("None\n");

  //=============輸出死二================
  printf("Dead2 Black\n");
  for (m = 0; m < bd2; m++)
  {
    letter = 'A' + Bdead2point[m].x;
    printf("%c, %d\n", letter , Bdead2point[m].y + 1);
  }
  if(bd2==0)
    printf("None\n");
  
  printf("Dead2 White\n");
  for (m = 0; m < wd2; m++)
  {
    letter = 'A' + Wdead2point[m].x;
    printf("%c, %d\n", letter, Wdead2point[m].y + 1);
  }
  if(wd2==0)
    printf("None\n");

  //============輸出跳二==================
  printf("Live2 w/. empty Black\n");
  for (m = 0; m < bj2; m++)
  {
    letter = 'A' + Bjump2point[m].x;
    printf("%c%d\n", letter, Bjump2point[m].y + 1);
  }
  if(bj2==0)
    printf("None\n");

  printf("Live2 w/. empty White\n");
  for (m = 0; m < wj2; m++)
  {
    letter = 'A' + Wjump2point[m].x;
    printf("%c%d\n", letter, Wjump2point[m].y + 1);
  }
  if(wj2==0)
    printf("None\n");
  //============輸出活一=================
  printf("Live1 Black\n");
  for (m = 0; m < bl1; m++)
  {
    letter = 'A' + Blive1point[m].x;
    printf("%c, %d\n", letter, Blive1point[m].y + 1);
  }
  if(bl1==0)
    printf("None\n");

  printf("Live1 White\n");
  for (m = 0; m < wl1; m++)
  {
    letter = 'A' + Wlive1point[m].x;
    printf("%c, %d\n", letter, Wlive1point[m].y + 1);
  }
  if(wl1==0)
    printf("None\n");
    
  //=============輸出死一================
  printf("Dead1 Black\n");
  for (m = 0; m < bd1; m++)
  {
    letter = 'A' + Bdead1point[m].x;
    printf("%c, %d\n", letter , Bdead1point[m].y + 1);
  }
  if(bd1==0)
    printf("None\n");
  
  printf("Dead1 White\n");
  for (m = 0; m < wd1; m++)
  {
    letter = 'A' + Wdead1point[m].x;
    printf("%c, %d\n", letter, Wdead1point[m].y + 1);
  }
  if(wd1==0)
    printf("None\n");
*/
}

void beststep(char color)
{
  char letter;
  int numberline;
  int bigblack=0;
  int bigwhite=0;
  int i, j;
  switch (color)
  {
    case 'b':
      if(btemp>=wtemp)
      {
        for (i = 0; i < 19; i++)
        {
          for (j = 0; j < 19; j++)
          {
            if(bigblack<BBR[i][j])
            {
              bigblack = BBR[i][j];
              letter = 'A' + j;
              numberline = i + 1;
            }
          }
        }
      }
      else if(btemp<wtemp)
      {
        for (i = 0; i < 19; i++)
        {
          for (j = 0; j < 19; j++)
          {
            if(bigwhite<WBR[i][j])
            {
              bigwhite = WBR[i][j];
              letter = 'A' + j;
              numberline = i + 1;
            }
          }
        }
      }
      break;

    case 'w':
      if(wtemp>=btemp)
      {
        for (i = 0; i < 19; i++)
        {
          for (j = 0; j < 19; j++)
          {
            if(bigwhite<WBR[i][j])
            {
              bigwhite = WBR[i][j];
              letter = 'A' + j;
              numberline = i + 1;
            }
          }
        }
      }
      else if(wtemp<btemp)
      {
        for (i = 0; i < 19; i++)
        {
          for (j = 0; j < 19; j++)
          {
            if(bigblack<BBR[i][j])
            {
              bigblack = BBR[i][j];
              letter = 'A' + j;
              numberline = i + 1;
            }
          }
        }
      }
      break;
  }
  printf("%c, %d\n", letter, numberline);


}
