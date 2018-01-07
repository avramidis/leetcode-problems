#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "catch.hpp"

class Solution {
public:
	int removeElement(std::vector<int>& nums, int val) {
		if (nums.empty()) {
			return 0;
		}
		if (nums.size() == 1) {
			if (nums[0] == val) {
				return 0;
			}
			else {
				return 1;
			}
		}

		unsigned int result = 0;
		unsigned int idx1 = 0;
		unsigned int idx2 = nums.size();

		while (idx1 < idx2) {
			if (nums[idx1] == val) {
				while (idx1 < idx2) {
					idx2--;
					if (nums[idx2] != val) {
						nums[idx1] = nums[idx2];
						result++;
						break;
					}
				}
			}
			else {
				result++;
			}
			idx1++;
		}

		return result;
	}
};

TEST_CASE("27. Remove Element") {
	Solution solution;

	SECTION("Input set 1") {
		std::vector<int> input = { 3, 2, 2, 3 };
		std::vector<int> output = { 2, 2, 2, 3 };

		int result = solution.removeElement(input, 3);

		REQUIRE(result == 2);
		REQUIRE(input == output);
	}
	SECTION("Input set 1") {
		std::vector<int> input = {  };
		std::vector<int> output = {  };

		int result = solution.removeElement(input, 3);

		REQUIRE(result == 0);
		REQUIRE(input == output);
	}
	SECTION("Input set 3") {
		std::vector<int> input = { 2 };
		std::vector<int> output = { 2 };

		int result = solution.removeElement(input, 3);

		REQUIRE(result == 1);
		REQUIRE(input == output);
	}
	SECTION("Input set 4") {
		std::vector<int> input = { 3, 3 };
		std::vector<int> output = { 3, 3 };

		int result = solution.removeElement(input, 3);

		REQUIRE(result == 0);
		REQUIRE(input == output);
	}
	SECTION("Input set 5") {
		std::vector<int> input = { 3, 3 };
		std::vector<int> output = { 3, 3 };

		int result = solution.removeElement(input, 5);

		REQUIRE(result == 2);
		REQUIRE(input == output);
	}
	SECTION("Input set 6") {
		std::vector<int> input = { 1, 2, 3, 4 };
		std::vector<int> output = { 1, 2, 3, 4 };

		int result = solution.removeElement(input, 5);

		REQUIRE(result == 4);
		REQUIRE(input == output);
	}
}