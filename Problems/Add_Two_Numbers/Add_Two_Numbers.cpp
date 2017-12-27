#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.hpp"

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result = new ListNode(0);
		ListNode* temp_result = result;

		ListNode* temp_l1 = l1;
		ListNode* temp_l2 = l2;

		int sum;
		int carry = 0;

		while (temp_l1 != NULL || temp_l2 != NULL) {
			
			sum = 0;

			if (temp_l1 != NULL) {
				sum = sum + temp_l1->val;
			}

			if (temp_l2 != NULL) {
				sum = sum + temp_l2->val;
			}

			sum = sum + carry;

			if (sum < 10) {
				temp_result->val = sum;
				carry = 0;
			}
			else {
				temp_result->val = (sum % 10);
				carry = 1;
			}

			if (temp_l1 != NULL) {
				if (temp_l1->next != NULL) {
					temp_l1 = temp_l1->next;
				}
				else {
					temp_l1 = NULL;
				}
			}

			if (temp_l2 != NULL) {
				if (temp_l2->next != NULL) {
					temp_l2 = temp_l2->next;
				}
				else {
					temp_l2 = NULL;
				}
			}

			if (temp_l1 != NULL && temp_l2 != NULL) {
				temp_result->next = new ListNode(0);
				temp_result = temp_result->next;
			}
		}

		if (carry == 1) {
			temp_result->next = new ListNode(carry);
		}

		return result;
	}
};

void printlist(ListNode* listNode) {
	
	ListNode* temp_listNode = listNode;
	
	while (temp_listNode != NULL) {
		std::cout << temp_listNode->val << std::endl;
		
		if (temp_listNode->next != NULL) {
			temp_listNode = temp_listNode->next;
		}
		else {
			temp_listNode = NULL;
		}
	}
}

bool compareLists(ListNode* l1, ListNode* l2) {
	
	ListNode* temp_l1 = l1;
	ListNode* temp_l2 = l2;

	while (temp_l1 != NULL && temp_l2 != NULL) {
		if (temp_l1->val != temp_l2->val) {
			return false;
		}

		if ((temp_l1->next == NULL) ^ (temp_l2->next == NULL)) {
			return false;
		}

		temp_l1 = temp_l1->next;
		temp_l2 = temp_l2->next;
	}

	return true;
}

TEST_CASE("Add two numbers")
{
	Solution solution;

	SECTION("Input set 1")
	{
		//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
		//Output : 7 -> 0 -> 8
		//Explanation : 342 + 465 = 807.

		ListNode* l1 = new ListNode(2);
		l1->next = new ListNode(4);
		l1->next->next = new ListNode(3);
		ListNode* l2 = new ListNode(5);
		l2->next = new ListNode(6);
		l2->next->next = new ListNode(4);

		ListNode* result = solution.addTwoNumbers(l1, l2);

		std::cout << std::endl;
		std::cout << "Solution" << std::endl;
		printlist(result);

		ListNode* groundtruth = new ListNode(7);
		groundtruth->next = new ListNode(0);
		groundtruth->next->next = new ListNode(8);
		
		REQUIRE(compareLists(result, groundtruth));
	}

	SECTION("Input set 2")
	{
		//Input: (5) + (5)
		//Output : 0 -> 1
		//Explanation : 5 + 5 = 10.

		ListNode* l1 = new ListNode(5);
		ListNode* l2 = new ListNode(5);

		ListNode* result = solution.addTwoNumbers(l1, l2);

		std::cout << std::endl;
		std::cout << "Solution" << std::endl;
		printlist(result);

		ListNode* groundtruth = new ListNode(0);
		groundtruth->next = new ListNode(1);

		REQUIRE(compareLists(result, groundtruth));
	}


	SECTION("Input set 3")
	{
		//Input: (1 -> 8) + (0)
		//Output : 1 -> 8
		//Explanation : 81 + 0 = 81.

		ListNode* l1 = new ListNode(1);
		l1->next = new ListNode(8);

		ListNode* l2 = new ListNode(0);

		ListNode* result = solution.addTwoNumbers(l1, l2);

		std::cout << std::endl;
		std::cout << "Solution" << std::endl;
		printlist(result);

		ListNode* groundtruth = new ListNode(1);
		groundtruth->next = new ListNode(8);

		REQUIRE(compareLists(result, groundtruth));
	}

}