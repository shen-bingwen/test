#include <stdio.h>
// #define MAX 100
// int main()
// {
//     int i = MAX;
//     printf("哈喽");
//     return 0;
// }
// 翻译环境
// gcc -E test_3_22.c  预处理命令
// gcc -E test_3_22.c > test.i 全部重定向输出到test.i的文件 因为预编译默认会产生一个.i文件
// 在预处理文件中敲大写G会跳到.i文件末尾
// vim test.c 打开文件
// clear清空屏幕
// 预处理(编译)阶段阶段:
// 1.处理#include头文件的包括,把头文件的内容放到.c文件去
// 2.删除注释 使用空格替换我们的注释
// 3.#define 替换  例如上面的MAX在预编译阶段会被替换成int i=100;
//
// 编译阶段:
// gcc -S test.i
// 把C代码翻译成汇编代码,由编译器来完成
// 1.词法分析
// 2.语法分析
// 3.语义分析
// 4.符号汇总
//
// 汇编阶段:
// 把汇编代码(指令)转换成二进制指令
// gcc -c test.s
// 形成符号表
// 例如main 形成main和他的地址 如果在test.c里面函声明外部函数那会给外部函数放一个无意义的地址.

// 链接器阶段
// 1.合并段表 .o文件是有自己固定格式(elf文件格式)的,他会把自己固定分成几个段,只是test.o和add.o的内容不一样
// 在链接期间会把两个.o目标文件链接在一起.对应段上的数据.名字有冲突的用有效的地址.比如main和add函数的地址合并到一块,最终只能生成一个可执行程序elf格式
// 2.符号表的合并和重定位 链接期间合并的符号表,如果add.c文件屏蔽掉找不到就会链接错误
// 最终生成的可执行程序也是elf文件格式

// 运行环境
// 一般通过操作系统来完成

// 预定义符号
// int main()
// {
//     // printf("%s\n",__FILE__);//代码所在的原文件名称
//     // printf("%d\n",__LINE__);//代码所在的行号
//     // printf("%s\n",__DATE__);//年月日
//     // printf("%s\n",__TIME__);//时间
//     // 写日志文件
//     int i = 0;
//     int arr[10] = {0};
//     FILE *pf = fopen("log.txt", "w");
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = i;
//         fprintf(pf, "file:%s line:%d data:%s time:%s i=%d\n",
//                 __FILE__, __LINE__, __DATE__, __TIME__, i);
//         printf("%s\n", __FUNCTION__); // 打印所在函数的名字
//     }
//     fclose(pf);
//     pf = NULL;
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

// int main(){
//     printf("%d\n",__STDC__);//严格遵守c语言标准的编译器则__STDC__的值为1
//     return 0;
// }

// 预处理指令
// #define可以定义各种各样的符号
// #define MAX 100
// #define STR "hehe"
// #define reg register

// #define也可以是一段代码
// #define do_forever for(;;)//死循环

// #define建议末尾不要加分号

// #SQUARE就是我们的宏,是有名字有参数的
// #define SQUARE(X) X*X
// #define SQUARE(X) (X)*(X)
// #define DOUBLE(X) ((X)+(X))
// 所以用语对数值表达式进行求值的宏定义都应该用这种方式加上括号,避免在使用宏时由于参数操作符或领近操作符之间不可预料的相互作用

// #define MAX 100
// #define DOUBLE(X)  ((X)+(X))
// int main()
// {
//     //     // int max=MAX;
//     //     //int max =100;
//     //     // printf("%d\n",max);

//     //     // char ch[]={STR};
//     //     // printf("%s\n",ch);
//     //     // printf("%s\n",STR);

//     //     // reg int a;
//     //     // register int a;

//     //     // do_forever;
//     //     //替换成for(;;);什么都不干,分号不能掉,不然就把return 0;变成循环内容 无法死循环

//     //     //SQUARE(X)的X就替换成5 然后X*X 5传给了x 就是5*5=25
//     //     // int ret=SQUARE(5);
//     //     // printf("%d\n",ret);

//     //     //宏的参数是替换的不是传参数的 5+1当成宏的参数 就会完完整整传过去
//     //     //最终酸楚的结果就是 5+1*5+1=11
//     //     //可以把后面的X带括号就是(5+1)*(5+1)=36
//     //     int ret=SQUARE(5+1);
//     //     printf("%d\n",ret);

//     // int a = 5;
//     // int ret = 10 * DOUBLE(a);
//     // printf("%d\n", ret);

