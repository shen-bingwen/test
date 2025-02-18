#include "game.h"
#include "game.c"
void menu()
{
    printf("****************************\n");
    printf("*********1.开始游戏**********\n");
    printf("*********0.退出游戏**********\n");
    printf("****************************\n");
}
void game()
{
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};
    // 初始化棋盘
    InitBoard(mine, ROWS, COLS, '0');
    // Displayboard(mine,ROW,COL);
    // 初始化棋盘
    InitBoard(show, ROWS, COLS, '*');
    Displayboard(show,ROW,COL);//想操作几行几列就写几行几列,但是数组传过来的时候必须写11*11因为数组在内存中都是连续存储的
    //布置雷于mine
    Setmine(mine,ROW,COL);
    Displayboard(mine,ROW,COL);
    //排雷
    FindMine(mine,show,ROW,COL);
}
void test()
{
    int input = 0;
    srand((unsigned int)time(NULL));//srand不能频繁调用调用一次就可以了
    do
    {
        menu();
        printf("请选择:>");
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