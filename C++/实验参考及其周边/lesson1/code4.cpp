#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n; 
	cout << "�����ģ:" << '\n';
	cin >> n;

	//�ϰ벿��n��
	for (int i = 0; i < n; i++)
        cout<<string(n - i -1, ' ')<<string(2 * i + 1, '*')<<endl;
		
    //�°벿��n-1��
    for (int i = 0; i < n - 1; i++)
		cout<<string(i + 1, ' ')<<string(2 * ( n - i ) - 3, '*')<<endl;
    return 0;
}
