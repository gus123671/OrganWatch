#include "../.h/PQTree.h"
#include <bitset>

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

Recipient PQTree::extract() {
	return _root->recipient;
} // return the recipient with the highest priority

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
	binarySize = intToBinary(++this->_size);
	binarySizeTail = intToBinary(this->_size-1);
	string p;
	int a = 0;
	while (binarySize[a] == '0') {
		a++;
	}
	for (int b = a; b < binarySizeTail.size(); b++) {
		p += binarySizeTail[b];
	}
	binarySizeTail = p;
	std::string s;
	int i = 0;
	while (binarySize[i] == '0') {
		i++;
	}
	for (int j = i + 1; j < binarySize.size(); j++) {
		s += binarySize[j];
	}
	TreeNode* temp = this->_root;
	TreeNode* location = nullptr;

	for (int i = 0; i < s.size(); i++) {
		location = findLocationPass(s[i], fill, temp);
	}
	insertRecipient(s[s.length() - 1], location, recipient);
}

void PQTree::insertRecipient(char lastDigit, TreeNode*& root, TreeNode*& recipient) {
	// adds node to tree based on last digit of size in binary, then heapifies up
	if (lastDigit == '1') {
		if (root->right == nullptr) {
			root->right = recipient;
			this->_end = recipient;
			recipient->parent = root;
			heapifyUp(root->right);
			count = 0;
		}
	}
	else if (lastDigit == '0') {
		if (root->left == nullptr) {
			root->left = recipient;
			this->_end = recipient;
			recipient->parent = root;
			heapifyUp(root->left);
			count = 0;
		}
	}

}

TreeNode* PQTree::findLocationPass(char leftOrRight, TreeNode*& root, TreeNode*& temp) {
	//for each character of the binary string representing size, traverse left for 0, right for 1
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
	return std::bitset<64>(x).to_string();
}

void PQTree::swap(TreeNode* a, TreeNode* b) {
	int val = a->priority;
	Recipient r = a->recipient;
	a->priority = b->priority;
	a->recipient = b->recipient;
	b->priority = val;
	b->recipient = a->recipient;
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

void PQTree::deleteTopPriority() {
	this->deleteNode();
}

vector<Recipient> PQTree::createVector() {
	vector<Recipient> recipients;
	vector<TreeNode*> tree = levelOrderTraverse(this->_root);
	for (int i = 0; i < tree.size(); i++) {
		recipients.push_back(tree[i]->recipient);
	}
	return recipients;
}

vector<TreeNode*> PQTree::levelOrderTraverse(TreeNode* root) {
	vector<TreeNode*> vector;
	if (root == NULL)
		return vector;

	queue<TreeNode*> q;

	q.push(root);

	while (q.empty() == false) {
		TreeNode* node = q.front();
		vector.push_back(node);
		q.pop();

		if (node->left != NULL)
			q.push(node->left);
		if (node->right != NULL)
			q.push(node->right);
	}
	return vector;
}

void PQTree::createInPlace(vector<TreeNode*> nodes) {
	for (int i = 0; i < nodes.size(); i++) {
		this->findLocation(this->_root, nodes[i]);
	}
}

void PQTree::printTopTen() {
	//prints the top ten recipients by priority in descending order
	PQTree* temp = this;
	vector<Recipient> topTen;
	for (int i = 0; i < 10; i++) {
		topTen.push_back(temp->extract());
	}
	for (int i = topTen.size() - 1; i >= 0; i--) {
		cout << topTen[i].getName() << ": " << topTen[i].getPriority();
	}
}

int PQTree::getSize() {
	return this->_size;
}
