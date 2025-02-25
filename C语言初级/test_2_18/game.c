#include "game.h"

void InitBoard(char board[ROWS][COLS], int row, int col, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            board[i][j] = set;
        }
    }
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    // 打印列号
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i); // 打印行号
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void Setmine(char board[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int count = EASY_COUNT;
    while (count)
    {
        x = rand() % row + 1;
        y = rand() % col + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
    return mine[x - 1][y] +
           mine[x - 1][y - 1] +
           mine[x][y - 1] +
           mine[x + 1][y - 1] +
           mine[x + 1][y] +
           mine[x + 1][y + 1] +
           mine[x][y + 1] +
           mine[x - 1][y + 1] - 8 * '0';
}
// 递归探索地雷
void recurveSeach(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
    // 递归结束的条件:1.遇到了空白格2.当前格子外围有地雷
    if (x >= 1 && x <= row && y >= 1 && y <= col)
    {
        if (show[x][y] == ' ')
        {
            return;
        }
        else if (get_mine_count(mine, x, y) != 0)
        {
            show[x][y] = get_mine_count(mine, x, y) + '0';
            return;
        }
        // 以上两种情况都不符合,1.表示既没有被扫到过为空白格2.有雷区 那就开始递归调用,把当前坐标周围都没有雷区的设置为空白格.八个方位继续调用
        show[x][y] = ' ';
        recurveSeach(mine, show, row, col, x - 1, y);
        recurveSeach(mine, show, row, col, x - 1, y - 1);
        recurveSeach(mine, show, row, col, x, y - 1);
        recurveSeach(mine, show, row, col, x + 1, y - 1);
        recurveSeach(mine, show, row, col, x + 1, y);
        recurveSeach(mine, show, row, col, x + 1, y + 1);
        recurveSeach(mine, show, row, col, x, y + 1);
        recurveSeach(mine, show, row, col, x - 1, y + 1);
    }
}
bool IsWin(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 1; i <= row; ++i)
    {
        for (j = 1; j <=col; ++j)
        {
            // 当前位置是不是地雷,或者有没有被探索出来
            if (mine[i][j] == '1' || mine[i][j] == '0' && show[i][j] != '*')
            {
                continue; 
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (1)
    {
        printf("请输入排查雷的坐标:>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mine[x][y] == '0')
            {
                // int count = get_mine_count(mine, x, y);
                // show[x][y] = count + '0';
                recurveSeach(mine, show, ROW, COL, x, y);
                Displayboard(show, ROW, COL);
                if (IsWin(mine, show, row, col) == true)
                {
                    break;
                }
            }
            else
            {
                printf("你被炸死了\n");
                Displayboard(mine, ROW, COL);
                break;
            }
        }
        else
        {
            printf("非法输入,请重新输入\n");
        }
    }
    printf("恭喜你排雷成功\n");
}
