#include <stdio.h>
#include "game.h"
#include "game.c"
void menu()
{
    printf("*******************************\n");
    printf("**1.开始游戏*****0.退出游戏*******\n");
    printf("*******************************\n");
}
void game()
{
    char board[ROW][COL] = {0};
    InitBoard(board, ROW, COL);
    Displayboard(board, ROW, COL);
    char ret = 0;
    while (1)
    {
        PlayerMove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        IsWin(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        ComputerMove(board, ROW, COL);
        Displayboard(board, ROW, COL);
        IsWin(board, ROW, COL);
        ret = IsWin(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
    }
    if (ret=='*')
    {
        printf("玩家赢\n");
    }
    else if (ret=='#')
    {
        printf("电脑赢");
    } 
    else
    {
        printf("平局\n");
    }
    
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择:>\n");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误,请重新输入\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}