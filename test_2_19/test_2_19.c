#include <stdio.h>

// int main()
// {
// 移位操作符只能用于整形,基本都是算数移位
// int a = 3;
// int b = a >> 1;//011 > 001
// printf("%d\n", b);
// return 0;

// int a = 3;
// int b = a << 1;//0011 > 0110
// printf("%d\n", b);
// return 0;

// 右移除2
//  int a = 16;
//  int b = a >> 1;//00010000>00001000
//  printf("%d\n", b);
//  return 0;

// 左移乘2
//  int a = 5;
//  int b = a << 1;//0101>1010
//  printf("%d\n", b);
//  return 0;

// 位操作符只能用于整形 按位与(全1为1否则为0)
// int a = 3;
// int b = 5;
// int c = a & b; //011   101 -->001
// printf("%d\n", c);
// return 0;
// 按位或(全0为0,否则为1)
//  int a = 3;
//  int b = 5;
//  int c = a |b; //011   101 -->111
//  printf("%d\n", c);
//  return 0;
// 按位异或(相同为0,相异为1)
//  int a = 3;
//  int b = 5;
//  int c = a^b; //011   101 -->110
//  printf("%d\n", c);
//  return 0;

// 不创建第三个变量,交换两个变量
// int a=3;
// int b=5;
// 加减法,有缺陷,如果整形a和b很大但是没超过最大值,但是相加超过了就会丢失某些二进制位(溢出),就可能出错.
// a=a+b;//8
// b=a-b;//3
// printf("%d\n",b);
// a=a-b;//5
// printf("%d\n",a);
// return 0;

// 异或的方法 (相同为0 相异为1),a和b异或产生密码,再与原来的b异或翻译出来b,a此时还是密码再与原来的b异或能翻译出来原来的a
// 不创建第三个变量,交换两个变量,面试考但不推荐,还是推荐临时变量.代码可读性差.
//  int a=3;
//  int b=5;
//  a=a^b;  //011   101  ---> 110 6
//  b=a^b; //110  101 ---->011  3
//  a=a^b;//110 011 --->101  5
//  printf("%d\n",b);
//  printf("%d\n",a);
//  return 0;

// 统计num的补码中有几个1
// 编写代码求一个整数存储在内存中的二进制中1的个数.
// 方法二:
// int num = 0;
// scanf("%d", &num); // 3 011  3%2=1 3/2=1 01 1%2=1 1/2=0 break
// int count = 0;
// 32bit
// 当num&1==1,那么最低位肯定是个1,与运算全1为1,运算完后右移一位继续算
// 00000000000000000000000000000011
// 00000000000000000000000000000001
// 00000000000000000000000000000001
// int i = 0;
// for (i = 0; i < 32; i++)
// {
//     if (1 == ((num >> i)&1))
//     {
//         count++;
//     }
// }
// printf("%d\n", count);
// return 0;

// 方法一:统计num的补码中有几个1
// while (num)
// {
//     if (num % 2 == 1)//但是如果是负一代码就有问题了.-1%2=-1不等于1就无法进去了
//     {
//         count++;
//         num = num / 2;
//     }
// }
// printf("%d\n",count);
// return 0;

// 方法三:最优
// int num=0;
// scanf("%d", &num);
// int count = 0;
// while(num){
//     count++;
//     num=num&(num-1);
// }
// printf("%d\n",count);

// 赋值操作符
//  int a=10;
//  int x=0;
//  int y=20;
// 连续赋值
//   a=x=y+1;
//  printf("%d\n",a);
// 复合赋值符
//  a=a>>1;
//  printf("%d\n",a);
//  a>>=1;
//  printf("%d\n",a);

// 双目操作符 +  a+b符号两边有两个操作数
//  单目操作符只有一个数
//  int a=10;
//  printf("%d\n",!a);
//  int a=0;
//  printf("%d\n",!a);

// int a=0;
// if(!a){
//     printf("呵呵\n");
// }
// if(a){
//     printf("呵呵\n");
// }

// 负号
// int a=-5;
// a=-a;
// printf("%d\n",a);
// return 0;

