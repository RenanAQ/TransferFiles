#include "pch.h"
#include "CppUnitTest.h"
#include "management_r.h"

#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(distanceFunction)
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
				Assert::AreEqual(0.0, distance(&p1, &p2));
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
                Point p2 = { 2.5, 10.8 }; //passing float
                double expected = sqrt(2 * 2 + 10 * 10); //We expect our float be treated as integer since our gride is only integers
                Assert::AreEqual(expected, distance(&p1, &p2));
                
			}
		};
    TEST_CLASS(shortestPathMethods)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            struct Map map = populateMap();
            struct Point start = { 0, 0 };
            struct Point dest = { 2, 4 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                     {0,1}, {0,2}, {1,3}, {2,3}
                },
                4,
                DIVERSION
            };
            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i) 
            {
              Assert::AreEqual(expected.points[i].row, result.points[i].row);
              Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }

        TEST_METHOD(TestMethod2)
        {
            struct Map map = populateMap();
            struct Point start = { 0, 0 };
            struct Point dest = { 12, 6 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                     {1,0},{2,0},{3,1},{4,2},{5,3},{6,3},{7,3},{8,4},{9,5},{10,6},{11,6}
                },
                11,
                DIVERSION
            };
            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i)
            {
                Assert::AreEqual(expected.points[i].row, result.points[i].row);
                Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }

        TEST_METHOD(TestMethod3)
        {
            struct Map map = populateMap();
            struct Point start = { 8, 6 };
            struct Point dest = { 8, 10 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                    {9,7},{8,8},{8,9}
                },
                3,
                DIVERSION
            };
            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i) {
                Assert::AreEqual(expected.points[i].row, result.points[i].row);
                Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }

        TEST_METHOD(TestMethod4)
        {
            struct Map map = populateMap();
            struct Point start = { 5, 0 };
            struct Point dest = { 7, 0 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                     {5,1},{6,2},{7,2},{8,1},{8,0}
                },
                5,
                DIVERSION
            };
            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i) {
                Assert::AreEqual(expected.points[i].row, result.points[i].row);
                Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }
        TEST_METHOD(TestMethod5White)
        {
            struct Map map = populateMap();
            struct Point start = { 19, 1 };
            struct Point dest = { 24, 2 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                    {20,2},{20,1},{21,0},{22,0},{23,0},{24,0}
                },
                6,
                DIVERSION
            };

            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i) {
                Assert::AreEqual(expected.points[i].row, result.points[i].row);
                Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }
        TEST_METHOD(TestMethod6White)
        {
            struct Map map = populateMap();
            struct Point start = { -2, -2 };
            struct Point dest = { 2, 2 };
            struct Route result = shortestPath(&map, start, dest);

            struct Route expected = {
                {
                    {-2,-1},{-1,0},{0,1},{0,2},{1,3},{2,3}
                },
                6,
                DIVERSION
            };

            Assert::AreEqual(expected.numPoints, result.numPoints);
            for (int i = 0; i < expected.numPoints; ++i) 
            {
                Assert::AreEqual(expected.points[i].row, result.points[i].row);
                Assert::AreEqual(expected.points[i].col, result.points[i].col);
            }
        }
    };
}
