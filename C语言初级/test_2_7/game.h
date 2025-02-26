#define ROW 3
#define COL 3

#include <stdlib.h>//srand的库
#include <time.h>//time的库
#include <stdio.h>
//声明
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerBoard(char board[ROW][COL],int row,int col);
char IsWIn(char board[ROW][COL],int row,int col);
int IsFull(char board[ROW][COL],int row,int col);