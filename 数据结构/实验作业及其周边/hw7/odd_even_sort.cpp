# include<iostream>
using namespace std;
#define len 20

int main()
{
    int sort[len];
    int cur;
    for (int i = 0; i < len; i++)
    {
        if (rand()%2 == 1)
            cur = -rand();
        else cur = rand();
        sort[i] = cur;
    }
    int l=0,h=len-1;
    int temp;
    //思路是简单的双指针,请在40行打个断点查看结果作为output
    while (l <= h)
    {
        if (sort[l]>0&&sort[h]<0)
        {
            temp = sort[l];
            sort[l] = sort[h];
            sort[h] = temp;
            l++;
            h--;
        }
        else if(sort[l]>0&&sort[h]>0)
            h--;
        
        else if(sort[l]<0&&sort[h]<0)
            l++;
        else if(sort[l]<0&&sort[h]>0)
        {
            l++;
            h--;
        } 
    }
    ;
    return 0;
}