#include <stdio.h>

// 声明一个结构体类型
// struct Stu
// {
//     char name[20];
//     char tele[12];
//     char sex[10];
//     int age;
// };s4,s5,s6;
// //s3,s4,s5,s6都是全局变量
// struct Stu s3; // 全局变量
// int main()
// {
//     // 创建的结构体变量
//     struct Stu s1;
//     struct Stu s2;

//     return 0;
// }

// // 匿名结构体变量
// struct
// {
//     int a;
//     char c;
// }sa;
// // 匿名结构体指针
// struct
// {
//     int a;
//     char c;
// }*psa;

// int main()
// {
//     pas = &sa//写法非法.编译器默认这两种结构体不是同一种类型
//     return 0;
// }

// 数据结构:数据在内存中存储的结构
////结构体内存对其
// struct S1
// {
//     char a;
//     int b;
//     char c;
// };
// struct S2
// {
//     char a;
//     char b;
//     int c;
// };
// struct S3
// {
//     double d;
//     char c;
//     int i;
// };
// struct S4
// {
//     char c1;
//     struct S3 s3;
//     double i;
// };
// // 设置默认对其数
// //  #pragma pack(4)
// //      struct S5{
// //          char c1;
// //          double d;
// //  };
// // 取消默认对其数
// // #pragma pack()

// // 设置默认对其数
// // #pragma pack(1) // 设置默认对齐数为1
// // struct S5
// // {
// //     char c1;
// //     int i;
// //     double j;
// // };
// // // 取消默认对其数
// // #pragma pack()

// struct S5
// {
//     char c1;
//     int i;
//     double j;
// };
// #include <stddef.h>
// int main()
// {
//     // printf("%lu\n", sizeof(struct S1));
//     // printf("%lu\n", sizeof(struct S2));
//     // printf("%lu\n", sizeof(struct S3));
//     // printf("%lu\n", sizeof(struct S4));
//     // struct S5 s = {0};
//     // printf("%lu\n", sizeof(s));

// 写一个宏，计算结构体中某变量相对于首地址的偏移
//     printf("%lu\n",offsetof(struct S5,c1));
//     printf("%lu\n",offsetof(struct S5,i));
//     printf("%lu\n",offsetof(struct S5,j));
//     // 如果lu套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，
//     // 结构体的整体大小就是所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
//     return 0;
// }

// 结构体传参
//  struct S
//  {
//      int a;
//      char c;
//      double d;
//  };
//  void Init(struct S* ps){
//      ps->a=10;
//      ps->c='w';
//      ps->d=3.14;
//  }
//  void print(const struct S* tmp){
//      printf("%d %c %lf\n",(*tmp).a,(*tmp).c,(*tmp).d);
//  }
//  int main(){
//      struct S s={0};
//      Init(&s);
//      print(&s);
//  }

// 位段————二进制位
// 为了节省空间
// 47bit位-6个字节*8=48个bit  int类型字节大小是4->32 48就得需要两个int的类型字节.如果不用这个位段就得需要4个int类型.
// struct S
// {
//     int a : 2;
//     int b : 5;
//     int c : 10;
//     int d : 30;
// };

// int main(){
//     struct S s={0};
//     printf("%d\n",sizeof(s));
//     return 0;
// }

// struct S
// {
//     char a : 3;    // 00100 010  2  2     0000 0011 03  0000 0100 04
//     char b : 4;
//     char c : 5;
//     char d : 4;
// };
// int main()
// {
//     struct S s = {0};
//     s.a=10;
//     s.b=20;
//     s.c=3;
//     s.d=4;
//     //开辟空间时候因为类型是char类型,所以我们一次开辟一个字节
//     // 而一个字节呢使用方式是先使用低位,再使用高位.当开辟空间的剩余空间不能满足剩下比特位开辟的空间的时候我们就把它浪费掉,重新开辟一个字节的空间
//     //下一个新的空间也是从右至左使用.
//     //打断点看内存
//     printf("%d\n", sizeof(s));//02 b是4个比特位可以放的下,0110 0010就是63个比特位放不下1010,把第一位截掉变为010就是2 04   03
//     return 0;
// }