// int a=10;
// int* p=&a;//取地址操作符
// p=&a;
// printf("%p\n",p);
// *p=20;//解引用操作符
// printf("%d\n",a);
// return 0;

// int a=10;
// char c='r';
// char* p=&c;
// int arr[10]={0};
// //sizeof 计算的是变量所占内存空间的大小,单位是字节,sizeof后面是类型的时候不能省略括号
// printf("%lu\n",sizeof(a));//4
// printf("%lu\n",sizeof(int));//4
// printf("%lu\n",sizeof(c));//1
// printf("%lu\n",sizeof(char));//1
// printf("%lu\n",sizeof(p));//4\8看平台32还是64位
// printf("%lu\n",sizeof(char*));//4\8看平台32还是64位
// printf("%lu\n",sizeof(arr));//数组的大小是10个元素,每个元素是一个整形,一个整形4个字节,10个整形40个字节
// printf("%lu\n",sizeof(int[10]));//对于数组来说,去掉变量名就是数组的类型
// return 0;

// short s = 0;
// int a = 10;
// printf("%lu\n", sizeof(s = a + 5));
// printf("%d\n", s);//sizeof操作符的表达式是不会真实去运算的,也就是说a+5只是个摆设.
// return 0;

//~波浪号是按(2进制)位取反
// 00000000000000000000000000000000  取反后得到补码
// 11111111111111111111111111111111-补码
// 11111111111111111111111111111110-反码
// 10000000000000000000000000000001-原码
// int a=0;
// printf("%d\n",~a);

// int a = 11;
// a = a | (1 << 2);
// printf("%d\n", a);
// a=a&(~(1<<2));
// printf("%d\n", a);
// 000000000000000000000000000001011;
// 000000000000000000000000000000100;
// 000000000000000000000000000001111;
// 1<<2
// 再把第三位二进制1改回去
// 000000000000000000000000000001111;
// 111111111111111111111111111111011;
// 000000000000000000000000000000100;
// 000000000000000000000000000001011;

// 强制类型转换
//   int a=(int)3.14;
//   return 0;

//

// }

// 数组进行传参默认传的是数组元素首地址接受用指针变量,指针变量在32位是4字节 64位是8
//  void test1(int arr[])
//  {
//      printf("%lu\n", sizeof(arr[]));
//  }
//  void test2(char ch[])
//  {
//      printf("%lu\n", sizeof(ch));
//  }
//  int main(){
//      int arr[10] = {0};
//      char ch[10] = {0};
//      printf("%lu\n", sizeof(arr));
//      printf("%lu\n", sizeof(ch));
//      test1(arr);
//      test2(ch);
//      return 0;
//  }

// int main()
// {
// 逻辑操作符 判断真假
//  &&逻辑与 一个为假即为假,全1才为真
//  int a=0;
//  int b=5;
//  int c=a&&b;
//  printf("%d\n",c);
//  return  0;
// ||逻辑或 一个为真即为真,全0才为假
// int a=0;
// int b=1;
// int c=a||b;
// printf("%d\n",c);
// return  0;

// 全为真即为真,所以都执行,输出2335
//  int i=0,a=1,b=2,c=3,d=4;
//  i=a++&&++b&&d++;
//  printf(" a=%d\n b=%d\n c=%d\n d=%d\n",a,b,c,d);

// 有一个为假即全部为假,后面的也不算了,但是a用完后要加加 输出1234
// int i=0,a=0,b=2,c=3,d=4;
// i=a++&&++b&&d++;
// printf(" a=%d\n b=%d\n c=%d\n d=%d\n",a,b,c,d);

// 有一个为真即为真,到a++就就不再算后面的了 //输出2234
//  int i=0,a=1,b=2,c=3,d=4;
//  i=a++||++b||d++;
//  printf(" a=%d\n b=%d\n c=%d\n d=%d\n",a,b,c,d);
// 前面两个为真那么都执行,后面的和d++也为真就执行一个就行了所以d++不执行.有一个为真即为真,不再算后面的了 //输出2334
//  int i=0,a=1,b=2,c=3,d=4;
//  i=a++&&++b||d++;
//  printf(" a=%d\n b=%d\n c=%d\n d=%d\n",a,b,c,d);

