
#include "CppUnitTest.h"
#include "Workshop3.h"
#include "externalFunc.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestworkshop3
{
	TEST_CLASS(testingPostalCode) //testing function checkPostalCode
	{
	public:
		//Black Box Test
		//inputing empty (" ") string
		//this should return 0
		TEST_METHOD(InvalidPostalCode_Empty)
		{	
			
			Assert::IsTrue(checkPostalCode(" ") == 0); //Being 0 means the input is invalid in function
		}
		//White box Test
		//Since we have a position validation (example: isalpha(input[0]), ...), the 4th position is not being validate,
		// which means that anything can be inputed
		TEST_METHOD(ValidPostalCode_MiddlePosition) //Checking the element in the 4th position A0A-0A0
		{
			Assert::IsTrue(checkPostalCode("m4s-0b6") == 1); //Being 1 means the input is valid in function
		}
	};

	TEST_CLASS(testingAddress)
	{
		//Blackbox test
		//an empty input should return 0, which means in not valid
		TEST_METHOD(InvalidAddress_Empty)
		{
			Assert::IsTrue(checkAddress(" ") == 0); //returnig 0 means that the input is not valid
		}
		//Whitebox test:
		//testing a valid input
		TEST_METHOD(ValidAddress)
		{
			Assert::IsTrue(checkAddress("33 Dunfield") == 1); //returning 1 means the input is valid
		}
	};
}
