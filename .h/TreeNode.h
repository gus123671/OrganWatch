#include <iostream>

struct TreeNode {
	int priority;

	TreeNode();
	TreeNode(int val);

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* parent = nullptr;
	TreeNode* tail = nullptr;
	TreeNode* _tempEnd = nullptr;
};