// 输出1235 因为a++&&++b为假不执行,到了d++为真d++执行,如果d++之前为真则只执行前半部分
//  int i=0,a=0,b=2,c=3,d=4;
//  i=a++&&++b||d++;
//  printf(" a=%d\n b=%d\n c=%d\n d=%d\n",a,b,c,d);

// 条件操作符
// 三目操作符
// int a=0;
// int b=0;
// b=(a>5?3:-3);
// printf("%d\n",b);
// return 0;

// int a=10;
// int b=20;
// int max=0;
// max=(a>b?a:b);
// printf("%d\n",max);

//  逗号表达式 从左至右
// int a=1;
// int b=2;
// int c=(a>b,a=b+10,a,b=a+1l);
// printf("%d\n",c);

// 代码2逗号表达式.看最后是否为真,也就是d>0部分.
//  if(a=b+1,c=a/2,d>0)
// }

// struct Stu //类似盖房子的图纸
// {
// 成员变量
// char name[20];
// int age;
// char id[20];
// };
// 学生 结构体
// int float二struct也是类型
// 创建一个结构体类型-struct Stu
// int main(){
// int a=10;
// 使用struct Stu创建了一个学生对象s1并初始化
// struct Stu s1={"张三",20,"20200348"};//类似图纸
// 点操作符用于访问成员   结构体变量.成员名
// printf("%s\n",s1.name);
// printf("%d\n",s1.age);
// printf("%s\n",s1.id);

// struct Stu* ps=&s1;
// 结构体指针->成员名
// printf("%s\n",ps->name);//指针指向对象的值
// printf("%d\n",ps->age);
// printf("%s\n",ps->id);

// printf("%s\n",(*ps).name);
// printf("%d\n",(*ps).age);
// printf("%s\n",(*ps).id);
// }

// int main()
// {
// // 整形提升,在计算过程中,当一些操作数达不到整形大小,我们会进行整形提升,变成整形大小再进行计算.
// char a = 3;
// // 00000000000000000000000000000011
// // 00000011 - a
// char b = 127;
// // 00000000000000000000000001111111
// // 01111111-b

// // a和b如何相加,整形提升按照高位符号位(第一位)来提升,第一位是0就都是补0
// // 00000011 - a
// // 01111111-b
// // 00000000000000000000000000000011
// // 00000000000000000000000001111111
// // 00000000000000000000000010000010
// // 放到c里面去要一样要截断 10000010
// // 打印成%d整形,又要进行整形提升,高位为1就补1
// // 11111111111111111111111110000010--补码
// // 11111111111111111111111110000001--反码
// // 1000000000000 0000000000001111110--源码
// // 得到-126
// char c = a + b;
// printf("%d\n", c);
// return 0;

// 实例1:
// char a=0xb6;
// short b=0xb600;
// int c=0xb6000000;
// //a和b都不够32个字节,要打印出来都得整形提升,那么数值会发生变化就不相等了.而c就是整形了.就不用整形提升
// if(a==0xb6)
// printf("a\n");
// if(b==0xb600)
// printf("b\n");
// if (c==0xb6000000)
// {
//     printf("c\n");
// }
// return 0;

// char c=1;
// printf("%lu\n",sizeof(c));//1
// printf("%lu\n",sizeof(+c));//4  +c这里发生了整形运算就是4个字节
// printf("%lu\n",sizeof(!c));//4

// 算术转换
// float f=3.14;
// int num=f;//隐式转换,会有精度丢失
// printf("%d\n",num);

// 操作符的优先级和结合性以及是否控制求值顺序例如逻辑与逻辑或和条件操作符、逗号表达式
//  int a=10;
//  int b=20;
//  int c=a+b+3;
//  printf("%d\n",c);

// 这种表达式会错误在不同平台结果不一样 华而不实.不能确定唯一路径
//  int i=1;
//  int a=(++i)+(++i)+(++i);
//  printf("a=%d\n",a);

// }
