#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX  5
#define MAX_TELE 12
#define MAX_ADDR 20

#include <stdio.h>
#include <string.h>

struct Peoinfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};
//通讯录类型
struct Contact 
{
    struct Peoinfo data[MAX];
    int size;//记录当前已经有的元素个数
};
enum Option{
    EXIT,//0
    ADD,//1
    DEL,//2
    SEARCH,//3
    MODIFY,//4
    SHOW,//5
    SORT//6
};

void InitContact(struct Contact* ps);
//增加一个信息到通讯录
void AddContact(struct Contact* ps);
//打印通讯录中的信息
void ShowContact(const struct Contact* ps);
//删除通讯录中的信息
void DelcContact(struct Contact* ps);
//查找通讯录的信息
void SearchContact(const struct Contact* ps);
//修改通讯录中的信息
void ModifyContact(struct Contact* ps);
//对通讯录中的信息进行排序
void SortContact(struct Contact* ps);



