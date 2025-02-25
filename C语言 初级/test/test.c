#include <stdio.h>
#include <string.h>
// #include "add.c"
// int Add(int x, int y)
// {
//     int z = x + y;
//     return z;
// }

// int Max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//         return y;
// }
//   #define MAX(X,Y) (X>Y?X:Y) //宏定义

// struct book
// {
//     char name[100];
//     short price;
// };
int main()
{
  /*int line=0;
  printf("加入比特\n");
  while (line<20000)
  {
      printf("敲一行代码:%d\n",line);
      line++;
  }
  if (line>=20000)
  {
     printf("获得好offer\n");
  }
  */

  /*  int sum=0;
   int a=10;int b=20;
   sum=Add(a,b);
   printf("sum=%d\n",sum);
    return 0; */

  /* int a=1;
  int b= a<<6;
  printf("%d\n",b); */
  /*
      int a = 3;
      int b = 5;
      int c = a ^ b;
      printf("%d\n", c);
      return 0; */

  //  int arr[] = {'a','b'};
  // int a = 0;
  // int qq=0;
  // printf("%ld\n",sizeof arr); //8
  // printf("%ld\n",sizeof(arr)); //8
  // printf("%ld\n",sizeof (int)); //4
  // qq=sizeof arr/sizeof(int);//2
  // printf("%d\n",qq);
  // int sz = 0;
  // sz = sizeof arr / sizeof(int);
  // printf("sz=%d\n", sz);
  // printf("%ld\n", sizeof(a));
  // printf("%ld\n", sizeof(int));
  // printf("%lu\n", sizeof a);
  // printf("%lu\n", sizeof int);

  /*   int a = 10;
    int b = 20;
    int max=0;
   max= Max(a,b);˜
    printf("最大值是:%d\n",max );
    return 0; */
  //    char arr[]={1,2,3,4,5,6,7};
  // printf("%ld\n",strlen(arr));

  //  int a=10;
  //  int b=!a;
  //  printf("%d\n",b);
  //  printf("%d\n",a);

  //  int a=0;
  //  int b=!a;
  //  printf("%d\n",b);
  //  printf("%d\n",a);

  // int a=-2;
  // int b=~a; //正数取反得到补码,如果不取反32位的二进制首位是0为正,那么原反补相同.
  //             //如果是负数的话直接就是补码,然后推出原码后再取反.
  // printf("%d\n",b);
  // int a=0;
  // int b=~a;
  // printf("%d\n",b);
  // 00000000 先把得到的二进制所有按位取反得到111111111为补码,1在首位就是代表负,0为正;
  // 然后按照补码先减一到反码再不动首位符号为对所有再次取反就是原码
  // 11111111补码
  // 11111110反码
  // 10000001原码
  // (负数在内存中存储时代表是二进制的补码)补码到原码就是先减1得到反码
  // 然后符号为不变其余按位取反得到原码;

  // int  a=4;//0100
  // int b=8; //1000
  // int c=a|b;//1100
  // printf("%d\n",c);按位或

  //  int  a=8;//1000
  // int b=8; //1000
  // int c=a&b;//1000 8
  // printf("%d\n",c);按位与

  //  int  a=2;//0010
  // int b=8; //1000
  // int c=a^b;//1010  10
  // printf("%d\n",c);按位异或

  // const - 常属性
  // const int n = 10;//n是变量，但是又有常属性，所以我们说n是常变量
  // int arr[n] = {0};
  // n = 20;

  // 2. const修饰的常变量
  // const int num = 4;
  // printf("%d\n", num);
  // num = 8;
  // printf("%d\n", num);
  // unsigned int  num1=-20;
  // printf("%u\n", num1);
  // typedef unsigned int u_int;
  // u_int num2=10;
  // printf("%u\n", num2);
  // extern - 声明外部符号的
  // extern int g_val;
  // printf("g_val = %d\n", g_val);
  // return 0;

  // extern int Add(int,int);
  // int a=10;
  // int b=20;
  // int sum=Add(a,b);
  // printf("sum=%d\n",sum);

  // int a=10;
  // int b=20;
  // int max=MAX(a,b);
  // printf("%d\n",max);

  // int a=10;
  // printf("%p\n",&a);

  // int a=10;
  // int* p=&a;
  // printf("%p\n",&a);
  // printf("%p\n",p);

  // int a = 10;
  // int* p = &a;
  // *p = 20;
  // printf("a=%d\n", a);
  // return 0;

  // char ch='w';
  // char*  pc=&ch;
  // printf("%lu\n",sizeof(pc));
  // *pc='r';
  // printf("ch=%c\n", ch);

  // printf("\t**\n");
  // printf("\t**\n");
  // printf("    **********\n");
  // printf("    **********\n");
  // printf("\t* *\n");
  // printf("\t* *\n");

  // #define MAX 1000; //定义标识符常量
  // int a=MAX;
  // printf("%d\n",a);
  // int n = 0;
  // scanf("%d", &n);
  // if (n % 5 == 0)
  // {
  //     printf("YES\n");
  // }
  // else
  // {
  //     printf("NO\n");
  //     return 0;
  // }

  // double d=3.14;
  // double* pd=&d;
  // *pd=5.5;
  // printf("%lf\n",d);
  // printf("%lf\n",*pd);
  // printf("%p\n",pd);
  // printf("%p\n",&d);
  // printf("%lu\n",sizeof(double*));
  // printf("%lu\n",sizeof *pd);

  // int d=3;
  // int* pd=&d;
  // *pd=5;
  // printf("%lu\n",sizeof(char*));
  // printf("%lu\n",sizeof &d);
  // printf("%lu\n",sizeof pd);
  // printf("%lu\n",sizeof d);
  // printf("%lu\n",sizeof *pd);

  //    struct book b1={"C语言程序设计",55};
  //    struct book* p1=&b1;

  //     printf("书名是:%s\n",p1->name);
  //     printf("价格是:%d元\n",p1->price);
  //     strcpy(b1.name,"C++");
  // printf("修改后的书名是:%s\n",p1->name);
  // printf("修改后的书名是:%s\n",(*p1).name);

  // int age = 8;
  // if (age < 18)
  // {
  //     printf("未成年\n");
  //     printf("不能谈恋爱\n");
  // }

  // else
  // {
  //     if (age >= 18 && age < 28)
  //         printf("成年\n");
  //     else if (age >= 28 && age < 50)
  //         printf("壮年\n");
  //     else if (age >= 50 && age < 90)
  //         printf("老年\n");
  //     else
  //     {
  //         printf("老不死\n");
  //     }
  // }

  // int age=118;
  // if(age<18)
  // printf("未成年\n");
  // else if(age>=18&&age<28)
  // printf("成年\n");
  // else if(age>=28&&age<50)
  // printf("壮年\n");
  // else if(age>=50&&age<90)
  // printf("老年\n");
  // else
  // {
  //         printf("老不死\n");
  // }

  // printf("书名是:%s\n",(*p1).name);
  // printf("价格是:%d元\n",(*p1).price);

  // printf("书名是:%s\n",b1.name);
  // printf("价格是:%d元\n",b1.price);
  //    b1.price=15;
  // printf("修改后的价格是:%d元\n",b1.price);

  // int a = 10;
  // if (a > 8)
  // {
  //     printf("在干嘛\n");
  // }
  // //  printf("吃了吗\n");
  // else
  // {
  //     printf("吃了吗\n");
  // }

  // int num=5;
  // if(5==num)
  // printf("呵呵\n");
  // return 0;

  // int num = 1;
  // while (num <= 100)
  // {
  //     if (num % 2 != 0)
  //    printf("%d\n", num);
  //     num++;
  // }
  // return 0;

  // int num=1;
  // while (num<100)
  // {
  //     printf("%d\n",num);
  //     num+=2;
  // }

  // int day=1;
  // if (2==day)
  // {
  //     printf("星期一\n");
  // }

  // int day = 1;
  // scanf("%d", &day);
  // switch (day)
  // {
  // case 1:
  //     printf("星期一\n");
  //     break;
  // case 2:
  //     printf("星期二\n");
  //     break;
  // case 3:
  //     printf("星期三\n");
  //     break;
  // case 4:
  //     printf("星期四\n");
  //     break;
  // case 5:
  //     printf("星期五\n");
  //     break;
  // case 6:
  //     printf("星期六\n");
  //     break;
  // case 7:
  //     printf("星期天\n");
  //     break;
  // }

  // //
  // int n=1;
  // int m=2;
  // switch (n)//1
  // {
  // case 1:m++;//3
  // case 2:n++;//2
  // case 3:
  // switch (n)//2
  // {
  // case 1:n++;
  // case 2:m++;n++;//4 3
  //     break;
  // }
  // case  4:m++;//5 3
  // printf("%d\n",m);
  // printf("%d\n",n);
  //     break;

  // default:
  //     break;
  // }

  // int i = 1;
  // while (i <= 10)
  // {
  //   if (5 == i)
  //     continue;
  //   printf("%d\n", i);
  //   i++;
  // }

  // int i=0;
  //  while (i <= 10)
  // {
  //   i++;
  //   if (5 == i)
  //     continue;
  //   printf("%d\n", i);
  // }

    // int ch =1;
    //EOF 文件结束标志-end of file 值为-1;
    // while ((ch=getchar())!=EOF) //ctrl+z 把EOF放到ch里面就为假了就不执行了
    // {
    //   putchar(ch);
    // }
}