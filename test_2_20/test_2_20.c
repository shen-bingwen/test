#include <stdio.h>
// int main()
// {
//     int a = 0x11223344;
//     int *pa = &a;
//     *pa = 0;
//     char *pc = &a;
//     *pc = 0;
//     // 指针类型决定了指针进行解引用操作的时候,能够访问空间的大小 以下是32位平台上
//     // int *p; *p能够访问4个字节  也就是说*pa=0 可以改成0x00000000
//     // char *p *p能够访问1个字节  但是*pc=0 只能改成0x00223344 只能动一个字节,8个比特位 十六进制两位数就是刚好一个字节
//     // double *p *p能够访问8个字节
//     printf("%p\n", pa);
//     printf("%p\n", pc);
//     return 0;
// }

// int main()
// {
//     // 所以指针类型决定了指针走一步走多远也就是决定了指针的步长
//     int a = 0x11223344;
//     int *pa = &a;
//     *pa = 0;
//     char *pc = &a;
//     printf("%p\n", pa);
//     printf("%p\n", pa + 1); //pa+1加1就是加4个字节 0x0000000
//     printf("%p\n", pc);
//     printf("%p\n", pc + 1);//pc+1加1就是加1个字节  0x00223344
//     return 0;
// }

// int main()
// {
//     int arr[10] = {0};
//     // int *p=arr;//数组名,首元素地址 存放第一个元素的地址,这一次可以访问4个字节
//     char *p = arr; // char * 一次只能访问一个字节,所以即使加到9也只能改成两个半的字节.因为数组一个元素是4个字节
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         *(p + i) = 1;
//     }
//     return 0;
// }

// 野指针
//  int main(){
//      // int a; //局部变量不初始化默认是随机值
//      int* p;//局部的指针变量,就被初始化为随机值
//      *p=20;
//      printf("%d\n",*p);
//      return 0;
//  }
//  int main(){
//      int arr[10]={0};
//      int * p=arr;
//      int i=0;
//      for ( i = 0; i < 12; i++)
//      {
//          p++;//当指针指向的范围超出数组arr的范围时,p就是野指针
//      }

//     return 0;
// }
// 调用函数的时候先创建变量一个a地址是0x0012ff44,当局部变量出这个函数就销毁了.把地址返回去
// int *test()
// {
//     int a = 10;
//     return &a;
// }
// int main()
// {
//     int *p = test();
//     // 确实接受到了0x0012ff44,但是调用完之后局部变量又把这空间还给系统了,*p想通过地址把20想放进去,
//     // 但是这时候地址已经不是当前程序的了,而是已经还给人家的内存块,也是会导致指针问题.
//     *p = 20;
//     return 0;
// }

// 数组越界导致的野指针问题
//  int main(){
//      int a[10]={0};
//      int* p=a;
//      int i=0;
//      for ( i = 0; i <=12; i++)
//      {
//*p=i
// p++
//         *p++=i;//这个等于上两步
//     }
//     return 0;
// }

// 如何规避野指针
// int main()
// {
//     // int a=10;
//     // int* pa=&a;
//     // //当不知道指针该指向哪里的时候就指向空 就是0 赋空指针
//     // int* p=NULL;
//     int a = 10;
//     int *pa = &a;
//     *pa = 20;
//     pa = NULL; // 指针指向空间释放
//     if (pa != NULL)
//     {
//         // 使用指针
//     }
// }

// 指针运算
// int main()
// {
// 指针加整数
// int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// int i = 0;
// int sz = sizeof(arr) / sizeof(arr[0]);
// int *p = arr;
// for (i = 0; i < sz; i++)
// {
//     printf("%d\n", *p);
//     p++;
// }
// for (i = 0; i < 5; i++)
// {
//     printf("%d\n", *p);
//     p += 2;
// }
// 指针减整数
// int *p=&arr[9];
// for (i = 0; i < 5; i++)
// {
//     printf("%d\n", *p);
//     p -= 2;
// }
// 指针加减整数
//     int arr[10]={1,2,3,4,5,6};
//     int* p;
//     for ( p=&arr[0]; p < &arr[5];)
//     {
//         *p++=0;

//     }
//     return 0;

// 地址减地址 大地址减小地址为中间元素的个数 小地址减大地址的绝对值等于中间元素个数
//  char ch[5]={0};
//  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//  printf("%ld\n",&arr[9]-&arr[0]);
//  printf("%ld\n",&arr[9]-&ch[0]);//err
// }

// 求字符串长度
// int my_strlen(char *str)
// {
//     char *start = str;
//     char *end = str;
//     while (*end != '\0')
//     {
//         end++;
//     }
//     return end - start;
// }
// int main()
// {
//     char arr[] = "bit";
//     int len = my_strlen(arr);
//     printf("%d\n", len);
// }

// 指针的关系运算 只能和内存中最后一个元素的后一位比较不能和第一个元素的前一位比较
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6};
//     int *p;
//     for (p = &arr[6]; p > &arr[0];)
//     {
//         *--p = 0;
//     }
//     return 0;
// }

// int main(){
//     // &arr--&数组名不是首元素的地址-数组名表示整个数组-&数组名取出的是整个数组的地址
//     // sizeof(arr)-sizeof(数组名)-数组名表示的是整个数组-sizeof(数组名)计算的是整个数组的的大小
//     //除以上两种情况数组名都是首元素地址
//     int arr[10]={0};
//     printf("%p\n",arr);
//     printf("%p\n",arr+1);

//     printf("%p\n",&arr[0]);
//     printf("%p\n",&arr[0]+1);

//     printf("%p\n",&arr);//取出的是整个数组的地址
//     printf("%p\n",&arr+1);
//     return 0;
// }

// int main()
// {
//     int arr[10]={0};
//     int* p=arr;
//     int i=0;
// for ( i = 0; i < 10; i++)
// {
//     printf("%p=======%p\n",p+i,&arr[i]);
// }
// 数组可以通过指针来访问
// for ( i = 0; i < 10; i++)
// {
//     *(p+i)=i;
// }
// for ( i = 0; i < 10; i++)
// {
//     // printf("%d\n",arr[i]);
//     printf("%d\n",*(p+i));

// }
// }


// int main()
// {
//     int a = 10;
//     int *pa = &a;//一级指针变量
//     int* *ppa=&pa;//二级指针
//     // int*** pppa=&ppa;//三级指针
//     printf("%d\n",**ppa);
//     **ppa=20;
//     printf("%d\n",**ppa);   
//     return 0;
// }

//指针数组 - 数组
//数组指针 - 指针
// int main(){
    // int a=10;
    // int b=20;
    // int c=30;
    // // int* pa=&a;
    // // int* pb=&b;
    // // int* pc=&c;
    // //整形数组-存放整形
    // //字符数组-存放字符
    // //指针数组-存放指针
    // // int arr[19];
    // int* arr2[3]={&a,&b,&c};//指针数组
    // int i=0;
    // for ( i = 0; i < 3; i++)
    // {
    //     printf("%d\n",*(arr2[i]));
    // }
    // return 0;
// }