//     //  int a = 5;
//     // int ret = 10 * DOUBLE(MAX+MAX);//调用宏时首先检查是否有被#define定义的值
//     // printf("%d\n", ret);
//     // 宏参数和#define定义中可以出现其他#define定义的变量,但是对于宏,不能出现递归
//    // 当预处理搜索#define定义的符号时候,字符串常量的内容并不被搜索.例如printf("MAX = %d",MAX);前面的MAX不被搜索
//     return 0;
// }

// void print(int a){
//     printf("the value of a is %d\n",a);
// }
// int main(){
//     int a=10;
//     int b=20;
//     // printf("the value of a is %d\n",a);
//     print(a);
//     print(b);

// }

// 多个字符串放在一起的话会天然的连接在一起
//  int main(){
//      printf("hello world\n");
//      printf("hello " "world\n");
//      printf("hel" "lo world\n");
//      return 0;
//  }

// 如何把宏的参数输入到字符串中呢
// 使用#把一个宏参数变成对应的字符串
//  宏和define定义符号的时候都写成大写,约定
// 用双引号隔开保证前面是一串字符串,“the value of" 是一串,#X则是“a”为一串,而 后面的“ is %d\n”是一串
// #X会变成双引号A

// #define PRINT(X) printf("the value of "#X" is %d\n",X)

// int main(){
//     int a=10;
//     int b=20;
//     PRINT(a);
//     //printf("the value of ""a"" is %d\n",a);
//     PRINT(b);
//     //printf("the value of "“b”" is %d\n",b);
// //  宏参数前面的值出现了#是不会把它替换成对应的值而是转换成对应的字符串
//     return 0;
// }

// ##的作用 在预处理的时候位于它两端的符号合成一个符号  也就把两个没有什么作用的符号和在一块变成有用的符号
// #define CAT(X,Y) X##Y
// int main(){
//     int Class84=2025;
//     // printf("%d\n",class84);
//     printf("%d\n",CAT(Class,84));
//    //##会变成   printf("%d\n",CAT(Class##84));
//    //等价于     printf("%d\n",CAT(Class84));
//      return 0;
// }

// 宏参数的副作用可能传进来之后结果不是自己想要的
// 牢记宏的参数是替换进去的,而不是算好后替换进去的
//  #define MAX(X,Y)   ((X)>(Y)?(X):(Y))
//  int main(){
//      int a=10;
//      int b=11;
//      int max=MAX(a++,b++);
//      // int max=((a++)>(b++)?(a++):(b++));
//      printf("%d\n",max);//12
//      printf("%d\n",a);//11
//      printf("%d\n",b);//13
//      return 0;
//  }

// 宏和函数的对比
// 函数
// int Max(int x, int y)
// {
//     return (x > y ? x : y);
// }
// float Max2(float x, float y)
// {
//     return (x > y ? x : y);
// }
// // 宏
// #define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

// int main()
// {
//     int a = 10;
//     int b = 20;
//     float c=3.0f;
//     float d=4.0f;
//     //函数处理不同类型的得写不同类型的函数
//     int max = Max(a,b);
//     printf("%d\n", max);
//     //函数在调用的时候
//     //会有函数调用和返回的开销
//     //
//     float max2 = Max2(c,d);
//     printf("%f\n", max2);

//     //宏优势
//     //宏则不用写各种类型函数,而宏要处理什么类型都无关,都可以实现
//     //宏在预处理阶段就完成了替换,没有调用和返回的开销
//     // max=MAX(c:d);
//     // max=((c)>(d)?(c):(d));
//     //宏劣势
//     //函数调用的时候只调用同一块地方的代码即可,而宏在调用时所有宏的参数都会替换成宏对应的代码,整体代码长度增长
//     //宏没法调试 被替换后和肉眼看到的不一样会看不出错误
//     //宏由于类型无关,不够严谨
//     //宏可能带来运算符优先级的问题,导致程序容易出错 如果传过去的事表达式操作符,和宏体内的操作符优先级不一样可能会错误
//     //函数式计算好结果传进去,副作用对宏有影响,对函数没有影响
//     max=MAX(a,b);
//     printf("%d\n", max);
//     float max3 = MAX(c,d);
//     printf("%f\n", max2);
//     return 0;
// }

// 宏可以传类型,但是函数做不到
//  #define SIZEOF(type) sizeof(type)
//  int main(){
//      int ret=SIZEOF(int);
//      printf("%d\n",ret);
//      return 0;
//  }

// #define MALLOC(num,type) (type*)malloc(num*sizeof(type))
// #include <stdlib.h>
// int main(){
//     int *p=(int*)malloc(10*sizeof(int));
//     printf("%lu\n",sizeof(p));
//     int *p2=MALLOC(10,int);
//     printf("%lu\n",sizeof(p));
//     return 0;
// }

