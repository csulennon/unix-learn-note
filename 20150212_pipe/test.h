#ifndef TEST_H_
#define TEST_H_
// 告诉编译器这两个函数是用C语言写的,否则使用
// g++ 方设编译的时候会报错
#ifdef __cplusplus
extern "C" {
#endif

int max(int a, int b);
int add(int a, int b);

#ifdef __cplusplus
}
#endif

#endif
