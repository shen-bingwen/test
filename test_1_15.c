#include <stdio.h>
#include <string.h>
#include <math.h>
#include "add.c"
int main()
{
    int a = 20;
    int b = 10;
    int sum = 0;
    sum=Add(a,b);
    printf("%d\n", sum);
    return 0;
}


// int get_max(int x, int y)
// {
//     if (x > y)
//         return x;
//     else
//     {
//         return y;
//     }
// }
// void swap1(int x, int y) //void传值调用 是空代表没有返回值,但是这种传过来的是变量不是地址,而形参会自己开辟一个地址,最后就做不到调换的值回传.不能完成操作
// {
//     int tmp=0;
//     tmp = x;
//     x = y;
//     y = tmp;
// }
// void swap2(int* pa, int* pb) // 形参,传址调用得用指针来接受传过来的地址,这样子就可以把交换的结果回传回去.
// {
//     int tmp = 0;
//     tmp = *pa;
//     *pa = *pb;
//     *pb = tmp;
// }

// int is_prime(int n)
// {
//     int z = 0;
//     for (z = 2; z <= sqrt(n); z++)
//     {
//         if (n % z == 0)
//         {
//             return 0;//直接结束本串函数
//         }
//        /* 这种写法是错误的,左倾了,假设n为9,当n%2!=0,直接return 1,打印9为素数,
//         但是并没有把2之后的值都试一遍,例如3就能被9整除.9并不是素数
//         else{
//             return 1;
//         }*/
//     }
//     return 1;//这次只有一种情况会到这,当z>sqrt(n)的函数时才会来到这,因为上面是return 0而不是break,所以不会来到这里.
// }

// int is_lear_year(int x)
// {
//     if ((x % 4 == 0 && x % 100 != 0)||(x % 400 == 0))
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// int arr[] 本质上是一个指针,因为假设实参有10000个数组元素,这边只是临时拷贝,为了避免空间浪费,这边就不会把1w个元素再拷贝过来.
// int is_binary_search(int arr[],int k,int sz) //形参和实参的名字相同语法支持
// {
//     //所以这里sizeof(arr)去计算一个指针大小的时候就是4或8,在这里64位平台就是8 8/4=2 得不到元素个数
//     // int sz =sizeof(arr) / sizeof(arr[0]); 所以得去函数外部算
//     int left = 0;
//     int right = sz-1;
//     while (left <= right)
//     {
//         int mid = (left + right) / 2;
//         if (arr[mid] < k)
//         {
//             left = mid+1;//这里如果不用加一用加加的话,首先mid为4+9=13/2=6 把6赋给left(旧值) 然后6+9=15/2=7 把7赋给left(旧).然后就是7+9=16/2=8赋给left(旧)然后就是8+9=17/2=8left(旧)会把坐下标到8的时候 然后就8+9=17/2=8=mid=left
//              然后8+9就一直为8死循环,因为mid++传回去的是8,就等于left永远是不会>9,这样判断条件left<=right恒成立.
//         }
//         else if (arr[mid] > k)
//         {
//             right = mid-1;
//         }
//         else
//         {
//             return mid;
//         }
//     }
//     return -1;
// }
// void Add(int* p){
//     // *p++;//加加的优先级高过* 所以该种写法是错误的!!!
//     (*p)++;
// }

// void new_line(){
//     printf("呵呵\n");
// }
// void three_line(){
//     int i=0;
//     for ( i = 0; i < 3; i++)
//     {
//         new_line();
//     }
// }


// int Add(int, int); // 函数声明
// int main()
// {
//     int a = 20;
//     int b = 10;
//     int sum = 0;
//     sum = Add(a, b);//函数调用
//     printf("%d\n", sum);
// }
// int Add(int x, int y)//函数定义
// {
//     int z = x + y;
//     return z;
// }

// int main()
// {
    // printf("%d\n",printf("%d",printf("%d",43))); //printf的返回值是每次字符的个数.
    // return 0;

    // 链式访问
    // int len = 0;
    // len = strlen("abc");
    // printf("%d\n", len);
    // printf("%lu\n", strlen("abc"));
    // return 0;

    // 函数的嵌套调用
    //  three_line();

    // 每调用一次函数num+1;
    //  int num=0;
    //  Add(&num);
    //  printf("%d\n",num);
    //  Add(&num);
    //  printf("%d\n",num);
    //  Add(&num);
    //  printf("%d\n",num);
    //  return 0;

    //     // 二分查找 思路:先写函数怎么用, 再去写函数怎么实现.
    //     int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //     int k = 11;
    //     int sz =sizeof(arr) / sizeof(arr[0]);
    //     int ret=is_binary_search(arr,k,sz);//arr传的是一个地址
    //     if(ret==-1)
    //     {
    //         printf("找不到指定的数字\n");
    //     }
    //     else
    //     {
    //         printf("找到了,下标为:%d\n",ret);
    // }

    // 调用函数判断一年是不是闰年
    // int year = 0;
    // int count=0;
    // for (year = 1000; year <= 2000; year++)
    // {
    //     if (1==is_lear_year(year))
    //     {
    //         count++;
    //         printf("%d是闰年\n",year);
    //     }
    // }
    //         printf("\n闰年个数为:%d\n",count);

    // 调用函数打印素数
    // 打印100-200的素数
    // int i = 0;
    // for (i = 101; i <= 200; i+=2)
    // {
    //     if (is_prime(i) == 1)
    //         printf("素数为:%d\n", i);
    // }
    // return 0;

    //  int count = 0;
    //  count++;
    // printf("\n素数个数为:%d\n", count);

    // 调用函数交换值
    //  int a = 10;
    //  int b = 20;
    //  swap2(&a, &b);//把地址传过去才能保证传回来的值进行改变.
    //  printf("a=%d b=%d\n", a, b);

    // 函数类型 函数名(函数参数(形参)){函数体};
    // 而实参可以是常数,变量,表达式,函数等
    // int a=10;
    // int b=20;
    // int max=0;
    // max=get_max(a,b);//实参变量
    // printf("%d\n",max);
    // max=get_max(200,300);//实参常数
    // max=get_max(200,300+1);//实参表达式
    // max=get_max(200,get_max(3,7));//实参函数
    // printf("%d\n",max);

    // memset
    //  char arr[]="hello world";
    //  memset(arr,'*',5);
    //  printf("%s\n",arr);
    //  return 0;
// }