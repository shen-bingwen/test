#include <stdio.h>
// #include <string.h>
// #include <unistd.h>
// #include <stdlib.h>

int main()
{
//     // char password[20] = "12345";
//     // int i = 0;
//     // for ( i = 0; i < 3; i++)
//     // {
//     // {
//     //     printf("请输入密码:>");
//     //     scanf("%s", password);
//     //     if (strcmp(password,"12345")==0)//等号不能用来比较两个字符串是否相等!!!,应该使用一个库函数-strcmp
//     //     {
//     //         printf("登陆成功\n");
//     //         break;
//     //     }
//     //     else
//     //     {
//     //         printf("登陆失败\n");
//     //     }
//     // }
//     // }
//     char password[20] = "12345";
//     int i = 0;
//     char k[10]={0};
//     // for ( i = 0; i < 3; i++)
//     while (i<3)
//     {
//     {
//         printf("请输入密码:>");
//         scanf("%s", k);
//         if (strcmp(password,k)==0)//等号不能用来比较两个字符串是否相等!!!,应该使用一个库函数-strcmp
//         {
//             printf("登陆成功\n");
//             break;
//         }
//         else
//         {
//             printf("登陆失败\n");
//         }
//         i++;
//     }
//     }
//     if (i==3)
//     {
//     printf("你已连错3次,程序锁定\n");
//     }
    

    //{'W','E','L','C'};
    // {'#','#','#','#'};
    // char arr[] = "welcome to bit!!!!!!";
    // char arr2[] = "####################";
    // int sz = sizeof(arr) / sizeof(arr[0]);
    // int yz = sizeof(arr2) / sizeof(arr2[0]);
    // int right = yz - 1; //右下标
    // int right2 = yz- 1; //右下标
    // int left = 0;  // 左下标
    // int left2 = 0; // 左下标
    // 或者这样命名右下标省区sz和yz两部分,但是得减2 因为字符数组默认最后是以多一个斜杠0结尾的.所以得比整形数组再多减一个,因为整形数组虽然是从0开始但是没有默认的斜杠0结束.
    // int right=sizeof(arr)/sizeof(arr[0])-2;
    // int right2=sizeof(arr2)/sizeof(arr2[0])-2;
    // 再或者这样,利用strlen函数求字符数组元素个数,此函数求出个数,不包括斜杠0,而数组下标从0开始,减1就可以了
    // int right=strlen(arr)-1;
    // int right2=strlen(arr2)-1;
    // while (left<=right)//值得推敲 说明中间有元素可以被查找
    // {
    //     arr2[left]=arr[left];
    //     left++;
    //     arr2[right]=arr[right];
    //     right--;
    //     printf("%s\n",arr2);
    //     sleep(1);
    //     system("clear");//执行系统命令的一个函数
    // }
    //     printf("%s\n",arr2);
    // if (left>right)
    //     {
    //         printf("打印完毕\n");
    //     }
    // return 0;

    // // 折半查找办法/二分查找算法 算法复杂度是log2n  值得推敲
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int sz = sizeof(arr) / sizeof(arr[0]);
    // int left = 0;//左下标
    // int right = sz - 1; //右下标
    // int k = 7;
    // while (left<=right)//值得推敲 说明中间有元素可以被查找
    // {
    //     int mid = (left + right) / 2;   //值得推敲 进行二分查找的时候每次都得根据左右下标求出中间元素的下标,拿中间元素的下标跟我们的元素进行比较.
    //     if (arr[mid] < k) //值得推敲
    //     {
    //         left = mid++;
    //     }
    //     else if (arr[mid] >k)//值得推敲
    //     {
    //         right = mid--;
    //     }
    //     else
    //     {
    //         printf("找到了,下标是:%d\n", mid);
    //         break;//值得推敲
    //     }
    //     if (left>right) //有找得到和找不到两种情况都会来到这,如果不加这个条件判断就会在上一步的执行语句执行完后打印完找到了,又打印找不到.
    //     {
    //         printf("找不到\n");
    //     }

    // }
    // return 0;

    // 顺序查找法
    //  int arr[]={1,2,3,4,5,6,7,8,9,10};
    //  int i=0;
    //  int k=15;
    //  int sz=sizeof(arr)/sizeof(arr[0]);//计算数组元素个数 数组总长度除以单个字符所占长度 40/4=10
    //  for (i=0;i<sz;i++)
    //  {
    //      if (k==arr[i])
    //      {
    //          printf("找到了\n");
    //          break;//找到了就不用再往后走了
    //      }
    //  }
    //   if (i==sz)
    //  {
    //      printf("没找到\n");
    //  }
    //  return 0;

    // int i=0;
    // int sum=0;
    // int Q=0;
    // for ( i = 0; i < 10; i++)
    // {
    //     sum+=1;
    // }
    // Q=sum+2;
    // printf("%d\n",Q);

    //计算某个数阶乘的和. 例如3的阶乘  1的阶乘加2的阶乘加3的阶乘 1 2 6=9
    // int i = 0;
    // int n = 0;
    // int ret = 1;
    // int sum=0;
    // for (n = 1; n <= 3; n++)//计算所有数的阶乘,控制各个数的阶乘
    // {
    //     ret=1; //每求一次ret都得重新置为1.. 想求出几个数的阶乘的时候ret就得重新置为1  例如3 1*1  1*2 1*2*3
    //     for (i = 1; i <= n; i++)
    //     {
    //         ret = ret * i;
    //     }
    //     sum=sum+ret;
    // }
    // printf("sum=%d\n", sum);
    // return 0;

    // //计算1-10的阶乘之和
    //     int i = 0;
    //     int n = 0;
    //     int ret = 1;
    //     int sum=0;
    //     for (n = 1; n<=10; n++)
    //     {
    //         ret = ret*n;
    //          sum=sum+ret;
    //     }

    //     printf("sum=%d\n", sum);
    //     return 0;

    //计算n的阶乘
    //  int i = 0;
    //  int n = 0;
    //  int ret = 1;
    //  scanf("%d",&n);
    //  for (i = 1; i<=n; i++)
    //  {
    //      ret = ret*i;
    //  }
    //  printf("ret=%d\n", ret);

    // return 0;

    //     char password[20]={0};
    //     printf("请输入密码:>");
    //     scanf("%s",password);
    //     int ch=0;
    //     while ((ch=getchar())!='\n')//只要不是\n就一直获取,直到到尾部跳出.
    //     {
    //         ;
    //     }
    //    // getchar(); 把单个“\n”带走
    //     printf("请确认(Y/N):>");
    //     char ret=0;
    //     scanf("%c",&ret);
    //     if (ret=='Y')
    //     {
    //         printf("确认正确\n");
    //     }
    //     else
    //     {
    //         printf("确认错误\n");
    //     }

    // int ch = 0;
    // while ((ch = getchar())!= EOF)
    // {
    //     if (ch < '0' || ch > '9')//只打印数字 ch<48 huo ch >57跳出循环 ASCII码值‘0’-‘9’十进制是代表所有阿拉伯数字
    //     continue;
    //     putchar(ch);
    // }
    // return 0;
    // int a = 0;
    // for (a = 1; a <= 10; a++)
    // {
    //     if (a==5)
    //     continue;
    //     printf("%d\n", a);
    // }
    // return 0;

    //     int a = 0;
    //     for (a = 1; a <= 10; a++)
    //     {
    //         if (a=5) //在for循环体内修改变量会使得for循环失去控制
    //         printf("呵呵\n");
    //         printf("哈哈\n");
    //     }
    //     return 0;

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int i = 0;
    // for (i = 0; i < 10; i++) // 建议for循环语句控制变量采用前闭后开区间形式,可以代表一种10次循环10次打印10个元素 一般不采用a<=9
    // {
    //     printf("%d\n", arr[i]);
    // }
    // return 0;

    // int i = 0;
    // for (;;) // 三个变量可以省略 ,判断省略恒为正.
    // {
    //     printf("呵呵呵\n");
    // }
    // return 0;

    // int i = 0;
    // for (i = 0; i < 10; i++) // 三个变量可以省略 ,判断省略恒为正.
    // {
    //     int j = 0;
    //     for (j = 0; j < 10; j++) // 三个变量可以省略 ,判断省略恒为正.
    //     {
    //         printf("呵呵呵\n");
    //     }
    // }
    // return 0;

    // int i = 0;
    // int j = 0;
    // for (i = 0; i < 10; i++)
    // {
    //     for (; j < 10; j++)//省略了后当j走到10不会销毁 当i从0++为1的时候j还是保持10.
    //     {
    //         printf("呵呵\n");
    //     }
    // }
    // return 0;

    // int x,y;
    // for (x=0,y=0;x<2&&y<5;++x,y++)
    // {
    //         printf("呵呵\n");
    // }
    // return 0;

    // int i=0;
    // int j=0;
    // for (i = 0,j=0; j=0; i++,j++) //j=0是赋值语句,不是判断语句,0为假,1为真就是死循环.当改成0的时候不进行循环
    // {
    //     printf("你好\n");
    // }

    // int i = 1;
    // do
    // {
    //     if (i==5)
    //     break;
    //     printf("%d\n",i);
    //     i++;
    // } while (i<=10);

    // return 0;
}
