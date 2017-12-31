#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

class Solution {
public:
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
		double result = 0;

		double length = nums1.size() + nums2.size();
		length = length * 0.5;
		std::cout << "\nlength " << length << std::endl;

		int num1loc = -1;
		int num2loc = -1;

		if (length == floor(length)) {
			num1loc = int(length)-1;
			num2loc = int(length);
		}
		else {
			num1loc = int(floor(length));
		}

		std::cout << "\nnum1loc " << num1loc << std::endl;
		std::cout << "num2loc " << num2loc << std::endl;

		int idx1 = 0;
		int idx2 = 0;

		double temp = 0;

		for (int i = 0; i < nums1.size() + nums2.size(); i++) {
			
			std::cout << "\nidx1 " << idx1 << std::endl;
			std::cout << "idx2 " << idx2 << std::endl;

			std::cout << "\nnums1 " << nums1[idx1] << std::endl;
			std::cout << "nums2 " << nums2[idx2] << std::endl;

			if (i == num1loc) {
				if (idx1 < idx2) {
					result = nums1[idx1];
				}
				else {
					result = nums2[idx2];
				}

				if (num2loc == -1) {
					break;
				}
			}

			if (i == num2loc) {
				if (idx1 > idx2) {
					result = (result + nums1[idx1]) * 0.5;
				}
				else {
					result = (result + nums2[idx2]) * 0.5;
				}

				break;
			}

			std::cout << "result " << result << std::endl;

			if (idx1 < nums1.size() - 1) {
				if (nums1[idx1] > nums2[idx2]) {
					idx1++;
				}
			}

			if (idx2 < nums2.size() - 1) {
				if (nums2[idx2] > nums1[idx1]) {
					idx2++;
				}
			}


			//if (nums1[idx1] < nums2[idx2] && idx1 < nums1.size() - 1) {
			//	idx1++;
			//}
			//else {
			//	idx2++;
			//}

			//if (nums2[idx2] < nums1[idx1] && idx2 < nums2.size() - 1) {
			//	idx2++;
			//}
			//else {
			//	idx1++;
			//}
		}

		std::cout << "\nidx1 " << idx1 << std::endl;
		std::cout << "idx2 " << idx2 << std::endl;
		std::cout << "result " << result << std::endl;

		return result;
	}
};

TEST_CASE("Median of Two Sorted Arrays")
{
	Solution solution;

	std::vector<int> nums1;
	std::vector<int> nums2;

	SECTION("Input set 1") {
		nums1.push_back(1);
		nums1.push_back(3);

		nums2.push_back(2);

		double result = 0;
		BENCHMARK("Get the median of two sorted vectors")
		{
			result = solution.findMedianSortedArrays(nums1, nums2);
		}
		REQUIRE(result == 2);
	}

	SECTION("Input set 2") {
		nums1.push_back(1);
		nums1.push_back(2);

		nums2.push_back(3);
		nums2.push_back(4);

		double result = 0;
		BENCHMARK("Get the median of two sorted vectors")
		{
			result = solution.findMedianSortedArrays(nums1, nums2);
		}
		REQUIRE(result == 2.5);
	}

	SECTION("Input set 3") {
		nums1.push_back(2);

		nums2.push_back(1);
		nums2.push_back(2);
		nums2.push_back(5);
		nums2.push_back(6);

		double result = 0;
		BENCHMARK("Get the median of two sorted vectors")
		{
			result = solution.findMedianSortedArrays(nums1, nums2);
		}
		REQUIRE(result == 2.5);
	}
}