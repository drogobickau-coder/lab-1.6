#include "pch.h"
#include "CppUnitTest.h"
#include "../lab-1.6/Complex.h" 
#include "../lab-1.6/Complex.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMultiplyFields)
        {
            Complex::Pair p;
            p.Init(5.0, 3.0);

            double result = p.multiplyFields();

            Assert::AreEqual(15.0, result);
        }

        TEST_METHOD(TestComplexSubtract)
        {
            Complex c1, c2;
            Complex::Pair p1, p2;

            p1.Init(5.0, 3.0);
            p2.Init(2.0, -1.0);

            c1.Init(p1);
            c2.Init(p2);

            Complex result = c1.subtract(c2);

            Assert::AreEqual(3.0, result.getPair().getFirst());
            Assert::AreEqual(4.0, result.getPair().getSecond());
        }
    };
}