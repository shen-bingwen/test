#include <stdio.h>
// 创建一个数组实现逆置
// void Init(int arr[], int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         arr[i] = 0;
//     }
// }
// void Print(int arr[], int sz)
// {
//     int i = 0;
//     for (i = 0; i < sz; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }
// // 法1:
// // void Reverse(int arr[], int sz)
// // {
// //     int i = 0;
// //     for (i = sz-1; i >= 0; i--)
// //     {
// //         printf("%d ", arr[i]);
// //     }
// // }
// // 法2:
// void Reverse(int arr[], int sz)
// {
//     int left = 0;
//     int right = sz - 1;
//     while (left < right)
//     {
//         int tmp = arr[left];
//         arr[left] = arr[right];
//         arr[right] = tmp;
//         left++;
//         right--;
//     }
// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int i = 0;
//     // Init(arr, sz);
//     Print(arr, sz);
//     Reverse(arr, sz);
//     Print(arr, sz);
//     return 0;
// }

// 等位交换
//  int main()
//  {
//      int arr1[] = {1, 3, 5, 7, 9};
//      int arr2[] = {2, 4, 6, 8, 10};
//      int sz = sizeof(arr1) / sizeof(arr1[0]);
//      int i = 0;
//      for (i = 0; i < sz; i++)
//      {
//          int tmp = 0;
//          tmp = arr1[i];
//          arr1[i] = arr2[i];
//          arr2[i] = tmp;
//          printf("%d ", arr1[i]);
//      }
//      printf("\n");
//      for (i = 0; i < sz; i++)
//      {
//          printf("%d ", arr2[i]);
//      }
//      printf("\n");
//      return 0;
//  }

// short*一次能访问两个字节,但是int*一个元素4个字节,所以访问了4次就是访问了8个字节两个元素,所以只改变了前两个元素的值
//  int main(){
//      int arr[]={1,2,3,4,5};
//      short *p=(short*)arr;
//      int i=0;
//      for ( i = 0; i < 4; i++)
//      {
//          *(p+i)=0;
//      }
//      for ( i = 0; i < 5; i++)
//      {
//          printf("%d\n",arr[i]);
//      }
//      return 0;
//  }

// sizeof的比较
//  int i;
//  int main(){
//      i--;
//      if (i>sizeof(i))
//      {
//          printf(">\n");//sizeof()计算变量/所占内存的大小 >= 因为所占内存大小不管正负数都是恒大于0的.
//          //sizeof返回值c语言中规定是无符号数,那和有符号数-1比较的时候会先把负一转换成一个无符号数,
//          //而-1在二进制中首位是1,如果不把1看成有符号数,而是转换成无符号数就会变成非常大,1就变成了实际的数值.就比4还要大的多.所以输出>.
//          //-1      10000000000000000000001
//      }
//      else
//      {
//          printf("<\n");
//      }
//      return 0;
//  }

// int main()
// {
//     int a, b, c;
//     a = 5;
//     c = ++a;//6
//     b = ++a,++c, c++,  a++;//等号优先级高于逗号表达式 所以直接把++a赋值给b  b此时则为7,然后根据逗号表达式从左至右执行
//     b += a++ + c;
//     printf("a=%d b=%d c=%d\n",a,b,c);
//     return 0;
// }