// 枚举 ————顾名思义一一列举
//  enum Sex
//  {
//      //枚举的可能取值-枚举常量(即使是一个常量也可以赋值,但是未来不能改变它),后面的值没有赋值顺下去加一
//      MALE,
//      FEMALE=9,
//      SECRET
//  };
//  enum Color{
//      RED,//0
//      GREEN,//1
//      BLUE//2
//  };
//  int main(){
//      // enum Sex s=MALE;
//      // enum Color c=BLUE;
//      enum Color c=2;//左边enum Color类型 右边int类型的2
//      //其实是错误.只是没报错,换成cpp后缀的文件语法检测更加严格.就会报错.
//      printf("%d %d %d\n",MALE,FEMALE,SECRET);
//      printf("%d %d %d\n",RED,GREEN,BLUE);
//      return 0;
//  }

// 联合-联合体-共用体
//  union Un
//  {
//      char c;//1
//      int i;//4
//  };

// int main(){
// union Un u;
// //共用一个空间,联合体变量的大小至少是最大成员的大小(因为联合至少得有能力保存最大的那个成员)
// printf("%lu\n",sizeof(u));

// //共用同一块空间,联合体不能同时存在.因为共用一个空间,改了i之后c也变了
// printf("%p\n",&u);
// printf("%p\n",&(u.c));
// printf("%p\n",&(u.i));
//     return 0;
// }

// int check_sys(){
//     int a=1;
//     //返回1,表示小端
//     //返回0,表示大端
//    return *(char*)&a;
// }
//法二:
// int check_sys()
// {
//     //用匿名共用体对象,和匿名结构体对象类似 这里用一次之后再也不会用到的就可以省去类型名字
//     union 
//     {
//         char c;//1
//         int i;//4
//     } u;
//     u.i = 1;
//     //利用共用体的特点,巧妙的利用他们共用同一个地址拿出c的内容要么就是01 要么就是 00
//     // 返回1,表示小端
//     // 返回0,表示大端
//     return u.c;
// }
// // 大小端字节序问题
// int main()
// {
//     // int a=1; //00 00 00 01(低)->存到内存中01 00 00 00 (低->高)
//     int ret = check_sys();
//     if (1 == ret)
//     {
//         printf("小端存储\n");
//     }
//     else
//     {
//         printf("大端存储\n");
//     }

//     // int a=0x11223344;
//     // 低地址-------------高地址
//     //[][][][][][][11][22][33][44][][][][][][][][]..//大端字节序存储模式
//     //[][][][][][][44][33][22][11][][][][][][][][]..//小端字节序存储模式
//     // 讨论一个数据,放在内存中存放的字节顺序
//     // 大小端字节序

//     return 0;
// }


//枚举类型的大小计算
// enum Sex{
//     MALE,
//     FEMALE,
//     SECRET
// };
// int main(){
//     enum Sex s=FEMALE;//MALE在枚举常量里面第一位默认是0 那么就是整形值,跟整形大小一样
//     printf("%lu\n",sizeof(s));
//     return 0;
// }

union Un{
    int a;//4 默认对其数是8,自身是4.较小值就是4 所以是4
    char arr[5];//5  char最小是1 默认是8 那么就是1 ,不按照倍数来算.算的是单个元素的大小
    //4+1=5 不是最大字节数4的整数倍
    //5不是4的倍数浪费3个字节,就是4的倍数了就是8
    //所以结构体存在对齐,位段为了节约空间不存在对齐
    //枚举也都是整形4个字节也不存在对齐的概念,那么就是共用体也是存在对齐的概念的
};  
int main(){
    union Un u;
    printf("%lu\n",sizeof(u));    
    return 0;
}

