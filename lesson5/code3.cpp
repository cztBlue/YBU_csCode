#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
public:
    double x;
    double y;
    Point(double a, double b) : x(a), y(b){};
    double calDistance(Point a, Point b) { return pow(pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0), 0.5); };
};

// x,y表示矩形左上角点坐标
class Rectangle : public Point
{
private:
    /* data */
public:
    double width;
    double height;
    Rectangle(double x, double y, double a, double b) : Point(x, y), width(a), height(b){};
    double calPermiter() { return 2 * (this->height + this->width); };
    double calArea() { return this->height * this->width; };
};

class Cuboid : public Rectangle
{
private:
    /* data */
public:
    double deep;
    Cuboid(double x, double y, double width, double height, double a) : Rectangle(x, y, width, height), deep(a){};
    double calVolume() { return this->calArea() * this->deep; };
    double calSurfaceArea() { return 2 * (this->calArea() + this->height * this->deep + this->width * this->deep); };
};

int main()
{
    Cuboid cube = Cuboid(0,0,12.5,4.3,6.1);
    cout<<cube.calSurfaceArea()<<endl;
    cout<<cube.calVolume()<<endl;
    return 0;
}