#define ROW 3
#define COL 3

#include<stdlib.h>
#include<time.h>
#include <stdio.h>

void InitBoard(char board[ROW][COL],int row,int col);
void Displayboard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col);
void ComputerMove(char board[ROW][COL],int row,int col);
char IsWin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL],int row,int col);


