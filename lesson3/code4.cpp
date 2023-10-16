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
    Student stu;
    stu.setName("张三");
    stu.setNo("123456");
    stu.setSex("男");
    stu.setPhone("11111111111");
    
    stu.printInfo();

    return 0;
}
