#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//必须全局定义
typedef struct student
{
	string name = "张三"; //学生姓名
	string sex = "male"; //性别
	string no = "123456"; //学号
	float score = 0.0; //成绩
}Student;


float giveAverageScore(vector<Student> vec)
{
    float sum;
    int count = 0;
    vector<Student>::iterator v = vec.begin();
    while( v != vec.end()) 
    {
        //打一遍每个学生的成绩
        cout<<(*v).score<<endl;

        sum += (*v).score;
        v++;
        count++;
    }
    return sum/count;
}

int main()
{
    srand(17);
    vector<Student> vec;
    
    for(int i = 0; i < 3; i++)
    {
        Student student; 
        student.score = (float)(rand()%(100 - 0 +1));
        vec.push_back(student);
    } 

    //增加一个学生
    Student lisi;
    lisi.name = "李四";
    lisi.sex = "male";
    lisi.no = "654321";
    lisi.score = 99.0;
    vec.push_back(lisi);

    //删除第三个学生
    vec.erase(vec.begin()+2);

   //计算平均成绩
    cout<<giveAverageScore(vec)<<endl;

    return 0;
}