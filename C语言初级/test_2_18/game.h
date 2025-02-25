#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2
#define EASY_COUNT 10


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<stdbool.h>

void InitBoard(char board[ROWS][COLS],int row,int col,char set);
void Displayboard(char board[ROWS][COLS],int row,int col);
void Setmine(char mine[ROWS][COLS],int row,int col);
void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);

bool IsWin(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
