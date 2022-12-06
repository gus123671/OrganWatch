#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"

class PQTree {
	TreeNode* _root;
	TreeNode* _end;
	int _size = 0;
	int _tail = 0;
	int count = 0;

	int retrieveHighestPriority();
	void findLocation(TreeNode*& root, TreeNode*& recipient);
	TreeNode* findLocationPass(char leftOrRight, TreeNode*& root, TreeNode*& temp);
	void insertRecipient(char lastDigit, TreeNode*& root, TreeNode*& recipient);
	void deleteNode();
	void heapifyUp(TreeNode*& recipient);
	void heapifyDown(TreeNode* recipient);
	void printByLevel(TreeNode* root);
	void setTreeTail(TreeNode* root);
	void swap(TreeNode* a, TreeNode* b);

public:
	PQTree();
	void createInPlace(std::vector<TreeNode*>& recipientsList);
	void print();
	std::string intToBinary(int x);
};