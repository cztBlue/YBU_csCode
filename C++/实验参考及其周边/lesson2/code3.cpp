#include <iostream>
#include <string>

using namespace std;

// for泛型
void pointer_swap(void *vp1, void *vp2, int size)
{
    char buffer[size]; // 这里gcc可以通过,其他编译器不做保证
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

// 引用泛型
template <typename T>
void refer_swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

int main()
{

    int i = 39;
    int j = 20;

    // Test for swap1
    pointer_swap(&i, &j, sizeof(int));
    cout << i << " " << j << endl;

    refer_swap(i, j);
    cout << i << " " << j << endl;

    return 0;
}