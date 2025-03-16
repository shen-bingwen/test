#include <stdio.h>
// 指针详解

// 当数组名作为函数参数时， 这里 arr 是指向 int 的指针,在32位就是4个字节,64位就是8个字节
//  void test(int arr[]){
//      int sz=sizeof(arr)/sizeof(arr[0]);
//      printf("%d\n",sz);
//  }
//  int main(){
//      int arr[10]={0};
//      test(arr);
//      return 0;
//  }

// int main()
// {
//     char arr[] = "abcdef";
//     char *pr = arr;
//     printf("%s\n",arr);
//     printf("%s\n",pr);
//     return 0;
// }

// int main()
// {
//    char *pr = "abcdef"; //“abcdef”是一个常量字符串是改不了的
//     *pr='w';//所以这是个段错误
//     printf("%s\n",pr);
//     return 0;
// }

// int main()
// {
//     char arr1[] = "abcdef";
//     char arr2[] = "abcdef";
//     const char *p1 = "abcdef";
//     const char *p2 = "abcdef"
//     // if (arr1 == arr2) // arr1数组名和arr2数组名不一样,首元素地址自然也不一样
//     // {
//     //     printf("hehe\n");
//     // }
//     // else
//     // {
//     //     printf("haha\n");
//     // }
// 但是p1和p2不一样了
//     // if (p1 == p2)//因为这里是常量字符串,不能被修改所以只能拿去用,那么就是p1p2指向同一块地址.所以相等.虽然P1和P2有独立空间,但指针指向的是同一个地址.
//     // {
//     //     printf("hehe\n");
//     // }
//     // else
//     // {
//     //     printf("haha\n");
//     // }
//     return 0;
// }

// 指针数组 是数组,用来存放指针的
//  int main(){
//      int arr[10]={0};//整形数组
//      char ch[5]={0};//字符数组
//      int* par[4];//存放整形指针的数组
//      char* pch[5];//存放字符指针的数组
//  }

// int main()
// {
//     int a = 10;
//     int b = 20;
//     int c = 30;
//     int d = 40;
//     int *arr[4] = {&a, &b, &c, &d};
//     int i = 0;
//     for (i = 0; i < 4; i++)
//     {
//         printf("%d\n", *(arr[i]));//很少这样用,比较低级
//     }
//     return 0;
// }

// 指针数组的用法
//  int main()
//  {
//      int arr1[] = {1, 2, 3, 4, 5};
//      int arr2[] = {2, 3, 4, 5, 6};
//      int arr3[] = {3, 4, 5, 6, 7};
//      int *parr[] = {arr1, arr2, arr3};
//      int i = 0;
//      for (i = 0; i < 3; i++)
//      {
//          int j = 0;
//          for (j = 0; j < 5; j++)
//          {
//              printf("%d ", *(parr[i] + j));
//          }
//          printf("\n");
//      }
//      return 0;
//  }

// 数组指针 -- 指针
// int main()
// {
//     int *p = NULL;   // p是整形指针,指向整形的指针 --可以存放整形的地址
//     char *pc = NULL; // pc是字符指针,指向字符的指针 --可以存放字符的地址
//     // 数组指针-指向数组的指针 可以存放数组的地址
//     int arr[10] = {0};
//     // arr-首元素地址
//     //&arr[0]-首元素的地址
//     //&arr-数组的地址
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     //因为*的优先级没有[]高,所以得加个括号,区别出来是数组指针,而不是指针数组
//     //此时p就是数组指针
//     int(*p)[10] =&arr;
//     return 0;
// }

// int main()
// {
//     char *arr[5];
//     char *(*pa)[5] = &arr;
//     return 0;
// }

// int main(){
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int(*p)[10] =&arr;
//     int i=0;
//     //第一种
//     // for ( i = 0; i < 10; i++)
//     // {
//     //    printf("%d ", (*p)[i]);
//     // }
//     //第二种
//     // for ( i = 0; i < 10; i++)
//     // {
//     //    printf("%d ", *(*p+i)); //*p=arr
//     // }
//     //第三种最简单
//     int *pa=arr;
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d ",*(pa+i));
//     }
// }