// #undef的使用
// #define MAX 100
// int main(){
//     printf("MAX=%d\n",MAX);
//     // #undef移除一个宏定义
//     // #undef MAX
//     // #undef NAME 如果现存的一个名字需要被重定义,那么它的旧名字要首先被移除
//     // printf("MAX=%d\n",MAX);
// }

// 命令行定义
// cat test.c是把代码显示在命令行
// gcc test.c -D SZ=10  定义SZ 也是在预编译阶段进行替换
//-D就是命令行参数
// 定义完后再./a.out运行即可
//  int main(){
//      int arr[]={0,1,2,3,4,5,6,7,8,9};
//      int i=0;
//      for ( i = 0; i < SZ; i++)
//      {
//          arr[i]=i;
//      }
//      for ( i = 0; i < SZ; i++)
//      {
//          printf("%d\n",arr[i]);
//      }
//  }

// ls -a会多出两个隐藏文件夹 一个是 .  代表当前目录 一个是..代表上级目录
// ls -l显示a.out是按照一行的信息来显示的,而前面的东西都是文件相关属性什么时候创建的拥有者是谁
// ls -al 包含了点和点点两个参数

// 条件编译(选择性编译),
// 1.决定的是代码有没有机会被执行到
// 预处理指令里面有条件编译指令
// #define DEBUG // 这里如果没定义DEBUG.那么下面#ifdef 和 #endif之间的printf就会不打印
// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = 0;
// #ifdef DEBUG    // 如果DEBUG 被定义了就为真,条件就参与编译,没定义就是不参加编译,在预编译就会被删掉,从ifdef到endif这一阶段
//         printf("%d ", arr[i]);
// #endif
//     }
//     return 0;
// }

// int main()
// {
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//     int i = 0;
//     for (i = 0; i < 10; i++)
//     {
//         arr[i] = 0;
// #if  1 //如果条件为 1 真参与编译  为0就不参与编译  也可以是1+1 或者1-1这种常量表达式
// // #if  0 //如果条件为 1 真参与编译  为0就不参与编译
//         printf("%d ", arr[i]);
// #endif  //用于结束#if
//     }
//     return 0;
// }

// 2. 多分支的条件编译指令
//  如果if为真则if参与编译,到elif如果为真参与编译,否则继续往下走else的内容.
//   int main(){
//       #if 1==2
//       printf("haha\n");
//       #elif 2==1
//       printf("hehe\n");
//       #else
//       printf("heihei\n");
//       #endif
//   }

// 3.判断是否被定义的条件编译指令
//  #define DEBUG 0
//  int main(){
//      // #ifdef DEBUG
//      // printf("hehe\n");
//      // #endif
//      // //等价于
//      // #if defined(DEBUG)
//      // printf("haha\n");
//      // #endif

//     //加感叹号就是和上面两种完全对立的
//     //没定义即参与编译 ,定义了则不参与编译
//     // #if  !defined(DEBUG)
//     // printf("hehe\n");
//     // #endif
//     //等价于
//     //if和def中间加个n即not就是没定义参与编译,定义了就会参与编译
//     #ifndef DEBUG
//     printf("hehe\n");
//     #endif
//     return 0;
// }

// 4.嵌套指令
//   #if defined(OS_UNIX)
//       #ifdef OPTION1
//                unix_version_option1();
//       #endif
//       #ifdef OPTION2
//                unix_version_option2();
//       #endif
//   #elif defined(OS_MSDOS)
//       #ifdef OPTION
//               unix_version_option2();
//       #endif
//   #endif

// 引用头文件的两种方式和使用场景
// 引自定义文件.本地文件用双引号引 查找顺序是先去自己的目录下查找,再去库函数着 范围虽然大但是效率会慢,如果明确知道自己目录没有就别用引号
// 库函数文件用尖括号引
// 头文件的包含就是把头文件的内容调用过来

// 用gcc test.c -E >test.i 查看
// 如果重复包含则预处理的时候会有三份,用gcc test.c -E >test.i 查看.
// 有时候不可避免的会让代码引入多次,因为再多人协作的时候互相使用得包含他们各自的头文件
// 可以用三种方法解决避免头文件被多次引用 具体看test.h
//
// #include "test.h"
// #include "test.h"
// #include "test.h"
// int main()
// {
//     int ret = ADD(2, 3);
//     printf("ret=%d\n", ret);
//     return 0;
// }

