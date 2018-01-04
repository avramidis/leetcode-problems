#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {
		if (strs.empty()) {
			return "";
		}
		if (strs.size() == 1) {
			return std::string(strs[0].begin(), strs[0].end());
		}

		std::vector<char> result;

		for (int i = 0; i < strs[0].length(); ++i) {
			for (std::vector<std::string>::iterator it = strs.begin()+1; it != strs.end(); ++it) {
				if ((*it).size() < i) {
					return std::string(result.begin(), result.end());
				}

				if ((*it)[i] != strs[0][i]) {
					return std::string(result.begin(), result.end());
				}
			}
			result.push_back(strs[0][i]);
		}
		return std::string(result.begin(), result.end());
	}
};

TEST_CASE("14. Longest Common Prefix")
{
	Solution solution;
	std::vector<std::string> input;

	SECTION("Input set 1") {

		input.push_back("1234567890");
		input.push_back("12345890");

		std::string results;

		results = solution.longestCommonPrefix(input);

		REQUIRE(results == "12345");
	}

	SECTION("Input set 2") {

		input.push_back("1234567890");
		input.push_back("");

		std::string results;

		results = solution.longestCommonPrefix(input);

		REQUIRE(results == "");
	}

	SECTION("Input set 3") {

		input.push_back("1234567890");
		input.push_back("000");

		std::string results;

		results = solution.longestCommonPrefix(input);

		REQUIRE(results == "");
	}

	SECTION("Input set 4") {

		input.push_back("a");
		input.push_back("a");
		input.push_back("b");

		std::string results;

		results = solution.longestCommonPrefix(input);

		REQUIRE(results == "");
	}
}
