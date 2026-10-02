#include <iostream>
#include "Complex.h"
#pragma execution_character_set("utf-8")
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    {
        setlocale(LC_ALL, "uk_UA.UTF-8");
    }
    Complex c1, c2;

    cout << "--- Input first complex number ---";
    c1.Read();

    cout << "\n--- Input second complex number ---";
    c2.Read();

    cout << "\n--- Complex 1 ---";
    c1.Display();
    cout << "Fields multiplied: " << c1.getPair().multiplyFields() << endl;

    cout << "\n--- Complex 2 ---";
    c2.Display();
    cout << "Fields multiplied: " << c2.getPair().multiplyFields() << endl;

    cout << "\n--- Multiplication (c1 * c2) ---";
    Complex c_mult = c1.multiply(c2);
    c_mult.Display();

    cout << "\n--- Subtraction (c1 - c2) ---";
    Complex c_sub = c1.subtract(c2);
    c_sub.Display();

    cout << "\n--- Pairs addition (c1.pair + c2.pair) ---\n";
    Complex::Pair p_add = c1.getPair().add(c2.getPair());
    cout << "Result pair: ";
    p_add.Display();
    cout << endl;

    return 0;
}