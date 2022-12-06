#include "../.h/TreeNode.h"

/*
Created By Ethan Willis
gitHub: ethanbwillis
email: ebwillis123@gmail.com
*/

TreeNode::TreeNode() {
	this->priority = 0;
}

TreeNode::TreeNode(double val) {
	this->priority = val;
}

TreeNode::TreeNode(Recipient recipient) {
	this->priority = recipient.priority;
	this->recipient = recipient;
}