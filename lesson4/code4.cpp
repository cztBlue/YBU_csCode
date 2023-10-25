#include <iostream>
using namespace std;

class Complex // 复数
{
private:
    double real; // 实部
    double imag; // 虚部
public:
    Complex(){};
    Complex(double x, double y) : real(x), imag(y) {}
    ~Complex() {}

    // 友元-->去掉注释即用
    // friend Complex operator+(const Complex &l ,const Complex &r);
    // friend Complex operator-(const Complex &l ,const Complex &r);
    // friend Complex operator*(const Complex &l ,const Complex &r);
    // friend Complex operator/(const Complex &l ,const Complex &r);

    friend ostream &operator<<(ostream &os, const Complex &dt);

    //成员函数
    Complex operator+(const Complex &r)
    {
        Complex res;
        res.real = this->real + r.real;
        res.imag = this->imag + r.imag;
        return res;
    }

    Complex operator-(const Complex &r)
    {
        Complex res;
        res.real = this->real - r.real;
        res.imag = this->imag - r.imag;
        return res;
    }

    Complex operator*(const Complex &r)
    {
        Complex res;
        res.real = (this->real * r.real) - (this->imag * r.imag);
        res.imag = (this->imag * r.real) + (this->real * r.imag);
        return res;
    }
    Complex operator/(const Complex &r)
    {
        Complex res;
        res.real = (this->real * r.real + this->imag * r.imag) / (r.real * r.real + r.imag * r.imag);
        res.imag = (this->imag * r.real - this->real * r.imag) / (r.real * r.real + r.imag * r.imag);
        return res;
    }
};

ostream &operator<<(ostream &os, const Complex &dt)
{
    os << dt.real << " + " << dt.imag << 'i';
    return os;
}

// 友元-->去掉注释即用
// Complex operator+(const Complex &l ,const Complex &r)
// {
//     Complex res;
//     res.real = l.real + r.real;
//     res.imag = l.imag + r.imag;
//     return res;
// }

// Complex operator-(const Complex &l ,const Complex &r)
// {
//     Complex res;
//     res.real = l.real - r.real;
//     res.imag = l.imag - r.imag;
//     return res;
// }

// Complex operator*(const Complex &l ,const Complex &r)
// {
//     Complex res;
//     res.real = (l.real * r.real) - (l.imag * r.imag);
//     res.imag = (l.imag * r.real) + (l.real * r.imag);
//     return res;
// }
// Complex operator/(const Complex &l ,const Complex &r)
// {
//     Complex res;
//     res.real = (l.real * r.real + l.imag * r.imag) / (r.real * r.real + r.imag * r.imag);
//     res.imag = (l.imag * r.real - l.real * r.imag) / (r.real * r.real + r.imag * r.imag);
//     return res;
// }

int main()
{
    Complex c_1(12.5, 66);
    Complex c_2(56.74, 91.57);
    cout << c_1 + c_2 << endl;
    cout << c_1 - c_2 << endl;
    cout << c_1 * c_2 << endl;
    cout << c_1 / c_2 << endl;

    return 0;
}
