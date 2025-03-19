#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// 动态内存分配
//  int main(){
//      //向内存申请10个整形的空间,malloc类型默认是void* 所以要把整形的地址存起来先强制类型转换再存到整形指针里面
//      int *p=(int*)malloc(10*sizeof(int));
//      if (p==NULL)
//      {
//          //打印错误原因的一个方式
//          printf("%s\n",strerror(errno));
//      }
//      else
//      {
//          //正常使用空间
//          int i=0;
//          for ( i = 0; i < 10; i++)
//          {
//              *(p+i)=i;
//          }
//          for ( i = 0; i < 10; i++)
//          {
//              printf("%d ",*(p+i));
//          }
//      }
//      //当动态申请的空间不再使用的时候
//      //就应该还给我们的操作系统
//      free(p);//malloc和free成对使用,谁开辟谁释放
//      p=NULL;//虽然指向的空间被释放了,但是p依然有能力找到这块空间,如果要断开联系赋值个空指针.

//     return 0;
// }

// calloc函数
//  int main(){
//      //malloc(10*sizeof(int));
//      int* p=(int*)calloc(10,sizeof(int));//和malloc参数有区别,并且空间内容每一个元素自动初始化为0,与malloc的区别在于calloc会在返回地址之前把申请的空间每个字节初始化为0,而malloc是随机值
//      if(p==NULL){
//          printf("%s\n",strerror(errno));
//      }
//      else
//      {
//          int i=0;
//          for ( i = 0; i < 10; i++)
//          {
//              printf("%d ",*(p+i));
//          }
//      }
//      //释放空间
//      //free函数是用来释放动态开辟的空间的
//      free(p);
//      p=NULL;
//      return 0;
//  }

// realloc函数可以调整动态内存开辟的大小
// int main()
// {
//     int *p = (int *)malloc(20);
//     if (p == NULL)
//     {
//         printf("%s\n", strerror(errno));
//     }
//     else
//     {
//         int i = 0;
//         for (i = 0; i < 5; i++)
//         {
//             *(p + i) = i;
//         }
//         // 只是在使用malloc开辟的20个字节的空间
//         // 假设这里,20个字节不能满足我们的使用要求了
//         // 希望我们能够有40个字节的空间
//         // 这里就可以使用realloc来调整动态开辟的内存
//     }
//     // 第一个参数是要调整的值的地址,第二个是新的大小,单位是字节.默认的类型也是void*
//     //
//     // realloc使用的注意事项:
//     // relloc函数在使用的时候有两种情况.
//     // 1. 第一种是刚刚malloc动态开辟空间的后面有足够多的空间给你追加,返回旧的地址p回去.
//     // 2.第二种就是p指向的空间没有足够的空间让你追加的话会一次性给你开辟一个新的空间.满足你对新的大小的要求
//     // 同时,把原有数据的内容拿下来放到我们新开辟的空间上,这些数据不能丢,让你感觉只是在后面追加了,把数据拷下来后原来的空间就会free掉,就没用了
//     // 拷贝的地址就不再是malloc原来的地址,而是新的地址,并把原来的数据内容拷贝到新的空间上
//     // 3.万一第一种情况追加失败了返回了一个NULL指针,那么原来的地址就会失效,找不到了,所以这里得设置一个指针来接收,做一个处理得用一个新的变量来接收realloc函数的返回值
//     int *ptr = realloc(p, 4000);
//     if (ptr != NULL)
//     {
//         // 追加成功进入
//         p = ptr;
//         int i = 0;
//         for (i = 5; i < 10; i++)
//         {
//             *(p + i) = i;
//         }
//         for (i = 0; i < 10; i++)
//         {
//             printf("%d ", *(p + i));
//         }
//     }
//     // 释放内存,如果返回的是新地址,那么realloc函数会把旧地址释放掉.然后释放一下新地址就行了
//     free(p);
//     p = NULL;

//     // 补充:
//     // int*p=realloc(NULL,40);//与realloc如果第一个地放给空指针那么他的功能跟malloc是一样的
//     return 0;
// }

// 常见错误修改:法1:改GetMemory的函数参数为二级指针
// void GetMemory(char** p){
//     *p=(char*)malloc(100);
// }
// void test(){
//     char* str=NULL;
//     GetMemory(&str);
//     strcpy(str,"hello bit");
//     // printf(str);
//     printf("%s\n",str);
// }
// int main(){
//     test();
//     return 0;
// }
// 法二:把分配完的地址p返回给str
// char* GetMemory(char* p){
//     p=(char*)malloc(100);
//     return p;
// }
// void test(){
//     char* str=NULL;
//     str=GetMemory(str);
//     strcpy(str,"hello bit");
//     // printf(str);
//     printf("%s\n",str);
// }
// int main(){
//     test();
//     return 0;
// }

