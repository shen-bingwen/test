#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main()
{
    // 关机语句
    char input[20] = {0};
    system("sudo shutdown -h +2");
    while (1)
    {
        printf("请注意:你的电脑将在1分钟内关机,如果输入:我是猪,就取消关机\n,请输入>:");
        scanf("%s", input);
        if (strcmp(input, "我是猪") == 0)
        {
            {
                system("sudo killall shutdown");
                break;
            }
        }
    }

    return 0;

    //     //关机语句配合goto
    //     char input[]={0};
    //     system("sudo shutdown -h +1");
    //     error:
    //     printf("请注意:你的电脑将在1分钟内关机,如果输入:我是猪,就取消关机\n,请输入>:");
    //     scanf("%s",input);
    //    if (strcmp(input,"我是猪")==0)
    //    {
    //     system("sudo killall shutdown");
    //    }
    //    else
    //    {
    //     goto error;
    //    }
    //     return 0;

    // goto语句
    // printf("hello bit\n");
    // goto again;
    // printf("你好\n");
    // again:
    // printf("呵呵\n");

    // again:
    // printf("hello bit\n");
    // goto again;

    // void menu()
    // {
    //     printf("**************************\n");
    //     printf("****** 1.play  0.exit*****\n");
    //     printf("**************************\n");
    // }
    // // RAND_MAX 0-0x7fffffff
    // void game()
    // {
    //     // 1.生成一个随机数
    //     // 拿时间戳设置一个生成起点
    //     //  time_t
    //     int ret = 0;
    //     int guess = 0;
    //     ret = rand() % 100 + 1; // 生出1-100的随机数
    //     // printf("%d\n", ret);
    //     // 2.猜数字
    //     while (1)
    //     {
    //         printf("请猜数字\n");
    //         scanf("%d", &guess);
    //         if (guess > ret)
    //         {
    //             printf("猜大了\n");
    //         }
    //         else if (guess < ret)
    //         {
    //             printf("猜小了\n");
    //         }
    //         else
    //         {
    //             printf("恭喜你,猜中了\n");
    //             break;
    //         }
    //     }
    // }

    // int main()
    // {
    //     // 猜数字游戏
    //     srand((unsigned int)time(NULL));
    //     // 时间戳 当前计算机的时间-计算机的起始时间(1970年0时0分0秒)=(xxxx)秒
    //     int input = 0;
    //     do
    //     {
    //         menu();
    //         printf("请选择:>");
    //         scanf("%d", &input);
    //         switch (input)
    //         {
    //         case 1:
    //             game();
    //             break;
    //         case 0:
    //             printf("退出游戏\n");
    //             break;
    //         default:
    //             printf("选择错误\n");
    //             break;
    //         }
    //     } while (input);
    //     {
    //         ;
    //     }
    //     return 0;
    // }

    // // /二分查找法
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int k = 7;
    // int sz = sizeof(arr) / sizeof(arr[0]);
    // int left = 0;
    // int right = sz - 1;
    // while (left <= right)
    // {
    //     int mid = (left + right) / 2;
    //     if (arr[mid] < k)
    //     {
    //         left = mid++;
    //     }
    //     else if (arr[mid] > k)
    //     {
    //         right = mid--;
    //     }
    //     else
    //     {
    //         printf("找到了,下标为:%d\n", mid);
    //         break;
    //     }
    // }
    // if (left > right)
    // {
    //     printf("没找到\n");
    // }

    // 乘法口诀表
    //  int i=0;
    //  int j=0;
    //  for ( i = 1; i <=9; i++) //行 1-9  1 2 3
    //  {
    //      for ( j = 1; j<=i; j++) //列 1-9   1 1*1  2*1 2*2  3*1 3*2 3*3
    //      {
    //      printf("%d*%d=%-2d ",i,j,i*j);//%2d默认是打印两位数字 如果不够两位就自动补齐.%-2d就是两位左对齐
    //      }
    //  printf("\n");
    //  }

    // //挑选出10个数中的最大值
    // int arr[]={-1,-2,-3,-4,-5,-6,-7,-8,-9,-10};
    // int max=arr[0];
    // int i=0;
    // int sz=sizeof(arr)/sizeof(arr[0]);
    // for (i=1;i<sz;i++)//假设第0个位置是我们的最大值,循环这里就可以从1开始走,这样会更好.
    // {
    //     if(arr[i]>max)
    //         max=arr[i];
    // }
    //     printf("最大值是:%d\n",max);

    // return 0;

    // //求1/1-1/2+1/3-1/4...1/100的结果
    // int i=0;
    // double sum=0.0;
    // int flag=1;
    // for (i=1;i<=100;i++)
    // {
    //     sum+=flag*1.0/i;
    //     flag=-flag;
    // }
    //     printf("sum=%lf\n",sum);
    // return 0;
    // 第二种求法
    // int i = 0;
    // int j=0;
    // double num = 0;
    // double sum1 = 0.0;
    // double sum2 = 0.0;
    // for (i = 1; i <= 100; i+=2)
    // {
    //     sum1 += 1.0 / i;
    //     printf("sum1=%lf\n", sum1);
    // }
    // for (j = 2; j <= 100; j+=2)
    // {
    //     sum2 += 1.0 / j;
    //     printf("sum2=%lf\n", sum2);
    // }
    // num=sum1-sum2;
    // printf("num=%lf\n", num);
    // return 0;

    // 数9的个数出现了多少个9 思路:个位为9模上一个10那么就是余9,十位为除模上一个10就是商9;
    // 9 19 29..99 10个   90 91 92 93..99 10个  加起来20个
    // int count = 0;
    // int i = 0;
    // for (i = 1; i <= 100; i++)
    // {
    //     if (i % 10 == 9)
    //     {
    //         count++;
    //     }
    //     if (i / 10 == 9)
    //     {
    //         count++;
    //     }
    // }
    // printf("count=%d\n", count);
    // return 0;

    // // 打印素数 (优化版 利用sqrt数学库函数) 1.试除法
    // int num = 0;
    // int i = 0;
    // int count = 0;
    // for (num = 101; num <= 200; num+=2)//跳过偶数,在奇数里面找素数.(更优化)
    // {
    //     // 判断num是否为质数
    //     for (i = 2; i <= sqrt(num); i++)
    //     {
    //         if (num % i == 0)
    //         {
    //             break;
    //         }
    //     }
    //     // 有两种情况会跳到这来,第一种情况就是i>sqrt(num)就是素数了,第二种情况就是不是素数break.这要区分所以得加个if
    //     if (i > sqrt(num))
    //     {
    //         count++;
    //         printf("素数为:%d\n", num);
    //     }
    // }
    // printf("\ncount=%d\n", count);
    // return 0;

    // // 打印素数
    // int num = 0;
    // int i = 0;
    // int count=0;
    // for (num = 100; num <= 200; num++)
    // {
    //     // 判断num是否为质数
    //     for (i = 2; i < num; i++)
    //     {
    //         if (num % i == 0)
    //         {
    //             break;
    //         }
    //     }
    //     //有两种情况会跳到这来,第一种情况就是i=num就是素数了,第二种情况就是不是素数break.这要区分所以得加个if
    //     if (num==i)
    //     {
    //             count++;
    //             printf("素数为:%d\n", num);
    //     }
    // }
    //             printf("\ncount=%d\n",count);
    //             return 0;

    // 计算闰年
    // int year=1000;
    // int count=0;
    // for (year = 1000; year<=2000; year++)
    // {
    //     if (year%4==0&&year%100!=0)
    //     {
    //         printf("%d\n",year);
    //         count++;
    //     }
    //     else if (year%400==0)
    //     {
    //         printf("%d\n",year);
    //         count++;
    //     }
    // }
    // printf("\ncount=%d\n",count);

    // int year = 1000;
    // int count = 0;
    // for (year = 1000; year <= 2000;year++)
    // {
    //     if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
    //     {
    //         printf("%d\n", year);
    //         count++;
    //     }
    // }
    // printf("\ncount=%d\n", count);

    // //求最大公约数 辗转相除法
    // int m=0;
    // int n=0;
    // int r=0;
    // scanf("%d%d",&m,&n);
    // while (r=m%n)
    // {
    //     m=n;
    //     n=r;
    // }
    // printf("最大公约数是:%d\n",n);

    // int i=0;
    // for(i=1;i<=100;i++)
    // {
    //     if (i%3==0)
    //     {
    //         printf("%d\n",i);
    //     }
    // }

    // int a = 0, b = 0, c = 0;
    // int tmp = 0;
    // scanf("%d%d%d", &a, &b, &c);
    //     //算法实现,a放最大值,b放次大值,c放最小值.
    // if (a < b)
    // {
    //     tmp = a;
    //     a = b;
    //     b=tmp;
    // }
    // if (a < c)
    // {
    //     tmp = a;
    //     a = c;
    //     c = tmp;
    // }
    // if (b<c)
    // {
    //     tmp=b;
    //     b=c;
    //     c=tmp;
    // }
    // printf("%d %d %d\n", a, b, c); // 2 1 3
    // return 0;
}