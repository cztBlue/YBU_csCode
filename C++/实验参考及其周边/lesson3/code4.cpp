#include <iostream>
using namespace std;

class Student
{
private:
   string name;
   string no;
   string sex;
   string phone;

public:
   void setName(string str)
   {
      name = str;
   }

   void setNo(string str)
   {
      no = str;
   }

   void setSex(string str)
   {
      if (str != "男" && str != "女")
         sex = "未知";
      else
         sex = str;
   }

   void setPhone(string str)
   {
      if (str.length() != 11)
         phone = "非法电话";
      else
         phone = str;
   }

   string getNo()
   {
      return this->no;
   }

   string getSex()
   {
      return this->sex;
   }

   string getPhone()
   {
      return this->phone;
   }

   string getName()
   {
      return this->name;
   }

   void printInfo()
   {
      cout << "姓名：" << name << endl;
      cout << "性别：" << sex << endl;
      cout << "学号：" << no << endl;
      cout << "电话：" << phone << endl;
   }
};
int main()
{
   Student stu;
   stu.setName("张三");
   stu.setNo("1224023333");
   stu.setSex("男");
   stu.setPhone("12345611111");
   Student stu_2;
   stu_2.setName("李四");
   stu_2.setNo("1224023333");
   stu_2.setSex("Dawnset");
   stu_2.setPhone("1234561111123");

   cout << "test for get" << endl;
   cout << stu.getName() << endl;
   cout << stu.getSex() << endl;
   cout << stu.getNo() << endl;
   cout << stu.getPhone() << endl;

   cout << "test for print" << endl;
   stu.printInfo();
   cout << "" << endl;
   stu_2.printInfo();

   return 0;
}