// 经典的错误:返回栈空间内存的区别
// char *GetMemory(void)
//{
//	char p[] = "hello world";//这里是局部变量,栈区上开辟的,出了函数就销毁了,接下来的值是什么就不清楚了
//	return p;
//}
//
// void Test(void)
//{
//	char *str = NULL;
//	str = GetMemory();虽然把地址返回来了但是返回来的就是随机值了
//	printf(str);
//}
//
// int main()
//{
//	Test();
//	return 0;
//}
//

// int* test()
//{
//	//static int a = 10;//但在静态区没问题,因为静态区会延长局部变量的生命周期,出了不销毁内存空间还在就可以找到这块空间了
//	int a = 10;//栈区 ,万一有人把a的地址接受一下那就出问题了非法访问内存
//	return &a;
// }
//
// int main()
//{
//	int*p = test();
//	*p = 20;//
//	return 0;
// }

// int* test()
//{
//	int *ptr = malloc(100);//堆区也没问题 只要不free这个空间一直在,虽然ptr销毁了但是再被销毁之前把地址交给了p
//	return ptr;
// }
// int main()
//{
//	int *p = test();
//
//	return 0;
// }

// 柔性数组
//特点1: 柔性数组成员前面必须至少一个成员
//特点2: sizeof返回的结构大小不包含柔性数组的内存
//特点3: 包含柔性数组的成员的结构用malloc()函数进行内存的动态分配,并且分配的内存应该大于结构的大小,以适应柔性数组的预期大小.
// struct S
// {
//     int n;
//     int arr[]; // 未知大小的-柔性数组成员-数组的大小是可以调整的
// };
// // struct S
// // {
// //     int n;
// //     int arr[0];//未知大小的-柔性数组成员-数组的大小是可以调整的
// // };
// int main()
// {
//     // struct  S s;
//     // printf("%lu ",sizeof(s));//4  这时候还没算柔性数组字节大小,下面开创了才有

//     struct S *ps = (struct S *)malloc(sizeof(struct S) + 5 * sizeof(int));
//     // printf("%lu ",sizeof(ps));
//     ps->n = 100;
//     printf("%d \n", ps->n);
//     int i = 0;
//     for (i = 0; i < 5; i++)
//     {
//         ps->arr[i] = i;
//         printf("%d ", ps->arr[i]);
//     } 
//     printf("\n");
//     struct S *ptr = realloc(ps , 44);
//     if (ptr != NULL)
//     {
//         ps = ptr;
//     }
//     for ( i = 5; i < 10; i++)
//     {
//         ps->arr[i]=i;
//     }
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d ", ps->arr[i]);
//     }
//     return 0;
// }

// 第二种方法,动态开辟的空间可以用指针来维护,所以创建了个结构体有n有一个arr指针
// struct S
// {
//     int n;
//     int *arr;
// };
// int main()
// {
//     struct S *ps = (struct S *)malloc(sizeof(struct S));
//     ps->arr = malloc(5 * sizeof(int));

//     int i = 0;
//     for (i = 0; i < 5; i++)
//     {
//         ps->arr[i] = i;
//     }
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", ps->arr[i]);
//     }
//     printf("\n");
//     int *ptr = realloc(ps->arr, 10 * sizeof(int));
//     if(ptr!=NULL){
//         ps->arr=ptr;
//     }
//     for ( i = 5; i < 10; i++)
//     {
//         ps->arr[i]=i;
//     }
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d  ",ps->arr[i]);
//     }
//     free(ps->arr);
//     ps->arr=NULL;
//     free(ps);
//     ps=NULL;
// }


// struct S
// {
//     int n;
//     int *arr;
// };
// int main()
// {
//     struct S* s;//这种就是在栈上开辟的空间,而上面的是两次malloc堆区开辟的空间
//     s->arr = malloc(5 * sizeof(int)); 
//     int i = 0;
//     for (i = 0; i < 5; i++)
//     {
//         s->arr[i] = i;
//     }
//     for (i = 0; i < 5; i++)
//     {
//         printf("%d ", s->arr[i]);
//     }
//     printf("\n");
//     int *ptr = realloc(s->arr, 10 * sizeof(int));
//     if(ptr!=NULL){
//         s->arr=ptr;
//     }
//     for ( i = 5; i < 10; i++)
//     {
//         s->arr[i]=i;
//     }
//     for ( i = 0; i < 10; i++)
//     {
//         printf("%d  ",s->arr[i]);
//     }
//     free(s->arr);
//     s->arr=NULL;
// }