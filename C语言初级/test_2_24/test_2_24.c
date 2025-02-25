#include <stdio.h>

// c语言调试技巧

// 不用strcmp函数,用自己写的my_strcmp函数进行拷贝字符
//  1.第一版(可优化:)
//  void my_strcmp(char* dest,char* src){
//     while (*src!='\0')
//     {
//      *dest=*src;
//      src++;
//      dest++;
//     }
//     *dest=*src;//'\0'也赋过去
//  }
//  第二版(可优化:)
//  void my_strcmp(char* dest,char* src){
//     while (*src!='\0')
//     {
//      *dest++=*src++;//后置++就是说明先解引用使用了再加加,比第一版省略了两句
//     }
//     *dest=*src;
//  }
// 第三版(还可优化)
//  void my_strcmp(char* dest,char* src){
//     while (*dest++=*src++)//后置++就是说明先解引用使用了再加加,把src指向的字符串拷贝到dest的空间,包含‘\0'字符
//     //而且这里巧妙的运用到了'\0'的ASCII码值就是0来作为while循环判断结束的条件,先把斜杠0赋给了*dest,此时*dest为0循环为假跳出
//     {
//         ;
//     }
//  }
// int main()
// {
//     char arr1[] = "#######";
//     char arr2[] = "bit";
//     my_strcmp(arr1, arr2);
//     printf("%s\n", arr1);
// }
// 第四版(可优化)
//  void my_strcmp(char* dest,char* src){
//     //当传进来的是一个空值时,则是野指针.会崩溃,所以得判断是否为空,但是也只是规避了问题,并没有解决问题
//     if (dest!=NULL&&src!=NULL)
//     {
//         while (*dest++=*src++)//
//         {
//             ;
//         }
//     }
//  }
//  int main()
// {
//     char arr1[] = "#######";
//     char arr2[] = "bit";
//     my_strcmp(arr1, NULL);
//     printf("%s\n", arr1);
// }

// 第五版(引入assert语句,还可以优化)
//  #include<assert.h>
//  void my_strcmp(char* dest,char* src){
//          assert(dest!=NULL);//断言函数,如果表达式为真,那么就往下执行,如果表达式为假传空指针那么就报错
//          assert(src!=NULL);
//          while (*dest++=*src++)
//          {
//              ;
//          }
//   }
//  //第六版(加const常变量,即复制源不被改变,这样哪怕while循环语句出错了可以及时发现),还可以优化
//  #include<assert.h>
//  void my_strcmp(char* dest,const char* src){
//          assert(dest!=NULL);//断言函数,如果表达式为真,那么就往下执行,如果表达式为假传空指针那么就报错
//          assert(src!=NULL);
//          while (*dest++=*src++)
//          {
//              ;
//          }
//   }
//   int main()
//  {
//      char arr1[] = "#######";
//      char arr2[] = "bit";
//      my_strcmp(arr1, arr2);
//      printf("%s\n", arr1);
//  }


//const常量的使用
// int main()
// {
//     const int num = 10;
//     const int * p = &num;
//     // const 放在指针变量的*左边时,修饰的是*p,也就是说:不能通过p来改变*p(num)的值
//     // const 放在指针变量的*右边时.修饰的时指针变量指针变量p本身,p不能被改变了

//     *p = 20; // err
//     int n = 100;//假如设置的是 int* const p就不能改地址,取决于const的位置
//     p = &n;
//     return 0;
// }
   

// 第七版(加返回值,使得返回值就是另一个函数的参数,也称为链式访问)
//  #include<assert.h>
//  char* my_strcmp(char* dest,const char* src){
//          //再开始先把地址存起来,后面dest往后走了也是返回起始地址,而不是终点地址
//          char* ret=dest;
//          assert(dest!=NULL);//断言函数,如果表达式为真,那么就往下执行,如果表达式为假传空指针那么就报错
//          assert(src!=NULL);
//          while (*dest++=*src++)
//          {
//              ;
//          }
//          return ret;
//   }
//   int main()
//  {
//      char arr1[] = "#######";
//      char arr2[] = "bit";
//      printf("%s\n", my_strcmp(arr1, arr2));
//  }

// 模拟实现strlen函数
 #include<assert.h>
 int my_strlen(const char* str){
     assert(str!=NULL);
     int count=0;
     while (*str!='\0')
     {
         count++;
         str++;
     }
     return count;

}
int main(){
    char arr[]="abcdef";
    int len=my_strlen(arr);
    printf("%d\n",len);
    return 0;
}