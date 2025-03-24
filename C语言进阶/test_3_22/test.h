// 如果第一次引头文件没有定义过就往下走定义然后endif
// 如果第二次引的话定义过了就直接跳出条件为假就不参与编译了,相当于不会被包含在代码里面去了

// 第一种写法 古老写法 把.改成了_
//  #ifndef __TEST_H__
//  #define __TEST_H__
//  #include <stdio.h>
//  int ADD(int x,int y){
//  return x+y;
//  }
//  #endif

// 第二种写法
//  #if !defined(__TEST_H__)
//  #define __TEST_H__
//  #include <stdio.h>
//  int ADD(int x,int y){
//  return x+y;
//  }
//  #endif

// 第三种写法 现代写法 在老编译器可能编不过去
#pragma once
int ADD(int x, int y)
{
    return x + y;
}
