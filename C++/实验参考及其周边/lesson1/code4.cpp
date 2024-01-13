#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n; 
	cout << "输入规模:" << '\n';
	cin >> n;

	//上半部分n行
	for (int i = 0; i < n; i++)
        cout<<string(n - i -1, ' ')<<string(2 * i + 1, '*')<<endl;
		
    //下半部分n-1行
    for (int i = 0; i < n - 1; i++)
		cout<<string(i + 1, ' ')<<string(2 * ( n - i ) - 3, '*')<<endl;
    return 0;
}
