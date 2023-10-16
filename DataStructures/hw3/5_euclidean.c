#include <stdio.h>
//3.3.2_5 ,欧几里得改迭代

int fun(int m, int n)
{
    int r;
    do
    {
        r = m % n;
        m = n;
        n = r;
    } while (r != 0);
    return m;
}

int main()
{
    int m,n;
    m = 27;
    n = 6;
    printf("作业3.3.2\n");
    printf("%d和%d的最大公约数是%d",m,n,fun(m,n));
    return 0;
}