// 设计一个函数求a的二进制表示中有几个1
// 方法一:不管正负 把它转换成无符号数,最高位就不是有符号数了,是有效位无符号数
//  int count_bit_one(unsigned int n){
//      int count =0;
//      while (n)
//      {
//         if(n%2==1){
//              count++;
//         }
//         n=n/2;
//      }
//      return count;
//  }
// 方法二:
// int count_bit_one(int n)
// {
//     int count = 0;
//     int i=0;
//     for ( i = 0; i < 32; i++)
//     {
//         if (((n>>i)&1)==1)
//         {
//             count++;
//         }
//     }
//     return count;
// }
// 方法三:最精简且经典
// int count_bit_one(int n)
// {
//     int count = 0;
//     int i = 0;
//     // n=n&(n-1)
//     // n
//     // 13
//     // 1101 n
//     // 1100 n-1
//     // 1100 n
//     // 1011 n-1
//     // 1000 n
//     // 0111 n-1
//     // 0000 n
//     //执行一次去掉一个1,能执行几次就能加加几次,就说明有多少个1
//     while (n)
//     {
//         n=n & (n - 1);
//         count++;
//     }
//     return count;
// }
// // 设计一个函数求a的二进制表示中有几个1
// int main()
// {
//     int a = 0;
//     scanf("%d", &a);
//     int count = count_bit_one(a);
//     //-1
//     // 1000000000000000000000000000000000000001
//     // 1111111111111111111111111111111111111110
//     // 1111111111111111111111111111111111111111
//     // 用按位与的方法去求
//     // 0000000000000000000000000000000000000001
//     printf("count=%d\n", count);
//     return 0;
// }

// 统计二进制位中不同位的个数
// 方法一:取出每位之后对比,不同的话就加加
//  int count_bit_difference(int x,int y){
//      int count=0;
//      int i=0;
//      for ( i = 0; i < 32; i++)
//      {
//          if (((x>>i)&1)!=((y>>i)&1))
//          {
//              count++;
//          }
//      }
//      return count;
//  }
// 方法二:通过异或相同为0相异为1的规则把两个数不同的二进制数求出来,1的个数就是不同的个数,再利用按位与-1的方法求出1的个数
//  int count_bit_difference(int x,int y){
//      int count=0;
//      int tmp=x^y;
//      while(tmp){
//          tmp=tmp&(tmp-1);
//          count++;
//      }
//      return count;
//  }
//  int main()
//  {
//      int a = 0;
//      int b=0;
//      scanf("%d %d", &a,&b);
//      int count = count_bit_difference(a,b);
//     //1101 13
//     //0011 3
//      printf("count=%d\n", count);
//      return 0;
//  }

// 打印一个二进制的奇数位和偶数位打印出来
// 10
// 00000000000000000000000000001010
// void get_jiou(int n)
// {
//     int i = 0;
//     printf("打印奇数\n");
//     //这里for循环从大到小的原因是要从头左边开始打印不是从尾部打印,所以应该从大到小
//     for (i = 30; i>=0; i -= 2)
//     {
//         printf("%d", (n >> i) & 1);
//     }
//     printf("\n");
//     printf("打印偶数\n");
//     for (i = 31; i>=1; i-= 2)
//     {
//         printf("%d", (n >> i) & 1);
//     }
//     printf("\n");
// }
// int main()
// {
//     int a = 0;
//     scanf("%d", &a);
//     get_jiou(a);
//     // printf("count=%d\n", count);
//     return 0;
// }

// 使用指针打印数组内容
//  void print(int* p,int sz){
//      int i=0;
//      for ( i = 0; i < sz; i++)
//      {
//          printf("%d\n",*(p+i));
//      }
//  }
//  int main(){
//      int arr[]={1,2,3,4,5,6,7,8,9,10};
//      int sz=sizeof(arr)/sizeof(arr[0]);
//      print(arr,sz);
//      return 0;
//  }

// 函数作业
// 递归,当Fun(2)时,函数输出多少
// 首先2*fun(2+1) 继续递归 2*2*(3+1) 继续2*2*2*fun(4+1) 此时fun(4+1)为fun5 retune2 所以就是2*2*2*2=16
// int Fun(int n)
// {
//     if (n == 5)
//         return 2;
//     else
//     {
//         return 2 * Fun(n + 1);
//     }
// }
// int main(){
//     printf("%d\n",Fun(2));
// }

