#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include "catch.hpp"

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> result;
		size_t nums_size = nums.size();

		for (int i = 0; i < nums_size; i++)
		{
			if (target != 0)
			{
				if (nums[i] == target)
				{
					continue;
				}
			}

			for (int j = i + 1; j < nums_size; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					result.push_back(i);
					result.push_back(j);

					return result;
				}
			}
		}

		result.push_back(-1);
		result.push_back(-1);
		return result;
	}
};

TEST_CASE("Two sum")
{
	Solution solution;
	std::vector<int> input;

	SECTION("Input set 1") {

		input.push_back(-3);
		input.push_back(4);
		input.push_back(3);
		input.push_back(90);

		std::vector<int> results;

		BENCHMARK("Calculate the two sum") 
		{
			results = solution.twoSum(input, 0);
		}

		REQUIRE((results[0] == 0 && results[1] == 2));
	}

	SECTION("Input set 2") {

		input.push_back(-3);
		input.push_back(4);
		input.push_back(3);
		input.push_back(90);

		std::vector<int> results;

		BENCHMARK("Calculate the two sum")
		{
			results = solution.twoSum(input, 93);
		}

		REQUIRE((results[0] == 2 && results[1] == 3));
	}

}
