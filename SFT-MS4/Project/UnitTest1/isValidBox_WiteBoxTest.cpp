#include "pch.h"
#include "CppUnitTest.h"
#include <limits.h>
extern "C" {
#include "management.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BoxSizeTests
{
    TEST_CLASS(BoxSizeTests)
    {
    public:

        TEST_METHOD(TestNegativeInput)
        {   // Verify Negatives Inputs
            int result = isValidBoxSize(-3);
            Assert::AreEqual(0, result);
        }

        TEST_METHOD(TestOverflowInput)
        {   // Verify if return 0 to values that overflow integer
            long long largeInput = (long long)INT_MAX + 1;
            int result = isValidBoxSize((int)largeInput);
            Assert::AreEqual(0, result);
        }
    };
}
