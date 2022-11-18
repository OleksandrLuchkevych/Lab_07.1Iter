#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07.1Iter/Lab_07.1Iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

            int** T = new int* [2];
            for (int i = 0; i < 2; i++) {

                T[i] = new int[2];
            }
            T[0][0] = 1;
            T[0][1] = 2;


            T[1][0] = 4;
            T[1][1] = 5;

            int S = 0;
            int k = 0;

            int t = Calc(T, 2, 2, S, k);
            Assert::AreEqual(t, 6);
             
            
		}
	};
}
