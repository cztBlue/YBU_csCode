#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int flag = 0;
int main()
{
	int N;
	cin >> N;
	vector<int> sequence;

	// pos[i]表示sequence中数值为i的元素的下标为pos[i]
	vector<int> pos;

	sequence.resize(N);
	pos.reserve(N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &sequence[i]);
		pos[sequence[i]] = i;
	}

	int temp, swap_times = 0, elements_num = 0;
	for (int element = 0; element < N; element++)
	{

		int element_circle = element;
		int temp0;
		temp = sequence[element_circle];

		// 每次进入circle前初始化elements_num为0；
		elements_num = 0;
		
        // 循环到位置sequence[i]是i为止
		while (pos[element_circle] != element_circle)
		{ 

			if (sequence[element_circle] == 0)
				flag = 1;										
			elements_num++;										 
			if (pos[pos[element_circle]] != pos[element_circle]) 
				sequence[element_circle] = element_circle;		 
			else
				sequence[element_circle] = temp;

			// 更新pos和移动element_circle
			temp0 = element_circle;
			element_circle = pos[element_circle];
			pos[temp0] = temp0;
		}
		// 判断是否是单元环
		if (elements_num != 0)
		{ 
			if (flag == 1)
				swap_times += elements_num - 1; // 判断circle是否有0，有0的非单元环移动elements-1次
			else
				swap_times += elements_num + 1; // 无0的非单元环移动elements+1次
		}

		flag = elements_num = 0;
	}
	cout << swap_times << endl;
	return 0;
}