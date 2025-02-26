#include <stdio.h>
// 数据的存储

// 数值一样但是在内存里存储的不一样
//  int main(){
//      int a=10;
//      float f=10.0;
//  }

// int main(){

//     return 0;
// }

// 空类型 通常用于函数的返回类型、函数参数、指针类型
// 想明确指定没有参数就指定一个void,表示这个函数无参,就会在调用的时候报
//  void test(void){
//      printf("hehe\n");
//  }
//  int main(){
//      test(100);
//      return 0;
//  }

int main()
{
    int a = 10;
    int b = 20;
    int *p=&a;
    return 0;
}
