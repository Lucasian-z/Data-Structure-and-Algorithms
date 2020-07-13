#include <stdio.h>
#include <stdarg.h>

/*variadic函数，即自变量数量可变的函数
va_list(va_list argptr, lastparam): 初始化argptr自变量指针
va_arg(va_list argptr, type): 获取argptr所引用的可选性自变量，也会将argptr前移到下一个自变量
va_end(va_list argptr): 不再需要自变量指针时，必须调用va_end宏
va_copy
author: zhanghao
email: zhangh2548@outlook.com
date:2020/07/08/ 23:04:22
*/


double add(int n,  ...) {
    int i = 0;
    double sum = 0.0;
    va_list argptr;
    va_start(argptr, n);//初始化argptr
    for (i = 0; i < n; ++i) {//遍历每个可选性自变量
        sum += va_arg(argptr, double);//读取类型为double的自变量
    }
    va_end(argptr);
    return sum;
}

int main()
{
    printf("%.2f\n", add(3, 3.3, 4.5, 6.6));
    return 0;
}