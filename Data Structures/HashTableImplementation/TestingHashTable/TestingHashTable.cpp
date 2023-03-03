#include "pch.h"
#include "CppUnitTest.h"
#include "../HashTableImplementation/HashTable.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingHashTable
{
	TEST_CLASS(TestingHashTable)
	{
	public:
		
		TEST_METHOD(TestHashFunciton)
		{
			HashTable hash{};
			Assert::AreEqual(97, hash.h("a"));
			Assert::AreEqual(195, hash.h("ab"));
		}
		TEST_METHOD(CounCollisions) 
		{
			HashTable hash{};
		}
	};
}
