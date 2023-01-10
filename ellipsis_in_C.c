#include <stdio.h>
#include <stdarg.h>

int average(int count, ...){
    va_list list;
    va_start(list, count);

    float sum = 0;
    for (int i = 0; i < count; i++)
    {
        int value = va_arg(list,int);
        sum += value;
    }
    va_end(list);
    return sum/(float)count;
}

int main(void)
{
    int result = average(5,26,36,44,56,74);
    int printResult = printf("average : %d",result);
    printf("\n%d",printResult);

    int a,b,c,d;
    int scanfResult = scanf("%d %d %d %d",&a,&b,&c,&d);
    printf("%d",scanfResult);
    
    return 0;
}