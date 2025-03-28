#include <stdio.h>
#include <string.h>
#include <errno.h>

// int main(){
//     int a=10000;
//     //指向一个名为 FILE 的结构体
//     FILE* pf=fopen("text.tex","wb");//fopen以文本文件打开的,wb则是以二进制的方式写  write binary
//     fwrite(&a,4,1,pf);//二进制的形式写到文件中,fwrite表示写文件,来自a地址处,写一个4个字节的文件,写一个这样的数据,放到pf维护的文件里面去
//     fclose(pf);//写进去后关闭这个文件
//     pf=NULL;
//     return 0;
// }

// 输入流（Input Stream）：从文件读取数据的通道（如从硬盘读入内存）。
// 输出流（Output Stream）：向文件写入数据的通道（如从内存写入硬盘）。
// 文件输出流,字符输入函数 从文件输出
//  int main()
//  {
//      FILE *pfWrite= fopen("test.txt", "w");
//      if (pfWrite==NULL)//说明打开文件失败
//      {
//          return 0;
//          printf("%s\n",strerror(errno));
//      }
//      //写文件 第一个字符是要写入的,第二值是要赋予的地方
//      fputc('b',pfWrite);
//      fputc('i',pfWrite);
//      fputc('t',pfWrite);
//      fclose(pfWrite);
//      pfWrite=NULL;
//      return 0;
//  }

// 文件输入流 从文件中输入 字符输入函数
//  int main()
//  {
// fopen第一个值可以给绝对路径也可以给相对路径
//      FILE *pfRead= fopen("test.txt", "r");
//      if (pfRead==NULL)//说明打开文件失败
//      {
//          return 0;
//          printf("%s\n",strerror(errno));
//      }
//      //写文件 第一个字符是要写入的,第二值是要赋予的地方
//      printf("%c",fgetc(pfRead));//b
//      printf("%c",fgetc(pfRead));//i
//      printf("%c",fgetc(pfRead));//t
//      //关闭文件
//      fclose(pfRead);
//      pfRead=NULL;
//      return 0;
//  }

// 从键盘输入
// 输出到屏蔽
// 键盘&屏幕都是外部设备
//
// 键盘-标准输入设备--stdin 可以通过fgetc键盘输入
// 屏幕-标准输出设备--stdout 通过fputc屏幕输出
// 是一个程序默认打开的两个流设备
//
// stdin FILE*
// stdout FILE*
// stderr FILE*

// fgetc和fputc适用于所有流
// int main()
// {
//     int ch = fgetc(stdin); // 从键盘读输出到屏幕上
//     fputc(ch, stdout);
//     return 0;
// }

//
// int main()
// {
//     FILE *pf = fopen("text.txt", "w");
//     if (pf==NULL)
//     {
//         printf("%s\n",strerror(errno));;
//     }
//     //写文件 fputc put把信息输出出去,放到文件里面
//     fputc('b',pf);
//     fputc('i',pf);
//     fputc('t',pf);
//     //关闭文件
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// int main()
// {
//     FILE *pf = fopen("text.txt", "r");
//     if (pf==NULL)
//     {
//         printf("%s\n",strerror(errno));;
//     }
//     //读文件,从文件指针流里读 返回读的值的ASCII码值,用int接受
//     int ch=fgetc(pf);
//     printf("%c",ch);
//     ch=fgetc(pf);
//     printf("%c",ch);
//     ch=fgetc(pf);
//     printf("%c",ch);

//     //关闭文件
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// 文本行的输入和输出
//  fgets函数
//  int main()
//  {
//      char buf[1024] = {0};
//      FILE *pf = fopen("text.txt", "r");
//      if (pf == NULL)
//      {
//          printf("%s\n", strerror(errno));
//      }
//      // 第一个值:数据的存储位置,第二个值:n是最多读取多少个字符,第三个是从哪个流里读取
//      // 读文件
//      fgets(buf, 1024, pf);//buf里面的换行
//      // printf("%s",buf); //这里打印的buf里面本身就拥有一个换行(bit不是最后一行),所以可以不加\n,因为读取的时候最后加换行才能到下一行去
//      puts(buf);//puts天生把信息打印出来会换行
//      fgets(buf, 1024, pf);
//      puts(buf);
//      // printf("%s\n",buf);//hello就没有斜杠n,因为hello下面没有东西可读了就不换行了
//      fclose(pf);
//      pf=NULL;
//      return 0;
//  }
// fputs
//  int main()
//  {
//      char buf[1024] = {0};
//      FILE *pf = fopen("text.txt", "w");
//      if (pf == NULL)
//      {
//          printf("%s\n", strerror(errno));
//      }
//      //写文件 这里得自己手动换行
//      fputs("hello\n",pf);
//      fputs("world\n",pf);
//      // printf("")
//      fclose(pf);
//      pf = NULL;
//      return 0;
//  }

// int  main(){
//     //从键盘读取一行文本信息
//     char buf[1024]={0};
//     // fgets(buf,1024,stdin);//从标准输入读取
//     // fputs(buf,stdout);//输出到标准输出流
//     //等价于
//     // gets(buf);
//     // puts(buf);
//     return 0;
// }

// 格式化输入输出函数
// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s={100,3.14f,"bit"};
//     FILE* pf=fopen("text.txt","w");
//     if(pf==NULL){
//         return 0;
//     }
//     //格式化的形式写文件
//     fprintf(pf,"%d %f %s",s.n,s.score,s.arr);
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// // 格式化输入输出函数
// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s={0};
//     FILE* pf=fopen("text.txt","r");
//     if(pf==NULL){
//         return 0;
//     }
//     //格式化的形式输入数据
//     fscanf(pf,"%d %f %s",&(s.n),&(s.score),s.arr);
//     printf("%d %f %s",s.n,s.score,s.arr);
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// // fscanf和fprintf
// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };
// int main()
// {
//     struct S s={0};
//     //从标准输入流输出流输入输出
//     fscanf(stdin,"%d %f %s",&(s.n),&(s.score),s.arr);
//     fprintf(stdout,"%d %.2f %s",s.n,s.score,s.arr);
//     return 0;
// }

