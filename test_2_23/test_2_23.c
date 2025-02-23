#include <stdio.h>

// 初识结构体
// 结构体的声明
// 描述一个学生-一些数据
// 名字
// 年龄
// 电话
// 性别

// struct 结构体关键字 Stu - 结构体标签 stuct Stu - 结构体类型
// 定义一个结构体类型,没有占有空间,相当于房子的设计图
// struct Stu
// {
//     // 成员变量
//     char name[20];
//     short age;
//     char tele[12];
//     char sex[6];
// }s1, s2, s3; // s1,s2,s3是三个全局结构体变量,不建议用全局

// typedef struct Stu
// {
//     // 成员变量,可以是标量(普通变量)、数组、指针,甚至是其他结构体
//     char name[20];
//     short age;
//     char tele[12];
//     char sex[5];
// }Stu;//用类型重命名产生的类型,配合typedef使用.不像上面的s1,s2,s3属于变量.之后直接用重命名的Stu即可
// int main()
// {
//     // struct Stu s1; // 创建局部的结构体变量,s占有空间,相当于按照图纸盖房子
//     struct Stu s1={"张三",20,"13275027173","男"}; //初始化
//     Stu s2={"来财",30,"18778505990","保密"};//初始化
//     return 0;
// }

// 结构体包含结构体
//  struct S
//  {
//      int a;
//      char c;
//      char arr[20];
//      double d;
//  };
//  struct T
//  {
//      char ch[10];
//      struct S s;//结构体包含结构体
//      char *pc;
//  };
//  int main(){
//      char arr[]="hello bit\n";
//      struct T t={"hehe",{100 ,'w',"hello world",3.14},arr};
//      printf("%s\n",t.ch);//hehe
//      printf("%s\n",t.s.arr);//hello world  两个结构体就用两个点访问(结构体变量.结构体变量.成员名)
//      printf("%lf\n",t.s.d);//3.14
//      printf("%s\n",t.pc);//hello bit
//      return 0;
//  }

// typedef struct Stu
// {
//     // 成员变量,可以是标量(普通变量)、数组、指针,甚至是其他结构体
//     char name[20];
//     short age;
//     char tele[12];
//     char sex[5];
// } Stu;
// void Print1(Stu tmp)
// {
//     printf("name:%s\n", tmp.name);//结构体变量.成员名
//     printf("age:%d\n", tmp.age);
//     printf("tele:%s\n", tmp.tele);
//     printf("sex:%s\n", tmp.sex);
// }
// void Print2(Stu *ps)
// {
//     printf("name:%s\n", ps->name);//结构体指针->结构体类型
//     printf("age:%d\n", ps->age);
//     printf("tele:%s\n", ps->tele);
//     printf("sex:%s\n", ps->sex);
// }
// int main()
// {
//     Stu s = {"李四", 40, "16605928128", "男"};
//     //打印结构体数据,封装时候传参可以传地址也可以传变量
//     //但是实际上2比1好因为传参的时候,形参是实参的一份临时拷贝,如果说实参过大那么形参开辟的空间就要很大造成浪费
//     //那么如果是2的话只传地址过去,无论数据多大都只传4或者8个字节(取决于系统32/64)过去,就大大提升了性能
//     Print1(s);
//     Print2(&s);
//     return 0;
// }

// 压栈
int Add(int x, int y)
{
    int z = 0;
    z = x + y;
    return z;
}
//首先内存中分为三个区域,分别是:栈区、堆区、静态区.任何一次函数调用都得在栈区中申请空间,局部变量、函数的形式参数、函数调用也会在这开辟空间.
//堆区用来动态内存分配,涉及到的的函数有malloc/free、realloc 、calloc
//静态区有全局变量和静态变量
int main()
{
    int a = 10;
    int b = 20;
    int ret = 0;
    ret = Add(a, b);
    printf("ret=%d\n", ret);
    return 0;
}