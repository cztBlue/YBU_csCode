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
        cout << "Volume of cube: " << this->Volume() << endl;
        cout << "Surface of cube: " << this->Surface() << endl;
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
    // 初始化
    double par[] = {2.5, 3.4, 2.5, 2.5, 3.4};
    Cylinder cy = Cylinder(par[0], par[1]);
    Cube cu = Cube(par[2]);
    Cube cu_2 = Cube(par[3]);
    Sphere sp = Sphere(par[4]);
    cout << "初始参数:"
         << "圆柱:(" << par[0] << "," << par[1] << ")"
         << " "
         << "方体1:(" << par[2] << ")"
         << " "
         << "方体2:(" << par[3] << ")"
         << " "
         << "球体:(" << par[4] << ")" << endl;

    //
    cout << "圆柱体积:" << cy.Volume() << endl;
    cout << "圆柱表面积:" << cy.Surface() << endl;
    cout << "方体1体积:" << cu.Volume() << endl;
    cout << "方体1表面积:" << cu.Surface() << endl;
    cout << "球体体积:" << sp.Volume() << endl;
    cout << "球体表面积:" << sp.Surface() << endl;

    cout << endl
         << "重载运算符与display测试(方体1+方体2):" << endl;
    (cu + cu_2).Display();

    return 0;
}