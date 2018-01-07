#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "catch.hpp"

class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}

		unsigned int result = 1;
		unsigned int idx1 = 0;
		unsigned int idx2 = 1;

		while (idx2 != nums.size()) {
			if (nums[idx1] != nums[idx2]) {
				// Stuff are different so just increase the idx locations
				idx1++;
				idx2++;
				result++;
			}
			else {
				// Stuff are the same so remove the same thing
				nums.erase(nums.begin() + result);
			}
		}
		return result;
	}
};

TEST_CASE("26. Remove Duplicates from Sorted Array") {
	Solution solution;

	SECTION("Input set 1") {
		std::vector<int> input = { 1, 1, 2 };
		std::vector<int> output = { 1, 2 };

		int result = solution.removeDuplicates(input);

		REQUIRE(input == output);
		REQUIRE(result == 2);
	}
	SECTION("Input set 2") {
		std::vector<int> input = { };
		std::vector<int> output = { };

		int result = solution.removeDuplicates(input);

		REQUIRE(input == output);
		REQUIRE(result == 0);
	}
	SECTION("Input set 3") {
		std::vector<int> input = { 1, 1, 1 };
		std::vector<int> output = { 1 };

		int result = solution.removeDuplicates(input);

		REQUIRE(input == output);
		REQUIRE(result == 1);
	}
	SECTION("Input set 4") {
		std::vector<int> input = { 1, 2, 3 };
		std::vector<int> output = { 1, 2, 3 };

		int result = solution.removeDuplicates(input);

		REQUIRE(input == output);
		REQUIRE(result == 3);
	}
}