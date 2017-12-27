#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:
	bool uniquestring(std::string s) {
		for (size_t i = 0; i < s.size(); i++) {
			for (size_t j = 0; j < s.size(); j++) {
				if (i == j) {
					continue;
				}
				if (s[i] == s[j]) {
					return false;
				}
			}
		}
		return true;
	}

	int lengthOfLongestSubstring(std::string s) {
		if (s.size() == 0)
		{
			return 0;
		}

		if (s.size() == 1)
		{
			return 1;
		}

		int result = 1;
		
		for (size_t i = 0; i < s.size(); i++) {
			for (size_t j = i+1; j < s.size(); j++) {
				if (uniquestring(s.substr(i, j - i + 1))) {
					if (s.substr(i, j - i + 1).size() > result) {
						result = s.substr(i, j - i + 1).size();
					}
				}
			}
		}

		return result;
	}
};

TEST_CASE("Unique characters in string")
{
	Solution solution;

	SECTION("Input set 1") {
		std::string input = "abcabcbb";
		REQUIRE(solution.uniquestring(input) == false);
	}

	SECTION("Input set 2") {
		std::string input = "a";
		REQUIRE(solution.uniquestring(input) == true);
	}

	SECTION("Input set 2") {
		std::string input = "au";
		REQUIRE(solution.uniquestring(input) == true);
	}
}

TEST_CASE("Two sum")
{
	Solution solution;

	SECTION("Input set 1") {
		std::string input = "abcabcbb";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 3);
	}

	SECTION("Input set 2") {
		std::string input = "bbbbb";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 1);
	}

	SECTION("Input set 3") {
		std::string input = "pwwkew";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 3);
	}

	SECTION("Input set 4") {
		std::string input = "c";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 1);
	}

	SECTION("Input set 5") {
		std::string input = "au";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 2);
	}

	SECTION("Input set 6") {
		std::string input = "";
		int result = solution.lengthOfLongestSubstring(input);
		REQUIRE(result == 0);
	}
}