#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:
	bool uniquestring(std::string s) {
		for (size_t i = 0; i < s.size(); i++) {
			for (size_t j = i + 1; j < s.size(); j++) {
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
				std::string temp_s = s.substr(i, j - i + 1);
				if (uniquestring(temp_s)) {
					if (temp_s.size() > result) {
						result = temp_s.size();
						if (result > s.size() - i) {
							return result;
						}
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
		bool result = false;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.uniquestring(input);
		}
		REQUIRE(result == false);
	}

	SECTION("Input set 2") {
		std::string input = "a";
		bool result = false;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.uniquestring(input);
		}
		REQUIRE(result == true);
	}

	SECTION("Input set 2") {
		std::string input = "au";
		bool result = false;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.uniquestring(input);
		}
		REQUIRE(result == true);
	}
}

TEST_CASE("Two sum")
{
	Solution solution;

	SECTION("Input set 1") {
		std::string input = "abcabcbb";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 3);
	}

	SECTION("Input set 2") {
		std::string input = "bbbbb";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 1);
	}

	SECTION("Input set 3") {
		std::string input = "pwwkew";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 3);
	}

	SECTION("Input set 4") {
		std::string input = "c";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 1);
	}

	SECTION("Input set 5") {
		std::string input = "au";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 2);
	}

	SECTION("Input set 6") {
		std::string input = "";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 0);
	}
}