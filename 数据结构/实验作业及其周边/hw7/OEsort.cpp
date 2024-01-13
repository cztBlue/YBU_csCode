# include<iostream>
# include<vector>
#define len 20
using namespace std;

void odd_even_sort(int arr[]) {
	int odd_even, i;
	int temp;
	int sorted = 0;
	while (!sorted) {
		sorted = 1;
		for (odd_even = 0; odd_even < 2; odd_even++)
			for (i = odd_even; i < len - 1; i += 2)
				if (arr[i] > arr[i + 1]) {
					temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
					sorted = 0;
				}
	}
}

int main()
{
    int sortT[len];
    for (int i = 0; i < len; i++)
        sortT[i] = rand();
    return 0;
    
}