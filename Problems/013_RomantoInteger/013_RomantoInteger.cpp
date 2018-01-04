#define CATCH_CONFIG_MAIN
#include <iostream>
#include <unordered_map>
#include "catch.hpp"

class Solution {
public:
	int romanToInt(std::string s) {
		int result = 0;

		std::vector<std::pair<std::string, int>> map = {
			{ "CM", 900 },
			{ "M", 1000 },
			{ "CD", 400 },
			{ "D", 500 },
			{ "XC", 90 },
			{ "C", 100 },
			{ "XL", 40 },
			{ "L", 50 },
			{ "IX", 9 },
			{ "X", 10 },
			{ "VI", 6 },
			{ "IV", 4 },
			{ "V", 5 },
			{ "I", 1 }
		};

		while (!s.empty()) {
			for (auto it = map.begin(); it != map.end(); ++it) {
				int pos = s.find(it->first);
				while (pos != -1) {
					result = result + it->second;
					s.erase(pos, it->first.size());
					pos = s.find(it->first);
				}
			}
		}

		return result;
	}
};

TEST_CASE("13. Roman to Integer")
{
	Solution solution;

	SECTION("Input set 1") {
		std::string input = "III";
		int result = solution.romanToInt(input);
		REQUIRE(result == 3);
	}
	SECTION("Input set 2") {
		std::string input = "I";
		int result = solution.romanToInt(input);
		REQUIRE(result == 1);
	}
	SECTION("Input set 3") {
		std::string input = "IV";
		int result = solution.romanToInt(input);
		REQUIRE(result == 4);
	}
	SECTION("Input set 4") {
		std::string input = "VI";
		int result = solution.romanToInt(input);
		REQUIRE(result == 6);
	}
	SECTION("Input set 5") {
		std::string input = "MMCDII";
		int result = solution.romanToInt(input);
		REQUIRE(result == 2402);
	}
	SECTION("Input set 6") {
		std::string input = "XCVIII";
		int result = solution.romanToInt(input);
		REQUIRE(result == 98);
	}
}