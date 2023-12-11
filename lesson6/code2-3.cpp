#include <iostream>
#include <cmath>
#define PI 3.1415926
using namespace std;

class Shape
{
private:
    /* data */
public:
    double surface = 0.0;
    double volume = 0.0;
    Shape(/* args */){};
    virtual double Surface() = 0;
    virtual double Volume() = 0;
};

class Cube : public Shape
{
private:
    double dege;

public:
    double Surface() { return surface; }
    double Volume() { return volume; }
    Cube operator+(const Cube &r) { return Cube(this->dege + r.dege); };
    void Display()
    {
        cout <<  this->Volume() << endl;
        cout <<  this->Surface() << endl;
    };
    Cube(double a) : dege(a)
    {
        surface = 6 * pow(dege, 2);
        volume = pow(dege, 3);
    };
};

class Sphere : public Shape
{
private:
    double r;

public:
    double Surface() { return surface; }
    double Volume() { return volume; }
    Sphere(double a) : r(a)
    {
        surface = 4 * PI * pow(r, 2);
        volume = 4.0 / 3.0 * PI * pow(r, 3);
    };
};

class Cylinder : public Shape
{
private:
    double height;
    double r;

public:
    double Surface() { return surface; }
    double Volume() { return volume; }
    Cylinder(double a, double b) : height(a), r(b)
    {
        surface = 2 * PI * r * height + 2 * PI * pow(r, 2);
        volume = PI * pow(r, 2) * height;
    };
};

int main()
{
    // Put your instance  and test function of all shape
    Cube cu = Cube(1.5);
    Cube cu_2 = Cube(1.8);
    (cu + cu_2).Display();

    return 0;
}