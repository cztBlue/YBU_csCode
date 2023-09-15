#include <iostream>
#include <string>

using namespace std;

void pointer_swap(int* vp1,int* vp2)
{  
    int temp = *vp1;
    *vp1 = *vp2;
    *vp2 = temp;
}  

void refer_swap(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main ()
{
    //留了一手,没做泛型
    //这里只以int类为例子
    int i = 39;
    int j = 20;
    
    //Test for swap1
    pointer_swap(&i,&j);
    cout<<i<<" "<<j<<endl;
    refer_swap(i,j);
    cout<<i<<" "<<j<<endl;
 
    return 0;
}