// 预处理阶段
//  1.条件编译指令
//  2.#include
//  3.#define
// 4.#pragma

// 作业讲解和offset
//  offset 要引的头文件
//  #include <stddef.h>
//  struct S
//  {
//      char c1;
//      int a;
//      char c2;
//  // };
//  struct S
//  {
//      int c1;   // 0-3
//      int a;    // 4-7
//      char c2;  // 8
//      double j; // 9-16  最后偏移量在17的位置上   0-16也是17 然后17不是8的倍数开始内存对其那么就是17-23 偏移量在24的位置上也可以理解成0-23有24位是最大整数的倍数
//  };
//  // 这里就是把0这个地址强制转换成结构体指针类型的来存放结构体的地址,然后这个地址再把它放在括号里面去箭头找到我的成员member_name,假设这里传的是c1那么就是拿c1过去
//  // 取出c1的地址进行强制类型转换int,也就是把起始位置的地址设置成0,然后后面的地址减去该地址即可得到偏移量
//  #define OFFSETOF(struct_name, member_name) (int)&(((struct_name *)0)->member_name)
//  int main()
//  {
//      // 求出各值偏移量所在的值
//      //  printf("%lu\n",offsetof(struct S,c1));//0
//      //  printf("%lu\n",offsetof(struct S,a));//4
//      //  printf("%lu\n",offsetof(struct S,c2));//8
//      //

//     printf("%d\n", OFFSETOF(struct S, c1)); // 0
//     printf("%d\n", OFFSETOF(struct S, a));  // 4
//     printf("%d\n", OFFSETOF(struct S, c2)); // 8
//     printf("%d\n", sizeof(struct S));       // 8

//     return 0;
// }

// 小端模式不影响位域：位域的内存分配是位级操作，与小端存储（字节顺序）无关。
// 关键规则：
// 位域从字节的低位向高位填充。
// 若当前字节剩余空间不足，编译器可能直接分配新字节。
// 因此，printf 的输出反映的是编译器对位域的具体分配策略，而非小端存储的字节顺序。
// #include <string.h>
// // 定义结构体（含位域）
// int main()
// {
//     unsigned char puc[4];
//     struct tagPIM
//     {
//         unsigned char ucPim1;      // 占1字节 8位
//         unsigned char ucData0 : 1; // 占1位
//         unsigned char ucData1 : 2; // 占2位
//         unsigned char ucData2 : 3; // 占3位
//     } *pstPimDate;
//     pstPimDate = (struct tagPIM *)puc;
//     memset(puc, 0, 4);
//     // 赋值操作  8421
//     pstPimDate->ucPim1 = 2;  // 0x02 → puc[0]     0000 0010    02
//     pstPimDate->ucData0 = 3; // 3 → 二进制11（占1位）  1位 0011  截断后剩1
//     pstPimDate->ucData1 = 4; // 4 → 二进制100（占2位）  2位 0100截断后剩 00
//     pstPimDate->ucData2 = 5; // 5 → 二进制101（占3位）  3位  1001 截断后剩 001
//     //0000 0010 PU1=0 2  0010 1001 PU2=2 9   00000000 PU3  00000000 PU4

//     // 输出内存值
//     printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//     return 0;
// }

// 找出单身狗
// 12345123456
// int SingleDog(int *arr, int sz)
// {
//     int i = 0;
//     int result = 0;

//     for (i = 0; i < sz; i++)
//     {
//         result = arr[i] ^ result;
//     }
//     return result;
// }
// int main()
// {
//     int arr[] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 6};
//     int sz = sizeof(arr) / sizeof(arr[0]);
//     int result = SingleDog(arr, sz);
//     printf("%d\n", result);
//     return 0;
// }



#include<stdio.h>
void find_single_dog(int* arr, int sz)//找到两个只出现一次的数字
{
	int i = 0;
	int ret = 0;
	int pos = 0;
	int single_dog[2] = { 0 };//存放找出来的两个单身狗
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];//异或得到的返回值  5^6 011 3
	}

	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)//那么证明两个数的第i+1位不同
		{
			pos = i;//两个单身狗不同的那一位需要偏移的位数  
		}
	}
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			single_dog[1] ^= arr[i];//异或得到一个单身狗
		}
		else
		{
			single_dog[0] ^= arr[i];//异或得到第二个单身狗
		}
	}
	printf("%d %d\n", single_dog[0], single_dog[1]);//打印两个单身狗

}
int main()
{
	int arr[10] = { 1,2,3,4,6,1,2,3,4,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	find_single_dog(arr, sz);
	return 0;
}
