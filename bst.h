#ifndef __BST_HPP__
#define __BST_HPP__

#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

typedef struct Node{
	int value;
	Node* parent;
	Node* left;
	Node* right;
} Node;

class BSTtree{
public:
	BSTtree(){
		root = nullptr;
	};
	~BSTtree(){};

	void addNode(int _value);
	void removeNode(int _value);
	void displayNode1(); // show all Node<K>
    void searchNode(int value_);
    void getTreeGraph();
    void printRootNode(){
        printf("(root node) : %d\n", root->value);
    }
    void tmpFunc2{
        printf("tmpFunc2\n");
    }

private:
	Node* root;
	void displayNode2(Node* _Node);
	Node* search(int _value);
    Node* findMin(Node* Node_);
    void DFSrecurssive(const Node* tmp, vector<int>& arr, int& maxDepth, int tmpDepth);
    int getIndexInTree(int tmpDepth);
};

#endif
