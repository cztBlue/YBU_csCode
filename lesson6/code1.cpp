#include <iostream>
using namespace std;

class Base
{
public:
    virtual void whoami() { cout << "Base" << endl; }
};

class Derived1 : public Base
{
private:
    /* data */
public:
    Derived1(/* args */){};
    void whoami() { cout<< "Derived1" << endl; }
};

class Derived2 : public Base
{
private:
    /* data */
public:
    Derived2(/* args */){};
    void whoami() { cout<< "Derived2" << endl; }
};

int main()
{
    //(1)
    Derived1 d1 = Derived1();
    Derived2 d2 = Derived2();
    d1.whoami();
    d2.whoami();

    //(2)
    Base *pBase1 = new Derived1();
    Base *pBase2 = new Derived2();
    Base *pBase = new Base;

    pBase1->whoami();
    pBase2->whoami();
    pBase->whoami();

    //(3)
    pBase1->Base::whoami();

    return 0;
}