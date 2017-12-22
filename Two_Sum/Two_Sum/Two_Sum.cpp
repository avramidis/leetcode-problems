#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <algorithm>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		std::vector<int> result;

		int nums_size = nums.size();

		for (int i = 0; i < nums_size; i++)
		{
			if (nums[i] > abs(target))
			{
				continue;
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

int main()
{
	Solution solution;

	// Generate input data
	std::vector<int> input;

	//input.push_back(-2);
	//input.push_back(7);
	//input.push_back(-7);
	//input.push_back(-11);
	//input.push_back(15);

	for (int i = 0; i < 100; i++)
	{
		input.push_back(i);
	}

	auto start = std::chrono::system_clock::now();
	std::vector<int> results = solution.twoSum(input, 99+98);
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	std::cout << "Elapsed time: " << elapsed_seconds.count() * 1000 << "ms" << std::endl;

	if (results[0] == -1)
	{
		std::cout << "No solution was found!" << std::endl;
	}
	else
	{
		std::cout << "The results is: [" << results[0] << ", " << results[1] << "]" << std::endl;
	}

	system("pause");

	return 0;
}