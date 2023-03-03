#include "pch.h"
#include "CppUnitTest.h"
#include "../DoublyLinkedList/DoublyLinkedList/DLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDLinkedList
{
	TEST_CLASS(TestDLinkedList)
	{
	public:
		
		TEST_METHOD(ThisShouldFail)
		{
			//I can declare local variables
			int a{ 2 };
			int b{ 5 };
			Assert::IsTrue(a == b);
		}
		TEST_METHOD(MakeADoubleLL)
		{
			DLinkedList<int> x{};
			Assert::AreEqual(0, x.getSize());
			//Tes that the expected and given values are the same
			//(expected, actual)

			//Assert::AreSame(expected, actual)
			//Like AreEqual, but checks that not just the value but the ADDRESS is the same.
		}
	};
}
