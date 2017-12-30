#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"


class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {

		return 0;
	}
};

TEST_CASE("Median of Two Sorted Arrays")
{
	Solution solution;

	std::vector<int> num1;
	std::vector<int> num2;

	SECTION("Input set 1") {
		std::string input = "abcabcbb";
		double result = 0;
		BENCHMARK("Check if the string is made of unique characters")
		{
			result = solution.findMedianSortedArrays(num1, num2);
		}
		REQUIRE(result == 0);
	}

}