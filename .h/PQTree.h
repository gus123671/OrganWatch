#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;

/*
Created By Ethan Willis
gitHub: ethanbwillis
email: ebwillis123@gmail.com
*/

class PQTree {
	//tree atrributes
	TreeNode* _root;
	TreeNode* _end;
	int _size = 0;
	int _tail = 0;
	int count = 0;
	string binarySize;
	string binarySizeTail;

	//private functions
	double retrieveHighestPriority();
	void findLocation(TreeNode*& root, TreeNode*& recipient);
	TreeNode* findLocationPass(char leftOrRight, TreeNode*& root, TreeNode*& temp);
	void insertRecipient(char lastDigit, TreeNode*& root, TreeNode*& recipient);
	void deleteNode();
	void heapifyUp(TreeNode*& recipient);
	void heapifyDown(TreeNode* recipient);
	void printByLevelPriority(TreeNode* root);
	void setTreeTail(TreeNode* root);
	void swap(TreeNode* a, TreeNode* b);
	void findTail(TreeNode* root);
	vector<TreeNode*> levelOrderTraverse(TreeNode* root);
	
	
	

public:
	//Public functions to be called on PQTree objects in different classes/files
	PQTree();
	Recipient extractValid(Donor& donor);
	void insert(Recipient recipient);
	void print();
	std::string intToBinary(int x);
	void createInPlace(vector<TreeNode*> nodes);
	Recipient extract();
	void deleteTopPriority();
	TreeNode* getRoot();
	vector<Recipient> createVector();
	void printTopTen();
	int getSize();
	Recipient completeExtract();
	bool isValid(Donor& donor, Recipient& recipient);
};
