#include "pch.h"
#include "CppUnitTest.h"
#include "../CustomHeapByMe/MaxHeap.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HeapTests
{
	TEST_CLASS(HeapTests)
	{
	public:
		
		TEST_METHOD(CompareHeapEntries) {
			HeapEntry a("lesser", 2);
			HeapEntry b("greater", 5);
			Assert::AreEqual(true, a < b);
			Assert::AreEqual(false, a == b);
			Assert::AreEqual(false, a > b);
			Assert::AreEqual(false, a >= b);
			Assert::AreEqual(true, a <= b);
		}

		TEST_METHOD(CreateHeap) {
			MaxHeap m;
			Assert::AreEqual(0, m.getSize());
		}

		TEST_METHOD(InsertOne) {
			MaxHeap m;
			HeapEntry a("first", 6);
			m.enqueue(a);
			Assert::IsTrue(a == m.reportData()[1]);
			Assert::AreEqual(1, m.getSize());
		}

		TEST_METHOD(InsertThree) {
			MaxHeap m;
			HeapEntry a("first", 6);
			HeapEntry b("second", 8);
			HeapEntry c("third", 5);
			//Note, expecting b,a,c
			m.enqueue(a);
			m.enqueue(b);
			m.enqueue(c);
			Assert::IsTrue(b == m.reportData()[1]);
			Assert::IsTrue(a == m.reportData()[2]);
			Assert::IsTrue(c == m.reportData()[3]);
		}

		TEST_METHOD(InsertAndPeek) {
			MaxHeap m;
			HeapEntry a("first", 500);
			m.enqueue(a);
			Assert::IsTrue(a == m.peek());
		}

		TEST_METHOD(InsertAndRemove) {
			MaxHeap m;
			HeapEntry a("first", 30);
			m.enqueue(a);
			Assert::IsTrue(a == m.dequeue());
			Assert::AreEqual(0, m.getSize());
		}

		TEST_METHOD(Peek) {

		}
	};
}
