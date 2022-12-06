#include "PQTree.h"

PQTree::PQTree() {
	this->_root = nullptr;
	this->_end = nullptr;
}

int PQTree::retrieveHighestPriority() {
	return _root->priority;
}

void PQTree::setTreeTail(TreeNode* recipient) {
	
}

void PQTree::findLocation(TreeNode*& root, TreeNode*& recipient) {
	if (this->_size == 0) {
		this->_root = recipient;
		this->_end = this->_root;
		this->_size++;
		return;
	}
	else if (this->_size == 1) {
		insertRecipient('0', this->_root, recipient);
		this->_size++;
		return;
	}
	this->_size++;
	std::string heapSize = intToBinary(this->_size);
	std::string s;
	for (int i = 1; i < heapSize.size(); i++) {
		s += heapSize[i];
	}
	TreeNode* temp = this->_root;
	TreeNode* location = nullptr;

	for (int i = 0; i < s.size(); i++) {
		location = findLocationPass(s[i], root, temp);
	}
	
	insertRecipient(s[s.length() - 1], location, recipient);
	
}
	

void PQTree::insertRecipient(char lastDigit, TreeNode*& root, TreeNode*& recipient) {
	if (lastDigit == '1') {
		if (root->right == nullptr) {
			root->right = recipient;
			recipient->parent = root;
			heapifyUp(root->right);
		}
		else {
			
		}
	}
	else if (lastDigit == '0') {
		if (root->left == nullptr) {
			root->left = recipient;
			recipient->parent = root;
			heapifyUp(root->left);
			
		}
		else {
			
		}
	}

}

TreeNode* PQTree::findLocationPass(char leftOrRight, TreeNode*& root, TreeNode*& temp) {
	if (root == nullptr) {
		return temp;
	}
	if (leftOrRight == '1') {
		if (root->right == nullptr) {
			return temp;
		}
		temp = root->right;
	}
	else if (leftOrRight == '0') {
		if(root->left == nullptr) {
			return temp;
		}
		temp = root->left;
	}
	else {
		return nullptr;
	}

}

void PQTree::heapifyUp(TreeNode*& recipient) {
	if (recipient == nullptr) {
		return;
	}
	if (recipient->parent == nullptr) {
		return;
	}
	if (recipient->priority > recipient->parent->priority) {
		swap(recipient->parent, recipient);
		heapifyUp(recipient->parent);
	}
}

void PQTree::heapifyDown(TreeNode* recipient) {
	if (recipient == nullptr) {
		return;
	}
	if (recipient->left == nullptr) {
		return;
	}
	if (recipient->priority > recipient->parent->priority) {
		swap(recipient->parent, recipient);
		heapifyUp(recipient->parent);
	}
}

void PQTree::deleteNode() {
	if (this->_root == nullptr) {
		return;
	}
	if (this->_root == this->_end) {
		this->_root = nullptr; this->_end = nullptr;
	}
	

	
}

void PQTree::printByLevel(TreeNode* root) {
	if (root == nullptr) {
		return;
	}
	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int count = q.size();

		while (count > 0) {
			TreeNode* currNode = q.front();
			std::cout << currNode->priority;
			q.pop();
			if (currNode->left != nullptr) {
				q.push(currNode->left);
			}
			if (currNode->right != nullptr) {
				q.push(currNode->right);
			}
			count--;
		}
		std::cout << std::endl;
	}
}

void PQTree::createInPlace(std::vector<TreeNode*>& recipientsList) {
	for (int i = 0; i < recipientsList.size(); i++) {
		findLocation(this->_root, recipientsList[i]);
	}
}

void PQTree::print() {
	std::cout << "Print by level: " << std::endl;
	printByLevel(this->_root);
	std::cout << "Highest priority: " << std::endl;
	std::cout << this->retrieveHighestPriority() << std::endl;
	std::cout << "Number of recipients: " << this->_size << std::endl;
}

void PQTree::inorderPrint(TreeNode* root) {
	if (root != nullptr) {
		inorderPrint(root->left);
		std::cout << root->priority << std::endl;
		inorderPrint(root->left);
	}
}

std::string PQTree::intToBinary(int x) {
	int remainder, product = 1, binary = 0;
	while (x != 0) {
		remainder = x % 2;
		binary = binary + (remainder * product);
		x = x / 2;
		product *= 10;
	}
	return std::to_string(binary);
}

void PQTree::swap(TreeNode* a, TreeNode* b) {
	int val = a->priority;
	a->priority = b->priority;
	b->priority = val;
}

int PQTree::smallerSwap(TreeNode* a, TreeNode* b) {
	int val = a->priority;
	a->priority = b->priority;
	b->priority = val;
	return b->priority;
}