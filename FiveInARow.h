
typedef enum {Black = 49, White = 48, None = 0} Player;

typedef enum
{
    Black4white = 5,
    Whiteblack4 = 6,
    White4black = 7,
    Blackwhite4 = 8
} SekiroD4;

typedef enum
{
    Wallblack4 = 9,
    Black4wall = 10,
    Wallwhite4 = 11,
    White4wall = 12
} SekiroWallD4;

typedef enum
{
    Black13 = 13,
    Black22 = 14,
    Black31 = 15,
    White13 = 16,
    White22 = 17,
    White31 = 18
} SekiroJ4;

typedef enum
{
    Black3white = 19,
    Whiteblack3 = 20,
    White3black = 21,
    Blackwhite3 = 22
} SekiroD3;

typedef enum
{
    Wallblack3 = 23,
    Black3wall = 24,
    Wallwhite3 = 25,
    White3wall = 26
} SekiroWallD3;

typedef enum
{
    Black12 = 27,
    Black21 = 28,
    White12 = 29,
    White21 = 30
} SekiroJ3;


typedef enum
{
    Black2white = 31,
    Whiteblack2 = 32,
    White2black = 33,
    Blackwhite2 = 34
} SekiroD2;

typedef enum
{
    Wallblack2 = 35,
    Black2wall = 36,
    Wallwhite2 = 37,
    White2wall = 38
} SekiroWallD2;

typedef enum
{
    Black11 = 39,
    White11 = 40,
} SekiroJ2;

typedef enum
{
    Blackcenter_white = 40,
    White_blackcenter = 42,
    Whitecenter_black = 43,
    Black_whitecenter = 44
} SekiroD1;

typedef enum
{
    Wallblack = 45,
    Blackwall = 46,
    Wallwhite = 47,
    Whitewall = 48
} SekiroWallD1;

struct Live4point{ int y, x, direct; };

struct Dead4point{ int y, x; };

struct Jump4point{ int x, y; };

struct Live3point{ int x, y, direct; };

struct Dead3point{ int x, y; };

struct Jump3point{ int x, y; };

struct Live2point{ int x, y, direct; };

struct Dead2point{ int x, y; };

struct Jump2point{ int x, y; };

struct Live1point{ int x, y, direct; };

struct Dead1point{ int x, y; };

/*
Player checkHorizontal(char (*p)[5]);
Player checkVertical(char (*p)[19]);
Player checkDiagonal(char (*p)[19]);
Player checkBackDiagonal(char (*p)[19]);
*/
void locationLive4(Player, int, int, int);
void locationLive3(Player, int, int, int);
void locationLive2(Player, int, int, int);
void locationLive1(Player, int, int, int);

Player live4Horizontal(char (*p)[6]);
Player live4Vertical(char (*p)[19]);
Player live4Diagonal(char (*p)[19]);
Player live4BackDiagonal(char (*p)[19]);

SekiroD4 dead4Horizontal(char (*p)[6]);
SekiroD4 dead4Vertical(char (*p)[19]);
SekiroD4 dead4Diagonal(char (*p)[19]);
SekiroD4 dead4BackDiagonal(char (*p)[19]);

SekiroWallD4 walldead4Horizontal(char (*p)[5], int);
SekiroWallD4 walldead4Vertical(char (*p)[19], int);
SekiroWallD4 walldead4Diagonal(char (*p)[19], int);
SekiroWallD4 walldead4BackDiagonal(char (*p)[19], int);

SekiroJ4 jump4Horizontal(char (*p)[5]);
SekiroJ4 jump4Vertical(char (*p)[19]);
SekiroJ4 jump4Diagonal(char (*p)[19]);
SekiroJ4 jump4BackDiagonal(char (*p)[19]);

Player live3Horizontal(char (*p)[5]);
Player live3Vertical(char (*p)[19]);
Player live3Diagonal(char (*p)[19]);
Player live3BackDiagonal(char (*p)[19]);

SekiroD3 dead3Horizontal(char (*p)[5]);
SekiroD3 dead3Vertical(char (*p)[19]);
SekiroD3 dead3Diagonal(char (*p)[19]);
SekiroD3 dead3BackDiagonal(char (*p)[19]);

SekiroWallD3 walldead3Horizontal(char (*p)[4], int);
SekiroWallD3 walldead3Vertical(char (*p)[19], int);
SekiroWallD3 walldead3Diagonal(char (*p)[19], int);
SekiroWallD3 walldead3BackDiagonal(char (*p)[19], int);

SekiroJ3 jump3Horizontal(char (*p)[6]);
SekiroJ3 jump3Vertical(char (*p)[19]);
SekiroJ3 jump3Diagonal(char (*p)[19]);
SekiroJ3 jump3BackDiagonal(char (*p)[19]);

Player live2Horizontal(char (*p)[4]);
Player live2Vertical(char (*p)[19]);
Player live2Diagonal(char (*p)[19]);
Player live2BackDiagonal(char (*p)[19]);

SekiroD2 dead2Horizontal(char (*p)[4]);
SekiroD2 dead2Vertical(char (*p)[19]);
SekiroD2 dead2Diagonal(char (*p)[19]);
SekiroD2 dead2BackDiagonal(char (*p)[19]);

SekiroWallD2 walldead2Horizontal(char (*p)[3], int);
SekiroWallD2 walldead2Vertical(char (*p)[19], int);
SekiroWallD2 walldead2Diagonal(char (*p)[19], int);
SekiroWallD2 walldead2BackDiagonal(char (*p)[19], int);

SekiroJ2 jump2Horizontal(char (*p)[5]);
SekiroJ2 jump2Vertical(char (*p)[19]);
SekiroJ2 jump2Diagonal(char (*p)[19]);
SekiroJ2 jump2BackDiagonal(char (*p)[19]);


Player live1Horizontal(char (*p)[3]);
Player live1Vertical(char (*p)[19]);
Player live1Diagonal(char (*p)[19]);
Player live1BackDiagonal(char (*p)[19]);

SekiroD1 dead1Horizontal(char (*p)[3]);
SekiroD1 dead1Vertical(char (*p)[19]);
SekiroD1 dead1Diagonal(char (*p)[19]);
SekiroD1 dead1BackDiagonal(char (*p)[19]);

SekiroWallD1 walldead1Horizontal(char (*p)[2], int);
SekiroWallD1 walldead1Vertical(char (*p)[19], int);
SekiroWallD1 walldead1Diagonal(char (*p)[19], int);
SekiroWallD1 walldead1BackDiagonal(char (*p)[19], int);

Player check4Winner(char chessboard[19][19]);
void beststep(char);


void blackcompare(int, int, int);
void whitecompare(int, int, int);
