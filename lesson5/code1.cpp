#include <iostream>
using namespace std;

class Base
{
private:
    int x, y;

protected:
    int z;

public:
    int k;
    Base(int a, int b, int c, int d) : x(a), y(b), z(c), k(d) {}
    int getx();
    int gety();
};

class Derived : public Base
{
private:
    int m;

protected:
    int n;

public:
    int q;
    Derived(int a, int b, int c, int d, int e, int f, int g)
        : Base(a, b, c, d), m(e), n(f), q(g) {}
    int getm();
    int getn();
    int getz();
    int gety_();
    int getx_();
};

int Derived::getm()
{
    return m;
}

int Derived::getn()
{
    return n;
}

int Derived::getz()
{
    return z;
}

int Base::getx()
{
    return x;
}

int Base::gety()
{
    return y;
}

//问题二，不能
//请添加一下代码
// int Derived::getx_()
// {
//     return getx();
// }

// int Derived::gety_()
// {
//     return gety();
// }

int main()
{
    //Base base(1,2,3,4);
    Derived derived(1,2,3,4,5,6,7);
    cout<<derived.getx()<<" "<<derived.gety()<<" "<<derived.getz()<<" "<<derived.getm()<<" "<<derived.getn()<<endl;
    //问题二，不能
    //请将getx(),gety()改为getx_(),gety_()

    Derived derived_(4, 5, 3, 1, 3, 6, 8);
    Base * pBase = &derived_;

    //问题三，不能
    //cout<<pBase->q<<endl;

    


    return 0;
}