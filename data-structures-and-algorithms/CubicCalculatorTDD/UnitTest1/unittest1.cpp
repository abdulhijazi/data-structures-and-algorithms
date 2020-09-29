#include "targetver.h"
#include "CppUnitTest.h"
#include "..\CubicCalculatorTDD\CubicCalculatorTDD.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

BEGIN_TEST_MODULE_ATTRIBUTE()
TEST_MODULE_ATTRIBUTE(L"Date", L"2020/09/28")
END_TEST_MODULE_ATTRIBUTE()

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{


	public:

		TEST_METHOD(TestCubic0)
		{
			float a = 0;
			Assert::AreEqual(a, cubic(0));
		}
		TEST_METHOD(TestCubic1)
		{
			float a = 1;
			Assert::AreEqual(a, cubic(1));
		}
		TEST_METHOD(TestCubic10)
		{
			float a = 1000;
			Assert::AreEqual(a, cubic(10));
		}
		TEST_METHOD(TestPosNum)
		{
			float a = 8;
			Assert::AreEqual(a, cubic(2));
			a = 27;
			Assert::AreEqual(a, cubic(3));
			a = 64;
			Assert::AreEqual(a, cubic(4));
			a = 125;
			Assert::AreEqual(a, cubic(5));
			a = 216;
			Assert::AreEqual(a, cubic(6));
		}
		TEST_METHOD(TestNegNum)
		{
			float a = -8;
			Assert::AreEqual(a, cubic(-2));
			a = -27;
			Assert::AreEqual(a, cubic(-3));
			a = -64;
			Assert::AreEqual(a, cubic(-4));
			a = -125;
			Assert::AreEqual(a, cubic(-5));
			a = -216;
			Assert::AreEqual(a, cubic(-6));
		}
		TEST_METHOD(TestDecimalNum)
		{
			float a = 0.001;
			float tolerance = 0.0001;
			Assert::AreEqual(a, cubic(0.1));
			a = 1.331;
			Assert::AreEqual(a, cubic(1.1), tolerance);
		}

	};
}