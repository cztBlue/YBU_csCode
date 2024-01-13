#include <iostream>
using namespace std;

//---------------学生类部分-------------------
class Student
{
private:
    string name;   // 姓名
    string sex;    // 性别
    string no;     // 学号，每个学生的学号是唯一的
    float Chinese; // 语文成绩
    float math;    // 数学成绩
    float English; // 英语成绩
public:
    Student(string _name, string _sex, string _no, float _chinese,
            float _math, float _english) : name(_name), sex(_sex),
                                           no(_no), Chinese(_chinese), math(_math), English(_english) {}
    virtual ~Student() {}
    string getName() { return name; }
    void setName(string _name) { name = _name; }

    string getSex() { return sex; }
    void setSex(string _sex) { sex = _sex; }

    string getNo() { return no; }
    void setNo(string _no) { no = _no; }

    float getChinese() { return Chinese; }
    void setChinese(float _chinese) { Chinese = _chinese; }

    float getMath() { return math; }
    void setMath(float _math) { math = _math; }

    float getEnglish() { return English; }
    void setEnglish(float _english) { English = _english; }

    // 做这些虚函数拓展student的多态性
    virtual string getTutor() { return ""; }
    virtual void setTutor(string t) { return; }
    virtual double tuition() { return 0.0; }
    virtual Student *getpartner() { return nullptr; }

    friend ostream &operator<<(ostream &o, Student &s);
};

// 本科生
class UnderGraduated : public Student
{
    // 添加了一个学伴字段和学费字段和GPA字段
private:
    double tuition_;
    Student *partner = nullptr;

public:
    UnderGraduated(string name, string sex, string no, float chinese, float math, float english, bool isPartner) : Student(name, sex, no, chinese, math, english)
    {
        if (isPartner == true)
        {
            partner = new Student("ban", "female", "0000000", 0.0, 0.0, 0.0);
            tuition_ = 4500.0 * 1.5;
        }
        else
        {
            tuition_ = 4500.0;
        }
    };
    // 释放学伴，防止内存泄漏.
    ~UnderGraduated()
    {
        delete partner;
        cout << "tip:undergraduate and her/his patrner are destructed now." << endl;
    };

    Student *getpartner()
    {
        return partner;
    }

    double tuition()
    {
        cout << "本科生学费:";
        return tuition_;
    }

    friend ostream &operator<<(ostream &o, UnderGraduated &s);
};

// 研究生
class Graduated : public Student
{
private:
    string tutor; // 导师姓名
public:
    Graduated(string name, string sex, string no, string tutor, float chinese, float math, float english) : Student(name, sex, no, chinese, math, english), tutor(tutor) {}
    ~Graduated() { cout << "tip:Graduated is destructed now." << endl; }

    void setTutor(string t)
    {
        tutor = t;
    }
    string getTutor() { return tutor; }
    friend ostream &operator<<(ostream &o, Graduated &s);
};

ostream &operator<<(ostream &o, Student &s)
{
    if (&s == NULL)
    {
        cout << "输出的学生不存在" << endl;
        return o;
    }
    o << "姓名：" << s.name << "\n"
      << "性别：" << s.sex << "\n"
      << "学号：" << s.no;
    return o;
}

ostream &operator<<(ostream &o, UnderGraduated &s)
{
    string type_info = "本科生";
    string part_info_null = "不存在";
    if (&s == NULL)
    {
        cout << "输出的学生不存在" << endl;
        return o;
    }
    o << "姓名：" << s.getName() << "\n"
      << "性别：" << s.getSex() << "\n"
      << "学号：" << s.getNo() << "\n"
      << "类别：" << type_info << "\n"
      << "学费：" << s.tuition_ << "\n";

    if (s.partner != nullptr)
        o << "学伴：" << s.partner->getName();
    else
        o << "学伴：" << part_info_null;
        
    return o;
}

ostream &operator<<(ostream &o, Graduated &s)
{
    string type_info = "研究生";
    if (&s == NULL)
    {
        cout << "输出的学生不存在" << endl;
        return o;
    }
    o << "姓名：" << s.getName() << "\n"
      << "性别：" << s.getSex() << "\n"
      << "学号：" << s.getNo() << "\n"
      << "类别：" << type_info << "\n"
      << "导师：" << s.tutor << "\n";

    return o;
}

//-----------------------链表部分--------------------
// 链表节点
class Node
{
public:
    Student *pStu;
    Node *pNext; // 下一个节点指针

