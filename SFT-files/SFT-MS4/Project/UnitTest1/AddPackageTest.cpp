#include "pch.h"
#include "CppUnitTest.h"
#include "management_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AddPackageTest
{
	TEST_CLASS(AddPackageBlackboxTest)
	{
	public:
        TEST_METHOD(addPackage_T001)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = 3.0;
            package.destination.row = 0;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(true, result);
        };
        TEST_METHOD(addPackage_T002)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 0.0;
            package.volume = 0.0;
            package.destination.row = 0;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        };
        TEST_METHOD(addPackage_T003)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 2501.0;
            package.volume = 5.0;
            package.destination.row = 0;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        }
        TEST_METHOD(addPackage_T004)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = 4.0;
            package.destination.row = 0;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        }
	};
    TEST_CLASS(AddPackageWhiteboxTest)
    {
    public:
        TEST_METHOD(addPackage_T005)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = 3.0;
            package.destination.row = 3;
            package.destination.col = 3;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        }
        TEST_METHOD(addPackage_T006)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = 3.0;
            package.destination.row = 0;
            package.destination.col = 25;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        };
        TEST_METHOD(addPackage_T007)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = 3.0;
            package.destination.row = 25;
            package.destination.col = 0;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        };
        TEST_METHOD(addPackage_T008)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = -1.0;
            package.volume = 5.0;
            package.destination.row = 6;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        };
        TEST_METHOD(addPackage_T009)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 0.0;
            truck.currentVolume = 0.0;
            package.weight = 100.0;
            package.volume = -1.0;
            package.destination.row = 6;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(false, result);
        };
        TEST_METHOD(addPackage_T010)
        {
            struct Truck truck = { 0 };
            struct Package package;
            struct Map basemap = populateMap();

            truck.currentWeight = 100.0;
            truck.currentVolume = 5.0;
            package.weight = 100.0;
            package.volume = 5.0;
            package.destination.row = 6;
            package.destination.col = 4;

            bool result = addPackage(&truck, package, basemap);

            Assert::AreEqual(true, result);
        };
    };
}
