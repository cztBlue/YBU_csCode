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
      ~Student()
      {
         cout<<"对象被删除"<<endl;
      }

     void setName(string str) {
        name = str;
     }

     void setNo(string str) {
        no = str;
     }  

     void setSex(string str) {
        sex = str;
     }

     void setPhone(string str) {
        phone = str;
     }

     void printInfo() {
        cout<<"姓名："<<name<<endl;
        cout<<"学号："<<no<<endl;
        cout<<"性别："<<sex<<endl;
        cout<<"电话："<<phone<<endl;
     }
};


int main()
{
    //分配内存
    Student* stu = new Student;
    stu->setName("李渊");
    stu->setNo("1224023000");
    stu->setSex("男");
    stu->setPhone("15005081111");
    stu->printInfo();

    //释放内存
    delete stu;

    return 0;
}