// void print1(int arr[3][5], int x, int y)
// {
//     int i = 0;
//     for (i = 0; i < x; i++)
//     {
//         int j = 0;
//         for (j = 0; j < y; j++)
//         {
//             printf("%d ",arr[i][j]);
//         }
//         printf("\n");
//     }
// }
//
// void print2(int (*p)[5], int x, int y)//把二维数组想象成一个一维数组,这样子就可以把参数部分写成指针
// {
//     int i = 0;
//     for (i = 0; i < x; i++)
//     {
//         int j = 0;
//         for (j = 0; j < y; j++)
//         {
//             // printf("%d ", *(*(p+i)+j));
//             // printf("%d ", *(p[i]+j));
//             // printf("%d ", p[i][j]);
//             // printf("%d ", (*(p + i))[j]);
//             //谁没变成中括号的形式谁就得解引用. 像+j就得整体扩起来解引用,虽然i已经解引用了但是j还没有
//         }
//         printf("\n");
//     }
// }
// int main()
// {
//     int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
//     // print1(arr, 3, 5);
//     print2(arr, 3, 5);
// }
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i = 0;
//     int* p=arr;
//     for (i = 0; i < 10; i++)
//     {
//         // printf("%d " ,arr[i]);
//         // printf("%d " ,p[i]);
//         // printf("%d " ,*(p+i));
//         // printf("%d " ,*(arr+i)); //arr[i]==*(arr+i)==*(p+i)==p[i]
//     }
//     return 0;
// }

// 函数指针
// int ADD(int x, int y)
// {
//     int z = 0;
//     z = x + y;
//     return z;
// }
// int main()
// {
//     // int a = 10;
//     // int b = 10;ƒ
//     // ADD(a, b);
//     //&+函数名和函数名都是函数的地址
//     // printf("%p\n", &ADD);
//     // printf("%p\n", ADD);ï
//     // 函数指针--存放函数地址的一个指针
//     int (*pa)(int, int) = ADD;
//     printf("%d \n", (pa)(2, 3));//pa是个函数地址,调用这个地址区指向这个函数也可以
//     printf("%d \n", (*pa)(2, 3));//pa是个指针的话*解引用.找到函数然后调用他
//     return 0;
// }

// void Print(char *str)
// {
//     printf("%s", str);
// }
// int main()
// {
//     void (*pa)(char *) = Print;
//     (*pa)("hello bit");
//     return 0;
// }

// 读代码
// 代码1:
//*(void(*)()0)(); //void(*)()这是一个函数指针类型.
// 总结把0强制类型转换就是一个函数指针类型.该指针指向的函数是无参,返回类型是void,当0变成一个函数地址之后进行解引用操作.去调用以0为地址处的该函数.

// 代码2:
// void(*signal(int,void(*)(int))(int);
// signal(int,void(*)(int)) 与函数声明一样 signal是个函数名,后面是2个函数参数类型,第一个是int 第二个是函数指针.该函数指向的指针类型是int,返回类型是void
// 而类型则为去掉函数名和参数类型剩下的 void(*         )(int) 也是一个函数指针
// signal函数的返回类型也是一个函数指针,该函数指向的指针类型是int,返回类型是void

// 可以通过typedef定义简化
//  typedef void(*pfun_t)(int); //和普通的类型重定义不一样,这里重定义的类型名依旧是贴近星号
//  //void(*signal(int,void(*)(int))(int); //结果就可以由这个变成下面那个
//  pfun_t signal(int,pfun_t);

// //函数指针数组
// int ADD(int x, int y)
// {
//     int z = 0;
//     z = x + y;
//     return z;
// }
// int Sub(int x,int y){
//     return x-y;
// }
// int Div(int x,int y){
//     return x/y;
// }int Mul(int x,int y){
//     return x*y;
// }
// int main()
// {
//     //指针数组
//     int* arr[5];
//     //需要一个数组,这个数组可以存放4个相同类型函数的地址-函数指针的数组
//     int (*pa)(int, int) = ADD;//Sub//Mul/Div
//     int(*parr[4])(int,int)={ADD,Sub,Mul,Div};
//     int i=0;
//     for ( i = 0; i < 4; i++)
//     {
//         printf("%d\n",parr[i](2,3));
//     }
//     return 0;
// }

