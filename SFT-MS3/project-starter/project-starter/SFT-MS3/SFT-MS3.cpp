#include "pch.h"
#include "mapping.h"
#include "management.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SFTMS3
{
	TEST_CLASS(SFTMS3)
	{
	public:
		
		TEST_METHOD(distance_T001)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 0, 0 };
			Assert::AreEqual(0.0, distance(&p1, &p2));
		}
		TEST_METHOD(distance_T002)
		{
			Point p1 = { -1, -1 };
			Point p2 = { -1, -1 };
			Assert::AreEqual(1.0, distance(&p1, &p2));
		}

		TEST_METHOD(distance_T003)
		{
			Point p1 = { 0, 0 };
			Point p2 = { 25, 25 };
			double expected = sqrt(25 * 25 + 25 * 25);
			Assert::AreEqual(expected, distance(&p1, &p2));
		}
		TEST_METHOD(distance_T004)
		{
			Point p1 = { 0, 0 };
			// Invalid input since Point should have integer values only
			Assert::ExpectException<std::invalid_argument>([&] {
				Point p2 = { 'A', 2 };
				distance(&p1, &p2);
				});
		}

		TEST_METHOD(distance_T005)
		{
			Point p1 = { 0, 0 };
			// This test should fail since input values exceed 25
			Assert::ExpectException<std::out_of_range>([&] {
				Point p2 = { 30, 100 };
				distance(&p1, &p2);
				});
		}
	};
}
