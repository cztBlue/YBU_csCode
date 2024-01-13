#include <stdio.h>
#include <math.h>

typedef struct rational
{
    double numerator;
    double denominator;
} Rational;

Rational rAdd(Rational r, Rational l)
{
    Rational res;
    res.numerator = r.numerator * l.denominator + r.denominator * l.numerator;
    res.denominator = r.denominator * l.denominator;
    return res;
}

Rational rReduce(Rational r, Rational l)
{
    Rational res;
    res.numerator = r.numerator * l.denominator - r.denominator * l.numerator;
    res.denominator = r.denominator * l.denominator;
    return res;
}

Rational rMul(Rational r, Rational l)
{
    Rational res;
    res.numerator = r.numerator * l.numerator;
    res.denominator = r.denominator * l.denominator;
    return res;
}

Rational rDiv(Rational r, Rational l)
{
    Rational res;
    res.numerator = r.numerator * l.denominator;
    res.denominator = r.denominator * l.numerator;
    return res;
}

double getDenominator(Rational num)
{
    return num.denominator;
}

double getNumerator(Rational num)
{
    return num.numerator;
}

double getDecimal(Rational num)
{
    return num.numerator/num.denominator;
}

int main()
{

    Rational num1;
    Rational num2;
    Rational num_res;
    num1.denominator = 12.5;
    num1.numerator = 56.8;
    num2.denominator = 57.4;
    num2.numerator = 30.1;

    num_res = rAdd(num1,num2);
    
    //Test for usablity
    printf("%lf\n",getDecimal(num1));
    printf("%lf\n",getDecimal(num2));
    printf("%lf\n",getDecimal(num_res));

    

    return 0;
}