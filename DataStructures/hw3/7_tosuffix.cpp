#include <stdio.h>
#include <iostream>
#include <stack>
//为了方便本例用了cpp（主要是有现成的STL用,自己写的那个太难用了）
//习题3，第4题

using namespace std;
double a = 7.2;
double b = 12.3;
double c = 11.2;
double d = 1.4;
double e = 5.1;
double f = 6.3;

string changeSuffix(char infix[])
{
    char *p = infix;
    stack<char> s;
    string res = "";
    while (*p != '\0')
    {
        if ('a' <= *p && *p <= 'z')
        {
            res = res + *p;
        }
        if ('+' == *p || '-' == *p)
        {
            if (s.empty())
            {
                s.push(*p);
            }
            else
            {
                while (!s.empty())
                {
                    if (s.top() == '(')
                    {
                        break;
                    }
                    res = res + s.top();
                    s.pop();
                }
                s.push(*p);
            }
        }
        if (')' == *p)
        {
            while ('(' != s.top())
            {
                res = res + s.top();
                s.pop();
            }
            s.pop();
        }
        if ('*' == *p || '/' == *p || '(' == *p)
        {
            s.push(*p);
        }

        *p++;
    }
    while (!s.empty())
    { // 把栈中剩余的符号弹出
        if (s.top() == '(')
            s.pop();
        else
        {
            res = res + s.top();
            s.pop();
        }
    }
    return res;
}

double calValue(string suffix)
{
    stack<char> optr;
    stack<double> ovs;
    double numb1, numb2;
    for (char ch : suffix)
    {
        switch (ch)
        {
        case 'a':
            ovs.push(a);
            break;
        case 'b':
            ovs.push(b);
            break;
        case 'c':
            ovs.push(c);
            break;
        case 'd':
            ovs.push(d);
            break;
        case 'e':
            ovs.push(e);
            break;
        case 'f':
            ovs.push(f);
            break;
        case '-':
            numb2 = ovs.top();
            ovs.pop();
            numb1 = ovs.top();
            ovs.pop();
            ovs.push(numb1 - numb2);
            break;
        case '+':
            numb2 = ovs.top();
            ovs.pop();
            numb1 = ovs.top();
            ovs.pop();
            ovs.push(numb1 + numb2);
            break;
        case '*':
            numb2 = ovs.top();
            ovs.pop();
            numb1 = ovs.top();
            ovs.pop();
            ovs.push(numb1 * numb2);
            break;
        case '/':
            numb2 = ovs.top();
            ovs.pop();
            numb1 = ovs.top();
            ovs.pop();
            ovs.push(numb1 / numb2);
            break;
        }
    }
    if (!ovs.empty())
    {
        return ovs.top();
    }
    return 0;
}

int main()
{
    printf("习题3，第四题\n");
    printf("a=%lf ,b=%lf ,c=%lf ,d=%lf ,e=%lf ,f=%lf \n",a,b,c,d,e,f);
    char infix[50] = "a*b+(c-d/e)*f";
    //abcdef为：，12.3，11.2，1.4，5.1，6.3
    string suffix = changeSuffix(infix);
    cout << infix << "的后缀表达式为:" << suffix << endl;
    cout << "结果为:" << calValue(suffix) << endl;
    return 0;
}
