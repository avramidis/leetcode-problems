#define CATCH_CONFIG_MAIN

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>
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

			//if (target != 0)
			//{
			//	if (nums[i] > abs(target))
			//	{
			//		std::cout << "In the if-continue branch" << std::endl;
			//		continue;
			//	}
			//}

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

//int main()
//{
//	Solution solution;
//
//	// Generate input data
//	std::vector<int> input;
//
//	input.push_back(-3);
//	input.push_back(4);
//	input.push_back(3);
//	input.push_back(90);
//
//	//for (int i = 0; i < 100; i++)
//	//{
//	//	input.push_back(i);
//	//}
//
//	auto start = std::chrono::system_clock::now();
//	std::vector<int> results = solution.twoSum(input, 0);
//	//std::vector<int> results = solution.twoSum(input, 99 + 98);
//	auto end = std::chrono::system_clock::now();
//
//	std::chrono::duration<double> elapsed_seconds = end - start;
//	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//
//	std::cout << "Elapsed time: " << elapsed_seconds.count() * 1000 << "ms" << std::endl;
//
//	if (results[0] == -1)
//	{
//		std::cout << "No solution was found!" << std::endl;
//	}
//	else
//	{
//		std::cout << "The results is: [" << results[0] << ", " << results[1] << "]" << std::endl;
//	}
//
//	system("pause");
//
//	return 0;
//}