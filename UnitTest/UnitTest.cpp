#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_6.1_ITER/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestFillArray)
        {
            int myArray[ARRAY_SIZE];
            fillArray(myArray);

            for (int i = 0; i < ARRAY_SIZE; ++i) {
                Assert::IsTrue(myArray[i] >= LOWER_BOUND && myArray[i] <= UPPER_BOUND);
            }
        }

        TEST_METHOD(TestProcessArray)
        {
            int myArray[ARRAY_SIZE] = { 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100, 105, 110, 115, 120, 125, 130, 135, 140 };
            int count, sum;

            processArray(myArray, count, sum);

            Assert::AreEqual(11, count);
            Assert::AreEqual(875, sum);

            for (int i = 0; i < ARRAY_SIZE; ++i) {
                if (i % 2 != 0 && i % 13 != 0) {
                    Assert::AreEqual(0, myArray[i]);
                }
            }
        }
    };
}