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
    Point *p1 = new Point(1.3, 1.9);
    Point *p2 = new Point(2.75, -3.6);
    Rectangle *rec = new Rectangle(0, 0, 12.5, 4.3);
    Cuboid *cub = new Cuboid(0, 0, 12.5, 4.3, 6.1);
    cout << "参数↓" << endl;
    cout << ">点类：" << endl;
    cout << "p1参数:(1.3, 1.9)=>(点x坐标,点y坐标)" << endl;
    cout << "p2参数:(2.75, -3.6)=>(点x坐标,点y坐标)" << endl;
    cout << ">矩形类" << endl;
    cout << "参数:(0, 0, 12.5, 4.3)=>(矩形左上点坐标两个，矩形长，矩形宽)" << endl;
    cout << ">方体类" << endl;
    cout << "参数:(0, 0, 12.5, 4.3, 6.1)=>(矩形参数四个，体高)" << endl;

    cout << "\n功能测试↓" << endl;
    cout << "两点距离:" << p1->calDistance(*p1,*p2)<< endl;
    cout << "矩形周长,面积:" << rec->calPermiter()<<","<<rec->calArea()<< endl;
    cout << "方体表面积,体积:" <<cub->calSurfaceArea()<<","<<cub->calVolume() << endl;
    
    delete p1,p2,rec,cub;
    return 0;
}