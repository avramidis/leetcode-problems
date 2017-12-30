#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:
	bool uniquestring(std::string s, int start, int end) {
		for (int i = start; i < end; i++) {
			for (int j = i + 1; j <= end; j++) {
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
			for (size_t j = i + result; j < s.size(); j++) {
				if (uniquestring(s, i, j)) {
					if (j - i + 1 > result) {
						result = j - i + 1;
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
			result = solution.uniquestring(input, 0, 7);
		}
		REQUIRE(result == false);
	}

	SECTION("Input set 2") {
		std::string input = "a";
		bool result = false;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.uniquestring(input, 0, 0);
		}
		REQUIRE(result == true);
	}

	SECTION("Input set 3") {
		std::string input = "au";
		bool result = false;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.uniquestring(input, 0, 1);
		}
		REQUIRE(result == true);
	}
}

TEST_CASE("Longest Substring Without Repeating Characters")
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

	SECTION("Input set 6") {
		std::string input = "dvdf";
		int result = 0;
		BENCHMARK("Calculate length of the longest substring with unique characters")
		{
			result = solution.lengthOfLongestSubstring(input);
		}
		REQUIRE(result == 3);
	}
}