#include <iostream>
#define PI 3.1415926

using namespace std;

typedef struct circle
{
  double radius = 1.0; // 半径
} Circle;

typedef struct rectangle // 矩形
{
  double height = 1.0; // 高度
  double width = 1.0;  // 宽度
} Rectangle;

class calGeo
{
public:
  double calPerimeter(Circle circle)
  {
    return 2 * PI * circle.radius;
  }
  double calPerimeter(Rectangle rec)
  {
    return 2 * (rec.height + rec.width);
  }
  double calArea(Circle circle)
  {
    return PI * circle.radius * circle.radius;
  }

  double calArea(Rectangle rec)
  {
    return rec.height * rec.width;
  }
};

int main()
{
  // GeoDefine
  Circle cir;
  cir.radius = 5.6;
  Rectangle rec;
  rec.height = 2.3;
  rec.width = 2.3;
  calGeo cg;

  cout << "周长测试" << endl;
  cout << cg.calPerimeter(cir) << endl;
  cout << cg.calPerimeter(rec) << endl;

  cout << "面积测试" << endl;
  cout << cg.calArea(cir) << endl;
  cout << cg.calArea(rec) << endl;
}