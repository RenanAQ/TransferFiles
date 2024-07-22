#include "pch.h"
#include "CppUnitTest.h"
extern "C" {
#include "management.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BoxSizeTests
{
    TEST_CLASS(BoxSizeTests)
    {
    public:

        TEST_METHOD(TestValidBoxSize1)
        {   //Verify if return true for 1mt3 boxes
            Assert::AreEqual(1, isValidBoxSize(1));
        }

        TEST_METHOD(TestValidBoxSize3)
        {   //Verify if return true for 3mt3 boxes
            Assert::AreEqual(1, isValidBoxSize(3));
        }

        TEST_METHOD(TestValidBoxSize5)
        {   //Verify if return true for 5mt3 boxes
            Assert::AreEqual(1, isValidBoxSize(5));
        }

        TEST_METHOD(TestInvalidBoxSize2)
        {   //Verify if return false for 2mt3 boxes
            Assert::AreEqual(0, isValidBoxSize(2));
        }

        TEST_METHOD(TestInvalidBoxSize4)
        {   //Verify if return false for 4mt3 boxes
            Assert::AreEqual(0, isValidBoxSize(4));
        }

        TEST_METHOD(TestInvalidBoxSize0)
        {   //Verify if return false for 0mt3 boxes
            Assert::AreEqual(0, isValidBoxSize(0));
        }

        TEST_METHOD(TestInvalidBoxSize6)
        {   //Verify if return false for 6mt3 boxes
            Assert::AreEqual(0, isValidBoxSize(6));
        }

    };
}
