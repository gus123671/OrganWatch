#include <iostream>
#include "Donor.h"
#include "Recipient.h"

/*
Created By Ethan Willis
gitHub: ethanbwillis
email: ebwillis123@gmail.com
*/

 struct TreeNode {
	double priority;
	Recipient recipient;

	TreeNode();
	TreeNode(double val);
	TreeNode(Recipient recipient);

	TreeNode* left = nullptr;
	TreeNode* right = nullptr;
	TreeNode* parent = nullptr;
};