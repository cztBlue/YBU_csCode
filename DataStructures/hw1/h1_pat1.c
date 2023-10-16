#include <stdio.h>
#include <math.h>

#define MAXN 10

double f( int n, double a[], double x );

int main()
{
    int n, i;
    double a[MAXN], x;

    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;
    n = 3;
    x=2.9;
    printf("%lf",f(n,a,x));

    return 0;
}

double f( int n, double a[], double x )
{
    double res = 0.0;
    for(int i = 0;i <= n;i++) {
        res += a[i]*pow(x,i);
    }
    return res;
}
