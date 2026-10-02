#include "Complex.h"
#include <iostream>
#include <sstream>
#include <cmath>
#pragma execution_character_set("utf-8")

using namespace std;

void Complex::Pair::Init(double first, double second)
{
    setFirst(first);
    setSecond(second);
}

void Complex::Pair::Display() const
{
    cout << toString();
}

void Complex::Pair::Read()
{
    double f, s;
    cout << "first = ? "; cin >> f;
    cout << "second = ? "; cin >> s;
    Init(f, s);
}

string Complex::Pair::toString() const
{
    stringstream ss;
    ss << "(" << first << ", " << second << ")";
    return ss.str();
}

double Complex::Pair::multiplyFields() const
{
    return first * second;
}

Complex::Pair Complex::Pair::add(const Complex::Pair& other) const
{
    Complex::Pair result;
    result.Init(first + other.first, second + other.second);
    return result;
}

void Complex::Init(Complex::Pair pair)
{
    setPair(pair);
}

void Complex::Display() const
{
    cout << endl;
    cout << "pair = ";
    pair.Display();
    cout << endl;
    cout << "complex = " << toString() << endl;
}

void Complex::Read()
{
    Complex::Pair p;
    cout << endl << "Pair = ?" << endl;
    p.Read();
    Init(p);
}

string Complex::toString() const
{
    stringstream ss;
    double r = pair.getFirst();
    double i = pair.getSecond();

    ss << r;
    if (i >= 0) {
        ss << " + " << i << "i";
    }
    else {
        ss << " - " << std::abs(i) << "i";
    }
    return ss.str();
}

Complex Complex::multiply(const Complex& other) const
{
    double a = pair.getFirst();
    double b = pair.getSecond();
    double c = other.getPair().getFirst();
    double d = other.getPair().getSecond();

    Complex::Pair p;
    p.Init(a * c - b * d, a * d + b * c);

    Complex result;
    result.Init(p);
    return result;
}

Complex Complex::subtract(const Complex& other) const
{
    double a = pair.getFirst();
    double b = pair.getSecond();
    double c = other.getPair().getFirst();
    double d = other.getPair().getSecond();

    Complex::Pair p;
    p.Init(a - c, b - d);

    Complex result;
    result.Init(p);
    return result;
}