# include<iostream>
using namespace std;

namespace myspace
{
    int n = 1145;
}

int n = 7;

//命名空间的访问测试
int main()
{
	int n = 5;
    cout<<"namespce-n:"<<myspace::n<<endl;
    cout<<"global-n:"<<::n<<endl;
    cout<<"local-n:"<<n<<endl;

	
    return 0;
}
