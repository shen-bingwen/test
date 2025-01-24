#include <stdio.h>

// void print(int n){
//     if (n>9)
//     {
//         print(n/10);//1234/10  123/10 12/10  1<9就不除以10了执行下面模10的操作 层层把大的数剥开
//     }
//     printf("%d\n",n%10);// 1<9 printf 1%10 回到上一层递归 12%10 出2  再回到上一层递归printf123%100出3,再回到上一层printf 1234%10 出4

// }
// int main()
// {
//     //接受一个整型值(无符号)，按照顺序打印它的每一位。 例如:输入:1234，输出1234.
//     unsigned int num =1234;
//     print(num);
//     return 0;
// }

// 要求不创建临时变量,实现获取字符串长度
//  int my_strlen(char* str){
//      if (*str!=0)
//      {
//          return 1+my_strlen(str+1);//1+1+1+0 (不断递归)
//      }
//      else
//          return 0;
//  }
//  int main()
//  {
//      char arr[]="bit";
//      //模拟实现一个strlen函数
//      int len=my_strlen(arr);//arr是数组,数组传参,传过去的不是整个数组,而是第一个元素的地址.
//      printf("len=%d\n",len);
//      return 0;
//  }

// 求n的阶乘
//  利用循环
//  int FAC2(int n){
//      int i=0;
//      int ret=1;
//      for ( i = 1; i <=n; i++)
//      {
//          ret*=i;
//      }
//      return ret;
//  }
//  //  利用递归
//  int FAC1(int n){
//      if (n<=1)
//      {
//          return 1;
//      }
//      else
//      {
//          return n*FAC1(n-1);
//      }
//  }
//  int main(){
//      int n=0;
//      int ret=0;
//      scanf("%d",&n);
//      ret=FAC1(n);
//      printf("%d\n",ret);
//      return 0;
//  }

// 求第n个斐波那契数  斐波那契数列(前两个数之和等于第三个数) 1 1 2 3 5 8 13 21 34 55...
// 这样效率太慢
// int count = 0;
// int Fib(int n)
// {
//     if (n == 3) // 测试第3个斐波那契数的计算次数
//     {
//         count++;
//     }

//     if (n <= 2)
//     {
//         return 1;
//     }
//     else
//         return Fib(n - 1) + Fib(n - 2);
// }
// 这样一层一层往下剥的话2的n次方
// 50
// 49 48
// 48 47 47 46
// 47 46 46 45 46 45 45 44
// 46 45 45 44 45 44 44 43 45 44 44 43 44 43 43 42

// int Fib(int n)
// {
//     int a = 1;
//     int b = 1;
//     int c = 1;
//     while (n > 2) // 1 1 2 3 5 8 13 21 34 55...
//     //例如求第4个斐波那契数,n=4
//     {
//         c = a + b; //a+b=2 c=a+b=1+2=3
//         a = b;//a=b=1   a=2
//         b = c;//b=c=2    b=c=3
//         n--;//n--=3>2 n--=2跳出循环
//     }
//     return c;
// }

// 每一段代码都先把主函数写出来,怎么用写出来 思路:TDD-测试驱动开发  先写怎么用再写怎么开发
// int main()
// {
//     int n = 0;
//     int ret = 0;
//     scanf("%d", &n);
//     ret = Fib(n);
//     printf("ret=%d\n", ret);
//     printf("count=%d\n", count);
//     return 0;
// }

// 汉诺塔问题
// 起始位置  中转位置 目标位置
// void hanoi(int n, char source, char auxiliary, char destination)
// {
//     if (n == 1)
//     {
//         printf("Move disk  %d from %c to %c\n", n, source, destination);
//     }
//     else
//     {
//         // 将n-1个圆盘从源柱子移动到辅助柱子,B柱是中转变量.
//         hanoi(n - 1, source, destination, auxiliary);
//         // 将第n个圆盘从源柱子移动到目标柱子
//         printf("Move disk  %d from %c to %c\n", n, source, destination);
//         //// 将n-1个圆盘从此时的起始柱子(B)辅助柱子(A)移动到目标柱子(C)
//         hanoi(n - 1, auxiliary, source, destination);
//     }
// }
// int main()
// {
//     int n = 0;
//     printf("请输入飞盘数量:>");
//     scanf("%d", &n);
//     hanoi(n, 'A', 'B', 'C');
//     return 0;
// }

// 青蛙跳台阶 动态规划:用上一步的结果来快速推算得到下一步的结果(斐波那契数列)
// 递归的话到50太久了
// int jump(int n)
// {
//     if (n == 1)
//     {
//         return 1;
//     }
//     else if (n == 2)
//     {
//         return 2;
//     }
//     else
//     {
//         return jump(n - 1) + jump(n - 2);
//     }
// }
// 使用循环解决青蛙跳台阶效率就会高 
// int jump(int n)
// {
//     int a = 1;
//     int b = 2;
//     int c = 0;
//     if (n == 1)
//     {
//         return a;
//     }
//     else if (n == 2)
//         return b;

//     while (n > 2)
//     {
//         c = a + b;
//         a = b;
//         b = c;
//         n--;
//     }
//     return c;
// }
// int main()
// {
//     int n = 0;
//     printf("请输入青蛙需要跳的台阶数>:");
//     scanf("%d", &n);
//     int ret = jump(n);
//     printf("ret=%d\n", ret);
// }