
#include "contact_D.c"
void menu()
{
    printf("*************************************\n");
    printf("***** 1.add       2.del   ***********\n");
    printf("***** 3.search    4.modify **********\n");
    printf("***** 5.show      6.sort  ***********\n");
    printf("******0.exit ************************\n");
    printf("*************************************\n");
    printf("*************************************\n");
}
void test()
{
    int input = 0;
    // 创建通讯录
    struct Contact con; // con就是通讯录,里边包含:data指针和size和capacity,这是创建的一个结构体变量,不是malloc出来的不用进行free,但里面的data指针就是malloc出来的就要free
    InitContact(&con);
    do
    {
        menu();
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DelcContact(&con);
            break;
        case SEARCH:
            SearchContact(&con);
            break;
        case MODIFY:
            ModifyContact(&con);
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case SORT:
            SortContact(&con);
            break;
        case EXIT:
            // 销毁通讯录-释放动态开辟的内存
            DestroyContact(&con);
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