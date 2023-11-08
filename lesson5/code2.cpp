#include <iostream>
using namespace std;

class automobile
{
private:
    /* data */
public:
    string gearbox;
    string brake;
    string wheel;
    string engine;
    string steering;
    automobile(/* args */){};
    void run(){};
    void stop(){};
    void start(){};
};

class Car : public automobile
{
private:
    /* data */
public:
    Car(/* args */){};
    void Car_PC(){};
    void ATO(){};
};

class Truck : public automobile
{
private:
    /* data */
public:
    Truck(/* args */){};
    void unloading(){};
    void cargo(){};
};

int main()
{
    return 0;
}