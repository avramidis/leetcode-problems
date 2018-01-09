#define CATCH_CONFIG_MAIN
#include <iostream>
#include <list>
#include "catch.hpp"

class Solution {
public:
	std::string countAndSay(int n) {
		if (n == 0) {
			return "";
		}
		if (n == 1) {
			return "1";
		}
		if (n == 2) {
			return "11";
		}

		std::string input = "11";
		std::string output = "";

		for (int iter = 3; iter <= n; ++iter) {
			char check = input[0];
			int count = 1;
			output = "";

			for (int i = 1; i < input.size(); ++i) {
				if (check == input[i]) {
					count++;
				}
				else {
					output.append(std::to_string(count));
					output.append(std::string(1, check));

					check = input[i];
					count = 1;
				}
			}
			if (count) {
				output.append(std::to_string(count));
				output.append(std::string(1, check));
			}

			input = output;
		}

		return output;
	}
};

TEST_CASE("38. Count and Say") {
	Solution solution;

	SECTION("Input 1") {
		int input = 1;
		std::string result = solution.countAndSay(input);

		REQUIRE(result == "1");
	}
	SECTION("Input 2") {
		int input = 2;
		std::string result = solution.countAndSay(input);

		REQUIRE(result == "11");
	}
	SECTION("Input 3") {
		int input = 3;
		std::string result = solution.countAndSay(input);

		REQUIRE(result == "21");
	}
	SECTION("Input 4") {
		int input = 4;
		std::string result = solution.countAndSay(input);

		REQUIRE(result == "1211");
	}
	SECTION("Input 5") {
		int input = 5;
		std::string result = solution.countAndSay(input);

		REQUIRE(result == "111221");
	}
}