#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

class Solution {
public:
	int strStr(std::string haystack, std::string needle) {
		if (needle.empty()) {
			return 0;
		}
		if (haystack.empty()) {
			return -1;
		}
		if (haystack.size() < needle.size()) {
			return -1;
		}

		unsigned int j = 0;
		for (unsigned int i = 0; i < haystack.size(); i++) {
			for (unsigned int k = i; i < i + needle.size(); k++) {
				if (haystack[k] == needle[j]) {
					if (j == needle.size() - 1) {
						return k - j;
					}
					j++;
				}
				else {
					j = 0;
					break;
				}
			}
		}
		return -1;
	}
};

TEST_CASE("28. Implement strStr()") {
	Solution solution;

	SECTION("Input 1") {
		std::string haystack = "";
		std::string needle = "test";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == -1);
	}
	SECTION("Input 2") {
		std::string haystack = "";
		std::string needle = "test";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == -1);
	}
	SECTION("Input 3") {
		std::string haystack = "test";
		std::string needle = "test1";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == -1);
	}
	SECTION("Input 4") {
		std::string haystack = "this is sparta!";
		std::string needle = "spa";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == 8);
	}
	SECTION("Input 5") {
		std::string haystack = "this is sparta!";
		std::string needle = "spartas";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == -1);
	}
	SECTION("Input 6") {
		std::string haystack = "";
		std::string needle = "";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == 0);
	}
	SECTION("Input 7") {
		std::string haystack = "mississippi";
		std::string needle = "issip";

		int result = solution.strStr(haystack, needle);

		REQUIRE(result == 4);
	}
}