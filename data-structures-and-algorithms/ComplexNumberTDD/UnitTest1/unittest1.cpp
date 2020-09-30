#include "CppUnitTest.h"
#include "targetver.h"
#include "../ComplexNumberTDD/Complex.h"
#include "../ComplexNumberTDD/Complex.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	using namespace std;
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(testAddingPos1)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = 1;
			tb1 = 1;
			tb2 = 1;
			ta = 2;
			tb = 2;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)"; //cannot access private members from class, final implementation includes converted to string
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}
		TEST_METHOD(testAddingNeg1)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = -1;
			ta2 = -1;
			tb1 = -1;
			tb2 = -1;
			ta = -2;
			tb = -2;
			string testOut = "(" + to_string(ta) + to_string(tb) + "i)"; 
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testAddingPosNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = 2;
			tb1 = 3;
			tb2 = 4;
			ta = 3;
			tb = 7;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = 5;
			ta2 = 6;
			tb1 = 10;
			tb2 = 12;
			ta = 11;
			tb = 22;
			testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testAddingNegNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = -1;
			ta2 = -2;
			tb1 = -3;
			tb2 = -4;
			ta = -3;
			tb = -7;
			string testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5;
			ta2 = -6;
			tb1 = -10;
			tb2 = -12;
			ta = -11;
			tb = -22;
			testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testAddingPosAndNegNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = -2;
			tb1 = 3;
			tb2 = -4;
			ta = -1;
			tb = -1;
			string testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5;
			ta2 = 6;
			tb1 = -10;
			tb2 = 12;
			ta = 1;
			tb = 2;
			testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testAddingDecNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1.1;
			ta2 = 3.2;
			tb1 = 3.4;
			tb2 = 1.6;
			ta = 4.3;
			tb = 5;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5.1;
			ta2 = 6.7;
			tb1 = -10.11;
			tb2 = 12.42;
			ta = 1.6;
			tb = 2.31;
			testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.addAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testSubPos1)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = 1;
			tb1 = 1;
			tb2 = 1;
			ta = 0;
			tb = 0;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}
		TEST_METHOD(testSubNeg1)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = -1;
			ta2 = -1;
			tb1 = -1;
			tb2 = -1;
			ta = 0;
			tb = 0;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testSubPosNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = 2;
			tb1 = 3;
			tb2 = 4;
			ta = -1;
			tb = -1;
			string testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = 5;
			ta2 = 6;
			tb1 = 10;
			tb2 = 12;
			ta = -1;
			tb = -2;
			testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testSubNegNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = -1;
			ta2 = -2;
			tb1 = -3;
			tb2 = -4;
			ta = 1;
			tb = 1;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5;
			ta2 = -6;
			tb1 = -10;
			tb2 = -12;
			ta = 1;
			tb = 2;
			testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testSubPosAndNegNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1;
			ta2 = -2;
			tb1 = 3;
			tb2 = -4;
			ta = 3;
			tb = 7;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5;
			ta2 = 6;
			tb1 = -10;
			tb2 = 12;
			ta = -11;
			tb = -22;
			testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}

		TEST_METHOD(testSubDecNum)
		{
			Complex objt;
			double ta, tb, ta1, ta2, tb1, tb2;
			ta1 = 1.1;
			ta2 = 3.2;
			tb1 = 3.4;
			tb2 = 1.6;
			ta = -2.1;
			tb = 1.8;
			string testOut = "(" + to_string(ta) + "+" + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());

			ta1 = -5.1;
			ta2 = 6.7;
			tb1 = -10.11;
			tb2 = 12.42;
			ta = -11.8;
			tb = -22.53;
			testOut = "(" + to_string(ta) + to_string(tb) + "i)";
			objt.subtractAB(ta1, tb1, ta2, tb2);
			Assert::AreEqual(testOut, objt.printAB());
		}
	};
};