//9:172pp65pp11pp3p94pp
//6:124pp5pp36pp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define MAXSIZE 30

int preOrder[MAXSIZE];
int inOrder[MAXSIZE];
int lastOrder[MAXSIZE];

void RecurTravel(int beforLen, int midLen, int lastLen, int n)
{
    if ( n == 0 ) //边界
        return;
    if ( n == 1 )//基准条件
    {
        lastOrder[lastLen] = preOrder[beforLen];
        return;
    }
    int root = preOrder[beforLen];
    lastOrder[lastLen + n - 1] = root;
    int L, R ,i;
    for (i = 0; i < n; i++)
    {
        if ( inOrder[midLen + i] == root )
            break;
    }
    L = i;   
    R = n - L - 1;   
    RecurTravel(beforLen + 1, midLen, lastLen, L);
    RecurTravel(beforLen + L + 1, midLen + L + 1, lastLen + L, R);
}

int main()
{
    for (int i = 0; i < MAXSIZE; i++)   
    {
        preOrder[i] = 0;
        inOrder[i] = 0;
        lastOrder[i] = 0;
    }
    stack<int> inputStack;
    int nodeNum;
    cin >> nodeNum;
    int i, data;
    int preIndex = 0, inIndex = 0, postIndex = 0;
    string str;
    for (i = 0; i < 2 * nodeNum; i++)
    {
        cin >> str;
        if (str == "Push")
        {
            cin >> data;
            preOrder[preIndex++] = data;
            inputStack.push(data);
        }
        else if (str == "Pop")
        {
            inOrder[inIndex++] = inputStack.top();
            inputStack.pop();
        }
    }
    RecurTravel(0, 0, 0, nodeNum);
    for (int i = 0; i < nodeNum; i++)
    {
        if ( i == nodeNum - 1 )
            cout << lastOrder[i] << endl;
        else
            cout << lastOrder[i] << ' ';
    }
}

