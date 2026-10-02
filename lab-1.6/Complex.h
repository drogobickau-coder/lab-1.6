#pragma once
#include <string>

using namespace std;

class Complex
{
public: // Робимо тип Complex::Pair доступним ззовні
    class Pair
    {
    private:
        double first;
        double second;
    public:
        double getFirst() const { return first; }
        double getSecond() const { return second; }

        void setFirst(double first) { this->first = first; }
        void setSecond(double second) { this->second = second; }

        void Init(double first, double second);
        void Display() const;
        void Read();
        string toString() const;

        double multiplyFields() const;
        Pair add(const Pair& other) const;
    };

private: // Поле-об'єкт залишається прихованим
    Pair pair;

public:
    Complex::Pair getPair() const { return pair; }
    void setPair(Complex::Pair pair) { this->pair = pair; }

    void Init(Complex::Pair pair);
    void Display() const;
    void Read();
    string toString() const;

    Complex multiply(const Complex& other) const;
    Complex subtract(const Complex& other) const;
};