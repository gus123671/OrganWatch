#include "../.h/PQTree.h"

/*
Created By Ethan Willis
gitHub: ethanbwillis
email: ebwillis123@gmail.com
*/

PQTree::PQTree() {
	this->_root = nullptr;
	this->_end = nullptr;
}

TreeNode* PQTree::getRoot() {
	return this->_root;
}

double PQTree::retrieveHighestPriority() { // return the root of the max heap, which will be the highest priority
	return _root->priority;
}

void PQTree::findLocation(TreeNode*& root, TreeNode*& recipient) { // converts the size of the heap to binary, then inserts the donor node at the correct location
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
	TreeNode* fill = root;
	this->_size++;
	binarySize = intToBinary(this->_size);
	binarySizeTail = intToBinary(this->_size-1);
	std::string s;
	for (int i = 1; i < binarySize.size(); i++) {
		s += binarySize[i];
	}
	TreeNode* temp = this->_root;
	TreeNode* location = nullptr;

	for (int i = 0; i < s.size(); i++) {
		location = findLocationPass(s[i], fill, temp);
	}
	insertRecipient(s[s.length() - 1], location, recipient);
	
}

void PQTree::insertRecipient(char lastDigit, TreeNode*& root, TreeNode*& recipient) {
	if (lastDigit == '1') {
		if (root->right == nullptr) {
			root->right = recipient;
			this->_end = root->right;
			recipient->parent = root;
			heapifyUp(root->right);
			count = 0;
		}
		else {
			std::cout << recipient->priority << " is not being added" << std::endl;
		}
	}
	else if (lastDigit == '0') {
		if (root->left == nullptr) {
			root->left = recipient;
			this->_end = root->left;
			recipient->parent = root;
			heapifyUp(root->left);
			count = 0;
		}
		else {
			std::cout << recipient->priority << " is not being added" << std::endl;
		}
	}

}

TreeNode* PQTree::findLocationPass(char leftOrRight, TreeNode*& root, TreeNode*& temp) {
	//for each character of the binary string representing size, traverse left for 0, right for 1
	TreeNode* x = nullptr;
	if (root == nullptr) {
		return temp;
	}
	if (leftOrRight == '1') {
		if (root->right == nullptr) {
			return temp;
		}
		temp = root->right;
		root = temp;
	}
	else if (leftOrRight == '0') {
		if(root->left == nullptr) {
			return temp;
		}
		temp = root->left;
		root = temp;
	}
	else {
		return nullptr;
	}

}

void PQTree::heapifyUp(TreeNode*& recipient) {
	//while the priority is greater than its parent, swap
	if (count == 1) {
		this->_end = recipient;
	}
	if (recipient == nullptr) {
		return;
	}
	if (recipient->parent == nullptr) {
		return;
	}
	if (recipient->priority > recipient->parent->priority) {
		swap(recipient->parent, recipient);
		heapifyUp(recipient->parent);
		count++;
	}
}

void PQTree::heapifyDown(TreeNode* recipient) {
	//while the root/parent is less than its child, swap them
	if (recipient == nullptr) {
		return;
	}
	if (recipient->left == nullptr) {
		return;
	}
	TreeNode* maximum = recipient->left;
	if (recipient->right != nullptr && maximum->priority < recipient->right->priority) {
		maximum = recipient->right;
	}
	if (maximum->priority > recipient->priority) {
		swap(recipient, maximum);
		heapifyDown(maximum);
	}
}

void PQTree::deleteNode() {
	if (this->_root == nullptr) {
		return;
	}
	if (this->_root == this->_end) {
		this->_root = nullptr; this->_end = nullptr;
		delete this->_root; delete this->_end;
	}
	else {
		swap(this->_root, this->_end);
		if (this->_end->parent->left == this->_end) {
			this->_end->parent->left = nullptr;
		}
		else if (this->_end->parent->right == this->_end) {
			this->_end->parent->right = nullptr;
		}
		//delete the end and set it to a new value
		delete this->_end;
		this->_end = nullptr;
		findTail(this->_root);
		count = 0;
		heapifyDown(this->_root);
		this->_size--;
	}
}

void PQTree::printByLevelPriority(TreeNode* root) {
	//inorder traversal using bfs to print each node by level in terms of priority
	if (root == nullptr) {
		return;
	}
	std::queue<TreeNode*> q;
	q.push(root);

	while (!q.empty()) {
		int count = q.size();

		while (count > 0) {
			TreeNode* currNode = q.front();
			std::cout << currNode->priority << " ";
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

void PQTree::print() {
	std::cout << "Print by level: " << std::endl;
	printByLevelPriority(this->_root);
	std::cout << "Highest priority: " << std::endl;
	std::cout << this->retrieveHighestPriority() << std::endl;
	std::cout << "Number of recipients: " << this->_size << std::endl;
}

std::string PQTree::intToBinary(int x) {
	int binaryRemainder, binaryProduct = 1, binaryRep = 0;
	while (x != 0) {
		binaryRemainder = x % 2;
		binaryRep += (binaryRemainder * binaryProduct);
		x = x / 2;
		binaryProduct *= 10;
	}
	return std::to_string(binaryRep);
}

void PQTree::swap(TreeNode* a, TreeNode* b) {
	int val = a->priority;
	a->priority = b->priority;
	b->priority = val;
}

void PQTree::findTail(TreeNode* root) {
	if (root == nullptr || count + 1 > binarySizeTail.size() + 1) {
		return;
	}
	if (binarySizeTail[count + 1] == '1') {
		this->_end = root->right;
		count++;
		findTail(root->right);
	}
	else if (binarySizeTail[count + 1] == '0') {
		this->_end = root->left;
		count++;
		findTail(root->left);
	}
}

void PQTree::insert(Recipient recipient) {
	TreeNode* recipientNode = new TreeNode(recipient);
	this->findLocation(this->_root, recipientNode);
}