// char *my_strcpy(char *dest, const char *src)
// {
// }
// int main()
// {
//     // 1.写一个函数指针 pf,能够指向my_strcpy
//     char (*pf)(char *, const char *);
//     // 2.写一个函数指针数组 pfArr,能够存放4个my_strcpy函数的地址
//     char (*pfArr[4])(char *, const char *);
// }

// 函数指针数组用途
// void menu()
// {
//     printf("*****************************\n");
//     printf("******1.ADD       2.SUB *****\n");
//     printf("******3.MUL       4.DIV *****\n");
//     printf("******5.XOL       0.EXIT*****\n");
//     printf("*****************************\n");
// }
// int ADD(int x, int y)
// {
//     return x + y;
// }
// int SUB(int x, int y)
// {
//     return x - y;
// }
// int MUL(int x, int y)
// {
//     return x * y;
// }
// int DIV(int x, int y)
// {
//     return x / y;
// }
// int XOL(int x, int y)
// {
//     return x ^ y;
// }
// // case语句里面冗余
// //  int main()
// //  {
// //      int input = 0;
// //      int a = 0;
// //      int b = 0;
// //      do
// //      {
// //          menu();
// //          printf("请选择:>");
// //          scanf("%d", &input);
// //         switch (input)
// //         {
// //         case 1:
// //             printf("请输入两个操作数:>");
// //             scanf("%d%d", &a, &b);
// //             printf("%d\n", ADD(a, b));
// //             break;
// //         case 2:
// //             printf("请输入两个操作数:>");
// //             scanf("%d%d", &a, &b);
// //             printf("%d\n", SUB(a, b));
// //             break;
// //         case 3:
// //             printf("请输入两个操作数:>");
// //             scanf("%d%d", &a, &b);
// //             printf("%d\n", MUL(a, b));
// //             break;
// //         case 4:
// //             printf("请输入两个操作数:>");
// //             scanf("%d%d", &a, &b);
// //             printf("%d\n", DIV(a, b));
// //             break;
// //         default:
// //             printf("选择错误\n");
// //             break;
// //         }
// //     } while (input);
// //     return 0;
// // }

// 解决冗余法1:利用函数指针数组
// int main()
// {
//     int input = 0;
//     int a = 0;
//     int b = 0;
//     //pfArr是一个函数指针数组--转移表
//     int (*pfArr[])(int, int) = {0, ADD, SUB, MUL, DIV,XOL};
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d", &input);
//         if (input >= 1 && input <= 5)
//         {
//             printf("请输入两个数:>");
//             scanf("%d%d", &a, &b);
//             int ret=pfArr[input](a,b);
//             printf("%d\n",ret);
//         }
//         else if (input == 0)
//         {
//             printf("退出游戏\n");
//         }
//         else
//         {
//             printf("输入错误,请重新输入\n");
//         }
//     } while (input);
//     return 0;
// }

