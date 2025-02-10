// #include <stdio.h>
#include "game.c"
#include "game.h"
// 三子棋

void menu()
{
    printf("*************************\n");
    printf("***1.开始游戏**0.退出游戏***\n");
    printf("*************************\n");
}
// 游戏的整个实现
void game()
{
    char ret = 0;
    // 数组,存放棋盘走的信息
    char board[ROW][COL] = {0};
    // 初始化棋盘
    InitBoard(board, ROW, COL);
    // 显示棋盘
    DisplayBoard(board, ROW, COL);
    while (1)
    {
        // 玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        //判断输赢
        ret=IsWIn(board, ROW, COL);
        if (ret != 'C')
        {
            break;
        }
        // 判断输赢
        //  玩家赢返回“*”
        //  电脑赢返回“#”
        //  平局返回”Q“
        //  继续返回”C“
        // 电脑输入
        ComputerBoard(board, ROW, COL);
        DisplayBoard(board, ROW, COL);
        ret=IsWIn(board, ROW, COL);
        // //判断输赢 
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
            printf("电脑赢\n");
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
            printf("选择错误,请重新选择\n");
            break;
        }
    } while (input);
}
int main()
{
    test();
    return 0;
}