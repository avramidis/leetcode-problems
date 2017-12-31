#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:

	bool isoverflow(int x) {
		if (x != 0) {
			return ((x*10)/100 != x / 10);
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

			result = result*10 + x % 10;
			x = x / 10;
		}
		return result;
	}
};

TEST_CASE("7. Reverse Integer")
{
	Solution solution;

	SECTION("Input set 1") {

		int input = 123;
		
		int result = solution.reverse(input);

		REQUIRE(result == 321 );
	}
	
	SECTION("Input set 2") {

		int input = -123;

		int result = solution.reverse(input);

		REQUIRE(result == -321);
	}

	SECTION("Input set 3") {

		int input = 120;

		int result = solution.reverse(input);

		REQUIRE(result == 21);
	}

	SECTION("Input set 4") {

		int input = 0;

		int result = solution.reverse(input);

		REQUIRE(result == 0);
	}

	SECTION("Input set 5") {

		int input = 1534236469;

		int result = solution.reverse(input);

		REQUIRE(result == 0);
	}
}