    Node(Student *p) : pStu(p), pNext(NULL) {}
    Node() : pStu(0), pNext(0) {}
    virtual ~Node() {}
};

class myList
{
private:
    Node *pHead;   // 链表头指针
    int nodeCount; // 链表中节点的个数
public:
    myList() : pHead(0), nodeCount(0) {}
    ~myList(); // 删除所有的节点，请定义完整

    // 以下函数需要定义
    void add(Student *p);          // 增加一个节点（链表尾）
    Student *findByNo(string _no); // 按学号查找并定位学生（节点）

    // 按姓名查找并定位学生（节点）
    Student *findByName(string _name);

    bool erase(string _no); // 按学号定位并删除学生（节点）

    double averChinese(); // 计算所有的学生的语文平均成绩
    double averMath();    // 计算所有的学生的数学平均成绩
    double averEnglish(); // 计算所有的学生的英语平均成绩

    // 计算指定学号的学生所有课程的平均成绩
    double average(string _no);
};

myList::~myList(void)
{
    for (int i = 0; i < nodeCount; i++)
    {
        Node *pn = pHead->pNext;
        delete pHead->pStu;
        delete pHead;
        pHead = pn;
    }
}

// 尾插法(没有做头节点)
void myList::add(Student *p)
{
    nodeCount++;
    Node *rear = pHead;
    while (rear != NULL && rear->pNext != NULL)
    {
        rear = rear->pNext;
    }
    Node *newNode = new Node(p);
    if (rear == NULL)
        pHead = newNode;
    else
        rear->pNext = newNode;
}

Student *myList::findByNo(string _no)
{
    Node *rear = pHead;
    while (rear != NULL && rear->pStu->getNo() != _no)
    {
        rear = rear->pNext;
    }
    return rear->pStu;
}

Student *myList::findByName(string _name)
{
    Node *rear = pHead;
    while (rear != NULL && rear->pStu->getName() != _name)
    {
        rear = rear->pNext;
    }
    if (rear == NULL)
        return NULL;

    return rear->pStu;
}

bool myList::erase(string _no)
{
    Node *rear = pHead;
    Node *rbefore;
    while (rear != NULL && rear->pStu->getNo() != _no)
    {
        rbefore = rear;
        rear = rear->pNext;
    }

    if (rear != NULL)
    {
        rbefore->pNext = rear->pNext;
        delete rear;
        return true;
    }
    return false;
}

double myList::averChinese()
{
    double sum = 0.0;
    Node *rear = pHead;
    while (rear != NULL)
    {
        sum += (double)(rear->pStu->getChinese());
        rear = rear->pNext;
    }
    if (nodeCount != 0)
        return sum / (double)nodeCount;

    return 0.0;
}

double myList::averMath()
{
    double sum = 0.0;
    Node *rear = pHead;
    while (rear != NULL)
    {
        sum += (double)(rear->pStu->getMath());
        rear = rear->pNext;
    }
    if (nodeCount != 0)
        return sum / (double)nodeCount;

    return 0.0;
}

double myList::averEnglish()
{
    double sum = 0.0;
    Node *rear = pHead;
    while (rear != NULL)
    {
        sum += (double)(rear->pStu->getEnglish());
        rear = rear->pNext;
    }
    if (nodeCount != 0)
        return sum / (double)nodeCount;

    return 0.0;
}

double myList::average(string _no)
{
    double sum = 0.0;
    Student *s = findByNo(_no);
    sum += (double)(s->getChinese() + s->getEnglish() + s->getMath());
    return sum / 3.0;
}

int main()
{
    // List test
    myList *list1 = new myList();
    list1->add(new UnderGraduated("张三", "male", "123456", 61, 95, 66, false));
    list1->add(new UnderGraduated("李四", "male", "654321", 95, 65, 81, true));
    list1->add(new Graduated("王五", "female", "415263", "王金祥", 53, 44, 63));
    list1->add(new Graduated("马六", "female", "142536", "李政世", 87, 79, 85));
    cout << "<<重载测试:" << endl;
    cout << *((UnderGraduated *)(list1->findByName("张三"))) << endl
         << endl;
    cout << *((Graduated *)(list1->findByName("马六"))) << endl;

    cout << "功能成员测试:" << endl;
    cout << list1->findByName("张三")->tuition() << endl;
    cout << list1->findByName("李四")->tuition() << endl;
    cout << "王五导师:" << list1->findByName("王五")->getTutor() << endl;

    cout << endl
         << "释放测试:" << endl;
    delete list1;

    return 0;
}