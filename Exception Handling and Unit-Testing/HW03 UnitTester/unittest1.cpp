#include "stdafx.h"
#include "CppUnitTest.h"
#include "readint.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

///////////////////////
// Ben Morledge-Hampton
// 
// Exception Handling and Unit-Testing
//
// 3/8/2017
///////////////////////

namespace HW03UnitTester
{		
	TEST_CLASS(UnitTest1) // Test suite for read_int()
	{
		
		// After calling read_int("My prompt: ", -3, 3)
		// Expect 0 to be returned if given the input: Hello\n0
		TEST_METHOD(TestCase1) 
		{
			// Open a file stream to read the file zeroinput.txt (remember CS-172)
			std::ifstream ss("..\\HW03 UnitTester\\Test Case 1 Input.txt");

			// Check if we opened the file stream successfully
			if (ss.fail())
				throw int(-1); // throw an integer with value -1

			// Replace the cin read buffer with the read buffer from the file stream 
			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			// Perform the read_int() test.
			// cin will now read from your file and not from the keyboard.
			// We expect the correct value returned is 0, ignoring the Hello string.
			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			// Restore cin to the way it was before
			std::cin.rdbuf(orig_cin);

			// Close the file stream
			ss.close();
		}

		// After calling read_int("My prompt: ", 5, 1)
		// Expect an invalid_argument exception because the given range is empty.
		TEST_METHOD(TestCase2) 
		{

			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);

		}

		// After calling read_int("My prompt: ", 0, 4)
		// Expect 3 to be returned if given the input: -3\n5\n10\n-2\n3
		TEST_METHOD(TestCase3) {

		}

		// After calling read_int("My prompt: ", 0, 0)
		// Expect an invalid_argument exception because the given range is empty.
		TEST_METHOD(TestCase4)
		{

			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 4)
				read_int("My prompt: ", 0, 0);
			};

			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);

		}

	};
}