// 实现一个函数,打印乘法口诀表,口诀表的行数和列数自己指定
//  如:输入9,输出9*9口诀表,输出12,输出12*12的乘法口诀表
//  void   print_table(int n){
//      int i=0;
//      int j=0;
//      //行
//      for ( i = 1; i <=n; i++)
//      {
//          //列
//          for ( j=1;j<=i;j++)
//          {
//              printf("%d*%d=%-2d ",i,j,i*j);
//          }
//          printf("\n");
//      }
//  }
//  int main(){
//      int n=0;
//      scanf("%d",&n);
//      print_table(n);
//      return 0;
//  }

// 递归函数，用于打印整数的每一位
// void printDigits(int n) {
//     if (n < 10) {
//         // 如果n是一位数，直接打印
//         printf("%d\n", n);
//     } else {
//         // 递归调用，先打印前面的数字
//         printDigits(n / 10);
//         // 打印最后一位数字
//         printf("%d\n", n % 10);
//     }
// }
// int main() {
//     int number;
//     // 输入一个整数
//     printf("请输入一个整数: ");
//     scanf("%d", &number);
//     // 调用递归函数打印每一位
//     printDigits(number);
//     return 0;
// }

// 逆置字符串内容而不是逆序打印
// 法一:使用了strlen的库函数
//  #include<string.h>
//  void reverse_string(char* arr){
//      int left=0;
//      int right=strlen(arr)-1;
//      int tmp=0;
//      while (left<right)
//      {
//          tmp=arr[left];
//          arr[left]=arr[right];
//          arr[right]=tmp;
//          left++;
//          right--;
//      }
//  }
// 法二:计数器配合while循环的方法去实现
// int my_strlen(char *str)
// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
//  void reverse_string(char* arr){
//      int left=0;
//      int right=my_strlen(arr)-1;
//      int tmp=0;
//      while (left<right)
//      {
//          tmp=arr[left];
//          arr[left]=arr[right];
//          arr[right]=tmp;
//          left++;
//          right--;
//      }
//  }
// 法三:递归的方法去解决(不如前两个简单理解,只是为了培养递归写代码的能力),值得反复研究
// int my_strlen(char *str)
// {
//     int count = 0;
//     while (*str != '\0')
//     {
//         count++;
//         str++;
//     }
//     return count;
// }
// void reverse_string(char *arr)
// {
//     char tmp = 0;
//     tmp = arr[0];
//     int len = my_strlen(arr);
//     arr[0] = arr[len - 1];
//     arr[len - 1] = '\0';
//     if (my_strlen(arr+1) >= 2)
//     {
//         reverse_string(arr + 1);
//     }
//     arr[len-1]=tmp;
// }
// int main()
// {
//     char arr[] = "abcdef"; // fedcba
//     reverse_string(arr);
//     printf("%s\n", arr);
//     return 0;
// }

// 输入一个非负整数,计算这个数的每位之和 例如1729输出1+7+2+9=19
// int DigitSum(unsigned int n)
// {
//     if (n > 9)
//     {
//         return DigitSum(n / 10) + n % 10;
//     }
//     else
//     {
//         return n;
//     }
// }
// int main()
// {
//     unsigned int input = 0;
//     printf("请输入一个数:>");
//     scanf("%d", &input);
//     int ret = DigitSum(input);
//     printf("ret=%d\n", ret);
//     return 0;
// }

// 递归实现n的k次方 n^k=n*(k-1)
// double Pow(int n, int k)
// {
//     if (k < 0)
//     {   
//         // return n*pow(n,1/k);
//         return (1.0/(Pow(n,-k)));//这个妙,这里输入负数进来后把k再参数置换成负数的,负负得正,就可以继续往正的递归操作上走了,并且在前面加个1.0/
//     }
//     else if (k>0)
//     {
//         return n*Pow(n,k-1);
       
//     }
//     else
//     {
//         return 1.0;
//     }
// }
// int main()
// {
//     int n = 0;
//     int k = 0;
//     printf("请输入两个个数:>");
//     scanf("%d%d", &n,&k);
//     double ret = Pow(n, k);
//     printf("n=%lf\n", ret); 
//     return 0;
// }