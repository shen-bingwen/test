#include "contact_D.h"

void InitContact(struct Contact *ps)
{
    ps->data = (struct Peoinfo *)malloc(Default * sizeof(struct Peoinfo *));
    if (ps->data == NULL)
    {
        return;
    }
    ps->size = 0; // 设置通讯录最终只有0个元素.
    ps->capacity = Default;
}

void CheckCapacity(struct Contact *ps)
{
    if (ps->size == ps->capacity)
    {
        // 增容
        struct Peoinfo *ptr = (struct Peoinfo *)realloc(ps->data, (ps->capacity + 2) * sizeof(struct Peoinfo *));
        if (ptr != NULL)
        {
            ps->data = ptr;
            ps->capacity += 2;
            printf("增容成功!\n");
        }
        else
        {
            printf("增容失败!\n");
        }
        
    }
}
void AddContact(struct Contact *ps)
{
    // 检查当前通讯录的容量
    //  1.如果满了,就增加空间
    //  2.如果不满,啥事都不干
    CheckCapacity(ps);
    printf("请输入名字:>");
    scanf("%s", ps->data[ps->size].name);
    printf("请输入年龄:>");
    scanf("%d", (&ps->data[ps->size].age));
    printf("请输入性别:>");
    scanf("%s", ps->data[ps->size].sex);
    printf("请输入电话:>");
    scanf("%s", ps->data[ps->size].tele);
    printf("请输入地址:>");
    scanf("%s", ps->data[ps->size].addr);
    ps->size++;
    printf("添加成功\n");
}

void ShowContact(const struct Contact *ps)
{
    if (ps->size == 0)
    {
        printf("通讯录为空\n");
    }
    else
    {
        int i = 0;
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        for (i = 0; i < ps->size; i++)
        {
            printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
                   ps->data[i].name,
                   ps->data[i].age,
                   ps->data[i].sex,
                   ps->data[i].tele,
                   ps->data[i].addr);
        }
    }
}
// 辅助函数,只能在contact.c里面看到,其他的调用不了.不在暴露给外面不发生冲突,只在本文件里使用.
static int FindByName(const struct Contact *ps, char name[MAX_NAME])
{
    int i = 0;
    for (i = 0; i < ps->size; i++)
    {
        if (0 == strcmp(ps->data[i].name, name))
        {
            return i;
        }
    }
    return -1; // 找不到的情况
}
void DelcContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要删除人的名字:>");
    scanf("%s", name);
    // 1.查找要删除的人在什么位置
    // 找到了返回名字所在元素的下标
    // 找不到返回-1
    int pos = FindByName(ps, name);
    if (-1 == pos)
    {
        printf("通讯录中没有要删除的人\n");
    }
    else
    {
        // 删除数据
        int j = 0;
        for (j = 0; j < ps->size - 1; j++)
        {
            ps->data[j] = ps->data[j + 1];
        }
        ps->size--;
        printf("删除成功\n");
    }
}

void SearchContact(const struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要查找人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (-1 == pos)
    {
        printf("通讯录中没有此人\n");
    }
    else
    {
        printf("%-20s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-4d\t%-5s\t%-12s\t%-20s\n",
               ps->data[pos].name,
               ps->data[pos].age,
               ps->data[pos].sex,
               ps->data[pos].tele,
               ps->data[pos].addr);
    }
}

void ModifyContact(struct Contact *ps)
{
    char name[MAX_NAME];
    printf("请输入要修改人的名字:>");
    scanf("%s", name);
    int pos = FindByName(ps, name);
    if (-1 == pos)
    {
        printf("通讯录中没有此人\n");
    }
    else
    {
        printf("请输入名字:>");
        scanf("%s", ps->data[pos].name);
        printf("请输入年龄:>");
        scanf("%d", (&ps->data[pos].age));
        printf("请输入性别:>");
        scanf("%s", ps->data[pos].sex);
        printf("请输入电话:>");
        scanf("%s", ps->data[pos].tele);
        printf("请输入地址:>");
        scanf("%s", ps->data[pos].addr);

        printf("修改完成\n");
    }
}
void Swap(char *buf1, char *buf2, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
}
void bubble_sort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
    int i = 0;
    // 循环趟数
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}
int cmp_by_name(const void *e1, const void *e2)
{
    return strcmp(((struct Contact *)e1)->data->name, ((struct Contact *)e2)->data->name);
}
void SortContact(struct Contact *ps)
{
    bubble_sort(ps->data->name, ps->size, sizeof(ps->data[ps->size]), cmp_by_name);
}


void DestroyContact(Contact* ps){
    free(ps->data);
    ps->data=NULL;
}