// 解决冗余法2:回调函数
// void menu()
// {
//     printf("*****************************\n");
//     printf("******1.ADD       2.SUB *****\n");
//     printf("******3.MUL       4.DIV *****\n");
//     printf("******5.XOL       0.EXIT*****\n");
//     printf("*****************************\n");
// }
// int ADD(int x, int y)
// {
//     return x + y;
// }
// int SUB(int x, int y)
// {
//     return x - y;
// }
// int MUL(int x, int y)
// {
//     return x * y;
// }
// int DIV(int x, int y)
// {
//     return x / y;
// }
// int XOL(int x, int y)
// {
//     return x ^ y;
// }
// void Calc(int (*pf)(int, int)) // 接收后下面printf通过函数指针pf来通过地址来调用函数.
// //把一个函数的地址传给一个指针,在函数内部通过指针调用函数时候,那个被调用的函数(即ADD等等)就被称为回调函数.
// {
//     int a = 0;
//     int b = 0;
//     printf("请输入两个数:>");
//     scanf("%d%d", &a, &b);
//     printf("%d\n", pf(a, b));
// }
// int main()
// {
//     int input = 0;
//     do
//     {
//         menu();
//         printf("请选择:>");
//         scanf("%d", &input);
//         switch (input)
//         {
//         case 1:
//             // 利用函数的地址进行传参数,传过去用函数指针接受
//             Calc(ADD);
//             break;
//         case 2:
//             Calc(SUB);
//             break;
//         case 3:
//             Calc(MUL);
//             break;
//         case 4:
//             Calc(DIV);
//             break;
//         case 5:
//             Calc(XOL);
//             break;
//         case 0:
//             printf("退出游戏\n");
//             break;
//         default:
//             printf("输入错误,重新输入\n");
//             break;
//         }
//     } while (input);
// }

// 指向函数指针数组的指针
// int main(){
//     int arr[10]={0};
//     int (*p)[10]=&arr;//取出数组的地址

//     int(*pf)(int,int);//函数指针
//     int(*pfArr[4])(int,int);//pfarr是一个数组...函数指针的数组
//     int (*(*ppfArr)[4])(int,int)=&pfArr;//ppfArr是一个指向[函数指针数组]的指针

//     //
//     //ppfArr 是一个数组指针,指针指向的数组有4个元素
//     //指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
//     //
//     return 0;
// }

// 函数调用
// void print(char *str) // 传递字符串（如 "bit"）	char*	字符串本质是字符数组的地址，需要用指针接收地址
// {
//     printf("hehe:%s\n", str);
// }
// void test(void (*p)(char *))
// {
//     printf("test\n");
//     p("bit");
//     // 当你传递字符串 "bit" 给函数时：
//     //  字符串字面量 "bit" 会被编译器存储为 全局内存中的一个字符数组。
//     //  数组名 "bit" 会被隐式转换为指向数组首元素的指针（即 char* 类型）。
//     //  最终传递给函数的是这个指针（地址值）。所以print的形参得用char*接受
// }
// int main()
// {
//     test(print);
//     return 0;
// }

// int Add(int x, int y)
// {
//     return x + y;
// }
// int main()
// {
//     // 指针数组
//     int *arr[10];
//     // 数组指针
//     int *(*pa)[10] = &arr;
//     // 函数指针
//     int (*pAdd)(int, int) = Add; //&Add
//     // int sum = (*pAdd)(1, 2);
//     int sum = (pAdd)(1, 2);
//              //Add(1,2);一样的道理,加不加*都一样,既然Add()能直接通过地址调用,那么pAdd也可以用.
//     printf("%d\n", sum);
//     // 函数指针的数组
//     int (*pArr[5])(int,int);
//     //指向函数指针数组的指针
//     int (*(*ppArr)[5])(int,int)=&pArr;
//     return 0;
// }

// 冒泡排序
#include <stdlib.h>
// void bubble_sort(int arr[], int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz - 1; i++)
//     {
//         int j = 0;
//         for (j = 0; j < sz - 1 - i; j++)
//         {
//             int tmp = 0;
//             tmp = arr[j + 1];
//             arr[j + 1] = arr[j];
//             arr[j] = tmp;
//         }
//     }
// }
struct Stu
{
    char name[10];
    int age;
};
// qsort库函数-排序 快速排序
//  quick sort
// void qsort(void *base,
//     size_t num,
//     size_t width,
//     int (*cmp)(const void *e1,const void *e2));

