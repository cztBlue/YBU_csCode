# include<iostream>
using namespace std;

class Student
{
   private:
     string name;
     string no;
     string sex;
     string phone;
   public:
     Student();
     Student(string name,string no,string sex, string phone);//structor declare
     ~Student();//dtor declare
     void printInfo() {
        cout<<"姓名："<<name<<endl;
        cout<<"学号："<<no<<endl;
        cout<<"性别："<<sex<<endl;
        cout<<"电话："<<phone<<endl;
     }
};

Student::Student(void)
{
  name = "张三";
  no = "123456";
  sex = "男";
  phone = "11111111111";
}

Student::Student(string name_, string no_, string sex_, string phone_)
{
  name = name_;
  no = no_;
  sex = sex_;
  phone = phone_;
}

Student::~Student(void)
{
    cout << "Student析构了！" << endl;
}

int main()
{
  Student stu("lisi","123456","male","12346789");
  stu.printInfo();

  //程序退出时对象会被析构

  return 0;
}
