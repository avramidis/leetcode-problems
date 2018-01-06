#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include <list>

class Solution {
public:
	bool isValid(std::string s) {

		if (s.size() % 2 != 0) {
			return false;
		}

		std::list<char> ends;
		
		for (unsigned int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				ends.push_back(')');
				continue;
			}
			if (s[i] == '{') {
				ends.push_back('}');
				continue;
			}
			if (s[i] == '[') {
				ends.push_back(']');
				continue;
			}

			if (ends.back() != s[i]) {
				return false;
			}
			else {
				ends.pop_back();
			}
		}

		if (ends.size() > 0) {
			return false;
		}
		else {
			return true;
		}
	}
};

TEST_CASE("20. Valid Parentheses")
{
	Solution solution;

	SECTION("Input set 1") {
		std::string input = "()";
		bool result = solution.isValid(input);
		REQUIRE(result == true);
	}
	SECTION("Input set 2") {
		std::string input = "()[]{}";
		bool result = solution.isValid(input);
		REQUIRE(result == true);
	}
	SECTION("Input set 3") {
		std::string input = "(]";
		bool result = solution.isValid(input);
		REQUIRE(result == false);
	}
	SECTION("Input set 4") {
		std::string input = "([)]";
		bool result = solution.isValid(input);
		REQUIRE(result == false);
	}
	SECTION("Input set 5") {
		std::string input = "([{}])";
		bool result = solution.isValid(input);
		REQUIRE(result == true);
	}
	SECTION("Input set 6") {
		std::string input = "([]){}";
		bool result = solution.isValid(input);
		REQUIRE(result == true);
	}
	SECTION("Input set 7") {
		std::string input = "[";
		bool result = solution.isValid(input);
		REQUIRE(result == false);
	}
	SECTION("Input set 8") {
		std::string input = "((";
		bool result = solution.isValid(input);
		REQUIRE(result == false);
	}
}