// e1和e2接收要比较两个元素的地址
// int cmp_int(const void *e1, const void *e2)
// {
//     // 比较两个整形值的大小,因为这里接受的是两个void*的指针,那么我们解引用操作不行,因为在这个函数里面比较的是两个整形的元素,所以我们首先把e1hee2强制类型转换一下.
//     // 比较函数特点:当第一个元素小于第二个元素的时候让他返回小于0的数字,当相等的时候返回一个0,当第一个元素大于第二个元素的时候返回一个大于0的数字.
//     return *(int *)e1 - *(int *)e2;
// }
// void test1()
// {
//     int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     qsort(arr, sz, sizeof(arr[0]), cmp_int);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }
// int cmp_float(const void *e1, const void *e2)
// {
//     // if (*(float *)e1 == *(float *)e2)
//     // {
//     //     return 0;
//     // }
//     // else if (*(float *)e1 > *(float *)e2)
//     // {
//     //     return 1;
//     // }
//     // else
//     //     return -1;

//     //因为返回类型要和函数定义的类型相符合,所以float要再强制类型转换一下,要么就是上面的if else语句
//     return ((int)(*(float *)e1 - *(float *)e2));
// }
// void test2()
// {
//     float f[] = {9.0, 8.0, 7.0, 6.0, 5.0};
//     int sz = sizeof(f) / sizeof(f[0]);
//     qsort(f, sz, sizeof(f[0]), cmp_float);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%f ", f[i]);
//     }
// }
int cmp_stu_by_age(const void *e1, const void *e2)
{
    return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
}
// #include <string.h>
// int cmp_stu_by_nmae(const void *e1, const void *e2)
// {
//     // 比较名字就是比较字符串,不能直接用大于等于来比较,
//     // 字符串比较不能直接用><=来比较,应该用strcmp函数
//     return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
// }
// void test3()
// {
//     struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 10}, {"xiaoming", 99}};
//     int sz = sizeof(s) / sizeof(s[0]);
//     // 结构体是复杂对象,所以不能用大于号小于号比,得指定其中的元素来比.
//     // qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
//     qsort(s, sz, sizeof(s[0]), cmp_stu_by_nmae);
//     // 第一个参数：待排序数组的首元素地址
//     // 第二个参数：待排序数组的元素个数
//     // 第三个参数：待排序数组的每个元素的大小-单位是字节
//     // 第四个参数：是函数指针，比较两个元素的所用函数的地址-这个函数使用者自己实现
//     //            函数指针的两个参数是：待比较的两个元素的地址
//     int i = 0;//用于作为断点观察调试结果,并不打印
//     // for (i = 0; i < sz; i++)
//     // {
//     //     printf("%d ", s[i]);
//     // }
// }
// 回调函数实现冒泡排序
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
    // 循环趟数
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        // 每一趟比较的对数
        for (j = 0; j < sz - 1 - i; j++)
        {
            //相邻两个元素的比较
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
    }
}
// void test4()
// {
//     int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     // qsort(arr, sz, sizeof(arr[0]), cmp_int);
//     bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }
void test5()
{
    struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 10}, {"xiaoming", 30}};
    int sz = sizeof(s) / sizeof(s[0]);
    // 结构体是复杂对象,所以不能用大于号小于号比,得指定其中的元素来比.
    bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
    struct  Stu *p=s;  
    for (int i = 0; i < sz; i++) {
        // 法一:
        // printf("%d\n", s[i].age);  // ✅ 正确打印
        //法二:通过指针变量p指向数组首元素,通过p++来遍历.
        printf("%d\n", p->age);  // ✅ 正确打印
        p++;
    }
    
    // bubble_sort(s, sz, sizeof(s[0]), cmp_int);
}
int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();
    // bubble_sort(arr, sz);

    return 0;
}

// void*相关知识补充
//  int main(){
//      int a=10;
//      // int* pa=&a;
//      // char* pc=&a;

//     // char ch='w';
//     //void* 的指针可以接受任意类型的地址 不管是int* float* 还是struct*
//     void* p=&a;
//     //指针类型决定访问几个字节,但是void*没有指定是什么类型,所以是不能进行解引用操作的
//     // *p=0;
//     //也不能进行加减整数的运算因为也不知道向后走几个字节
//     // p++;
//     // p=&ch;
// }