// sscanf,是从字符串中读取格式化的数据.
// sprintf,是把格式化的数据输出成(存储到)字符串
// struct S
// {
//     int n;
//     float score;
//     char arr[10];
// };

// int main()
// {
//     struct S s = {100, 3.14f, "abcdef"};
//     struct S tmp={0};
//     char buf[1024] = {0};
//     //把格式化的数据转换成字符串存储到buf
//     sprintf(buf, "%d %f %s", s.n, s.score, s.arr);
//     // printf("%s\n", buf);
//     //从buf中读取格式化的数据到tmp中
//     sscanf(buf,"%d %f %s",&(tmp.n),&(tmp.score),tmp.arr);
//     printf("%d %f %s\n",tmp.n,tmp.score,tmp.arr);
//     return 0;
// }

// 二进制的形式读写
//  struct S{
//      char name[20];
//      int age;
//      double score;
//  };
//  int main(){
//      // struct S s={"张三",20,55.6};
//      struct S tmp={0};
//      // FILE* pf=fopen("text.txt","wb");
//      FILE* pf=fopen("text.txt","rb");
//      if (pf==NULL)
//      {
//          printf("%s\n",strerror(errno));
//          return 0;
//      }
//      //写文件 从内存写到磁盘上文件,以二进制形式 第一个值是要写入参数值的地址,第二个参数是写入类型的大小,第三个是写入的个数,第4个值是从写入哪里
//      // fwrite(&s,sizeof(struct S),1,pf);
//      fread(&tmp,sizeof(struct S),1,pf);
//      printf("%s %d %lf\n",tmp.name,tmp.age,tmp.score);
//      //关闭文件
//      fclose(pf);
//      pf=NULL;
//      return 0;
//  }

// fseek
// int main()
// {
//     FILE *pf = fopen("text.txt", "rb");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 1.定位文件指针
//     fseek(pf, -2, SEEK_END);
//     // fseek(pf, 2, SEEK_SET); //从起始位置读
//     // fseek(pf, 4, SEEK_CUR);//从当前位置读
//     // 2.读取文件
//     int ch = fgetc(pf);
//     printf("%c\n", ch);

//     fclose(pf);
//     pf = NULL;
// }

// int main()
// {
//     FILE *pf = fopen("text.txt", "rb");
//     if (pf == NULL)
//     {
//         return 0;
//     }
//     // 1.定位文件指针
//     // fseek(pf, -2, SEEK_END);

//     int ch=fgetc(pf);
//     ch=fgetc(pf);
//     printf("%c\n",ch);

//     //ftell文件指针相当于起始位置的偏移量,返回类型是int
//     fgetc(pf);//假设去pf里面读相当于文件指针向后偏移了一个
//     // int pos=ftell(pf);
//     // printf("%d\n",pos); 

//     //rewind让文件指针回到起始位置
//     rewind(pf);
//     ch=fgetc(pf);
//     printf("%c\n",ch);

//     fclose(pf);
//     pf = NULL;
// }


//文件结束判定
//feof不是用feof返回值直接用来判断文件的是否结束
//而是应当文件读取结束的时候,判断读取失败结束,还是遇到文件末尾结束
//fgetc返回的是EOF说明结束, fgets判断返回值是否为NULL 
// int main(){
//     // feof();//EOF- end of file -文件结束标志
//     FILE* pf=fopen("text.txt","r");
//     if (pf==NULL)
//     {
//         return 0;
//     }
//     int ch=fgetc(pf);
//     printf("%d\n",ch);//-1

//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// int main(){
//     //strerror- 把错误码对应的错误信息的字符串地址返回
//     //printf("%s\n",strerror(errno));

//     //perrror
//     FILE* pf=fopen("text2.txt","r");//该文件不存在
//     if (pf==NULL)
//     {
//         //更加直观一些perror比strerror更加简便,不需要引头文件,而且perror括号让代码的定制化更强一点
//         perror("open file text2.txt");
//         return 0;
//     }
//     //读文件
    
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }

// int main(){

//     FILE* pf=fopen("text.txt","r");
//     if (pf==NULL)
//     {
//         perror("open file text.txt");
//         return 0;
//     }
//     //读文件
//     int ch=0;
//     while ((ch=fgetc(pf))!=EOF)
//     {
//        putchar(ch);//打印abcdef
//     }
//     if (ferror(pf))//遇到错误结束会返回一个非0值为真,然后打印错误
//     {
//         printf("error\n");
//     }
//     else if (feof(pf))
//     {
//         printf("end of file\n");//遇到了文件结束正常停止
//     }
    
//     fclose(pf);
//     pf=NULL;
//     return 0;
// }


// 作业讲解
// typedef struct{
//     int a;//0-3  此时偏移位置在4上 
//     char b;//4  4是char类型的倍数1偏移刚好放进去 此时偏移位置在5
//     //5
//     short c;//5不是short的偏移量 浪费掉到6 刚好放进去  2  8 最大为8最小为2 偏移2 6、7 此时偏移位置在8上
//     //8是short的倍数
//     short d; //8-9 2
//     //10-11浪费掉
// }AA_t;
typedef struct{
    double a;//0-7  8  8 
    short b;//8-9  2 8
    //10
    short c;//10-11
    int d; //12 -15 
    //16
   
}AA_t;
//占10个字节
int main(){
    printf("%lu\n",sizeof(AA_t));
    return 0;
}