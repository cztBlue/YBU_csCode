#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    double PaperThickness = 0.002;
    double QomolangmaHeight = 8848;
    //bool stop = false;

    for(int i = 0; PaperThickness < QomolangmaHeight ;i++)
    {
        PaperThickness *= 2;
        if(PaperThickness > QomolangmaHeight)
        {
            //stop = true;
            cout<<"至少折叠 "<<i<<" 次后厚度开始超过珠峰"<<endl;
        }
    }

}