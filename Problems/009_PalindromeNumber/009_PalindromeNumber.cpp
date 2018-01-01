#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

class Solution {
public:
	bool isoverflow(int x) {
		if (x != 0) {
			return ((x * 10) / 100 != x / 10);
		}
		else {
			return false;
		}
	}

	int reverse(int x) {
		int result = 0;

		while (x != 0) {
			if (isoverflow(result)) {
				return 0;
			}

			result = result * 10 + x % 10;
			x = x / 10;
		}
		return result;
	}

	bool isPalindrome(int x) {

		if (x == 0) {
			return true;
		}

		if (x < 0) {
			return false;
		}
		
		if (x == reverse(x)) {
			return true;
		}
		else
		{
			return false;
		}
	}
};

TEST_CASE("9. Palindrome Number")
{
	Solution solution;

	SECTION("Input set 1") {

		int input = 123;

		bool result = solution.isPalindrome(input);

		REQUIRE(result == false);
	}

	SECTION("Input set 2") {

		int input = 0;

		bool result = solution.isPalindrome(input);

		REQUIRE(result == true);
	}

	SECTION("Input set 3") {

		int input = -1;

		bool result = solution.isPalindrome(input);

		REQUIRE(result == false);
	}

	SECTION("Input set 4") {

		int input = 121;

		bool result = solution.isPalindrome(input);

		REQUIRE(result == true);
	}

}