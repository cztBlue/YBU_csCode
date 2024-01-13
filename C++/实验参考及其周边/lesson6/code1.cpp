#include <iostream>
using namespace std;

class Base
{
public:
    virtual void whoami() { cout << "类名是:"
                                 << "Base" << endl; }
};

class Derived1 : public Base
{
private:
    /* data */
public:
    Derived1(/* args */){};
    void whoami() { cout << "类名是:"
                         << "Derived1" << endl; }
};

class Derived2 : public Base
{
private:
    /* data */
public:
    Derived2(/* args */){};
    void whoami() { cout << "类名是:"
                         << "Derived2" << endl; }
};

int main()
{
    //(1)
    cout<<"问题一(测试derived1,derived2的whoami()):"<<endl;
    Derived1 d1 = Derived1();
    Derived2 d2 = Derived2();
    d1.whoami();
    d2.whoami();

    //(2)
    Base *pBase1 = new Derived1();
    Base *pBase2 = new Derived2();
    Base *pBase = new Base;

    cout<<endl<<"问题二:"<<endl;
    cout<<"pBase1指针访问whoami():";
    pBase1->whoami();
    cout<<"pBase2指针访问whoami():";
    pBase2->whoami();
    cout<<"pBase指针访问whoami():";
    pBase->whoami();

    //(3)
    cout<<endl<<"问题三:"<<endl;
    cout<<"pBase1指针访问Base::whoami():";
    pBase1->Base::whoami();

    return 0;
}