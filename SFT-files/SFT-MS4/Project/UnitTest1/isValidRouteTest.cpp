#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "management.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isValidRoute_UnitTesting
{
    TEST_CLASS(Blackbox_Test)
    {
    public:

        TEST_METHOD(InvalidRoute_T001)
        {
            struct Truck truck;
            truck.routes[0] = getBlueRoute();
            truck.packageCount = 0;

            struct Package package;
            package.deliveryRoute = getGreenRoute();

            Assert::IsFalse(isValidRoute(&truck, &package));
        }

        TEST_METHOD(ValidRoute_T002)
        {
            struct Truck truck;
            truck.routes[0] = getBlueRoute();

            struct Package package;
            package.deliveryRoute = getBlueRoute();

            Assert::IsTrue(isValidRoute(&truck, &package));
        }

        TEST_METHOD(EmptyTruckRoutes_T003)
        {
            struct Truck truck;
            truck.routes[0].routeSymbol = '\0';

            struct Package package;
            package.deliveryRoute = getBlueRoute();

            Assert::IsFalse(isValidRoute(&truck, &package));
        }

        TEST_METHOD(MultipleRoutesWithValidMatch_T004)
        {
            struct Truck truck;
            truck.routes[0] = getGreenRoute();
            truck.routes[1] = getBlueRoute();

            struct Package package;
            package.deliveryRoute = getBlueRoute();

            Assert::IsTrue(isValidRoute(&truck, &package));
        }
    };





    TEST_CLASS(WhiteBox_Test)
    {
    public:

        TEST_METHOD(RouteMatching_T005)
        {
            struct Truck truck;
            struct Route route = getBlueRoute();
            truck.routes[0] = route;
            truck.packageCount = 0; 
            truck.currentWeight = 0;
            truck.currentVolume = 0;

            struct Package package;
            package.deliveryRoute = route;
            package.weight = 0;
            package.volume = 0;

            Assert::IsTrue(isValidRoute(&truck, &package));
        }

        TEST_METHOD(RouteNotMatching_T006)
        {
            struct Truck truck;
            struct Route blueRoute = getBlueRoute();
            struct Route greenRoute = getGreenRoute();
            truck.routes[0] = blueRoute;
            truck.packageCount = 0; 
            truck.currentWeight = 0;
            truck.currentVolume = 0;

            struct Package package;
            package.deliveryRoute = greenRoute;
            package.weight = 0;
            package.volume = 0;

            Assert::IsFalse(isValidRoute(&truck, &package));
        }

        TEST_METHOD(NoRoutesInTruck_T007)
        {
            struct Truck truck;
            truck.packageCount = 0; 
            truck.currentWeight = 0;
            truck.currentVolume = 0;

            struct Route route = getBlueRoute();

            struct Package package;
            package.deliveryRoute = route;
            package.weight = 0;
            package.volume = 0;

            Assert::IsFalse(isValidRoute(&truck, &package));
        }

        TEST_METHOD(MultipleRoutesInTruck_T008)
        {
            struct Truck truck;
            struct Route blueRoute = getBlueRoute();
            struct Route greenRoute = getGreenRoute();
            truck.routes[0] = blueRoute;
            truck.routes[1] = greenRoute;
            truck.packageCount = 0; 
            truck.currentWeight = 0;
            truck.currentVolume = 0;

            struct Package package;
            package.deliveryRoute = greenRoute;
            package.weight = 0;
            package.volume = 0;

            Assert::IsTrue(isValidRoute(&truck, &package));
        }
    };
}
