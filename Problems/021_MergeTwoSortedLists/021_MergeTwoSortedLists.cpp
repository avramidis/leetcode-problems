#define CATCH_CONFIG_MAIN
#include <iostream>
#include <vector>
#include "catch.hpp"

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printlist(ListNode* listNode) {
	
	std::cout << std::endl;

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

ListNode* createlist(std::vector<int> *input) {
	ListNode *headNode = new ListNode(input->at(0));
	ListNode *tempNode = headNode;
	//std::cout << tempNode->val << std::endl;

	for (int i = 1; i < input->size(); i++) {
		tempNode->next = new ListNode(input->at(i));
		tempNode = tempNode->next;
		//std::cout << tempNode->val << std::endl;
	}

	return headNode;
}

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL) {
			return NULL;
		}
		if (l1 == NULL) {
			return l2;
		}
		if (l2 == NULL) {
			return l1;
		}

		ListNode *result;
		ListNode *temp1;
		ListNode *temp2;

		ListNode *temp11;
		ListNode *temp22;

		if (l1->val <= l2->val) {
			temp1 = l1;
			temp2 = l2;
			result = temp1;
		}
		else {
			temp1 = l2;
			temp2 = l1;
			result = temp1;
		}

		while (true) {
			if (temp1->next == NULL) {
				temp1->next = temp2;
				break;
			}
			if (temp2->next == NULL) {
				if (temp1->next->val > temp2->val) {
					
					temp11 = temp1->next;

					temp1->next = temp2;
					temp2->next = temp11;

					temp1 = temp1->next;

					break;
				}
				else {
					temp1 = temp1->next;
					continue;
				}
			}

			if (temp1->next->val > temp2->val) {
				temp11 = temp1->next;

				temp22 = temp2->next;

				temp1->next = temp2;
				temp2->next = temp11;

				temp2 = temp22;

				temp1 = temp1->next;
			}
			else {
				temp1 = temp1->next;
			}
		}

		return result;
	}
};

TEST_CASE("21. Merge Two Sorted Lists")
{
	Solution solution;

	SECTION("Input set 1") {
		ListNode* input1 = createlist(new std::vector<int>({ 1, 2, 3 }));
		ListNode* input2 = createlist(new std::vector<int>({ 1, 3, 4 }));
		ListNode* output = createlist(new std::vector<int>({ 1, 1, 2, 3, 3, 4 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 2") {
		ListNode* input1 = createlist(new std::vector<int>({ 1 }));
		ListNode* input2 = createlist(new std::vector<int>({ 1, 3, 4 }));
		ListNode* output = createlist(new std::vector<int>({ 1, 1, 3, 4 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 3") {
		ListNode* input1 = createlist(new std::vector<int>({ 1, 3, 4 }));
		ListNode* input2 = createlist(new std::vector<int>({ 10 }));
		ListNode* output = createlist(new std::vector<int>({ 1, 3, 4, 10 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 4") {
		ListNode* input1 = createlist(new std::vector<int>({ 10 }));
		ListNode* input2 = createlist(new std::vector<int>({ 1, 3, 4 }));
		ListNode* output = createlist(new std::vector<int>({ 1, 3, 4, 10 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 5") {
		ListNode* input1 = createlist(new std::vector<int>({ 10 }));
		ListNode* input2 = createlist(new std::vector<int>({ 20 }));
		ListNode* output = createlist(new std::vector<int>({ 10, 20 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 6") {
		ListNode* input1 = createlist(new std::vector<int>({ 20 }));
		ListNode* input2 = createlist(new std::vector<int>({ 10 }));
		ListNode* output = createlist(new std::vector<int>({ 10, 20 }));

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
	SECTION("Input set 7") {
		ListNode* input1 = NULL;
		ListNode* input2 = NULL;
		ListNode* output = NULL;

		ListNode *result = solution.mergeTwoLists(input1, input2);
		printlist(result);

		REQUIRE(compareLists(output, result) == true);
	}
}