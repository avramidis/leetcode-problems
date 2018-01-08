#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

class Solution {
public:
	int searchInsert(std::vector<int>& nums, int target) {
		if (nums.size() == 0) {
			return -1;
		}
		
		unsigned int l = 0;
		unsigned int r = nums.size()-1;

		unsigned int m = 0;
		while (true) {
			if (l == r + 1) {
				return l;
			}
			m = (unsigned int)floor((l + r) / 2);

			if (nums[m] == target) {
				return m;
			}
			if (nums[m] < target) {
				l = m + 1;
				continue;
			}
			if (nums[m] > target) {
				r = m - 1;
				continue;
			}
		}

		return 0;
	}
};

TEST_CASE("35. Search Insert Position") {
	Solution solution;

	SECTION("Input 1") {
		std::vector<int> nums = {};
		int result = solution.searchInsert(nums, 10);
		REQUIRE(result == -1);
	}
	SECTION("Input 2") {
		std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int result = solution.searchInsert(nums, 3);
		REQUIRE(result == 2);
	}
	SECTION("Input 3") {
		std::vector<int> nums = { 1, 2, 3, 4, 6, 7, 8, 9, 10, 11 };
		int result = solution.searchInsert(nums, 5);
		REQUIRE(result == 4);
	}
	SECTION("Input 4") {
		std::vector<int> nums = { 1, 2, 3, 4, 5 };
		int result = solution.searchInsert(nums, 6);
		REQUIRE(result == 5);
	}
	SECTION("Input 5") {
		std::vector<int> nums = { 1, 2, 3, 4, 5 };
		int result = solution.searchInsert(nums, 0);
		REQUIRE(result == 0);
	}
}