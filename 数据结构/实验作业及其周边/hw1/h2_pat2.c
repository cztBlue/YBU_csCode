#include <stdio.h>
#define N 100000

int f(int n, int a[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int cursum = 0;
        for (int j = i; j  < n; j++) {
            cursum += a[j];
            if(cursum > max) max = cursum;
        }
    }
    return max;
}

int main()
{
    int a[N];
    int i,n;

    scanf("%d",&n);  
    for( int i =0; i<n; i++) {
        scanf("%d",&a[i]); 
    }
    
    printf("%d", f(n, a));
    return 0;
}